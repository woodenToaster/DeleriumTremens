// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"

#include "DeleriumTremensGameModeBase.generated.h"

UCLASS()
class DELERIUMTREMENS_API ADeleriumTremensGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

    ADeleriumTremensGameModeBase(const FObjectInitializer &ObjectInitializer);

    // Called when the game starts */
    virtual void BeginPlay() override;

	// Call when the game ends. */
	UFUNCTION(BlueprintCallable, Category = "Game")
    void GameOver();

	// Remove the current menu widget and create a new one from the specified class, if provided. */
    UFUNCTION(BlueprintCallable, Category = "Game")
    void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:
	// The widget class we will use as our menu when the game starts.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game")
    TSubclassOf<UUserWidget> StartingWidgetClass;

	// The widget instance that we are using as our menu.
	UPROPERTY()
    UUserWidget* CurrentWidget;
};
