// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "BallSpawner.h"
#include "EngineUtils.h"
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
    SphereCollisionComponent->OnComponentHit.AddDynamic(this, &ABall::OnHit);

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

}

UProjectileMovementComponent* ABall::GetBallMovement()
{
    return BallProjectile;
}

void ABall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, "POOP " + OtherComp->GetName());

    if (OtherComp->ComponentHasTag("EnemyGoal"))
    {
        Destroy();

        for (TActorIterator<ABallSpawner> ActorItr(GetWorld()); ActorItr; ++ActorItr)
        {
            ABallSpawner* tempBall = Cast<ABallSpawner>(*ActorItr);

            if (tempBall)
            {
                tempBall->ResetSpawnCount();
            }
        }
    }
    else if (OtherComp->ComponentHasTag("PlayerGoal"))
    {
        Destroy();

        for (TActorIterator<ABallSpawner> ActorItr(GetWorld()); ActorItr; ++ActorItr)
        {
            ABallSpawner* tempBall = Cast<ABallSpawner>(*ActorItr);

            if (tempBall)
            {
                tempBall->ResetSpawnCount();
            }
        }
    }
    
}
