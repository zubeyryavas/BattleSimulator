// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Unit.h"
#include "HealthBar.generated.h"

/**
 * 
 */
UCLASS( Abstract )
class BATTLESIMULATOR_API UHealthBar : public UUserWidget
{
	GENERATED_BODY()
public:
	void SetOwnerUnit(AUnit* InUnit) {OwnerUnit = InUnit;}

protected:
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime)override;

	TWeakObjectPtr<AUnit> OwnerUnit;

	UPROPERTY(meta = (BindWidget))
		class UProgressBar* HealthBar;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* CurrentHealthLabel;
	UPROPERTY(meta = (BindWidget))
		class UTextBlock* MaxHealthLabel;
};
