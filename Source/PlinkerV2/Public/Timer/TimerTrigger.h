// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "GameMode/FPSPlinkerGameModeBase.h"
#include "Character/PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "TimerTrigger.generated.h"

UCLASS()
class PLINKERV2_API ATimerTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimerTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleDefaultsOnly)
	UBoxComponent* CollisionComponent;

	UPROPERTY(EditAnywhere)
	bool IsTriggered = false;

	UPROPERTY(EditAnywhere)
	bool IsStart = true;

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnTrigger();

};
