#include "AI/Controllers/TC_MinionController.h"

AActor* ATC_MinionController::GetCurrentTarget() const
{
	return CurrentTarget;
}

void ATC_MinionController::SetCurrentTarget(AActor* Target)
{
	CurrentTarget = Target;
}
