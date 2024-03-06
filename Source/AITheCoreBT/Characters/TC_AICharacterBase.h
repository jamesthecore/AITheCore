#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TC_AICharacterBase.generated.h"

class ATC_SmartObject;
enum class ETC_AnimationType;
class UWidgetComponent;
class UBehaviorTree;

UCLASS()
class AITHECOREBT_API ATC_AICharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ATC_AICharacterBase(const FObjectInitializer& ObjectInitializer);
	UBehaviorTree* GetBehaviorTree() const;

	int32 GetAnimationOfTypeNum(ETC_AnimationType Type) const;
	float PlayAnimationOfType(ETC_AnimationType Type, int32 Index);

	void AddAggro(float AggroAmount);
	void SetAggro(float NewAggro);
	float GetAggro() const;

	ATC_SmartObject* GetSmartObject() const;
protected:
	UPROPERTY(EditAnywhere)
		UBehaviorTree* BehaviorTree = nullptr;
	UPROPERTY(EditDefaultsOnly)
		TArray<UAnimMontage*> IdleBreakers;
	UPROPERTY(EditDefaultsOnly)
		TArray<UAnimMontage*> AttackAnimations;
	UPROPERTY(EditDefaultsOnly)
		UWidgetComponent* AggroWidgetComponent = nullptr;
	UPROPERTY(EditAnywhere)
		ATC_SmartObject* SmartObject = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		float MaxAggro = 1.f;
	UPROPERTY(Transient, BlueprintReadWrite)
		float Aggro = 0.f;

	virtual void BeginPlay() override;

private:
	const TArray<UAnimMontage*>& GetAnimationsOfType(ETC_AnimationType Type) const;
};
