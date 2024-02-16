#include "FSM/States/TC_GoToTargetState.h"
#include "AI/Controllers/TC_MinionController.h"

void UTC_GoToTargetState::EnterState()
{
	Super::EnterState();

	if (ATC_MinionController* MinionController = Cast<ATC_MinionController>(GetOwnerController()))
	{
		MinionController->MoveToActor(MinionController->GetCurrentTarget());
	}
}