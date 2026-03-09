#pragma once

#include "CoreMinimal.h"
#include "AbilityBase.generated.h"

UENUM(BlueprintType)
enum class EAbilityTypes : uint8
{
	DASH = 0 UMETA(DisplayName = "Dash"),
	DOUBLE_JUMP = 1 UMETA(DisplayName = "DoubleJump")
};

UCLASS(Abstract)
class EVENTABILITYSYSTEM_API UAbilityBase : public UObject
{
	GENERATED_BODY()
	
public:
	void Activate();
	void End();
	void Cancel();
	
	FORCEINLINE bool IsActive() const { return bIsActive; }
	FORCEINLINE bool IsOnCooldown() const { return bIsOnCooldown; }
	
	virtual bool CanActivate() const;
	
	virtual void Initialize(ACharacter* InOwner, class UAbilityComponent* InComponent);
	
	FORCEINLINE EAbilityTypes GetAbilityType() { return AbilityType; }
	
protected:
	virtual void OnActivate();
	virtual void OnEnd();
	
	void StartCooldown(float Duration);
	void ResetCooldown();
	
	ACharacter* GetOwnerCharacter() const;
	
	EAbilityTypes AbilityType;
	
private:
	UPROPERTY()
	ACharacter* OwnerCharacter = nullptr;
	
	UPROPERTY()
	UAbilityComponent* AbilityComponent = nullptr;
	
	bool bIsActive = false;
	bool bIsOnCooldown = false;
	
	FTimerHandle ActivationTimerHandle;
};

