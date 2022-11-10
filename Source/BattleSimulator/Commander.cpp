// Fill out your copyright notice in the Description page of Project Settings.


#include "Commander.h"

void ACommander::BeginPlay(){
    Super::BeginPlay();

    //for(int i = 0; i< this->FoundAllyUnits.Num(); i++){
        //if(FoundAllyUnits[i] != this){
            //AllyUnits.Add(this->FoundAllyUnits[i]);
           // UE_LOG(LogTemp, Display, TEXT("Commander ally"));
        //}
   //}

}

void ACommander::Tick(float DeltaTime){
    Super::Tick(DeltaTime);
    isInRange();
}

void ACommander::GiveBuff(AUnit* Unit)
{
    //GetAllyUnits();
    //for(int i =0; i < AllyUnits.Num(); i++){
        //if (FVector::Dist(this->GetActorLocation(),AllyUnits[i]->GetActorLocation()) <= this->AttackRange){
    Unit->Armor = Unit->Armor + Unit->Armor*BuffPercentage;
        //}
   // }

}
void ACommander::NoBuff(AUnit* Unit){
    Unit->Armor = Unit->ArmorBackup;
}

void ACommander::isInRange(){
    //GetAllyUnits();
    for(int i =0; i < FoundAllyUnits.Num(); i++){
        if ((FVector::Dist(this->GetActorLocation(),FoundAllyUnits[i]->GetActorLocation()) <= this->AttackRange) 
            && !FoundAllyUnits[i]->isNearby){
            FoundAllyUnits[i]->isNearby = true;
            GiveBuff(FoundAllyUnits[i]);
        }else if(!(FVector::Dist(this->GetActorLocation(),FoundAllyUnits[i]->GetActorLocation()) <= this->AttackRange) 
                    && FoundAllyUnits[i]->isNearby){
            FoundAllyUnits[i]->isNearby = false;
            NoBuff(FoundAllyUnits[i]);
        }
    }

}

//void ACommander::GetAllyUnits()
//{
//    for(int i = 0; i< this->FoundAllyUnits.Num(); i++){
//        if(FoundAllyUnits[i] != this){
//            AllyUnits.Add(this->FoundAllyUnits[i]);
//        }
//    }
//}

void ACommander::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent){
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}