// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityBase.h"

bool UAbilityBase::CanActivate() const
{
	return true;
}

void UAbilityBase::Activate()
{
	if (CanActivate())
	{
		bIsActive = true;
		OnActivate():
	}
}

bool UAbilityBase::IsOnCooldown() const
{
	return false;
}

void UAbilityBase::End()
{
}

void UAbilityBase::OnActivate()
{
}