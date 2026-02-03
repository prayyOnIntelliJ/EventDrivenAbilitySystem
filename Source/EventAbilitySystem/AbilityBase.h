// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityBase.generated.h"

UCLASS()
class EVENTABILITYSYSTEM_API UAbilityBase : public UObject
{
	GENERATED_BODY()
	
public:
	virtual bool CanActivate() const;
	void Activate();
	FORCEINLINE bool IsActive() const { return bIsActive; }
	bool IsOnCooldown() const;
	virtual void End();
	
private:
	UPROPERTY()
	ACharacter* Owner;
	
	UPROPERTY()
	bool bIsActive = false;
	
	virtual void OnActivate();
	
	FTimerHandle ActivationTimerHandle;
	
	void StartCooldown();
	void ResetCooldown();
	FORCEINLINE ACharacter* GetOwnerCharacter() const { return Owner; }	
};

