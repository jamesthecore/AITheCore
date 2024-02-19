#include "AI/Controllers/TC_MinionController.h"

#include "AI/Characters/TC_MinionCharacter.h"

AActor* ATC_MinionController::GetCurrentTarget() const
{
	return CurrentTarget;
}

void ATC_MinionController::SetCurrentTarget(AActor* Target)
{
	CurrentTarget = Target;
}

float ATC_MinionController::PlayAttackAnimation() const
{
	const ATC_MinionCharacter* MinionCharacter = Cast<ATC_MinionCharacter>(GetPawn());
	return MinionCharacter ? MinionCharacter->PlayAttackMontage() : -1.f;
}
