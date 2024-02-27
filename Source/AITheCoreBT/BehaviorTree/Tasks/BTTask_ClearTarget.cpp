#include "BehaviorTree/Tasks/BTTask_ClearTarget.h"

#include "AIController.h"

EBTNodeResult::Type UBTTask_ClearTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* Controller = OwnerComp.GetAIOwner();
	if (!Controller)
		return EBTNodeResult::Failed;

	Controller->K2_ClearFocus();
	return EBTNodeResult::Succeeded;
}
