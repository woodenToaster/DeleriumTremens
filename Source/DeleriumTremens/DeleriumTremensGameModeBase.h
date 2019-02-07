// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DeleriumTremensGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DELERIUMTREMENS_API ADeleriumTremensGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

    ADeleriumTremensGameModeBase(const FObjectInitializer &ObjectInitializer);

    virtual void BeginPlay() override;

	/** Function to call when the game ends. */
	UFUNCTION(BlueprintCallable, Category = "Game")
    void GameOver();
};
