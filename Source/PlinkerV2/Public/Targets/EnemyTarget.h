// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Targets/TargetBase.h"
#include "EnemyTarget.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PLINKERV2_API AEnemyTarget : public ATargetBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemyTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Hit(FString areaHit) override;
	virtual void FlipUp() override;
	virtual void FlipDown() override;

	
};
