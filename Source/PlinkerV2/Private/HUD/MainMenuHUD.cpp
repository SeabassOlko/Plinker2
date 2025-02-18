// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/MainMenuHUD.h"
#include "Widgets/SWeakWidget.h"

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	currentWorld = GetWorld();

	MainMenuWidget = SNew(SSMenuWidget).OwningHUD(this);
	GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(SlateWidgetContainer, SWeakWidget).PossiblyNullContent(MainMenuWidget.ToSharedRef()));

	PlayerOwner->bShowMouseCursor = true; 
	PlayerOwner->SetInputMode(FInputModeUIOnly());
}
