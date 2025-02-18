// Fill out your copyright notice in the Description page of Project Settings.


#include "Targets/EnemyTarget.h"

AEnemyTarget::AEnemyTarget()
{
	
}

void AEnemyTarget::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyTarget::Hit(FString areaHit)
{
	Super::Hit(areaHit);
	if (IsActive)
	{
		if (areaHit == HeadCube->GetName())
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("HeadShot!")));

		}
		else 
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("BodyShot :(")));

		IsActive = false;
	}
}

void AEnemyTarget::FlipUp()
{
	Super::FlipUp();
}

void AEnemyTarget::FlipDown()
{
	Super::FlipDown();
}
