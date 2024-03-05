#pragma once

#include "CoreMinimal.h"
#include "TC_SmartObject.generated.h"

class UArrowComponent;
class UBehaviorTree;

UCLASS()
class ATC_SmartObject : public AActor
{
	GENERATED_BODY()

public:
	ATC_SmartObject();
	UBehaviorTree* GetSubTree() const;

protected:
	UPROPERTY(EditAnywhere, Category = "AI")
		UBehaviorTree* SubTree = nullptr;
	UPROPERTY(EditAnywhere)
		UArrowComponent* ArrowComponent = nullptr;
	UPROPERTY(EditAnywhere)
		UBillboardComponent* BillboardComponent = nullptr;
};