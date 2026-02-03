// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

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

