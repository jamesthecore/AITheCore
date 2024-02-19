#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/Actor.h"
#include "Interfaces/TC_DamageableInterface.h"
#include "TC_Turret.generated.h"

enum class ETC_Team;

UCLASS()
class AITHECORE_API ATC_Turret : public AActor, public ITC_DamageableInterface, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
	
public:	
	ATC_Turret();

protected:
	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* Mesh = nullptr;
	UPROPERTY(EditAnywhere)
		ETC_Team Team;

	virtual FGenericTeamId GetGenericTeamId() const override;
};
