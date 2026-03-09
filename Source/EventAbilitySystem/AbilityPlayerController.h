#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "AbilityPlayerController.generated.h"

enum class EAbilityTypes : uint8;
class UAbilityBase;
class UInputAction;
class UInputMappingContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAbilityActivatedDelegate, EAbilityTypes, AbilityType, bool, bHasBeenActivated);

UCLASS()
class EVENTABILITYSYSTEM_API AAbilityPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnAbilityActivatedDelegate OnAbilityStateChanged;
	
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
	virtual void OnPossess(APawn* InPawn) override;
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
private:
	void InputDash(const FInputActionValue& Value);
	void InputJumpStart(const FInputActionValue& Value);
	void InputJumpEnd(const FInputActionValue& Value);
	void InputMove(const FInputActionValue& Value);
	void InputLook(const FInputActionValue& Value);
	
	UFUNCTION()
	void RespondToAbilityStateChanged(EAbilityTypes AbilityType, bool bHasBeenActivated);
	
};
