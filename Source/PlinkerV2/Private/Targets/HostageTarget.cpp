// Fill out your copyright notice in the Description page of Project Settings.


#include "Targets/HostageTarget.h"

AHostageTarget::AHostageTarget()
{
}

void AHostageTarget::BeginPlay()
{
	Super::BeginPlay();
}

void AHostageTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHostageTarget::Hit(FString areaHit)
{
	Super::Hit(areaHit);

	if (IsActive)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("Hostage Shot!")));
		GameManagerRef->RemoveScore(GameManagerRef->BodyShotScore);

		IsActive = false;
	}
}

void AHostageTarget::FlipUp()
{
	Super::FlipUp();
}

void AHostageTarget::FlipDown()
{
	Super::FlipDown();
}
