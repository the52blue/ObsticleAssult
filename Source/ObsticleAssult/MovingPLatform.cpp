// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPLatform.h"

// Sets default values
AMovingPLatform::AMovingPLatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPLatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();

}

// Called every frame
void AMovingPLatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPLatform::MovePlatform(float DeltaTime)
{
	if (ShouldPlatformReturn())
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation= StartLocation+ MoveDirection*targetMove;
		SetActorLocation(StartLocation);
		PlatformVelocity=-PlatformVelocity;
	}
	else
	{
		FVector currentLocation = GetActorLocation();
		currentLocation = currentLocation + (PlatformVelocity* DeltaTime);
		SetActorLocation(currentLocation);
	}
}

void AMovingPLatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity*DeltaTime);
}

bool AMovingPLatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved()>targetMove;

}

float AMovingPLatform::GetDistanceMoved() const
{

	float DistanceMoved = FVector::Dist(StartLocation,GetActorLocation());
	return DistanceMoved;

}

