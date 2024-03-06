#include "TC_SmartObjectSubsystem.h"

UTC_SmartObjectSubsystem* UTC_SmartObjectSubsystem::GetTCSmartObjectSubsystem(const UWorld* InWorld)
{
	return InWorld ? InWorld->GetSubsystem<UTC_SmartObjectSubsystem>() : nullptr;
}

void UTC_SmartObjectSubsystem::ClaimSmartObject(ATC_SmartObject* SmartObject)
{
	if (!SmartObject)
		return;

	if (ETC_SmartObjectSlotType* FreeSlot = SmartObject->GetFreeSlot())
	{
		*FreeSlot = ETC_SmartObjectSlotType::Claimed;
	}
}
