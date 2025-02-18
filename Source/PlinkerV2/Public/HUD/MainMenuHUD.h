// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h"
#include "GUI/Slate/SSMenuWidget.h"
#include "MainMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class PLINKERV2_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;

	UWorld* currentWorld;

	TSharedPtr<class SSMenuWidget> MainMenuWidget;
	TSharedPtr<class SWidget> SlateWidgetContainer;
	
};
