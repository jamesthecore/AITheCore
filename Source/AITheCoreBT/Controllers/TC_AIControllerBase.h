#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TC_AIControllerBase.generated.h"

class UBehaviorTreeComponent;

UCLASS()
class AITHECOREBT_API ATC_AIControllerBase : public AAIController
{
	GENERATED_BODY()

public:
	ATC_AIControllerBase();
	float PlayBreakAnimation(int32 Index) const;
	int32 GetIdleBreakAnimationsNum() const;

protected:
	UPROPERTY()
		UBehaviorTreeComponent* BehaviorTreeComponent = nullptr;
	UPROPERTY()
		UBlackboardComponent* BlackboardComponent = nullptr;

	virtual void OnPossess(APawn* InPawn) override;
};
