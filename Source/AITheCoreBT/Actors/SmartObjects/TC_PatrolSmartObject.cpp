#include "Actors/SmartObjects/TC_PatrolSmartObject.h"
#include "Components/SplineComponent.h"

ATC_PatrolSmartObject::ATC_PatrolSmartObject()
{
	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("SplineComponent"));
	SplineComponent->SetupAttachment(RootComponent);

#if WITH_EDITOR
	SplineComponent->bDrawDebug = true;
#else
	SplineComponent->bDrawDebug = false;
#endif
}

const TArray<FVector>& ATC_PatrolSmartObject::GetSplinePoints() const
{
	return SplinePoints;
}

void ATC_PatrolSmartObject::FillSplinePoints()
{
	if (!SplineComponent)
		return;

	for (int32 Index = 0; Index <= SplineComponent->GetNumberOfSplinePoints(); ++Index)
	{
		SplinePoints.Add(SplineComponent->GetLocationAtSplinePoint(Index, ESplineCoordinateSpace::World));
	}
}

void ATC_PatrolSmartObject::BeginPlay()
{
	Super::BeginPlay();

	FillSplinePoints();
}
