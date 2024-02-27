#include "BehaviorTree/Services/BTService_DecideBreakIdle.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Controllers/TC_AIControllerBase.h"

UBTService_DecideBreakIdle::UBTService_DecideBreakIdle()
{
	bCreateNodeInstance = true;
}

void UBTService_DecideBreakIdle::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	const ATC_AIControllerBase* Controller = Cast<ATC_AIControllerBase>(OwnerComp.GetAIOwner());
	const int32 NumAnimations = Controller ? Controller->GetAnimationOfTypeNum(Type) : 0;

	if (!BlackboardComponent || NumAnimations == 0)
		return;

	//FTC_BreakIdleInfo* MyMemory = CastInstanceNodeMemory<FTC_BreakIdleInfo>(NodeMemory);
	if (MatchesPercentage())
	{
		const int32 RandIndex = FMath::RandRange(0, NumAnimations - 1);
		BlackboardComponent->SetValueAsInt(GetSelectedBlackboardKey(), RandIndex);
	}

	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}

/**void UBTService_DecideBreakIdle::InitializeMemory(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTMemoryInit::Type InitType) const
{
	Super::InitializeMemory(OwnerComp, NodeMemory, InitType);

	FTC_BreakIdleInfo* MyMemory = CastInstanceNodeMemory<FTC_BreakIdleInfo>(NodeMemory);
	ensureAlways(MyMemory);
	MyMemory->Index = INDEX_NONE;
}*/

/**uint16 UBTService_DecideBreakIdle::GetInstanceMemorySize() const
{
	return sizeof(FTC_BreakIdleInfo);
}*/

bool UBTService_DecideBreakIdle::MatchesPercentage() const
{
	if (Percentage <= 0)
		return false;

	return FMath::RandRange(1, 100 / Percentage) == 1;
}
