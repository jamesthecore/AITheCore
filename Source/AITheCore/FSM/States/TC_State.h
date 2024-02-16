#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TC_State.generated.h"

class ATC_AIControllerBase;

UCLASS(Blueprintable)
class AITHECORE_API UTC_State : public UObject
{
	GENERATED_BODY()

public:
	void InitState(ATC_AIControllerBase* Controller);
	virtual void EnterState();
	virtual void ExitState();
	virtual void UpdateState(float DeltaTime);

	ATC_AIControllerBase* GetOwnerController() const;

protected:
	UPROPERTY()
		ATC_AIControllerBase* OwnerController = nullptr;
	
};
