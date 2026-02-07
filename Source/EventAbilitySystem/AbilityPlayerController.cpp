// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityPlayerController.h"

#include "AbilityComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"

void AAbilityPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = 
			LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AAbilityPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInput =
		Cast<UEnhancedInputComponent>(InputComponent);
	
	check(EnhancedInput);
	
	EnhancedInput->BindAction(
		DashAction,
		ETriggerEvent::Triggered,
		this,
		&AAbilityPlayerController::InputDash
		);
}

void AAbilityPlayerController::InputDash(const FInputActionValue& Value)
{
	if (!Value.Get<bool>())
	{
		return;
	}
	
	ACharacter* Char = GetCharacter();
	if (!Char)
	{
		return;
	}
	
	UAbilityComponent* AbilityComp = Char->FindComponentByClass<UAbilityComponent>();
	
	if (!AbilityComp)
	{
		return;
	}
	
	AbilityComp->TryActivateAbility("Dash");
}
