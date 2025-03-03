// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/ScoreCardWidget.h"
#include "HUD/FPSGameHud.h"
#include "Managers/GameManager.h"
#include "GameMode/FPSPlinkerGameModeBase.h"

void UScoreCardWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (MenuButton)
		MenuButton->OnClicked.AddDynamic(this, &UScoreCardWidget::OnMenuClicked);
	if (QuitButton)
		QuitButton->OnClicked.AddDynamic(this, &UScoreCardWidget::OnQuitClicked);

	PlayerTime = Cast<AFPSPlinkerGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()))->GetCurrentTime();
	PlayerScore = Cast<AGameManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AGameManager::StaticClass()))->Score;
	MaxGameScore = Cast<AGameManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AGameManager::StaticClass()))->MaxScore;

	LoadScore();
	CheckScores();

	SetUpTexts();
}

void UScoreCardWidget::OnMenuClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "MainMenu", false);
}

void UScoreCardWidget::OnQuitClicked()
{
	AFPSGameHud* FPSHUD = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD<AFPSGameHud>();
	FPSHUD->QuitGame();
}

void UScoreCardWidget::SaveScore()
{
	IsPlayerScoreHigher = true;
	if (UPlayerSaveLoad* SaveGameInstance = Cast<UPlayerSaveLoad>(UGameplayStatics::CreateSaveGameObject(UPlayerSaveLoad::StaticClass())))
	{
		// Set data on the savegame object.
		SaveGameInstance->BestScore = PlayerScore;
		SaveGameInstance->BestTime = PlayerTime;

		// Save the data immediately.
		if (UGameplayStatics::SaveGameToSlot(SaveGameInstance, SaveGameInstance->SaveSlotName, SaveGameInstance->UserIndex))
		{
			UE_LOG(LogTemp, Warning, TEXT("Saved New Highscore"));
		}
	}
}

void UScoreCardWidget::LoadScore()
{
	if (UPlayerSaveLoad* LoadedGame = Cast<UPlayerSaveLoad>(UGameplayStatics::LoadGameFromSlot("PlayerSaveSlot", 0)))
	{
		// The operation was successful, so LoadedGame now contains the data we saved earlier.
		UE_LOG(LogTemp, Warning, TEXT("LOADED Saved Score"));

		PreviousScore = LoadedGame->BestScore;
		PreviousTime = LoadedGame->BestTime;
	}
	else
	{
		PreviousScore = 0;
		PreviousTime = 0;
	}
}

void UScoreCardWidget::CheckScores()
{
	if (PlayerScore > PreviousScore)
		SaveScore();
	else if (PlayerScore == PreviousScore)
		if (PlayerTime < PreviousTime)
			SaveScore();
}

FString UScoreCardWidget::SetUpTime(int TimeAmount)
{
	int MiliSeconds = TimeAmount % 100;
	int Seconds = (TimeAmount / 100) % 100;
	int Minutes = TimeAmount / 10000;

	FString MiliSecString;
	FString SecondsString;
	FString MinutesString;

	if (MiliSeconds < 10)
		MiliSecString = "0" + FString::FromInt(MiliSeconds);
	else
		MiliSecString = FString::FromInt(MiliSeconds);

	if (Seconds < 10)
		SecondsString = "0" + FString::FromInt(Seconds);
	else
		SecondsString = FString::FromInt(Seconds);

	if (Minutes < 10)
		MinutesString = "0" + FString::FromInt(Minutes);
	else
		MinutesString = FString::FromInt(Minutes);
	
	return MinutesString + ":" + SecondsString + ":" + MiliSecString;
}

void UScoreCardWidget::SetUpTexts()
{
	PreviousBestScoreText->SetText(FText::FromString(FString::FromInt(PreviousScore) + "/" + FString::FromInt(MaxGameScore) + "\n" + SetUpTime(PreviousTime)));
	PlayerScoreText->SetText(FText::FromString(FString::FromInt(PlayerScore) + "/" + FString::FromInt(MaxGameScore) + "\n" + SetUpTime(PlayerTime)));

	if (IsPlayerScoreHigher)
		BestScoreText->SetText(FText::FromString(FString::FromInt(PlayerScore) + "/" + FString::FromInt(MaxGameScore) + "\n" + SetUpTime(PlayerTime)));
	else
		BestScoreText->SetText(FText::FromString(FString::FromInt(PreviousScore) + "/" + FString::FromInt(MaxGameScore) + "\n" + SetUpTime(PreviousTime)));
}




