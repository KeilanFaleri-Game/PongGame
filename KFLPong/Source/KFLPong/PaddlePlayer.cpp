// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddlePlayer.h"
#include "PaperSpriteComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
APaddlePlayer::APaddlePlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    bc = CreateDefaultSubobject<UBoxComponent>("bc");
    SetRootComponent(bc);

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

    MovementUp = 0;
}

// Called when the game starts or when spawned
void APaddlePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaddlePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (MovementUp != 0)
    {
        FVector NewLocation = GetActorLocation() + (GetActorUpVector() * MovementUp);
        SetActorLocation(NewLocation);
        
    }
}

// Called to bind functionality to input
void APaddlePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("MoveUp", this, &APaddlePlayer::MoveUp);
}

void APaddlePlayer::MoveUp(float value)
{
    MovementUp = value;
}