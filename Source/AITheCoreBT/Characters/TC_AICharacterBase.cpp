#include "Characters/TC_AICharacterBase.h"

ATC_AICharacterBase::ATC_AICharacterBase()
{
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
