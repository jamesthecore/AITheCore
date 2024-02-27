#include "Components/TC_AIMovementComponent.h"
#include "AITheCoreBT.h"

float UTC_AIMovementComponent::GetSpeedByType(ETC_MovementState MovementState)
{
	return MovementState == ETC_MovementState::Walking ? WalkingSpeed : RunningSpeed;
}
