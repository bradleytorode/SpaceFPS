// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Calgreghard/Actor/CreatureBase.h"
#include "Sloth.generated.h"

/**
 * 
 */
UCLASS()
class SPACEFPS_API ASloth : public ACreatureBase
{
	GENERATED_BODY()

public:
	ASloth();

protected:
	virtual void BeginPlay() override;
	
};
