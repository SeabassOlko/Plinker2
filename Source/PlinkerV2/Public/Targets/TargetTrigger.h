// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Targets/TargetBase.h"
#include "Kismet/GameplayStatics.h"
#include "Character/PlayerCharacter.h"
#include "TargetTrigger.generated.h"

UCLASS()
class PLINKERV2_API ATargetTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleDefaultsOnly)
	UBoxComponent* CollisionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targets")
	TArray<ATargetBase*> TargetsToSpringUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Targets")
	TArray<ATargetBase*> TargetsToLower;

	UPROPERTY(EditAnywhere)
	bool IsActive = true;

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnTrigger();

};
