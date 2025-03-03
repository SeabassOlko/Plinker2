// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "HUD/FPSGameHud.h"
#include "GUI/FPSUserWidget.h"
#include "GameManager.generated.h"

UCLASS()
class PLINKERV2_API AGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	int Score = 0;

	UPROPERTY(EditAnywhere)
	int MaxScore = 0;

	UPROPERTY(EditAnywhere)
	int TotalTargets;

	UPROPERTY()
	UFPSUserWidget* PlayerHud;

	UPROPERTY()
	int HeadShotScore = 3;

	UPROPERTY()
	int BodyShotScore = 1;

	bool FirstTick = true;

	UFUNCTION()
	void AddScore(int amount);

	UFUNCTION()
	void RemoveScore(int amount);
};
