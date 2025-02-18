// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/PauseMenuWidget.h"
#include "HUD/FPSGameHud.h"
#include "Kismet/GameplayStatics.h"

void UPauseMenuWidget::NativeConstruct()
{
	Super::NativeConstruct(); 
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, FString::Printf(TEXT("Constructor called")));

	if (ResumeButton)
		ResumeButton->OnClicked.AddDynamic(this, &UPauseMenuWidget::OnResumeClicked);
	if (MenuButton)
		MenuButton->OnClicked.AddDynamic(this, &UPauseMenuWidget::OnMenuClicked);
	if (QuitButton)
		QuitButton->OnClicked.AddDynamic(this, &UPauseMenuWidget::OnQuitClicked);

	
}

void UPauseMenuWidget::OnResumeClicked()
{
	AFPSGameHud* FPSHUD = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD<AFPSGameHud>();
	FPSHUD->RemovePauseMenu();
}

void UPauseMenuWidget::OnMenuClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "MainMenu", false);
}

void UPauseMenuWidget::OnQuitClicked()
{
	AFPSGameHud* FPSHUD = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD<AFPSGameHud>();
	FPSHUD->QuitGame();
}
