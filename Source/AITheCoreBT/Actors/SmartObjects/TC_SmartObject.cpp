#include "Actors/SmartObjects/TC_SmartObject.h"
#include "Components/ArrowComponent.h"
#include "Components/BillboardComponent.h"

ATC_SmartObject::ATC_SmartObject()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	BillboardComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("BillboardComponent"));

	BillboardComponent->SetupAttachment(RootComponent);
	ArrowComponent->SetupAttachment(RootComponent);
}

UBehaviorTree* ATC_SmartObject::GetSubTree() const
{
	return SubTree;
}

ETC_SmartObjectSlotType* ATC_SmartObject::GetFreeSlot()
{
	ETC_SmartObjectSlotType* SlotType = Slots.FindByPredicate([](const ETC_SmartObjectSlotType& SlotType)
	{
		return SlotType == ETC_SmartObjectSlotType::Free;
	});

	return SlotType;  
}