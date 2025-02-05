// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Logging/StructuredLog.h"
#include "FPSPlinkerGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PLINKERV2_API AFPSPlinkerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	virtual void StartPlay() override;
	
};
