// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityBase.generated.h"

UCLASS()
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
	
	void Initialize(ACharacter* InOwner, class UAbilityComponent* InComponent);
	
protected:
	virtual void OnActivate();
	virtual void OnEnd();
	
	void StartCooldown(float Duration);
	
	ACharacter* GetOwnerCharacter() const;
	
private:
	UPROPERTY()
	ACharacter* OwnerCharacter = nullptr;
	
	UPROPERTY()
	UAbilityComponent* AbilityComponent = nullptr;
	
	bool bIsActive = false;
	bool bIsOnCooldown = false;
	
	FTimerHandle ActivationTimerHandle;
};

