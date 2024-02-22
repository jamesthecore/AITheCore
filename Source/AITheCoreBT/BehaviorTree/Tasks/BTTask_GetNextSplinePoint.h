#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_GetNextSplinePoint.generated.h"

struct FTC_SplinePointInfo
{
	int32 Index = INDEX_NONE;
};

UCLASS()
class AITHECOREBT_API UBTTask_GetNextSplinePoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_GetNextSplinePoint();

protected:
	virtual void InitializeMemory(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTMemoryInit::Type InitType) const override;
	virtual uint16 GetInstanceMemorySize() const override;
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};