#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/Character.h"
#include "Interfaces/TC_DamageableInterface.h"
#include "TC_AICharacterBase.generated.h"

enum class ETC_Team;
class USphereComponent;

UCLASS()
class AITHECORE_API ATC_AICharacterBase : public ACharacter, public IGenericTeamAgentInterface, public ITC_DamageableInterface
{
	GENERATED_BODY()

public:
	ETC_Team Team;

	ATC_AICharacterBase();

protected:
	UPROPERTY(EditDefaultsOnly)
		USphereComponent* AttackRangeSphereComponent = nullptr;

	virtual FGenericTeamId GetGenericTeamId() const override;
};
