// Fill out your copyright notice in the Description page of Project Settings.


#include "GUI/Slate/SSMenuWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SSMenuWidget::Construct(const FArguments& InArgs)
{
	OwningHUD = InArgs._OwningHUD;

	const FMargin ContentPadding = FMargin(500.0f, 300.0f);
	const FMargin ButtonPadding = FMargin(10.0f);

	FSlateFontInfo TitleTextStyle = FCoreStyle::Get().GetFontStyle("EmbassedText");
	TitleTextStyle.Size = 60.0f;

	FSlateFontInfo ButtonTextStyle = TitleTextStyle;
	ButtonTextStyle.Size = 40.0f;

	const FText TitleText = FText::FromString("Plinker V2");

	const FText PlayText = FText::FromString("Play");
	const FText SettingsText = FText::FromString("Settings");
	const FText QuitText = FText::FromString("Quit");

	ChildSlot
		[
			SNew(SOverlay)
				+ SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					// Background overlay
					SNew(SImage)
					.ColorAndOpacity(FColor::Blue)
				]
				+ SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(ContentPadding)
				[
					// Title Text
					SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						[
							SNew(STextBlock)
							.Font(TitleTextStyle)
							.Text(TitleText)
							.Justification(ETextJustify::Center)
						]
						+ SVerticalBox::Slot()
						.Padding(ButtonPadding)
						[
							// Resume Button
							SNew(SButton)
							.OnClicked(this, &SSMenuWidget::OnPlayClicked)
							[
								SNew(STextBlock)
								.Font(ButtonTextStyle)
								.Text(PlayText)
								.Justification(ETextJustify::Center)
							]
						]
						+ SVerticalBox::Slot()
						.Padding(ButtonPadding)
						[
							// Settings Button
							SNew(SButton)
							.OnClicked(this, &SSMenuWidget::OnSettingsClicked)
							[
								SNew(STextBlock)
								.Font(ButtonTextStyle)
								.Text(SettingsText)
								.Justification(ETextJustify::Center)
							]
						]
						+ SVerticalBox::Slot()
						.Padding(ButtonPadding)
						[
							// Quit Button
							SNew(SButton)
							.OnClicked(this, &SSMenuWidget::OnQuitClicked)
							[
								SNew(STextBlock)
								.Font(ButtonTextStyle)
								.Text(QuitText)
								.Justification(ETextJustify::Center)
							]
						]
				]
		];
}
FReply SSMenuWidget::OnPlayClicked() const
{
	UGameplayStatics::OpenLevel(OwningHUD->currentWorld, "Level1", false);
	return FReply::Handled();
}
FReply SSMenuWidget::OnSettingsClicked() const
{
	UE_LOG(LogTemp, Warning, TEXT("TODO: Spawn Settings if you want"));
	return FReply::Handled();
}
FReply SSMenuWidget::OnQuitClicked() const
{
	if (OwningHUD.IsValid()) {
		if (APlayerController* PC = OwningHUD->PlayerOwner) {
			PC->ConsoleCommand("quit");
		}
	}
	return FReply::Handled();
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
