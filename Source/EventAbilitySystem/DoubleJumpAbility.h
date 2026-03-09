#pragma once

#include "CoreMinimal.h"
#include "AbilityBase.h"
#include "DoubleJumpAbility.generated.h"

UCLASS()
class EVENTABILITYSYSTEM_API UDoubleJumpAbility : public UAbilityBase
{
	GENERATED_BODY()
	
protected:
	virtual void Initialize(ACharacter* InOwner, class UAbilityComponent* InComponent) override;
	virtual bool CanActivate() const override;
	virtual void OnActivate() override;
	virtual void OnEnd() override;
	
private:
	float DoubleJumpStrength = 500.f;
	float DoubleJumpDuration = 1.f;
	float DoubleJumpCooldown = 5.f;
	
	FTimerHandle DoubleJumpEndTimerHandle;
};
