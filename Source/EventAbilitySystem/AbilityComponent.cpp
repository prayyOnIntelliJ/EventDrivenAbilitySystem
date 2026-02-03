// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityComponent.h"

#include "AbilityBase.h"

UAbilityComponent::UAbilityComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAbilityComponent::InitializeAbilities()
{
}

void UAbilityComponent::TryActivateAbility(FName AbilityId)
{
	UAbilityBase** AbilityPtr = Abilities.Find(AbilityId);
	if (!AbilityPtr) return;
	
	UAbilityBase* Ability = *AbilityPtr;
	
	if (Ability->IsActive() || Ability->IsOnCooldown())
		return;
	
	if (!Ability->CanActivate())
		return;
	
	Ability->Activate();
	OnAbilityActivated(Ability);
}

void UAbilityComponent::CanActivateAbility(FName AbilityId)
{
}

void UAbilityComponent::GetAbility(FName AbilityId)
{
}

void UAbilityComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAbilityComponent::OnAbilityActivated(UAbilityBase* Ability)
{
}

void UAbilityComponent::OnAbilityEnded(UAbilityBase* Ability)
{
}

void UAbilityComponent::OnAbilityCooldownStarted(UAbilityBase* Ability)
{
}

void UAbilityComponent::OnAbilityCooldownEnded(UAbilityBase* Ability)
{
}

ACharacter* UAbilityComponent::GetOwningCharacter() const
{
	return nullptr;
}