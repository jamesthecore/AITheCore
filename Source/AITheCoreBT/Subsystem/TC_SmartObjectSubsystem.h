#pragma once

#include "CoreMinimal.h"
#include "Actors/SmartObjects/TC_SmartObject.h"
#include "Kismet/KismetSystemLibrary.h"
#include "TC_SmartObjectSubsystem.generated.h"

class ATC_SmartObject;

UCLASS()
class UTC_SmartObjectSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	static UTC_SmartObjectSubsystem* GetTCSmartObjectSubsystem(const UWorld* InWorld);

	void ClaimSmartObject(ATC_SmartObject* SmartObject);

	TArray<ATC_SmartObject*> GetCloseSmartObjects(float Radius, const FVector& InitPosition) const
	{
		TArray<ATC_SmartObject*> Result;
		TArray<AActor*> HitResult;
		const TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes {UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldDynamic)};

		if (UKismetSystemLibrary::SphereOverlapActors(this, InitPosition, Radius, ObjectTypes, ATC_SmartObject::StaticClass(), {}, HitResult))
		{
			HitResult = HitResult.FilterByPredicate([](AActor* Smart)
			{
				ATC_SmartObject* SmartObject = Cast<ATC_SmartObject>(Smart);
				return SmartObject && SmartObject->GetFreeSlot();
			});
		}

		for (AActor* InHitResultResult : HitResult)
		{
			ATC_SmartObject* SmartObject = Cast<ATC_SmartObject>(InHitResultResult);
			if (InHitResultResult)
			{
				Result.Add(SmartObject);
			}
		}

		return Result;
	}
};