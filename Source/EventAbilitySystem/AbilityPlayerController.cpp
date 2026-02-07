// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityPlayerController.h"

#include "AbilityComponent.h"
#include "BaseCharacter.h"
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
	
	EnhancedInput->BindAction(DashAction, ETriggerEvent::Triggered, this, &AAbilityPlayerController::InputDash);
	
	EnhancedInput->BindAction(JumpAction, ETriggerEvent::Started, this, &AAbilityPlayerController::InputJumpStart);
	EnhancedInput->BindAction(JumpAction, ETriggerEvent::Completed, this, &AAbilityPlayerController::InputJumpEnd);
	
	EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAbilityPlayerController::InputMove);
	EnhancedInput->BindAction(MouseLookAction, ETriggerEvent::Triggered, this, &AAbilityPlayerController::InputLook);
}

void AAbilityPlayerController::InputDash(const FInputActionValue& Value)
{
	if (!Value.Get<bool>())
	{
		return;
	}
	
	if (ABaseCharacter* Char = Cast<ABaseCharacter>(GetCharacter()))
	{
		Char->DoDash(Value);
	}
}

void AAbilityPlayerController::InputJumpStart(const FInputActionValue& Value)
{
	if (!Value.Get<bool>())
	{
		return;
	}
	
	if (ABaseCharacter* Char = Cast<ABaseCharacter>(GetCharacter()))
	{
		Char->DoJumpStart();
	}
}

void AAbilityPlayerController::InputJumpEnd(const FInputActionValue& Value)
{
	if (!Value.Get<bool>())
	{
		return;
	}
	
	if (ABaseCharacter* Char = Cast<ABaseCharacter>(GetCharacter()))
	{
		Char->DoJumpEnd();
	}
}

void AAbilityPlayerController::InputMove(const FInputActionValue& Value)
{
	if (!Value.Get<bool>())
	{
		return;
	}
	
	if (ABaseCharacter* Char = Cast<ABaseCharacter>(GetCharacter()))
	{
		Char->DoMove(Value);
	}
}

void AAbilityPlayerController::InputLook(const FInputActionValue& Value)
{
	if (!Value.Get<bool>())
	{
		return;
	}
	
	if (ABaseCharacter* Char = Cast<ABaseCharacter>(GetCharacter()))
	{
		Char->DoLook(Value);
	}
}
