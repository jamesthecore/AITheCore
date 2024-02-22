#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TC_AICharacterBase.generated.h"

class UWidgetComponent;
class UBehaviorTree;

UCLASS()
class AITHECOREBT_API ATC_AICharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ATC_AICharacterBase();
	UBehaviorTree* GetBehaviorTree() const;

	int32 GetIdleBreakersNum() const;
	float PlayBreakAnimation(int32 Index);

	void AddAggro(float AggroAmount);
	void SetAggro(float NewAggro);
	float GetAggro() const;

protected:
	UPROPERTY(EditDefaultsOnly)
		UBehaviorTree* BehaviorTree = nullptr;
	UPROPERTY(EditDefaultsOnly)
		TArray<UAnimMontage*> IdleBreakers;
	UPROPERTY(EditDefaultsOnly)
		UWidgetComponent* AggroWidgetComponent = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float MaxAggro = 1.f;
	UPROPERTY(Transient, BlueprintReadWrite)
		float Aggro = 0.f;

	virtual void BeginPlay() override;
};
