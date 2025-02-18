// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/MainMenuHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class PLINKERV2_API SSMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSMenuWidget)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, OwningHUD)
	SLATE_END_ARGS()

	TWeakObjectPtr<class AMainMenuHUD> OwningHUD;

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	FReply OnPlayClicked() const;

	FReply OnSettingsClicked() const;

	FReply OnQuitClicked() const;
};
