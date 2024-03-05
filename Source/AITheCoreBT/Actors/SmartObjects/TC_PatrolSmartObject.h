#pragma once

#include "CoreMinimal.h"
#include "TC_SmartObject.h"
#include "TC_PatrolSmartObject.generated.h"

class USplineComponent;
class UArrowComponent;
class UBehaviorTree;

UCLASS()
class ATC_PatrolSmartObject : public ATC_SmartObject
{
	GENERATED_BODY()

public:
	ATC_PatrolSmartObject();

	void FillSplinePoints();
	const TArray<FVector>& GetSplinePoints() const;

protected:
	UPROPERTY(EditAnywhere)
		USplineComponent* SplineComponent = nullptr;

	virtual void BeginPlay() override;

private:
	TArray<FVector> SplinePoints;
};