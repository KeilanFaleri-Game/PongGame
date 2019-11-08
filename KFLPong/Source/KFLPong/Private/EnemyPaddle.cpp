// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyPaddle.h"
#include "Ball.h"
#include "PaperSpriteComponent.h"
#include "EngineUtils.h"
#include "Components/BoxComponent.h"

// Sets default values
AEnemyPaddle::AEnemyPaddle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    BoxComponent = CreateDefaultSubobject<UBoxComponent>("bc");
    RootComponent = BoxComponent;
    BoxComponent->SetCollisionProfileName("BlockAll");
    BoxComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    BoxComponent->GetBodyInstance()->bLockXTranslation = true;

    AISpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Pawn Visual");
    AISpriteComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEnemyPaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    for (TActorIterator<ABall> ActorItr(GetWorld()); ActorItr; ++ActorItr)
    {
        ABall* tempBall = Cast<ABall>(*ActorItr);

        if (tempBall)
        {
            if (GetActorLocation().Z >= 265.0f)
            {
                float NewLocation = GetActorLocation().Z - 1.0f;
                SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, NewLocation));
            }
            else if (GetActorLocation().Z <= -265.0f)
            {
                float NewLocation = GetActorLocation().Z + 1.0f;
                SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, NewLocation));
            }
            else
            {
                //DECLARE a variable called targetLocation of type FVector and assign it to the return value of FMath::VInterpConstantTo(..) passing in --> GetActorLocation(), Target->GetActorLocation(), DeltaTime, 600.0f
                FVector targetLocation = FMath::VInterpConstantTo(GetActorLocation(), tempBall->GetActorLocation(), DeltaTime, 600.0f);
                //CALL  SetActorLocation(..) passing in targetLocation
                SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, targetLocation.Z));
            }
        }
        else
        {
            SetActorLocation(FVector(560.0f , 50.0f, 0.0f));
        }
    }

}

