// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/FPSPlinkerGameModeBase.h"


AFPSPlinkerGameModeBase::AFPSPlinkerGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFPSPlinkerGameModeBase::StartPlay()
{
	Super::StartPlay();

	// 1. To print to screen
	check(GEngine != nullptr);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode!"));
}

// Called every frame
void AFPSPlinkerGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TimerRunning)
	{
		CurrentTime += DeltaTime;
		UpdateTime();
	}
}

void AFPSPlinkerGameModeBase::StartTimer()
{
	AFPSGameHud* GameHud = Cast<AFPSGameHud>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
	PlayerHud = GameHud->GameWidgetContainer;
	TimerRunning = true;
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("Timer Started")));
}

void AFPSPlinkerGameModeBase::StopTimer()
{
	TimerRunning = false;
}

void AFPSPlinkerGameModeBase::UpdateTime()
{
	if (PlayerHud)
	{
		PlayerHud->SetTimeText(int(CurrentTime * 100));
	}
}

int AFPSPlinkerGameModeBase::GetCurrentTime()
{
	return CurrentTime * 100;
}
