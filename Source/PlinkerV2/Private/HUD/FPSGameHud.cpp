// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/FPSGameHud.h"
#include "Widgets/SWeakWidget.h"

void AFPSGameHud::BeginPlay()
{
	Super::BeginPlay();

	ShowGameUI(StartingGameWidget);
}

void AFPSGameHud::DrawHUD()
{
	Super::DrawHUD();

	if (!CrosshairTexture) return;

	FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
	FVector2D CrosshairHalfSize(CrosshairTexture->GetSurfaceWidth() * 0.5f, CrosshairTexture->GetSurfaceHeight() * 0.5f);
	FVector2D CrosshairDrawPosition(Center.X - CrosshairHalfSize.X, Center.Y - CrosshairHalfSize.Y);

	FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTexture->GetResource(), FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;

	Canvas->DrawItem(TileItem);
}

void AFPSGameHud::ShowGameUI(TSubclassOf<UFPSUserWidget> newGameWidget)
{
	PlayerOwner->bShowMouseCursor = false;
	PlayerOwner->SetInputMode(FInputModeGameOnly());

	PlayerOwner->SetPause(false);

	// Spawn a newGameWidget and addtoviewport
	GameWidgetContainer = CreateWidget<UFPSUserWidget>(GetWorld(), newGameWidget);
	GameWidgetContainer->AddToViewport();
}

void AFPSGameHud::ShowPauseMenu(TSubclassOf<UPauseMenuWidget> newGameWidget)
{
	PlayerOwner->bShowMouseCursor = true;
	PlayerOwner->SetInputMode(FInputModeUIOnly());

	PlayerOwner->SetPause(true);

	// Spawn a newGameWidget and addtoviewport
	PauseWidgetContainer = CreateWidget<UPauseMenuWidget>(GetWorld(), newGameWidget);
	PauseWidgetContainer->AddToViewport();
}

void AFPSGameHud::ShowScoreMenu(TSubclassOf<UScoreCardWidget> newGameWidget)
{
	PlayerOwner->bShowMouseCursor = true;
	PlayerOwner->SetInputMode(FInputModeUIOnly());

	PlayerOwner->SetPause(true);

	// Spawn a newGameWidget and addtoviewport
	ScoreCardWidgetContainer = CreateWidget<UScoreCardWidget>(GetWorld(), newGameWidget);
	ScoreCardWidgetContainer->AddToViewport();
}

void AFPSGameHud::RemovePauseMenu()
{
	// Check if a game menu has spawned RemoveFromParent
	if (PauseWidgetContainer)
	{
		PauseWidgetContainer->RemoveFromParent();
		PauseWidgetContainer = nullptr;
	}

	PlayerOwner->bShowMouseCursor = false;
	PlayerOwner->SetInputMode(FInputModeGameOnly());

	PlayerOwner->SetPause(false);
}

void AFPSGameHud::QuitGame()
{
	PlayerOwner->ConsoleCommand("quit");
}
