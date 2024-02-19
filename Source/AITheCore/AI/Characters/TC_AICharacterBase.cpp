#include "AI/Characters/TC_AICharacterBase.h"

#include "AITheCore.h"
#include "Components/SphereComponent.h"

namespace ATC_AICharacterBase_Const
{
	static constexpr float BaseRadius = 200.f;
}

ATC_AICharacterBase::ATC_AICharacterBase()
{
	AttackRangeSphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("AttackRangeSphereComponent"));
	AttackRangeSphereComponent->SetupAttachment(RootComponent);
	AttackRangeSphereComponent->SetSphereRadius(ATC_AICharacterBase_Const::BaseRadius);
}

FGenericTeamId ATC_AICharacterBase::GetGenericTeamId() const
{
	return FGenericTeamId(static_cast<uint8>(Team));
}