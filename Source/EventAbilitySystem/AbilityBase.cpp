// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityBase.h"

bool UAbilityBase::CanActivate() const
{
	return true;
}

void UAbilityBase::Initialize(ACharacter* InOwner, class UAbilityComponent* InComponent)
{
}

void UAbilityBase::Activate()
{
	if (CanActivate())
	{
		bIsActive = true;
		OnActivate();
	}
}

void UAbilityBase::End()
{
}

void UAbilityBase::Cancel()
{
}

void UAbilityBase::OnActivate()
{
}

void UAbilityBase::OnEnd()
{
}

void UAbilityBase::StartCooldown(float Duration)
{
}

ACharacter* UAbilityBase::GetOwnerCharacter() const
{
	return OwnerCharacter;
}
