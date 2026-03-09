#include "DashAbility.h"

#include "BaseCharacter.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UDashAbility::Initialize(ACharacter* InOwner, class UAbilityComponent* InComponent)
{
	Super::Initialize(InOwner, InComponent);
	
	AbilityType = EAbilityTypes::DASH;
}

bool UDashAbility::CanActivate() const
{
	const ACharacter* Character = GetOwnerCharacter();
	if (!Character)
	{
		return false;
	}
	
	return Character->GetCharacterMovement()->IsMovingOnGround();
}

void UDashAbility::OnActivate()
{
	ABaseCharacter* Character = Cast<ABaseCharacter>(GetOwnerCharacter());
	if (!Character)
	{
		End();
		return;
	}
	
	const FVector DashDirection = Character->GetActorForwardVector();
	
	Character->PlayAbilityAnimation(this);
	
	Character->LaunchCharacter(
		DashDirection * DashStrength,
		true,
		true);
	
	Character->GetWorldTimerManager().SetTimer(
		DashEndTimerHandle,
		this,
		&UDashAbility::End,
		DashDuration,
		false);
}

void UDashAbility::OnEnd()
{
	StartCooldown(CooldownDuration);
}