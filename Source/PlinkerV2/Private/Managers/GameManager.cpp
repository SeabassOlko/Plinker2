// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/GameManager.h"

// Sets default values
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundActors = TArray<AActor*>();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyTarget::StaticClass(), FoundActors);

	MaxScore = FoundActors.Num();
	
}

// Called every frame
void AGameManager::Tick(float DeltaTime)
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

void AGameManager::StartTimer()
{
	TimerRunning = true;
}

void AGameManager::StopTimer()
{
	TimerRunning = false;
}

void AGameManager::UpdateTime()
{
	UFPSUserWidget* PlayerHud = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD<AFPSGameHud>()->GameWidgetContainer;

	if (PlayerHud != NULL)
		PlayerHud->SetTimeText(int(CurrentTime));
}

void AGameManager::AddScore(int amount)
{
}

void AGameManager::RemoveScore(int amount)
{
}

