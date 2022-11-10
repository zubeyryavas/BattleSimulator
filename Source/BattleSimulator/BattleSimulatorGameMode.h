// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BattleSimulatorGameMode.generated.h"

UCLASS(minimalapi)
class ABattleSimulatorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABattleSimulatorGameMode();

	void UnitDied(class AUnit* DeadUnit);
};



