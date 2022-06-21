// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TopDownGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UE5_CPP_TOPDOWN_API ATopDownGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATopDownGameModeBase();

	UPROPERTY(EditAnywhere, Category="Spawn")
	TSubclassOf<class AFood> FoodBlueprint;

	float SpawnTimer;
	float NumberOfSecondsBetweenSpawn  =1.f;

	FVector GenerateRandomLocation();
	virtual void Tick(float DeltaSeconds) override;
	
};
