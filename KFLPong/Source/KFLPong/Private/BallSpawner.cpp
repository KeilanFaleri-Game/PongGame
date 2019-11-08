// Fill out your copyright notice in the Description page of Project Settings.


#include "BallSpawner.h"
#include "Components/ArrowComponent.h"
#include "ConstructorHelpers.h"
#include "TimerManager.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "EngineUtils.h"
#include "ball.h"


// Sets default values
ABallSpawner::ABallSpawner()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    /* arrow component  */
     //CREATE the UArrowComponent by Calling CreateDefaultSubobject<>() and assign the Return of that function to SpawnPointComponent
    SpawnPointComponent = CreateDefaultSubobject<UArrowComponent>
        (TEXT("SpawnPoint"));
    //ATTACH the SpawnPointComponent to the RootComponent by CALLING SetupAttachment(..) on SpawnPointComponent and pass in RootComponent 
    SpawnPointComponent->SetupAttachment(RootComponent);
    //SET the SpawnPointComponent's ArrowSize property to 5.0f
    SpawnPointComponent->ArrowSize = 5.f;
    //CALL SetRelativeRotation(..) on the SpawnPointComponent and pass in FRotator(50.f, 0.f, 0.f)
    SpawnPointComponent->SetRelativeRotation(FRotator(50.f, 0.f, 0.f));
    //CALL SetRelativeLocation(..) on the SpawnPointComponent and pass in FVector(0.f, 100.f, 0.f)
    SpawnPointComponent->SetRelativeLocation(FVector(0.f, 50.f, 0.f));

}

// Called when the game starts or when spawned
void ABallSpawner::BeginPlay()
{
    Super::BeginPlay();

    //CALL Super::BeginPlay()
    //DECLARE a variable called Timer of type FTimerManager& and Assign it to the return value of GetWorldTimerManager()
    FTimerManager& Timer = GetWorldTimerManager();// Returns the TimerManager in this World
    //CALL SetTimer(..) on the Timer variable and pass in -> SpawnTimer, this, &AActorSpawner::SpawnActor, SpawnDelay, true. This Creates and starts the timer with the spawn delay, the last argument (true) tells the timer to loop
    Timer.SetTimer(SpawnTimer, this, &ABallSpawner::SpawnActor, SpawnDelay, true);
    // SpawnTimer can now be reused for any other Timer. This is a way to stop the timer

}

// Called every frame
void ABallSpawner::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    /*for (TActorIterator<ABall> ActorItr(GetWorld()); ActorItr; ++ActorItr)
    {
        ABall* tempBall = Cast<ABall>(*ActorItr);

        if (tempBall)
        {
            if (tempBall->GetActorLocation().X > 700.0f)
            {
                tempBall->Destroy();
                SpawnCount--;
            }
            else if (tempBall->GetActorLocation().X < -700.0f)
            {
                tempBall->Destroy();
                SpawnCount--;
            }
        }
    }*/
}

void ABallSpawner::SpawnActor()
{
    //IF the FallingActorTemplate NOT EQUAL to nullptr
    if (FallingActorTemplate != nullptr)
    {
        //DECLARE a variable called World of type const UWorld* and assign it to the return value of GetWorld()
        UWorld* World = GetWorld();
        //IF World is NOT EQUAL to nullptr
        if (World && SpawnCount < 1)
        {
            //DECLARE a variable called SpawnParams of type FActorSpawnParameters
            FActorSpawnParameters SpawnParams;
            //SET SpawnParams Owner to this
            SpawnParams.Owner = this;
            //SET SpawnParams SpawnCollisionHandlingOverride property to ESpawnActorCollisionHandlingMethod::AlwaysSpawn
            SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

            //DECLARE a variable called SpawnTransform of type FTransform and assign it to the return value of SpawnPointComponent->GetComponentTransform()
            FTransform SpawnTransform = SpawnPointComponent->GetComponentTransform();
            //DECLARE a variable called SpawnedActor of type AFallingActor* and assign it to the return value of World->SpawnActor<type>(args..), 
            //passing in AFallingActor as the type argument (inside <>) and in function arguments pass --> FallingActorTemplate, SpawnTransform, SpawnParams
            //SpawnActor() is a very important Function, it Instantiates the TSubclassOf template class that we set in the editor.
            ABall* SpawnedActor = World->SpawnActor<ABall>(FallingActorTemplate, SpawnTransform, SpawnParams);
            //IF SpawnedActor NOT EQUAL to nullptr
            if (SpawnedActor)
            {
                //DECLARE a variable called direction of type FVector and assign it to the return value of --> FRotationMatrix(SpawnTransform.Rotator()).GetScaledAxis(EAxis::X)
                FVector direction = FRotationMatrix(SpawnTransform.Rotator()).GetScaledAxis(EAxis::X);
                UProjectileMovementComponent* physicsComponent = SpawnedActor->GetBallMovement();
                //CALL AddForce(..) on the physicsComponent and pass in --> direction * 1000000, NAME_None, true
                physicsComponent->Velocity = direction * 500;
                physicsComponent->UpdateComponentVelocity();
                SpawnCount++;
            }
            //ENDIF SpawnedActor NOT EQUAL to nullptr
        }

    }//ENDIF the FallingActorTemplate NOT EQUAL to nullptr

}

void ABallSpawner::ResetSpawnCount()
{
    SpawnCount--;
}


