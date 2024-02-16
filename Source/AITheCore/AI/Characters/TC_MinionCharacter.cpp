#include "AI/Characters/TC_MinionCharacter.h"
#include "Actors/TC_Nexo.h"
#include "Components/SphereComponent.h"

void ATC_MinionCharacter::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ATC_Nexo* Nexo = Cast<ATC_Nexo>(OtherActor))
	{
		FString s;
	}
}

void ATC_MinionCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (AttackRangeSphereComponent)
	{
		AttackRangeSphereComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &ATC_MinionCharacter::OnComponentBeginOverlap);
	}
}
