// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "AttackType.generated.h"
/**
 * 
 */
UENUM(BlueprintType)
enum class AttackType : uint8
{
	TYPE_MELEE UMETA(DisplayName="Melee"),
	TYPE_RANGED UMETA(DisplayName="Ranged"),
	TYPE_NONE UMETA(DisplayName="None")
};