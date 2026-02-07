// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityBase.h"
#include "DashAbility.generated.h"

UCLASS()
class EVENTABILITYSYSTEM_API UDashAbility : public UAbilityBase
{
	GENERATED_BODY()
	
protected:
	virtual bool CanActivate() const override;
	virtual void OnActivate() override;
	virtual void OnEnd() override;
	
private:
	float DashStrength = 1200.f;
	float DashDuration = 1.f;
	float CooldownDuration = 1.5f;
	
	FTimerHandle DashEndTimerHandle;
};
