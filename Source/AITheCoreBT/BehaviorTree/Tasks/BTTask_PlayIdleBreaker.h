#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_PlayIdleBreaker.generated.h"

UCLASS()
class AITHECOREBT_API UBTTask_PlayIdleBreaker : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_PlayIdleBreaker();

protected:
	UPROPERTY()
		UBehaviorTreeComponent* BehaviorTreeComponent = nullptr;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	FTimerHandle AnimationTimer;

	void OnAnimationTimerFinished();
};
