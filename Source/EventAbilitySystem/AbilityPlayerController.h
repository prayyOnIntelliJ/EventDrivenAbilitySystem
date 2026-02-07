// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "AbilityPlayerController.generated.h"

class UInputAction;
class UInputMappingContext;

UCLASS()
class EVENTABILITYSYSTEM_API AAbilityPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Abilities | Input | Mapping")
	UInputMappingContext* DefaultMappingContext;
	
	UPROPERTY(EditDefaultsOnly, Category = "Abilities | Input | Actions")
	UInputAction* DashAction;
	
	UPROPERTY(EditAnywhere, Category="Abilities | Input | Actions")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, Category="Abilities | Input | Actions")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, Category="Abilities | Input | Actions")
	UInputAction* MouseLookAction;
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
private:
	void InputDash(const FInputActionValue& Value);
	void InputJumpStart(const FInputActionValue& Value);
	void InputJumpEnd(const FInputActionValue& Value);
	void InputMove(const FInputActionValue& Value);
	void InputLook(const FInputActionValue& Value);
	
};
