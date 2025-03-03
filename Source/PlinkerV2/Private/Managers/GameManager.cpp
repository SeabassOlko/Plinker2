// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/GameManager.h"
#include "Targets/EnemyTarget.h"

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
	TArray<AActor*> FoundTargets;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyTarget::StaticClass(), FoundTargets);
	MaxScore = FoundTargets.Num() * HeadShotScore;
}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FirstTick)
	{
		PlayerHud = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD<AFPSGameHud>()->GameWidgetContainer;

		if (PlayerHud != NULL)
			PlayerHud->SetScoreText(Score, MaxScore);

		FirstTick = false;
	}
}

void AGameManager::AddScore(int amount)
{
	Score += amount;

	PlayerHud->SetScoreText(Score, MaxScore);
}

void AGameManager::RemoveScore(int amount)
{
	Score -= amount;

	PlayerHud->SetScoreText(Score, MaxScore);
}

