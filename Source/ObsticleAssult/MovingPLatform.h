// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPLatform.generated.h"

UCLASS()
class OBSTICLEASSULT_API AMovingPLatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPLatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Moving")
	FVector PlatformVelocity= FVector(0,-100,0);
	UPROPERTY(EditAnywhere, Category="Moving")
	float targetMove = 100;
	UPROPERTY(EditAnywhere, Category="Rotation");
	FRotator RotationVelocity;
 
	FVector StartLocation;

	void MovePlatform(float DeltaTime);

	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn() const;

	float GetDistanceMoved() const;
};
