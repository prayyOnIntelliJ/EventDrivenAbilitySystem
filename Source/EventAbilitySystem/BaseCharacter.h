// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

struct FInputActionValue;
class UAbilityBase;

UCLASS()
class EVENTABILITYSYSTEM_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	void PlayAbilityAnimation(UAbilityBase* Ability);
	void ApplyMovementImpulse(FVector Direction, float Strength);
	void ApplyDamage(float Amount);

public:
	void DoDash(const FInputActionValue& Value);
	void DoMove(const FInputActionValue& Value);
	void DoLook(const FInputActionValue& Value);
	void DoJumpStart();
	void DoJumpEnd();

};
