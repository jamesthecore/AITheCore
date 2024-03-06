#include "BehaviorTree/Tasks/BTTask_UseSmartObject.h"

#include "Actors/SmartObjects/TC_SmartObject.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Controllers/TC_AIControllerBase.h"

UBTTask_UseSmartObject::UBTTask_UseSmartObject()
{
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_UseSmartObject::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComponent)
		return EBTNodeResult::Failed;

	ATC_AIControllerBase* ControllerBase = Cast<ATC_AIControllerBase>(OwnerComp.GetAIOwner());
	if (!ControllerBase)
		return EBTNodeResult::Failed;

	const ATC_SmartObject* BlackboardSmartObject = Cast<ATC_SmartObject>(BlackboardComponent->GetValueAsObject(GetSelectedBlackboardKey()));
	ControllerBase->SetSubTree(BlackboardSmartObject);

	BlackboardComponent->SetValueAsBool("bIsUsingSmartObject", BlackboardSmartObject != nullptr);
	
	return EBTNodeResult::Succeeded;
}
