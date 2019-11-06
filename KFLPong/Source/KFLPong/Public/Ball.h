// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

UCLASS()
class KFLPONG_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess), Category = "Components")
        class USphereComponent* SphereCollisionComponent;

    UPROPERTY(EditAnywhere, Category = "Visual")
        class UPaperSpriteComponent* ballSpriteComponent;

    UPROPERTY(EditAnywhere, Category = "PhysicsComponent")
        class UProjectileMovementComponent* BallProjectile;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
