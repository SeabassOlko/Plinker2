// Fill out your copyright notice in the Description page of Project Settings.


#include "Targets/TargetTrigger.h"

// Sets default values
ATargetTrigger::ATargetTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if(!CollisionComponent) 
	{
		CollisionComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
		CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ATargetTrigger::BeginOverlap);
		CollisionComponent->InitBoxExtent(FVector(50.0f));
		RootComponent = CollisionComponent;
	}

}

// Called when the game starts or when spawned
void ATargetTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATargetTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATargetTrigger::BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (APlayerCharacter* player = Cast<APlayerCharacter>(OtherActor))
	{
		if (IsActive)
			OnTrigger();
	}
}

void ATargetTrigger::OnTrigger()
{
	if (TargetsToLower.Num() != 0)
	{
		for (ATargetBase* target : TargetsToLower)
		{
			if (target->IsActive)
				target->FlipDown();
		}
	}

	if (TargetsToSpringUp.Num() != 0)
	{
		for (ATargetBase* target : TargetsToSpringUp)
		{
			target->FlipUp();
		}
	}
	IsActive = false;
}

