// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyPaddle.generated.h"

UCLASS()
class KFLPONG_API AEnemyPaddle : public AActor
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, Category = "Collision Box")
        class UBoxComponent* BoxComponent;

    UPROPERTY(EditAnywhere, Category = "Visual")
        class UPaperSpriteComponent* AISpriteComponent;
	
public:	
	// Sets default values for this actor's properties
	AEnemyPaddle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    /* First of two patrol points to patrol between */
    UPROPERTY(EditInstanceOnly,
        Category = "AI",
        meta = (EditCondition = "Target"))
        AActor* Target;

};
