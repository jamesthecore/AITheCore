#include "BehaviorTree/Services/BTService_CheckDistance.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/TC_AICharacterBase.h"
#include "Kismet/KismetMathLibrary.h"

void UBTService_CheckDistance::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	AActor* Player = BlackboardComponent ? Cast<AActor>(BlackboardComponent->GetValueAsObject(GetSelectedBlackboardKey())) : nullptr;
	if (!Player)
		return;

	const AAIController* Controller = OwnerComp.GetAIOwner();
	const ATC_AICharacterBase* CharacterBase = Controller ? Cast<ATC_AICharacterBase>(Controller->GetPawn()) : nullptr;
	if (!CharacterBase)
		return;

	const float Distance = UKismetMathLibrary::Vector_Distance(Player->GetActorLocation(), CharacterBase->GetActorLocation());
	if (Distance < 500.f)
	{
		BlackboardComponent->SetValueAsObject(GetSelectedBlackboardKey(), nullptr);
		BlackboardComponent->SetValueAsObject("Player", Cast<UObject>(Player));
	}
}
