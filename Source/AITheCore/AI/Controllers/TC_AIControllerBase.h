#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TC_AIControllerBase.generated.h"

class UTC_FSMComponent;

UCLASS()
class AITHECORE_API ATC_AIControllerBase : public AAIController
{
	GENERATED_BODY()

public:
	ATC_AIControllerBase();

	void ChangeFSMState(const FString& StateId);

protected:
	UPROPERTY(EditDefaultsOnly)
		UTC_FSMComponent* FSMComponent = nullptr;

	virtual void BeginPlay() override;
};
