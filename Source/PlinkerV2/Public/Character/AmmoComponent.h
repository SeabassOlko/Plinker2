// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AmmoComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PLINKERV2_API UAmmoComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAmmoComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category = "Ammo Stats")
	int MaxAmmo;

	UPROPERTY(EditAnywhere, Category = "Ammo Stats")
	int CurrentAmmo;

	UPROPERTY(EditAnywhere, Category = "Ammo Stats")
	float ReloadTime;

	float CurrentTime = 0;

	UPROPERTY()
	bool IsReloading = false;

	UFUNCTION()
	bool UseAmmo();

	UFUNCTION()
	void ReloadGun();
};
