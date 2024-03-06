#include "BehaviorTree/Tasks/BTTask_GetSmartObject.h"

#include "AIController.h"
#include "Actors/SmartObjects/TC_SmartObject.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/TC_AICharacterBase.h"
#include "Controllers/TC_AIControllerBase.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Subsystem/TC_SmartObjectSubsystem.h"

UBTTask_GetSmartObject::UBTTask_GetSmartObject()
{
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_GetSmartObject::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComponent)
		return EBTNodeResult::Failed;

	const ATC_AIControllerBase* Controller = Cast<ATC_AIControllerBase>(OwnerComp.GetAIOwner());
	const ATC_AICharacterBase* Character = Controller ? Cast<ATC_AICharacterBase>(Controller->GetPawn()) : nullptr;

	if (!Character)
		return EBTNodeResult::Failed;

	UTC_SmartObjectSubsystem* SmartSubsystem = UTC_SmartObjectSubsystem::GetTCSmartObjectSubsystem(GetWorld());
	if (!SmartSubsystem)
		return EBTNodeResult::Failed;

	TArray<ATC_SmartObject*> SmartObjects = SmartSubsystem->GetCloseSmartObjects(SphereRadius, Character->GetActorLocation());
	if (SmartObjects.IsEmpty())
		return EBTNodeResult::Failed;

	const int32 RandIndex = FMath::RandRange(0, SmartObjects.Num() - 1);
	ATC_SmartObject* Result = SmartObjects[RandIndex];

	SmartSubsystem->ClaimSmartObject(Result);
	BlackboardComponent->SetValueAsObject("SmartObject", Result);
	
	return EBTNodeResult::Succeeded;
}
