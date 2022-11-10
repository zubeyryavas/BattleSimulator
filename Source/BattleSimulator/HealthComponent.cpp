// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BattleSimulatorGameMode.h"
#include "Unit.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	//Health = DefaultHealth;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	BattleSimulatorGameMode = Cast<ABattleSimulatorGameMode>(UGameplayStatics::GetGameMode(this));
	AActor* Owner = GetOwner();
	if(Owner){
		Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
	}
	
}

void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{	
	AUnit* DmgdUnit = Cast<AUnit>(DamagedActor);
	if(Damage <= 0)
	{
		return;
	}
	DmgdUnit->MaxHealth = DefaultHealth;
	Health = Health - Damage;
	DmgdUnit->Health = Health;
	//Cast<AUnit>(DamagedActor)->Health = Health;
	UE_LOG(LogTemp, Warning, TEXT("left health %f"),Health);

	if(Health <= 0.f && BattleSimulatorGameMode){
		BattleSimulatorGameMode->UnitDied(Cast<AUnit>(DamagedActor));
	}

}


// Called every frame
//void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
	//Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
//}

