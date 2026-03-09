#include "AbilityBase.h"

#include "AbilityComponent.h"
#include "GameFramework/Character.h"

bool UAbilityBase::CanActivate() const
{
	return true;
}

void UAbilityBase::Initialize(ACharacter* InOwner, class UAbilityComponent* InComponent)
{
	OwnerCharacter = InOwner;
	AbilityComponent = InComponent;
}

void UAbilityBase::Activate()
{
	if (CanActivate())
	{
		bIsActive = true;
		OnActivate();
	}
}

void UAbilityBase::End()
{
	if (!bIsActive)
	{
		return;
	}
	
	bIsActive = false;
	OnEnd();
	
	if (AbilityComponent)
	{
		AbilityComponent->NotifyAbilityEnded(GetAbilityType());
	}
}

void UAbilityBase::Cancel()
{
	if (!bIsActive)
	{
		return;
	}
	
	bIsActive = false;
	
	if (AbilityComponent)
	{
		AbilityComponent->NotifyAbilityEnded(GetAbilityType());
	}
}

void UAbilityBase::OnActivate()
{
}

void UAbilityBase::OnEnd()
{
}

void UAbilityBase::StartCooldown(float Duration)
{
	if (!OwnerCharacter || Duration <= 0.f)
	{
		return;
	}
	
	bIsOnCooldown = true;
	
	if (AbilityComponent)
	{
		AbilityComponent->NotifyAbilityCooldownStarted(GetAbilityType());
	}
	
	OwnerCharacter->GetWorldTimerManager().SetTimer(
		ActivationTimerHandle,
		this,
		&UAbilityBase::ResetCooldown,
		Duration,
		false
		);
}

void UAbilityBase::ResetCooldown()
{
	if (!bIsOnCooldown)
	{
		return;
	}
	
	bIsOnCooldown = false;
	
	if (AbilityComponent)
	{
		AbilityComponent->NotifyAbilityCooldownEnded(GetAbilityType());
	}
}

ACharacter* UAbilityBase::GetOwnerCharacter() const
{
	return OwnerCharacter;
}
