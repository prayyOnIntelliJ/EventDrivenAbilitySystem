#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AbilityComponent.generated.h"

class UAbilityBase;


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityActivatedSignature, EAbilityTypes, AbilityType);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityEndedSignature, EAbilityTypes, AbilityType);

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
	
	
	void NotifyAbilityActivated(EAbilityTypes AbilityType);
	void NotifyAbilityEnded(EAbilityTypes AbilityType);
	void NotifyAbilityCooldownStarted(EAbilityTypes AbilityType);
	void NotifyAbilityCooldownEnded(EAbilityTypes AbilityType);
	
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnAbilityActivatedSignature OnAbilityActivated;
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnAbilityEndedSignature OnAbilityEnded;

protected:
	virtual void BeginPlay() override;
	
private:
	void HandleAbilityActivated(EAbilityTypes AbilityType);
	void HandleAbilityEnded(EAbilityTypes AbilityType);
	
	ACharacter* GetOwningCharacter() const;
	
	UPROPERTY()
	TMap<FName, UAbilityBase*> Abilities;

};
