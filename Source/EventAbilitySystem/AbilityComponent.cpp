// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityComponent.h"

#include "AbilityBase.h"
#include "DashAbility.h"
#include "GameFramework/Character.h"

UAbilityComponent::UAbilityComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAbilityComponent::InitializeAbilities()
{
	ACharacter* Owner = GetOwningCharacter();
	if (!Owner)
	{
		return;
	}
	
	UAbilityBase* Dash = NewObject<UDashAbility>(this);
	Dash->Initialize(Owner, this);
	Abilities.Add("Dash", Dash);
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
	NotifyAbilityActivated(Ability);
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
	InitializeAbilities();
}

void UAbilityComponent::HandleAbilityActivated(UAbilityBase* Ability)
{
}

void UAbilityComponent::NotifyAbilityActivated(UAbilityBase* Ability)
{
	HandleAbilityActivated(Ability);
}

void UAbilityComponent::NotifyAbilityEnded(UAbilityBase* Ability)
{
}

void UAbilityComponent::NotifyAbilityCooldownStarted(UAbilityBase* Ability)
{
}

void UAbilityComponent::NotifyAbilityCooldownEnded(UAbilityBase* Ability)
{
}

ACharacter* UAbilityComponent::GetOwningCharacter() const
{
	return Cast<ACharacter>(GetOwner());
}