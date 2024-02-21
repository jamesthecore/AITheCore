#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TC_AICharacterBase.generated.h"

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

protected:
	UPROPERTY(EditDefaultsOnly)
		UBehaviorTree* BehaviorTree = nullptr;
	UPROPERTY(EditDefaultsOnly)
		TArray<UAnimMontage*> IdleBreakers;
};
