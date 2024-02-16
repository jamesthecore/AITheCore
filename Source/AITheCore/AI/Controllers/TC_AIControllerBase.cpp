#include "AI/Controllers/TC_AIControllerBase.h"
#include "FSM/TC_FSMComponent.h"

ATC_AIControllerBase::ATC_AIControllerBase()
{
	FSMComponent = CreateDefaultSubobject<UTC_FSMComponent>(TEXT("FSMComponent"));
}

void ATC_AIControllerBase::ChangeFSMState(const FString& StateId)
{
	if (FSMComponent)
	{
		FSMComponent->ChangeState(StateId);
	}
}

void ATC_AIControllerBase::BeginPlay()
{
	Super::BeginPlay();

	if (FSMComponent)
	{
		FSMComponent->InitStates(this);
	}
}
