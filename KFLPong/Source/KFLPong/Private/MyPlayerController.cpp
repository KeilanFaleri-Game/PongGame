// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "PaddlePlayer.h"

void AMyPlayerController::OnPossess(APawn* aPawn)
{
    Super::OnPossess(aPawn);
    GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow,
        "AMyPlayerController::Possess: - " + aPawn->GetName());
}

void AMyPlayerController::OnUnPossess()
{
    APawn* posessedPawn = Cast<APawn>(GetOwner());
    if (posessedPawn)
        GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow,
            "AMyPlayerController::UnPossess: - " + GetOwner()->GetName());

    Super::OnUnPossess();
}

void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    //MyPlayerState = Cast<AMyPlayerState>(PlayerState);
    //if (MyPlayerState)
    //{
    //    UE_LOG(LogTemp, Warning, TEXT("Found class %s"),
    //        TEXT("AMyPlayerController::BeginPlay: MyPlayerState Set"));
    //}
    if (InputComponent != nullptr)
    {
        InputComponent->BindAxis("MoveUp", this,
&AMyPlayerController::MoveUp);
    }
}

void AMyPlayerController::MoveUp(float value)
{
    APaddlePlayer* pawn = Cast<APaddlePlayer>(GetPawn());
    if (pawn)
        pawn->MoveUp(value);
}

