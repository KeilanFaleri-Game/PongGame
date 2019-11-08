// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGoal.h"
#include "Components/BoxComponent.h"
#include "PaperSpriteComponent.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
APlayerGoal::APlayerGoal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    BoxComponent = CreateDefaultSubobject<UBoxComponent>("Box Component");
    RootComponent = BoxComponent;
    BoxComponent->SetCollisionProfileName("BlockAll");
    BoxComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);

    ActorSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Actor Visual");
    ActorSpriteComponent->SetupAttachment(RootComponent);
    ActorSpriteComponent->ComponentTags.Add("PlayerGoal");
}

// Called when the game starts or when spawned
void APlayerGoal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

