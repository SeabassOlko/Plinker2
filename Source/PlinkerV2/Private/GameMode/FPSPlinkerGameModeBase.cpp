// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/FPSPlinkerGameModeBase.h"

void AFPSPlinkerGameModeBase::StartPlay()
{
	Super::StartPlay();

	// 1. To print to screen
	check(GEngine != nullptr);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode!"));

}
