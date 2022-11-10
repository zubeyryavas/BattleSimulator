// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "UnitAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESIMULATOR_API AUnitAIController : public AAIController
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaTime) override;

	class AUnit* MyActor;
	
protected:
	virtual void BeginPlay() override;	

};
