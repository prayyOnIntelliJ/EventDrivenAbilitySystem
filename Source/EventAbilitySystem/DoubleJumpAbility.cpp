#include "DoubleJumpAbility.h"

#include "BaseCharacter.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

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
	
	const FVector JumpDirection = Character->GetActorUpVector();
	
	Character->PlayAbilityAnimation(this);
	
	Character->LaunchCharacter(
		JumpDirection * DoubleJumpStrength,
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
