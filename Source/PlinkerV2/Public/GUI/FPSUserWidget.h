// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "FPSUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class PLINKERV2_API UFPSUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TimeText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* AmmoText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ScoreText;

	UFUNCTION()
	void SetTimeText(int time);

	UFUNCTION()
	void SetAmmoText(int currentAmmo, int maxAmmo);

	UFUNCTION()
	void SetScoreText(int currentScore, int maxScore);
	
};
