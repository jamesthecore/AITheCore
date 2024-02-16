#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TC_FSMComponent.generated.h"

class ATC_AIControllerBase;
class UTC_State;

USTRUCT(BlueprintType)
struct FTC_StateInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UTC_State> StateClass;
	UPROPERTY()
		UTC_State* State;
};

UCLASS()
class AITHECORE_API UTC_FSMComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void InitStates(ATC_AIControllerBase* OwnerController);
	void ChangeState(const FString& StateId);

protected:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditDefaultsOnly)
		TMap<FString, FTC_StateInfo> States;
	UPROPERTY()
		UTC_State* CurrentState = nullptr;
};
