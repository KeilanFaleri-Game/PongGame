// Fill out your copyright notice in the Description page of Project Settings.


#include "Background.h"
#include "PaperSpriteComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PaddlePlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ABackground::ABackground()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    
    PlayerSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Pawn Visual");
    PlayerSpriteComponent->SetupAttachment(RootComponent);

    SpringArmComponent =
        CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
    SpringArmComponent->SetupAttachment(RootComponent);
    SpringArmComponent->bDoCollisionTest = false;
    SpringArmComponent->bInheritPitch = false;
    SpringArmComponent->bInheritYaw = false;
    SpringArmComponent->bInheritRoll = false;
    SpringArmComponent->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

    FollowCameraComponent = CreateDefaultSubobject<UCameraComponent>("Player Follow Camera");
    FollowCameraComponent->SetProjectionMode(ECameraProjectionMode::Orthographic);
    FollowCameraComponent->SetOrthoWidth(2500.0f);
    FollowCameraComponent->SetupAttachment(SpringArmComponent);

}

// Called when the game starts or when spawned
void ABackground::BeginPlay()
{
	Super::BeginPlay();


    APlayerController* pc = GetWorld()->GetFirstPlayerController();
    if (pc)
        pc->SetViewTarget(this);
}

// Called every frame
void ABackground::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
