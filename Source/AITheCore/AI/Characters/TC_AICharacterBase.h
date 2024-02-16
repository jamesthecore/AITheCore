#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TC_AICharacterBase.generated.h"

class USphereComponent;

UCLASS()
class AITHECORE_API ATC_AICharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ATC_AICharacterBase();

protected:
	UPROPERTY(EditDefaultsOnly)
		USphereComponent* AttackRangeSphereComponent = nullptr;
};
