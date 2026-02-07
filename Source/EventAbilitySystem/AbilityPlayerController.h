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
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
private:
	void InputDash(const FInputActionValue& Value);
	
	UPROPERTY(EditDefaultsOnly, Category = "Abilities | Input")
	UInputMappingContext* DefaultMappingContext;
	
	UPROPERTY(EditDefaultsOnly, Category = "Abilities | Input")
	UInputAction* DashAction;
};
