#pragma once

#include "CoreMinimal.h"
#include "FSM/States/TC_State.h"
#include "TC_GoToTargetState.generated.h"

UCLASS(Blueprintable)
class AITHECORE_API UTC_GoToTargetState : public UTC_State
{
	GENERATED_BODY()

protected:
	virtual void EnterState() override;
	virtual void ExitState() override;
};
