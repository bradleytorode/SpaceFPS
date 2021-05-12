// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Calgreghard/Actor/CreatureBase.h"
#include "Fish.generated.h"

/**
 * 
 */
UCLASS()
class SPACEFPS_API AFish : public ACreatureBase
{
	GENERATED_BODY()
	
public:
	AFish();

protected:
	virtual void BeginPlay() override;
};
