// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"
#include "SaveGame/PlayerSaveLoad.h"
#include "ScoreCardWidget.generated.h"

/**
 * 
 */
UCLASS()
class PLINKERV2_API UScoreCardWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TitleText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* QuitText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* MenuText;

	UPROPERTY(meta = (BindWidget))
	UButton* MenuButton;

	UPROPERTY(meta = (BindWidget))
	UButton* QuitButton;

	UPROPERTY(meta = (BindWidget))
	UImage* BackingImage;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* BestScoreTitleText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* BestScoreText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* PreviousBestScoreTitleText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* PreviousBestScoreText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* PlayerScoreTitleText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* PlayerScoreText;

	UPROPERTY()
	int PlayerScore;

	UPROPERTY()
	int PlayerTime;

	UPROPERTY()
	int PreviousScore;

	UPROPERTY()
	int PreviousTime;

	UPROPERTY()
	int MaxGameScore;

	UPROPERTY()
	bool IsPlayerScoreHigher = false;

	UFUNCTION()
	void OnMenuClicked();

	UFUNCTION()
	void OnQuitClicked();

	UFUNCTION()
	void SaveScore();

	UFUNCTION()
	void LoadScore();

	UFUNCTION()
	void CheckScores();

	UFUNCTION()
	FString SetUpTime(int TimeAmount);

	UFUNCTION()
	void SetUpTexts();
	
};
