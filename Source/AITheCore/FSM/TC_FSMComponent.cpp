#include "FSM/TC_FSMComponent.h"
#include "States/TC_State.h"

void UTC_FSMComponent::InitStates(ATC_AIControllerBase* OwnerController)
{
	if (!OwnerController)
		return;

	for (TPair<FString, FTC_StateInfo>& State : States)
	{
		FTC_StateInfo& StateValue = State.Value;
		StateValue.State = NewObject<UTC_State>(this, StateValue.StateClass);
		StateValue.State->InitState(OwnerController);
	}
}

void UTC_FSMComponent::ChangeState(const FString& StateId)
{
	const FTC_StateInfo* StateInfo = States.Find(StateId);
	if (!StateInfo)
		return;

	if (CurrentState)
	{
		CurrentState->ExitState();
	}

	CurrentState = StateInfo->State;
	if (CurrentState)
	{
		CurrentState->EnterState();
	}
}

void UTC_FSMComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (CurrentState)
	{
		CurrentState->UpdateState(DeltaTime);
	}
}
