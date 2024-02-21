
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_DecideBreakIdle.generated.h"

struct FTC_BreakIdleInfo
{
	int32 Index = INDEX_NONE;
};

UCLASS()
class AITHECOREBT_API UBTService_DecideBreakIdle : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTService_DecideBreakIdle();

protected:
	UPROPERTY(EditAnywhere)
		int32 Percentage = 100;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	//virtual void InitializeMemory(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTMemoryInit::Type InitType) const override;
	//virtual uint16 GetInstanceMemorySize() const override;

private:
	bool MatchesPercentage() const;
	
};
