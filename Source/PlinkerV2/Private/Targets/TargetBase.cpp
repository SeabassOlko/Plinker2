// Fill out your copyright notice in the Description page of Project Settings.


#include "Targets/TargetBase.h"

// Sets default values
ATargetBase::ATargetBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!RotationPoint) {
		RotationPoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RotationPoint"));
		RootComponent = RotationPoint;
	}

	if (!BodyCube) {
		BodyCube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyCube"));
		BodyCube->SetupAttachment(RotationPoint);
	}

	if (!HeadCube) {
		HeadCube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HeadCube"));
		HeadCube->SetupAttachment(BodyCube);
	}
}

// Called when the game starts or when spawned
void ATargetBase::BeginPlay()
{
	Super::BeginPlay();
	SetActorRotation(FRotator(0, 0, -90), ETeleportType::None);
	GameManagerRef = Cast<AGameManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AGameManager::StaticClass()));
}

// Called every frame
void ATargetBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsLowering)
	{
		CurrentFlipTime += DeltaTime;
		if (CurrentFlipTime >= FlipTime)
		{
			CurrentFlipTime = FlipTime;
			IsLowering = false;
		}
		float LerpAngle = FMath::Lerp(StandingAngle, LoweredAngle, CurrentFlipTime/FlipTime);
		SetActorRotation(FRotator(0, 0, LerpAngle), ETeleportType::None);
	}
	else if (IsRaising)
	{
		CurrentFlipTime += DeltaTime;
		if (CurrentFlipTime >= FlipTime)
		{
			CurrentFlipTime = FlipTime;
			IsRaising = false;
		}
		float LerpAngle = FMath::Lerp(LoweredAngle, StandingAngle, CurrentFlipTime/FlipTime);
		SetActorRotation(FRotator(0, 0, LerpAngle), ETeleportType::None);
	}

}

void ATargetBase::Hit(FString areaHit)
{
	if (IsActive)
	{
		FlipDown();
	}
}

void ATargetBase::FlipUp()
{
	CurrentFlipTime = 0;
	IsRaising = true;
	IsActive = true;
}

void ATargetBase::FlipDown()
{
	CurrentFlipTime = 0;
	IsLowering = true;
}

