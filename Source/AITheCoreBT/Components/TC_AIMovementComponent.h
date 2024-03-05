#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TC_AIMovementComponent.generated.h"

enum class ETC_MovementState;

UCLASS()
class UTC_AIMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	float GetSpeedByType(ETC_MovementState aMovementState);

protected:
	UPROPERTY(EditDefaultsOnly)
		float WalkingSpeed;
	UPROPERTY(EditDefaultsOnly)
		float RunningSpeed;
};