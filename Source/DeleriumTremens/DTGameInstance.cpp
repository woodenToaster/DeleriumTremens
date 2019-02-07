// Fill out your copyright notice in the Description page of Project Settings.

#include "DTGameInstance.h"
#include "Engine.h"

void UDTGameInstance::Init()
{
	EnteringForegroundHandle = FCoreDelegates::ApplicationHasEnteredForegroundDelegate.AddUObject(
        this, &UDTGameInstance::OnEnteringForeground
    );
	EnteringBackgroundHandle = FCoreDelegates::ApplicationWillEnterBackgroundDelegate.AddUObject(
        this, &UDTGameInstance::OnEnteringBackground
    );
	ViewportHandle = FViewport::ViewportResizedEvent.AddUObject(
        this, &UDTGameInstance::OnViewportResize_Internal
    );

    Super::Init();
}

void UDTGameInstance::Shutdown()
{
	FViewport::ViewportResizedEvent.Remove(ViewportHandle);
	Super::Shutdown();
}

void UDTGameInstance::OnViewportResize_Internal(FViewport* Viewport, uint32 ID)
{
    OnViewportResize();
}
