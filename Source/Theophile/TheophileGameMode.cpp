// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TheophileGameMode.h"
#include "TheophileHUD.h"
#include "TheophileCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATheophileGameMode::ATheophileGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATheophileHUD::StaticClass();
}
