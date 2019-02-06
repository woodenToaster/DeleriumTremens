// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DTGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DELERIUMTREMENS_API UDTGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:

	// Called by the game at startup.
	void Init() override;

	// Called by the game as it shuts down.
	void Shutdown() override;

	// Called when the application has just entered the foreground.
	UFUNCTION(BlueprintImplementableEvent, Category = "Online")
    void OnEnteringForeground();

	// Called when the application is about to enter the background.
	UFUNCTION(BlueprintImplementableEvent, Category = "Online")
    void OnEnteringBackground();

	// Internal function to bind to viewport resizing delegate
	void OnViewportResize_Internal(FViewport* Viewport, uint32 ID);

	// Blueprint event to use to respond to viewport resizing, since FViewport* is not a valid Blueprint pin type
	UFUNCTION(BlueprintImplementableEvent, Category = "UI")
    void OnViewportResize();

private:
	FDelegateHandle EnteringForegroundHandle;
	FDelegateHandle EnteringBackgroundHandle;
	FDelegateHandle ViewportHandle;
};
