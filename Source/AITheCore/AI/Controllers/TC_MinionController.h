#pragma once

#include "CoreMinimal.h"
#include "AI/Controllers/TC_AIControllerBase.h"
#include "TC_MinionController.generated.h"

UCLASS()
class AITHECORE_API ATC_MinionController : public ATC_AIControllerBase
{
	GENERATED_BODY()

public:
	AActor* GetCurrentTarget() const;
	void SetCurrentTarget(AActor* Target);

protected:
	UPROPERTY()
		AActor* CurrentTarget = nullptr;
};
