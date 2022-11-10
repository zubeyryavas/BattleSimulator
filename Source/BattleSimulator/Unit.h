// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AttackType.h"
#include "Team.h"

#include "Unit.generated.h"

UCLASS()
class BATTLESIMULATOR_API AUnit : public ACharacter
{
	GENERATED_BODY()
private: 
	
	
public:
	// Sets default values for this character's properties
	AUnit(const FObjectInitializer& ObjectInitializer);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float MovementSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
		bool idle = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float Health;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float Armor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float ArmorBackup;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
		float AttackRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
		float AttackRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
		float AttackDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
		AttackType AttackType; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
		float Team; 

		//TArray<AUnit*> OnlyAllyUnits;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TArray<class AActor*> FoundActors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TArray<AUnit*> FoundUnits;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TArray<AUnit*> FoundEnemyUnits;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TArray<AUnit*> FoundAllyUnits;

	UPROPERTY(VisibleAnywhere)
		class UWidgetComponent* HealthBarComponent;
	

	bool isNearby = false;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//virtual void GiveBuff(AUnit* Unit);
	
	//FVector Direction;
	//float CurrentDistance;
	//FVector StartLocation;
	
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void Attack();
	
	void HandleDestruction();

	FTimerHandle AttackRateTimer;

	void CheckAttackCondition();

	AUnit* FindClosestEnemy();

	bool isDead;
};
