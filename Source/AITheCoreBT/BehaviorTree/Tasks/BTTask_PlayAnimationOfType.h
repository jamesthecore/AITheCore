#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_PlayAnimationOfType.generated.h"

enum class ETC_AnimationType;

UCLASS()
class AITHECOREBT_API UBTTask_PlayAnimationOfType : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_PlayAnimationOfType();

protected:
	UPROPERTY(EditAnywhere)
		bool bUseBlackboardKey = true;
	UPROPERTY(EditAnywhere)
		ETC_AnimationType Type;
	UPROPERTY()
		UBehaviorTreeComponent* BehaviorTreeComponent = nullptr;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	FTimerHandle AnimationTimer;

	void OnAnimationTimerFinished();
};
