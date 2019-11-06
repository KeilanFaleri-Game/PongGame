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
    SphereCollisionComponent->SetEnableGravity(false);
    SphereCollisionComponent->SetGenerateOverlapEvents(true);

    ballSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Pawn Visual");
    ballSpriteComponent->SetupAttachment(RootComponent);

    BallProjectile = CreateDefaultSubobject<UProjectileMovementComponent>("PhysicsComponent");
    BallProjectile->bShouldBounce = true;
    BallProjectile->InitialSpeed = 50.0f;
    BallProjectile->MaxSpeed = 300.0f;
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

}

