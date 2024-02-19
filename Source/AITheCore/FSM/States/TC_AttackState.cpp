#include "FSM/States/TC_AttackState.h"

#include "AI/Controllers/TC_MinionController.h"

void UTC_AttackState::EnterState()
{
	Super::EnterState();

	if (const ATC_MinionController* MinionController = Cast<ATC_MinionController>(GetOwnerController()))
	{
		MinionController->PlayAttackAnimation();
	}
}
