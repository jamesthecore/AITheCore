#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/Actor.h"
#include "Interfaces/TC_DamageableInterface.h"
#include "TC_Nexo.generated.h"

enum class ETC_Team;
class ATC_AICharacterBase;

UCLASS(Blueprintable)
class ATC_Nexo : public AActor, public ITC_DamageableInterface, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	ATC_Nexo();

protected:
	UPROPERTY(EditAnywhere)
		ETC_Team Team;
	UPROPERTY(EditAnywhere)
		USceneComponent* SpawnPoint = nullptr;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ATC_AICharacterBase> SpawnClass;
	UPROPERTY(EditAnywhere)
		AActor* MainTarget = nullptr;
	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* Mesh = nullptr;

	virtual void BeginPlay() override;
	virtual FGenericTeamId GetGenericTeamId() const override;
		
};

