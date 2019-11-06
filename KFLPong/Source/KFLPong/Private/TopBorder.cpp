// Fill out your copyright notice in the Description page of Project Settings.


#include "TopBorder.h"
#include "Components/BoxComponent.h"
#include "Components/PrimitiveComponent.h"
#include "PaperSpriteComponent.h"

// Sets default values
ATopBorder::ATopBorder()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    BoxComponent = CreateDefaultSubobject<UBoxComponent>("Box Component");
    RootComponent = BoxComponent;
    BoxComponent->SetCollisionProfileName("BlockAll");
    BoxComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
    

    ActorSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Actor Visual");
    ActorSpriteComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ATopBorder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATopBorder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

