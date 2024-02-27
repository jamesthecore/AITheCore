#include "BehaviorTree/Tasks/BTTask_FocusTarget.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UBTTask_FocusTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* Controller = OwnerComp.GetAIOwner();
	const UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	AActor* Player = BlackboardComponent ? Cast<AActor>(BlackboardComponent->GetValueAsObject(GetSelectedBlackboardKey())) : nullptr;
	if (!Controller || !Player)
		return EBTNodeResult::Failed;

	Controller->SetFocus(Player);
	return EBTNodeResult::Succeeded;
}
