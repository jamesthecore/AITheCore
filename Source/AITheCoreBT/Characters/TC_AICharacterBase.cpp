#include "Characters/TC_AICharacterBase.h"

#include "AITheCoreBT.h"
#include "WidgetComponent.h"
#include "Components/TC_AIMovementComponent.h"
#include "UI/TC_WidgetAggro.h"

ATC_AICharacterBase::ATC_AICharacterBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UTC_AIMovementComponent>("CharMoveComp"))
{
	AggroWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("AggroWidgetComponent"));
	AggroWidgetComponent->SetupAttachment(RootComponent);
	PrimaryActorTick.bCanEverTick = true;
}

UBehaviorTree* ATC_AICharacterBase::GetBehaviorTree() const
{
	return BehaviorTree;
}

int32 ATC_AICharacterBase::GetAnimationOfTypeNum(ETC_AnimationType Type) const
{
	const TArray<UAnimMontage*>& Montages = GetAnimationsOfType(Type);
	return Montages.Num();
}

float ATC_AICharacterBase::PlayAnimationOfType(ETC_AnimationType Type, int32 Index)
{
	const TArray<UAnimMontage*>& Montages = GetAnimationsOfType(Type);
	if (Montages.IsEmpty())
		return -1.f;

	UAnimMontage* AnimToPlay = Index < Montages.Num() ? Montages[Index] : nullptr;
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

ATC_SmartObject* ATC_AICharacterBase::GetSmartObject() const
{
	return SmartObject;
}

void ATC_AICharacterBase::BeginPlay()
{
	Super::BeginPlay();

	if (UTC_WidgetAggro* WidgetAggro = Cast<UTC_WidgetAggro>(AggroWidgetComponent->GetWidget()))
	{
		WidgetAggro->SetCharacterOwner(this);
	}
}

const TArray<UAnimMontage*>& ATC_AICharacterBase::GetAnimationsOfType(ETC_AnimationType Type) const
{
	if (Type == ETC_AnimationType::Attack)
	{
		return AttackAnimations;
	}

	return IdleBreakers;
}
