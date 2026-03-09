#include "DoubleJumpAbility.h"

#include "BaseCharacter.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UDoubleJumpAbility::Initialize(ACharacter* InOwner, class UAbilityComponent* InComponent)
{
	Super::Initialize(InOwner, InComponent);
	
	AbilityType = EAbilityTypes::DOUBLE_JUMP;
}

bool UDoubleJumpAbility::CanActivate() const
{
	const ACharacter* Character = GetOwnerCharacter();
	if (!Character)
	{
		return false;
	}
	
	return !Character->GetCharacterMovement()->IsMovingOnGround();
}

void UDoubleJumpAbility::OnActivate()
{
	ABaseCharacter* Character = Cast<ABaseCharacter>(GetOwnerCharacter());
	if (!Character)
	{
		End();
		return;
	}
	
	Character->PlayAbilityAnimation(this);
	
	FVector LaunchDir = Character->GetActorForwardVector() + Character->GetActorUpVector();
	
	Character->LaunchCharacter(
		LaunchDir * DoubleJumpStrength,
		true,
		true);
	
	Character->GetWorldTimerManager().SetTimer(
	DoubleJumpEndTimerHandle,
	this,
	&UDoubleJumpAbility::End,
	DoubleJumpDuration,
	false);
	
	
	Super::OnActivate();
}

void UDoubleJumpAbility::OnEnd()
{
	StartCooldown(DoubleJumpCooldown);
}
