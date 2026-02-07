// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

#include "AbilityComponent.h"
#include "InputActionValue.h"
#include "AbilityIds.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;
}
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::PlayAbilityAnimation(UAbilityBase* Ability)
{
}

void ABaseCharacter::ApplyMovementImpulse(FVector Direction, float Strength)
{
}

void ABaseCharacter::ApplyDamage(float Amount)
{
}

void ABaseCharacter::DoDash(const FInputActionValue& Value)
{
	if (!Value.Get<bool>())
	{
		return;
	}
	
	UAbilityComponent* AbilityComp = FindComponentByClass<UAbilityComponent>();
	
	if (!AbilityComp)
	{
		return;
	}
	
	AbilityComp->TryActivateAbility(AbilityIds::Dash);
}

void ABaseCharacter::DoMove(const FInputActionValue& Value)
{
	if (GetController() != nullptr)
	{
		FVector2D MovementVector = Value.Get<FVector2D>();
		
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ABaseCharacter::DoLook(const FInputActionValue& Value)
{
	FVector2D LookAxisVector = Value.Get<FVector2D>();
	
	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}

void ABaseCharacter::DoJumpStart()
{
	Jump();
}

void ABaseCharacter::DoJumpEnd()
{
	StopJumping();
}
