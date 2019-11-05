// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "PaperSpriteComponent.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    SphereCollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereCollisionComponent");
    SphereCollisionComponent->SetupAttachment(RootComponent);
    SphereCollisionComponent->SetSphereRadius(24.0f);
    SphereCollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    SphereCollisionComponent->SetCollisionProfileName("BlockAll");
    SphereCollisionComponent->SetGenerateOverlapEvents(true);
    SphereCollisionComponent->SetSimulatePhysics(true);
    SphereCollisionComponent->SetConstraintMode(EDOFMode::SixDOF);

	PrimaryActorTick.bCanEverTick = true;
    ballSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Pawn Visual");

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

