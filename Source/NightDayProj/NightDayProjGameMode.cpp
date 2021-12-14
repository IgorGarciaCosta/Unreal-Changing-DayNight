// Copyright Epic Games, Inc. All Rights Reserved.

#include "NightDayProjGameMode.h"
#include "NightDayProjCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANightDayProjGameMode::ANightDayProjGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
