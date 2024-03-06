#pragma once

#include "CoreMinimal.h"
#include "TC_SmartObject.generated.h"

class UArrowComponent;
class UBehaviorTree;

UENUM(BlueprintType)
enum class ETC_SmartObjectSlotType : uint8
{
	Free = 0,
	Claimed,
	Occupied
};

UCLASS()
class ATC_SmartObject : public AActor
{
	GENERATED_BODY()

public:
	ATC_SmartObject();
	UBehaviorTree* GetSubTree() const;
	ETC_SmartObjectSlotType* GetFreeSlot();

protected:
	UPROPERTY(EditAnywhere, Category = "AI")
		UBehaviorTree* SubTree = nullptr;
	UPROPERTY(EditAnywhere)
		UArrowComponent* ArrowComponent = nullptr;
	UPROPERTY(EditAnywhere)
		UBillboardComponent* BillboardComponent = nullptr;
	UPROPERTY(EditAnywhere)
		TArray<ETC_SmartObjectSlotType> Slots;
		
};