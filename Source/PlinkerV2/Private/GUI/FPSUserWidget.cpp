// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/FPSUserWidget.h"

void UFPSUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UFPSUserWidget::SetTimeText(int time)
{
	if (!TimeText) return;

	int MiliSeconds = time % 100;
	int Seconds = (time / 100) % 100;
	int Minutes = time / 10000;

	FString MiliSecString;
	FString SecondsString;
	FString MinutesString;

	if (MiliSeconds < 10)
		MiliSecString = "0" + FString::FromInt(MiliSeconds);
	else
		MiliSecString = FString::FromInt(MiliSeconds);

	if (Seconds < 10)
		SecondsString = "0" + FString::FromInt(Seconds);
	else
		SecondsString = FString::FromInt(Seconds);

	if (Minutes < 10)
		MinutesString = "0" + FString::FromInt(Minutes);
	else
		MinutesString = FString::FromInt(Minutes);

	TimeText->SetText(FText::FromString(MinutesString + ":" + SecondsString + ":" + MiliSecString));
}

void UFPSUserWidget::SetAmmoText(int currentAmmo, int maxAmmo)
{
	if (!AmmoText) return;

	AmmoText->SetText(FText::FromString("Ammo: " + FString::FromInt(currentAmmo) + "/" + FString::FromInt(maxAmmo)));
}

void UFPSUserWidget::SetScoreText(int currentScore, int maxScore)
{
	if (!ScoreText) return;

	ScoreText->SetText(FText::FromString("Score: " + FString::FromInt(currentScore) + "/" + FString::FromInt(maxScore)));
}
