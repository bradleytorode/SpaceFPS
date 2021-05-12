// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Calgreghard/Actor/CreatureBase.h"
#include "Plant.generated.h"

/**
 * 
 */
UCLASS()
class SPACEFPS_API APlant : public ACreatureBase
{
	GENERATED_BODY()
	
public:
	APlant();

protected:
	virtual void BeginPlay() override;
};
