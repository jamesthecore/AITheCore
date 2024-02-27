#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISense.h"
#include "TC_AIControllerBase.generated.h"

enum class ETC_AnimationType;
class UBehaviorTreeComponent;

UCLASS()
class AITHECOREBT_API ATC_AIControllerBase : public AAIController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
		const AActor* GetPlayer() const;

	ATC_AIControllerBase();
	float PlayAnimationOfType(ETC_AnimationType Type, int32 Index) const;
	int32 GetAnimationOfTypeNum(ETC_AnimationType Type) const;

protected:
	UPROPERTY()
		UBehaviorTreeComponent* BehaviorTreeComponent = nullptr;
	UPROPERTY()
		UBlackboardComponent* BlackboardComponent = nullptr;

	UFUNCTION()
		void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	virtual void OnPossess(APawn* InPawn) override;

private:
	template<typename T>
	static bool IsStimulusOfTypeDetected(const FAIStimulus& Stimulus)
	{
		return Stimulus.Type == UAISense::GetSenseID<T>();
	}
};
