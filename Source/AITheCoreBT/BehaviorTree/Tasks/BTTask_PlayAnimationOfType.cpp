#include "BehaviorTree/Tasks/BTTask_PlayAnimationOfType.h"

#include "AITheCoreBT.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Controllers/TC_AIControllerBase.h"

UBTTask_PlayAnimationOfType::UBTTask_PlayAnimationOfType()
{
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_PlayAnimationOfType::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	const ATC_AIControllerBase* ControllerBase = Cast<ATC_AIControllerBase>(OwnerComp.GetAIOwner());

	if (!BlackboardComponent || !ControllerBase)
		return EBTNodeResult::Failed;

	const int32 BreakIndex = bUseBlackboardKey ? BlackboardComponent->GetValueAsInt(GetSelectedBlackboardKey()) : 0;
	const float AnimationTime = ControllerBase->PlayAnimationOfType(Type, BreakIndex);
	BehaviorTreeComponent = &OwnerComp;
	ControllerBase->GetWorldTimerManager().SetTimer(AnimationTimer, this, &UBTTask_PlayAnimationOfType::OnAnimationTimerFinished, AnimationTime);
	return EBTNodeResult::InProgress;
}

void UBTTask_PlayAnimationOfType::OnAnimationTimerFinished()
{
	UBlackboardComponent* BlackboardComponent = BehaviorTreeComponent ? BehaviorTreeComponent->GetBlackboardComponent() : nullptr;
	if (!BlackboardComponent)
		return;

	FinishLatentTask(*BehaviorTreeComponent, EBTNodeResult::Succeeded);
	BlackboardComponent->SetValueAsInt(GetSelectedBlackboardKey(), -1);
	
}
