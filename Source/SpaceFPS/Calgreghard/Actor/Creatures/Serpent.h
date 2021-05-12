// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Calgreghard/Actor/CreatureBase.h"
#include "Serpent.generated.h"

/**
 * 
 */
UCLASS()
class SPACEFPS_API ASerpent : public ACreatureBase
{
	GENERATED_BODY()
	
public:
	ASerpent();

protected:
	virtual void BeginPlay() override;	
};
