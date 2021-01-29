// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class THEROLLINGSPHERE_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
public:

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UButton* PlayButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UButton* QuitButton;
	/*
	UFUNCTION()
		void Play();
	UFUNCTION()
		void Quit();
	*/
};
