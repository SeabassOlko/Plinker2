// Fill out your copyright notice in the Description page of Project Settings.


#include "Timer/TimerTrigger.h"

// Sets default values
ATimerTrigger::ATimerTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!CollisionComponent)
	{
		CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
		CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ATimerTrigger::BeginOverlap);
		CollisionComponent->InitBoxExtent(FVector(50.0f));
		RootComponent = CollisionComponent;
	}
}

// Called when the game starts or when spawned
void ATimerTrigger::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATimerTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATimerTrigger::BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (APlayerCharacter* player = Cast<APlayerCharacter>(OtherActor))
	{
		if (!IsTriggered)
			OnTrigger();
	}
}

void ATimerTrigger::OnTrigger()
{
	IsTriggered = true;
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("Timer On Trigger Called")));
	AFPSPlinkerGameModeBase* GameMode = Cast<AFPSPlinkerGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (IsStart)
		GameMode->StartTimer();
	else
	{
		GameMode->StopTimer();
		AFPSGameHud* GameHud = Cast<AFPSGameHud>(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD());
		GameHud->ShowScoreMenu(GameHud->ScoreCardWidget);
	}
}

