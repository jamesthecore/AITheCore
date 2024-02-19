#pragma once

#include "CoreMinimal.h"
#include "FSM/States/TC_State.h"
#include "TC_AttackState.generated.h"

UCLASS(Blueprintable)
class AITHECORE_API UTC_AttackState : public UTC_State
{
	GENERATED_BODY()

protected:
	virtual void EnterState() override;
};
