// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "PlayerSaveLoad.generated.h"

/**
 * 
 */
UCLASS()
class PLINKERV2_API UPlayerSaveLoad : public USaveGame
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere, Category = Basic)
	int BestTime;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	int BestScore;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	uint32 UserIndex;

	UPlayerSaveLoad();

};
