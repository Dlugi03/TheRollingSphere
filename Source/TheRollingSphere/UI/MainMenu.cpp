// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Blueprint/WidgetTree.h"
#include "Components/Button.h"
#include "Components/PanelWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();
	/*
	UPanelWidget* RootWidget = WidgetTree->ConstructWidget<UPanelWidget>(UPanelWidget::StaticClass(), TEXT("RootWidget"));
	WidgetTree->RootWidget = RootWidget;

	PlayButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("PlayButton"));
	QuitButton = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("QuitButton"));

	RootWidget->AddChild(PlayButton);
	RootWidget->AddChild(QuitButton);

	PlayButton->OnClicked.AddDynamic(this, &UMainMenu::Play);
	QuitButton->OnClicked.AddDynamic(this, &UMainMenu::Quit);
}

void UMainMenu::Play()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("Level_1"));
}

void UMainMenu::Quit()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, true);
}
*/
}