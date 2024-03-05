#include "BehaviorTree/Tasks/BTTask_GetNextSplinePoint.h"

#include "AIController.h"
#include "Actors/SmartObjects/TC_PatrolSmartObject.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/TC_AIPatrolCharacter.h"

UBTTask_GetNextSplinePoint::UBTTask_GetNextSplinePoint()
{
	NodeName = "Get Spline Point";
	bCreateNodeInstance = true;
}

void UBTTask_GetNextSplinePoint::InitializeMemory(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTMemoryInit::Type InitType) const
{
	Super::InitializeMemory(OwnerComp, NodeMemory, InitType);
	FTC_SplinePointInfo* MyMemory = CastInstanceNodeMemory<FTC_SplinePointInfo>(NodeMemory);
	ensureAlways(MyMemory);
	MyMemory->Index = 0;
}

uint16 UBTTask_GetNextSplinePoint::GetInstanceMemorySize() const
{
	return sizeof(FTC_SplinePointInfo);
}

EBTNodeResult::Type UBTTask_GetNextSplinePoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//FTC_SplinePointInfo* MyMemory = CastInstanceNodeMemory<FTC_SplinePointInfo>(NodeMemory);
	//if (!MyMemory)
	//	return EBTNodeResult::Failed;

	const AAIController* Controller = Cast<AAIController>(OwnerComp.GetAIOwner());
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	const ATC_AICharacterBase* CharacterBase = Controller ? Cast<ATC_AICharacterBase>(Controller->GetPawn()) : nullptr;
	const ATC_PatrolSmartObject* CurrentSmartObject = CharacterBase ? Cast<ATC_PatrolSmartObject>(CharacterBase->GetSmartObject()) : nullptr;

	if (!BlackboardComponent || !CurrentSmartObject)
		return EBTNodeResult::Failed;

	const TArray<FVector>& SplinePoints = CurrentSmartObject->GetSplinePoints();
	//int32& Index = MyMemory->Index;

	BlackboardComponent->SetValueAsVector(GetSelectedBlackboardKey(), SplinePoints[Index]);

	if (Index < SplinePoints.Num() - 1)
	{
		++Index;
		return EBTNodeResult::Succeeded;
	}

	Index = 0;
	
	return EBTNodeResult::Succeeded;
}
