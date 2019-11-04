// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyGoal.generated.h"

UCLASS()
class KFLPONG_API AEnemyGoal : public AActor
{
	GENERATED_BODY()

        UPROPERTY(EditAnywhere, Category = "Collision Box")
        class UBoxComponent* BoxComponent;

    UPROPERTY(EditAnywhere, Category = "Visual")
        class UPaperSpriteComponent* ActorSpriteComponent;
	
public:	
	// Sets default values for this actor's properties
	AEnemyGoal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
