// Copyright Epic Games, Inc. All Rights Reserved.

#include "SlashGameMode.h"
#include "SlashCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASlashGameMode::ASlashGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
