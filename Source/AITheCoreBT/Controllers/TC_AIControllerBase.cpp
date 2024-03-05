#include "Controllers/TC_AIControllerBase.h"

#include "Actors/SmartObjects/TC_SmartObject.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/TC_AICharacterBase.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Hearing.h"
#include "Perception/AISense_Sight.h"

const AActor* ATC_AIControllerBase::GetPlayer() const
{
	const AActor* Player = BlackboardComponent ? Cast<AActor>(BlackboardComponent->GetValueAsObject("Player")) : nullptr;
	return Player;
}

ATC_AIControllerBase::ATC_AIControllerBase()
{
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));
}

float ATC_AIControllerBase::PlayAnimationOfType(ETC_AnimationType Type, int32 Index) const
{
	ATC_AICharacterBase* CharacterBase = Cast<ATC_AICharacterBase>(GetPawn());
	return CharacterBase ? CharacterBase->PlayAnimationOfType(Type, Index) : -1.f;
}

int32 ATC_AIControllerBase::GetAnimationOfTypeNum(ETC_AnimationType Type) const
{
	const ATC_AICharacterBase* CharacterBase = Cast<ATC_AICharacterBase>(GetPawn());
	return CharacterBase ? CharacterBase->GetAnimationOfTypeNum(Type) : 0;
}

void ATC_AIControllerBase::SetSubTree(const ATC_SmartObject* SmartObject)
{
	if (SmartObject)
	{
		const FGameplayTag SubTag;
		BehaviorTreeComponent->SetDynamicSubtree(SubTag, SmartObject->GetSubTree());
	}
}

void ATC_AIControllerBase::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	const bool bStimulusDetected = Stimulus.WasSuccessfullySensed();
	const bool bSightStimulus = IsStimulusOfTypeDetected<UAISense_Sight>(Stimulus);
	const bool bHearingStimulus = IsStimulusOfTypeDetected<UAISense_Hearing>(Stimulus);

	if (bSightStimulus)
	{
		BlackboardComponent->SetValueAsObject("Player", bStimulusDetected ? Actor : nullptr);
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

void ATC_AIControllerBase::BeginPlay()
{
	Super::BeginPlay();

	const ATC_AICharacterBase* CharacterBase = Cast<ATC_AICharacterBase>(GetPawn());
	const ATC_SmartObject* SmartObject = CharacterBase ? CharacterBase->GetSmartObject() : nullptr;
	SetSubTree(SmartObject);

}
