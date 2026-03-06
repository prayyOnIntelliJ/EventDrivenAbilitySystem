#include "AbilityComponent.h"

#include "AbilityBase.h"
#include "AbilityIds.h"
#include "DashAbility.h"
#include "DoubleJumpAbility.h"
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
	UAbilityBase* DoubleJump = NewObject<UDoubleJumpAbility>(this);
	Dash->Initialize(Owner, this);
	DoubleJump->Initialize(Owner, this);
	Abilities.Add(AbilityIds::Dash, Dash);
	Abilities.Add(AbilityIds::DoubleJump, DoubleJump);
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

UAbilityBase** UAbilityComponent::GetAbility(FName AbilityId)
{
	if (!AbilityId.IsValid() || Abilities.IsEmpty())
	{
		return nullptr;
	}
	
	return Abilities.Find(AbilityId);
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