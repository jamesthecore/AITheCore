#include "Controllers/TC_AIControllerBase.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/TC_AICharacterBase.h"
#include "Kismet/KismetMathLibrary.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Hearing.h"
#include "Perception/AISense_Sight.h"

ATC_AIControllerBase::ATC_AIControllerBase()
{
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));
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

void ATC_AIControllerBase::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	const bool bStimulusDetected = Stimulus.WasSuccessfullySensed();
	const bool bSightStimulus = IsStimulusOfTypeDetected<UAISense_Sight>(Stimulus);
	const bool bHearingStimulus = IsStimulusOfTypeDetected<UAISense_Hearing>(Stimulus);

	if (bSightStimulus)
	{
		BlackboardComponent->SetValueAsObject("PlayerAggro", bStimulusDetected ? Actor : nullptr);
	}

	if (bHearingStimulus)
	{
		BlackboardComponent->SetValueAsVector("HearingLocation", bStimulusDetected ? Stimulus.StimulusLocation : FVector());
	}
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

	if (PerceptionComponent)
	{
		PerceptionComponent->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &ATC_AIControllerBase::OnTargetPerceptionUpdated);
	}
}
