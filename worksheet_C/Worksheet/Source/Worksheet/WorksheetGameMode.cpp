// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Worksheet.h"
#include "WorksheetGameMode.h"
#include "WorksheetHUD.h"
#include "WorksheetCharacter.h"

AWorksheetGameMode::AWorksheetGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AWorksheetHUD::StaticClass();
}
