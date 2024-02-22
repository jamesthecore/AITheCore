#include "BehaviorTree/Tasks/BTTask_Aggro.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/TC_AICharacterBase.h"

UBTTask_Aggro::UBTTask_Aggro()
{
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_Aggro::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	BlackboardComponent = OwnerComp.GetBlackboardComponent();
	const AAIController* Controller = OwnerComp.GetAIOwner();
	CharacterBase = Controller ? Cast<ATC_AICharacterBase>(Controller->GetPawn()) : nullptr;
	if (!CharacterBase)
		return EBTNodeResult::Failed;

	CharacterBase->GetWorldTimerManager().SetTimer(TimerHandle, this, &UBTTask_Aggro::OnUpdateAggro, AggroCheckTime, true);
	return EBTNodeResult::InProgress;
}

EBTNodeResult::Type UBTTask_Aggro::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	if (BlackboardComponent)
	{
		BlackboardComponent->SetValueAsObject("PlayerAggro", nullptr);
	}

	return Super::AbortTask(OwnerComp, NodeMemory);
}

void UBTTask_Aggro::OnUpdateAggro()
{
	if (!CharacterBase)
		return;

	CharacterBase->AddAggro(AggroStep);
	const float CurrentAggro = CharacterBase->GetAggro();
	if (CurrentAggro >= 1.f && BlackboardComponent)
	{
		BlackboardComponent->SetValueAsObject(GetSelectedBlackboardKey(), BlackboardComponent->GetValueAsObject("PlayerAggro"));
	}
}
