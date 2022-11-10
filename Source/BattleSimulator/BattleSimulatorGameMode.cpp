// Copyright Epic Games, Inc. All Rights Reserved.

#include "BattleSimulatorGameMode.h"
#include "BattleSimulatorPlayerController.h"
#include "BattleSimulatorCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Unit.h"

ABattleSimulatorGameMode::ABattleSimulatorGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABattleSimulatorPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ABattleSimulatorGameMode::UnitDied(AUnit* DeadUnit)
{
	DeadUnit->HandleDestruction();
}