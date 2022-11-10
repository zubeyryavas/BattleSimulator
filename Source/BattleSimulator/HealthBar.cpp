// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBar.h"
#include "HealthComponent.h"
#include <Components/ProgressBar.h>
#include <Components/TextBlock.h>

void UHealthBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);

    if(!OwnerUnit.IsValid()) return;

    //UHealthComponent* HealthComp;
    //OwnerUnit->GetComponents<UHealthComponent*>(HealthComp);

    HealthBar->SetPercent(OwnerUnit->Health/OwnerUnit->MaxHealth);

    FNumberFormattingOptions Opts;
    Opts.SetMaximumFractionalDigits(0);
    CurrentHealthLabel->SetText(FText::AsNumber(OwnerUnit->Health, &Opts));
    MaxHealthLabel->SetText(FText::AsNumber(OwnerUnit->MaxHealth, &Opts));
}