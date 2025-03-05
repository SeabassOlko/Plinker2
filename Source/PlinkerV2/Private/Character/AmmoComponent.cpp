// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AmmoComponent.h"

// Sets default values for this component's properties
UAmmoComponent::UAmmoComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAmmoComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentAmmo = MaxAmmo;
}


// Called every frame
void UAmmoComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsReloading)
	{
		CurrentTime += DeltaTime;

		if (CurrentTime >= ReloadTime)
		{
			IsReloading = false;
			CurrentAmmo = MaxAmmo;
			CurrentTime = 0.0f;
		}
	}
}

bool UAmmoComponent::UseAmmo()
{
	if (CurrentAmmo < 1 || IsReloading)
		return false;

	CurrentAmmo--;
	return true;
}

void UAmmoComponent::ReloadGun()
{
	if (!IsReloading)
		IsReloading = true;
}

