// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

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
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void PlayAbilityAnimation(UAbilityBase* Ability);
	void ApplyMovementImpulse(FVector Direction, float Strength);
	void ApplyDamage(float Amount);

};
