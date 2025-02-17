// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

	UPROPERTY(VisibleAnywhere)
	UStaticMesh* BodyCube;

	UPROPERTY(VisibleAnywhere)
	UStaticMesh* HeadCube;

	UFUNCTION()
	void Hit();

};
