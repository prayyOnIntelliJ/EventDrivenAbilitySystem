// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilityComponent.generated.h"


class UAbilityBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EVENTABILITYSYSTEM_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAbilityComponent();
	void InitializeAbilities();
	void TryActivateAbility(FName AbilityId);
	void CanActivateAbility(FName AbilityId);
	void GetAbility(FName AbilityId);

protected:
	virtual void BeginPlay() override;
	
private:
	void OnAbilityActivated(UAbilityBase* Ability);
	void OnAbilityEnded(UAbilityBase* Ability);
	void OnAbilityCooldownStarted(UAbilityBase* Ability);
	void OnAbilityCooldownEnded(UAbilityBase* Ability);
	
	ACharacter* GetOwningCharacter() const;
	
	UPROPERTY()
	TMap<FName, UAbilityBase*> Abilities;

};
