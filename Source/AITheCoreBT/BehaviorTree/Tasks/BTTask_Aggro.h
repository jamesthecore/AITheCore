#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_Aggro.generated.h"

class ATC_AICharacterBase;

UCLASS()
class AITHECOREBT_API UBTTask_Aggro : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_Aggro();

protected:
	UPROPERTY(EditAnywhere)
		float AggroStep = 0.1f;
	UPROPERTY(EditAnywhere)
		float AggroCheckTime = 0.3f;

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY()
		ATC_AICharacterBase* CharacterBase = nullptr;
	UPROPERTY()
		UBlackboardComponent* BlackboardComponent = nullptr;

	FTimerHandle TimerHandle;

	void OnUpdateAggro();
};
