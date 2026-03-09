#pragma once

#include "CoreMinimal.h"
#include "AbilityBase.h"
#include "DashAbility.generated.h"

UCLASS(	Abstract)
class EVENTABILITYSYSTEM_API UDashAbility : public UAbilityBase
{
	GENERATED_BODY()
	
protected:
	virtual void Initialize(ACharacter* InOwner, class UAbilityComponent* InComponent) override;
	virtual bool CanActivate() const override;
	virtual void OnActivate() override;
	virtual void OnEnd() override;
	
private:
	float DashStrength = 3000.f;
	float DashDuration = 1.f;
	float CooldownDuration = 1.5f;
	
	FTimerHandle DashEndTimerHandle;
};
