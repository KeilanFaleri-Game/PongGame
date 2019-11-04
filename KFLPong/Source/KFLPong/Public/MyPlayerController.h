// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class KFLPONG_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
public:

    virtual void OnPossess(APawn* aPawn) override;
    virtual void OnUnPossess() override;

protected:
    virtual void SetupInputComponent() override;

    void MoveUp(float value);

    class AMyPlayerState* MyPlayerState;
    class AMyFirstPawn* MyPawn;
	
};
