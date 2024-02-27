#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ETC_AnimationType
{
	IdleBreaker,
	Attack
};

UENUM(BlueprintType)
enum class ETC_MovementState
{
	Walking,
	Running
};
