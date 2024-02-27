#include "Characters/TC_AIPatrolCharacter.h"

#include "Components/SplineComponent.h"

ATC_AIPatrolCharacter::ATC_AIPatrolCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	SplineComponent->SetupAttachment(RootComponent);

#if WITH_EDITOR
	SplineComponent->bDrawDebug = true;
#else
	SplineComponent->bDrawDebug = false;
#endif
	
}

const TArray<FVector>& ATC_AIPatrolCharacter::GetSplinePoints() const
{
	return SplinePoints;
}

void ATC_AIPatrolCharacter::FillSplinePoints()
{
	if (!SplineComponent)
		return;

	for (int32 Index = 0; Index <= SplineComponent->GetNumberOfSplinePoints(); ++Index)
	{
		SplinePoints.Add(SplineComponent->GetLocationAtSplinePoint(Index, ESplineCoordinateSpace::World));
	}
}

void ATC_AIPatrolCharacter::BeginPlay()
{
	Super::BeginPlay();

	FillSplinePoints();
}
