#include "FSM/States/TC_State.h"
#include "Kismet/GameplayStatics.h"

void UTC_State::InitState(ATC_AIControllerBase* Controller)
{
	OwnerController = Controller;
}

void UTC_State::EnterState()
{
}

void UTC_State::ExitState()
{
}

void UTC_State::UpdateState(float DeltaTime)
{
}

ATC_AIControllerBase* UTC_State::GetOwnerController() const
{
	return OwnerController;
}
