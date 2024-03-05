#include "Components/TC_AIMovementComponent.h"
#include "AITheCoreBT.h"

float UTC_AIMovementComponent::GetSpeedByType(ETC_MovementState aMovementState)
{
	return aMovementState == ETC_MovementState::Walking ? WalkingSpeed : RunningSpeed;
}
