#include "BehaviorTree/Tasks/BTTask_GetSmartObject.h"

#include "AIController.h"
#include "Actors/SmartObjects/TC_SmartObject.h"
#include "Characters/TC_AICharacterBase.h"
#include "Controllers/TC_AIControllerBase.h"
#include "Kismet/KismetSystemLibrary.h"

UBTTask_GetSmartObject::UBTTask_GetSmartObject()
{
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_GetSmartObject::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ATC_AIControllerBase* Controller = Cast<ATC_AIControllerBase>(OwnerComp.GetAIOwner());
	ATC_AICharacterBase* Character = Controller ? Cast<ATC_AICharacterBase>(Controller->GetPawn()) : nullptr;

	if (!Character)
		return EBTNodeResult::Failed;

	TArray<AActor*> Out;
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldDynamic));
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(Character->GetSmartObject());
	DrawDebugSphere(GetWorld(), Character->GetActorLocation(), SphereRadius, 10, FColor::Red);
	if (UKismetSystemLibrary::SphereOverlapActors(this, Character->GetActorLocation(), SphereRadius, ObjectTypes, ATC_SmartObject::StaticClass(), ActorsToIgnore, Out))
	{
		Controller->SetSubTree(Cast<ATC_SmartObject>(Out[FMath::RandRange(0, Out.Num() - 1)]));
	}
	return EBTNodeResult::Succeeded;
}
