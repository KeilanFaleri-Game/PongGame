// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Background.generated.h"

UCLASS()
class KFLPONG_API ABackground : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABackground();

        UPROPERTY(EditAnywhere, Category = "Visual")
        class UPaperSpriteComponent* PlayerSpriteComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera Spring", meta = (AllowPrivateAccess = "true"))
        class USpringArmComponent* SpringArmComponent;

    UPROPERTY(EditAnywhere, Category = "Player Camera")
        class UCameraComponent* FollowCameraComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
