// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h"
#include "GUI/FPSUserWidget.h"
#include "GUI/PauseMenuWidget.h"
#include "GUI/ScoreCardWidget.h"
#include "FPSGameHud.generated.h"

/**
 * 
 */
UCLASS()
class PLINKERV2_API AFPSGameHud : public AHUD
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere)
	UTexture2D* CrosshairTexture;

public:
	virtual void BeginPlay() override;

	// 1. HUD method of making UI
	virtual void DrawHUD() override;

	// 3. UMG method for making UI

	UPROPERTY(EditAnywhere)
	TSubclassOf<UFPSUserWidget> StartingGameWidget;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UPauseMenuWidget> PauseGameWidget;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UScoreCardWidget> ScoreCardWidget;

	UPROPERTY()
	UFPSUserWidget* GameWidgetContainer;

	UPROPERTY()
	UPauseMenuWidget* PauseWidgetContainer;

	UPROPERTY()
	UScoreCardWidget* ScoreCardWidgetContainer;

	UFUNCTION()
	void ShowGameUI(TSubclassOf<UFPSUserWidget> newGameWidget);

	UFUNCTION()
	void ShowPauseMenu(TSubclassOf<UPauseMenuWidget> newGameWidget);

	UFUNCTION()
	void ShowScoreMenu(TSubclassOf<UScoreCardWidget> newGameWidget);

	UFUNCTION()
	void RemovePauseMenu();

	UFUNCTION()
	void QuitGame();
};
