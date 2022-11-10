// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitAIController.h"
#include "Unit.h"
#include "Kismet/GameplayStatics.h"


void AUnitAIController::BeginPlay(){
    Super::BeginPlay();
    
    MyActor = static_cast<AUnit*>(GetPawn());
    
}

void AUnitAIController::Tick(float DeltaTime){

    Super::Tick(DeltaTime);
    //MyActor->FindClosestEnemy();
    if(MyActor->FindClosestEnemy()){
        SetFocus(MyActor->FindClosestEnemy());
        MoveToActor(MyActor->FindClosestEnemy(), MyActor->AttackRange-72);
    }
} 
