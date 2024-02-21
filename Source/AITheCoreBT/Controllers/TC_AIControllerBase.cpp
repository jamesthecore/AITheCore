#include "Controllers/TC_AIControllerBase.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/TC_AICharacterBase.h"

ATC_AIControllerBase::ATC_AIControllerBase()
{
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
}

float ATC_AIControllerBase::PlayBreakAnimation(int32 Index) const
{
	ATC_AICharacterBase* CharacterBase = Cast<ATC_AICharacterBase>(GetPawn());
	return CharacterBase ? CharacterBase->PlayBreakAnimation(Index) : -1.f;
}

int32 ATC_AIControllerBase::GetIdleBreakAnimationsNum() const
{
	const ATC_AICharacterBase* CharacterBase = Cast<ATC_AICharacterBase>(GetPawn());
	return CharacterBase ? CharacterBase->GetIdleBreakersNum() : 0;
}

void ATC_AIControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	const ATC_AICharacterBase* CharacterBase = Cast<ATC_AICharacterBase>(InPawn);
	if (UBehaviorTree* BehaviorTree = CharacterBase ? CharacterBase->GetBehaviorTree() : nullptr)
	{
		BlackboardComponent->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
		BehaviorTreeComponent->StartTree(*BehaviorTree);
		BlackboardComponent->SetValueAsInt("IdleBreakerIndex", -1);
	}
}
