// Fill out your copyright notice in the Description page of Project Settings.


#include "Unit.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "UnitAIController.h"
#include "TimerManager.h"
#include "GameFramework/DamageType.h"
#include "Components/WidgetComponent.h"
#include "HealthBar.h"

// Sets default values
AUnit::AUnit(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    

    HealthBarComponent = ObjectInitializer.CreateDefaultSubobject<UWidgetComponent>(this, TEXT("HealthBar"));
    HealthBarComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AUnit::BeginPlay()
{
	Super::BeginPlay();
	
    UHealthBar* HealthBar = Cast<UHealthBar>(HealthBarComponent->GetUserWidgetObject());
    HealthBar->SetOwnerUnit(this);

    ArmorBackup = Armor;
	
    UGameplayStatics::GetAllActorsOfClass(GetWorld(),AUnit::StaticClass(),FoundActors);
    AUnit* TemporaryUnit;
    for(int i = 0; i<FoundActors.Num();i++){           
        FoundUnits.Add(static_cast<AUnit*>(FoundActors[i]));
	}	
	for(int i = 0; i < FoundUnits.Num(); i++){
            if(Team != FoundUnits[i]->Team){
                FoundEnemyUnits.Add(FoundUnits[i]);
                UE_LOG(LogTemp, Display, TEXT("Enemy added"));
            }else if((Team == FoundUnits[i]->Team) && (FoundUnits[i] != this)){
                FoundAllyUnits.Add(FoundUnits[i]);
                UE_LOG(LogTemp, Display, TEXT("Ally added"));
            }
        }
        UE_LOG(LogTemp, Display, TEXT("my team %f, Enemy team %f, enemy attackrange %f "),
                                      Team,
                                      FindClosestEnemy()->Team,
                                      FindClosestEnemy()->AttackRange);


	GetWorldTimerManager().SetTimer(AttackRateTimer, this, &AUnit::CheckAttackCondition, AttackRate, true);
    isDead = false;
}

// Called every frame
void AUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    //FindClosestEnemy();
    //for(int i = 0; i<FoundEnemyUnits.Num(); i++)
    //{
    //    if(FoundEnemyUnits[i]->isDead)
    //}

}

AUnit* AUnit::FindClosestEnemy(){
    AUnit* ClosestEnemy;
    //if(idle){
        //return nullptr;
    //}
    //else{
        if(FoundEnemyUnits.Num()==0){
            return nullptr;
        }else if(FoundEnemyUnits.Num()==1 && !(FoundEnemyUnits[0]->isDead) ){
            return FoundEnemyUnits[0];
        }else{
            ClosestEnemy = FoundEnemyUnits[0];
            for(int i =1;i< FoundEnemyUnits.Num();i++){
                if((FVector::Dist(ClosestEnemy->GetActorLocation(),this->GetActorLocation()) >
                   FVector::Dist(FoundEnemyUnits[i]->GetActorLocation(),GetActorLocation())) && !(FoundEnemyUnits[i]->isDead) ){
                    ClosestEnemy = FoundEnemyUnits[i];
                }
            }
            return ClosestEnemy;
        }
    //}
}


void AUnit::CheckAttackCondition(){
    if(FindClosestEnemy())
    {
        UE_LOG(LogTemp, Display, TEXT("Enemy found"));
        float Distance = FVector::Dist(this->GetActorLocation(),FindClosestEnemy()->GetActorLocation());
		UE_LOG(LogTemp, Display, TEXT("distance %f range %f, enemy attack range %f"),Distance,AttackRange,FindClosestEnemy()->AttackRange);
        if(Distance <= AttackRange)
        {
            UE_LOG(LogTemp, Display, TEXT("Attack is done from Range %f"),AttackRange);
            Attack();
        }
    }
}

void AUnit::Attack(){
	//FVector AttackStartPoint = GetOwner()->GetActorLocation();

    float DamageAmount = (AttackDamage - AttackDamage*FindClosestEnemy()->Armor);
    auto MyOwner = GetOwner();
    if(MyOwner == nullptr) return;
    auto MyOwnerInstigator = MyOwner->GetInstigatorController();
    auto DamageTypeClass = UDamageType::StaticClass();

    UGameplayStatics::ApplyDamage(FindClosestEnemy(),DamageAmount,MyOwnerInstigator,this,DamageTypeClass);
	UE_LOG(LogTemp, Display, TEXT("given damage is %f"),DamageAmount);
}

void AUnit::HandleDestruction()
{      

    //has to wait 10 seconds then destroy
    isDead=true;
    Destroy();
}



// Called to bind functionality to input
void AUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



