// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyGoal.h"
#include "Components/BoxComponent.h"
#include "Components/PrimitiveComponent.h"
#include "PaperSpriteComponent.h"

// Sets default values
AEnemyGoal::AEnemyGoal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    ActorSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Actor Visual");
    RootComponent = ActorSpriteComponent;
    BoxComponent = CreateDefaultSubobject<UBoxComponent>("Box Component");

    BoxComponent->SetupAttachment(ActorSpriteComponent);

}

// Called when the game starts or when spawned
void AEnemyGoal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyGoal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

