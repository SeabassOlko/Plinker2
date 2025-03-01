// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/FPSUserWidget.h"

void UFPSUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	SetupStats();
}

void UFPSUserWidget::SetupStats()
{

	 AFPSPlinkerGameModeBase GameMode = UGameplayStatics::GetGameMode(GetWorld());

}

void UFPSUserWidget::SetTimeText(int time)
{
	if (!TimeText) return;

	TimeText->SetText(FText::FromString(FString::FromInt(time / 60) + ":" + FString::FromInt(time % 60)));
}

void UFPSUserWidget::SetAmmoText(int currentAmmo, int maxAmmo)
{
	if (!AmmoText) return;

	AmmoText->SetText(FText::FromString("Ammo: " + FString::FromInt(currentAmmo) + "/" + FString::FromInt(maxAmmo)));
}

void UFPSUserWidget::SetScoreText(int currentScore, int maxScore)
{
	if (!AmmoText) return;

	AmmoText->SetText(FText::FromString("Score: " + FString::FromInt(currentScore) + "/" + FString::FromInt(maxScore)));
}
