#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TC_Nexo.generated.h"

class ATC_AICharacterBase;

UCLASS(Blueprintable)
class ATC_Nexo : public AActor
{
	GENERATED_BODY()

public:
	ATC_Nexo();

protected:
	UPROPERTY(EditAnywhere)
		USceneComponent* SpawnPoint = nullptr;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ATC_AICharacterBase> SpawnClass;
	UPROPERTY(EditAnywhere)
		AActor* MainTarget = nullptr;
	UPROPERTY(EditDefaultsOnly)
		UStaticMeshComponent* Mesh = nullptr;

	virtual void BeginPlay() override;
		
};

