// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Calgreghard/Actor/CreatureAIController.h"
#include "PlantController.generated.h"

/**
 * 
 */
UCLASS()
class SPACEFPS_API APlantController : public ACreatureAIController
{
	GENERATED_BODY()
	
public:
	/*Constructor*/
	APlantController();

	/*Overriden functions*/
	virtual void OnPawnDetected(const TArray<AActor*>& DetectedPawns) override;
};
