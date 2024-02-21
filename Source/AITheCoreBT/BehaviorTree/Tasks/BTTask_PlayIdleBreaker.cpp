#include "BehaviorTree/Tasks/BTTask_PlayIdleBreaker.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Controllers/TC_AIControllerBase.h"

UBTTask_PlayIdleBreaker::UBTTask_PlayIdleBreaker()
{
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_PlayIdleBreaker::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	const ATC_AIControllerBase* ControllerBase = Cast<ATC_AIControllerBase>(OwnerComp.GetAIOwner());

	if (!BlackboardComponent || !ControllerBase)
		return EBTNodeResult::Failed;

	const int32 BreakIndex = BlackboardComponent->GetValueAsInt(GetSelectedBlackboardKey());
	const float AnimationTime = ControllerBase->PlayBreakAnimation(BreakIndex);
	BehaviorTreeComponent = &OwnerComp;
	ControllerBase->GetWorldTimerManager().SetTimer(AnimationTimer, this, &UBTTask_PlayIdleBreaker::OnAnimationTimerFinished, AnimationTime);
	return EBTNodeResult::InProgress;
}

void UBTTask_PlayIdleBreaker::OnAnimationTimerFinished()
{
	UBlackboardComponent* BlackboardComponent = BehaviorTreeComponent ? BehaviorTreeComponent->GetBlackboardComponent() : nullptr;
	if (!BlackboardComponent)
		return;

	FinishLatentTask(*BehaviorTreeComponent, EBTNodeResult::Succeeded);
	BlackboardComponent->SetValueAsInt(GetSelectedBlackboardKey(), -1);
	
}
