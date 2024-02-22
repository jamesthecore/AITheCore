#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISense.h"
#include "TC_AIControllerBase.generated.h"

class UBehaviorTreeComponent;

UCLASS()
class AITHECOREBT_API ATC_AIControllerBase : public AAIController
{
	GENERATED_BODY()

public:
	ATC_AIControllerBase();
	float PlayBreakAnimation(int32 Index) const;
	int32 GetIdleBreakAnimationsNum() const;

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
