#include "AI/Characters/TC_MinionCharacter.h"
#include "AI/Controllers/TC_AIControllerBase.h"
#include "Components/SphereComponent.h"
#include "Interfaces/TC_DamageableInterface.h"

float ATC_MinionCharacter::PlayAttackMontage() const
{
	if (!AttackMontage)
		return -1.f;

	GetMesh()->PlayAnimation(AttackMontage, true);
	return AttackMontage->GetPlayLength();
}

void ATC_MinionCharacter::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const ITC_DamageableInterface* DamageableInterface = Cast<ITC_DamageableInterface>(OtherActor);
	if (!DamageableInterface)
		return;

	const ETeamAttitude::Type Attitude = GetTeamAttitudeTowards(*OtherActor);
	if (Attitude == ETeamAttitude::Hostile)
	{
		if (ATC_AIControllerBase* ControllerBase = Cast<ATC_AIControllerBase>(GetController()))
		{
			ControllerBase->ChangeFSMState("AttackState");
		}
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
