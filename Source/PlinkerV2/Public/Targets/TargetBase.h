// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Managers/GameManager.h"
#include "TargetBase.generated.h"

UCLASS()
class PLINKERV2_API ATargetBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* RotationPoint;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* BodyCube;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* HeadCube;

	UPROPERTY(EditAnywhere)
	AGameManager* GameManagerRef;

	UPROPERTY(EditAnywhere)
	bool IsActive = false;

	UPROPERTY(EditAnywhere)
	bool IsRaising = false;

	UPROPERTY(EditAnywhere)
	bool IsLowering = false;

	UPROPERTY(EditAnywhere)
	float FlipTime = 0.3f;

	UPROPERTY(EditAnywhere)
	float CurrentFlipTime = 0;

	float LoweredAngle = -90.0f, StandingAngle = 0.0f;

	UFUNCTION()
	virtual void Hit(FString areaHit);

	UFUNCTION()
	virtual void FlipUp();

	UFUNCTION()
	virtual void FlipDown();

};
