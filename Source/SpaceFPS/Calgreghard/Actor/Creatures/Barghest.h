// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Calgreghard/Actor/CreatureBase.h"
#include "Barghest.generated.h"

/**
 * 
 */
UCLASS()
class SPACEFPS_API ABarghest : public ACreatureBase
{
	GENERATED_BODY()

public:
	ABarghest();

protected:
	virtual void BeginPlay();
	
};
