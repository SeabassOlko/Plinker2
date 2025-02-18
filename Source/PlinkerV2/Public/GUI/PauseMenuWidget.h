// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "PauseMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class PLINKERV2_API UPauseMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TitleText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ResumeText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* MenuText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* QuitText;

	UPROPERTY(meta = (BindWidget))
	UButton* ResumeButton;

	UPROPERTY(meta = (BindWidget))
	UButton* MenuButton;

	UPROPERTY(meta = (BindWidget))
	UButton* QuitButton;

	UFUNCTION()
	void OnResumeClicked();

	UFUNCTION()
	void OnMenuClicked();

	UFUNCTION()
	void OnQuitClicked();

	
};
