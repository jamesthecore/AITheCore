#include "Characters/TC_AICharacterBase.h"

#include "WidgetComponent.h"
#include "UI/TC_WidgetAggro.h"

ATC_AICharacterBase::ATC_AICharacterBase()
{
	AggroWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("AggroWidgetComponent"));
	AggroWidgetComponent->SetupAttachment(RootComponent);
	PrimaryActorTick.bCanEverTick = true;
}

UBehaviorTree* ATC_AICharacterBase::GetBehaviorTree() const
{
	return BehaviorTree;
}

int32 ATC_AICharacterBase::GetIdleBreakersNum() const
{
	return IdleBreakers.Num();
}

float ATC_AICharacterBase::PlayBreakAnimation(int32 Index)
{
	UAnimMontage* AnimToPlay = Index < IdleBreakers.Num() ? IdleBreakers[Index] : nullptr;
	if (!AnimToPlay)
		return -1.f;

	PlayAnimMontage(AnimToPlay);
	return AnimToPlay->GetPlayLength();
}

void ATC_AICharacterBase::AddAggro(float AggroAmount)
{
	Aggro = FMath::Clamp(Aggro + AggroAmount, 0.f, 1.f);
}

void ATC_AICharacterBase::SetAggro(float NewAggro)
{
	Aggro = NewAggro;
}

float ATC_AICharacterBase::GetAggro() const
{
	return Aggro;
}

void ATC_AICharacterBase::BeginPlay()
{
	Super::BeginPlay();

	if (UTC_WidgetAggro* WidgetAggro = Cast<UTC_WidgetAggro>(AggroWidgetComponent->GetWidget()))
	{
		WidgetAggro->SetCharacterOwner(this);
	}
}
