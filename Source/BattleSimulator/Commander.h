// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Unit.h"
#include "Commander.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESIMULATOR_API ACommander : public AUnit
{
	GENERATED_BODY()
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void GiveBuff(AUnit* Unit);
	void NoBuff(AUnit* Unit);

private:
	//TArray<AUnit*> AllyUnits;

	void GetAllyUnits();
	void isInRange();
	float BuffPercentage = 0.3f;
};
