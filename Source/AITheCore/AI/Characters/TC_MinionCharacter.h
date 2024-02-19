#pragma once

#include "CoreMinimal.h"
#include "AI/Characters/TC_AICharacterBase.h"
#include "TC_MinionCharacter.generated.h"

enum class ETC_Team;

UCLASS()
class AITHECORE_API ATC_MinionCharacter : public ATC_AICharacterBase
{
	GENERATED_BODY()

public:
	float PlayAttackMontage() const;

protected:
	UPROPERTY(EditDefaultsOnly)
		UAnimMontage* AttackMontage = nullptr;

	UFUNCTION()
		void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void BeginPlay() override;
};
