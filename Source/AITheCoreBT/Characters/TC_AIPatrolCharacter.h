#pragma once

#include "CoreMinimal.h"
#include "Characters/TC_AICharacterBase.h"
#include "TC_AIPatrolCharacter.generated.h"

class USplineComponent;

UCLASS()
class AITHECOREBT_API ATC_AIPatrolCharacter : public ATC_AICharacterBase
{
	GENERATED_BODY()

public:
	ATC_AIPatrolCharacter();

	const TArray<FVector>& GetSplinePoints() const;
	void FillSplinePoints();

protected:
	UPROPERTY(EditAnywhere)
		USplineComponent* SplineComponent = nullptr;

	virtual void BeginPlay() override;

private:
	TArray<FVector> SplinePoints;
};
