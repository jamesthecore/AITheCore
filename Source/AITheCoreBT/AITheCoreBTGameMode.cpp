// Copyright Epic Games, Inc. All Rights Reserved.

#include "AITheCoreBTGameMode.h"
#include "AITheCoreBTCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAITheCoreBTGameMode::AAITheCoreBTGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
