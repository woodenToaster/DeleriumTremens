// Fill out your copyright notice in the Description page of Project Settings.

#include "DeleriumTremensGameModeBase.h"


AMatch3GameMode::AMatch3GameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass =  APawn::StaticClass();
	PlayerControllerClass = ADTPlayerController::StaticClass();
}

void AMatch3GameMode::BeginPlay()
{
	Super::BeginPlay();
	bGameWillBeWon = false;
}
