// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode/FPSPlinkerGameModeBase.h"

void AFPSPlinkerGameModeBase::StartPlay()
{
	Super::StartPlay();

	// 1. To print to screen
	check(GEngine != nullptr);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is FPSGameMode!"));

	TArray<AActor*> FoundActors = TArray<AActor*>();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyTarget::StaticClass(), FoundActors);

	MaxScore = FoundActors.Num();
}

// Called every frame
void AFPSPlinkerGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FirstTick)
	{
		UFPSUserWidget* PlayerHud = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD<AFPSGameHud>()->GameWidgetContainer;

		if (PlayerHud != NULL)
			PlayerHud->SetScoreText(Score, MaxScore);

		FirstTick = false;
	}

	if (TimerRunning)
	{
		CurrentTime += DeltaTime;
		UpdateTime();
	}
}

void AFPSPlinkerGameModeBase::StartTimer()
{
	TimerRunning = true;
}

void AFPSPlinkerGameModeBase::StopTimer()
{
	TimerRunning = false;
}

void AFPSPlinkerGameModeBase::UpdateTime()
{
	UFPSUserWidget* PlayerHud = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD<AFPSGameHud>()->GameWidgetContainer;

	if (PlayerHud != NULL)
		PlayerHud->SetTimeText(int(CurrentTime));
}

void AFPSPlinkerGameModeBase::AddScore(int amount)
{
}

void AFPSPlinkerGameModeBase::RemoveScore(int amount)
{
}
