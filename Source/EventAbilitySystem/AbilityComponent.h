#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilityComponent.generated.h"

class UAbilityBase;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityActivatedSignature, UAbilityBase*, Ability);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityEndedSignature, UAbilityBase*, Ability);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EVENTABILITYSYSTEM_API UAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAbilityComponent();
	void InitializeAbilities();
	void TryActivateAbility(FName AbilityId);
	void CanActivateAbility(FName AbilityId);
	UAbilityBase** GetAbility(FName AbilityId);
	
	
	void NotifyAbilityActivated(UAbilityBase* Ability);
	void NotifyAbilityEnded(UAbilityBase* Ability);
	void NotifyAbilityCooldownStarted(UAbilityBase* Ability);
	void NotifyAbilityCooldownEnded(UAbilityBase* Ability);
	
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnAbilityActivatedSignature OnAbilityActivated;
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnAbilityEndedSignature OnAbilityEnded;

protected:
	virtual void BeginPlay() override;
	
private:
	void HandleAbilityActivated(UAbilityBase* Ability);
	void HandleAbilityEnded(UAbilityBase* Ability);
	
	ACharacter* GetOwningCharacter() const;
	
	UPROPERTY()
	TMap<FName, UAbilityBase*> Abilities;

};
