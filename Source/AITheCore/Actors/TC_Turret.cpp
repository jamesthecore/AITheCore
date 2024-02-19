#include "Actors/TC_Turret.h"

ATC_Turret::ATC_Turret()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent")); 
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	PrimaryActorTick.bCanEverTick = true;
}

FGenericTeamId ATC_Turret::GetGenericTeamId() const
{
	return FGenericTeamId(static_cast<uint8>(Team));
}
