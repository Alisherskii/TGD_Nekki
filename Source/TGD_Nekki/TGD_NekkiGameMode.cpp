// Copyright Epic Games, Inc. All Rights Reserved.

#include "TGD_NekkiGameMode.h"
#include "TGD_NekkiCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATGD_NekkiGameMode::ATGD_NekkiGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
