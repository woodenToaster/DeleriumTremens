// Fill out your copyright notice in the Description page of Project Settings.

#include "DeleriumTremensGameModeBase.h"
#include "DTPlayerController.h"
#include "Kismet/GameplayStatics.h"


ADeleriumTremensGameModeBase::ADeleriumTremensGameModeBase(const FObjectInitializer& ObjectInitializer) :
    Super(ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass =  APawn::StaticClass();
	PlayerControllerClass = ADTPlayerController::StaticClass();
}

void ADeleriumTremensGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	// bGameWillBeWon = false;
    ChangeMenuWidget(StartingWidgetClass);
}

void ADeleriumTremensGameModeBase::GameOver()
{
    
}

void ADeleriumTremensGameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
    if (CurrentWidget)
    {
        CurrentWidget->RemoveFromViewport();
        CurrentWidget = nullptr;
    }
    if (NewWidgetClass)
    {
        if (ADTPlayerController *pc = Cast<ADTPlayerController>(
                UGameplayStatics::GetPlayerController(GetWorld(), 0)))
        {
            CurrentWidget = CreateWidget<UUserWidget>(pc, NewWidgetClass);
            if (CurrentWidget)
            {
                CurrentWidget->AddToViewport();
            }
        }
    }
}
