// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDownGameModeBase.h"

#include "Food.h"

ATopDownGameModeBase::ATopDownGameModeBase():Super()
{
	PrimaryActorTick.bCanEverTick = true;
}


void ATopDownGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	SpawnTimer -= DeltaSeconds;

	if (SpawnTimer < 0)
	{
		SpawnTimer = NumberOfSecondsBetweenSpawn;

		UWorld* world = GetWorld();
		if (world)
		{
			FVector foodLocation = GenerateRandomLocation();

			AFood* food = world->SpawnActor<AFood>(FoodBlueprint, foodLocation, FRotator::ZeroRotator);
		}
	}
}

FVector ATopDownGameModeBase::GenerateRandomLocation()
{
	FVector location;
	float minimum = 100;
	float maximum = 1000;
	location.X = FMath::RandRange(minimum, maximum);
	location.Y = FMath::RandRange(minimum, maximum);
	location.Z = 0;
	return location;
}
