// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "PaperSpriteComponent.h"

// Sets default values
ABall::ABall()
{
    PrimaryActorTick.bCanEverTick = true;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

    SphereCollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereCollisionComponent");
    RootComponent = SphereCollisionComponent;
    SphereCollisionComponent->SetSphereRadius(24.0f);
    SphereCollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    SphereCollisionComponent->SetCollisionProfileName("BlockAll");
    SphereCollisionComponent->SetGenerateOverlapEvents(true);
    SphereCollisionComponent->GetBodyInstance()->bLockRotation = true;
    SphereCollisionComponent->GetBodyInstance()->bLockYTranslation = true;

    ballSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Pawn Visual");
    ballSpriteComponent->GetBodyInstance()->bLockRotation = true;
    ballSpriteComponent->GetBodyInstance()->bLockYTranslation = true;
    ballSpriteComponent->SetupAttachment(RootComponent);

    BallProjectile = CreateDefaultSubobject<UProjectileMovementComponent>("PhysicsComponent");
    BallProjectile->bShouldBounce = true;
    BallProjectile->ProjectileGravityScale = 0.0f;
    BallProjectile->InitialSpeed = 500.0f;
    BallProjectile->Velocity = FVector (1.0f, 0.0f, 1.0f);
    //BallProjectile->bRotationFollowsVelocity = true;
    BallProjectile->Friction = 0.0f;
    BallProjectile->MaxSpeed = 2000.0f;
    BallProjectile->Bounciness = 1.0f;

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (GetActorLocation().X > 700)
    {
        SetActorLocation(FVector(0.0f, 50.0f, 0.0f));
    }
    else if (GetActorLocation().X < -700)
    {
        SetActorLocation(FVector(0.0f, 50.0f, 0.0f));
    }

}
