#include "Actors/TC_Nexo.h"

#include "AI/Characters/TC_AICharacterBase.h"
#include "AI/Controllers/TC_MinionController.h"

ATC_Nexo::ATC_Nexo()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnPoint"));

	Mesh->SetupAttachment(RootComponent);	
	SpawnPoint->SetupAttachment(RootComponent);
}

void ATC_Nexo::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters Params;
	Params.Owner = this;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	ATC_AICharacterBase* SpawnedActor = GetWorld()->SpawnActor<ATC_AICharacterBase>(SpawnClass, SpawnPoint->GetComponentTransform(), Params);
	if (!SpawnedActor)
	{
		UE_LOG(LogTemp, Error, TEXT("ATC_Nexo::BeginPlay Couldn't spawn actor correctly"));
		return;
	}

	SpawnedActor->SpawnDefaultController();
	SpawnedActor->Team = Team;
	
	if (ATC_MinionController* MinionController = Cast<ATC_MinionController>(SpawnedActor->GetController()))
	{
		MinionController->SetCurrentTarget(MainTarget);
		MinionController->ChangeFSMState("GoToTarget");
	}
}

FGenericTeamId ATC_Nexo::GetGenericTeamId() const
{
	return FGenericTeamId(static_cast<uint8>(Team));
}
