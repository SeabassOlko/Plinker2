// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Logging/StructuredLog.h"
#include "Kismet/GameplayStatics.h"
#include "HUD/FPSGameHud.h"
#include "GUI/FPSUserWidget.h"
#include "FPSPlinkerGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PLINKERV2_API AFPSPlinkerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void StartPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float CurrentTime = 0;

	UPROPERTY()
	bool TimerRunning = false;

	UPROPERTY()
	UFPSUserWidget* PlayerHud;

public:
	AFPSPlinkerGameModeBase();

	UFUNCTION()
	void StartTimer();

	UFUNCTION()
	void StopTimer();

	UFUNCTION()
	void UpdateTime();

	UFUNCTION()
	int GetCurrentTime();
};
