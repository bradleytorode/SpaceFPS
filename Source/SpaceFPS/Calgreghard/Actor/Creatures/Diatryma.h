// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Calgreghard/Actor/CreatureBase.h"
#include "Diatryma.generated.h"

/**
 * 
 */
UCLASS()
class SPACEFPS_API ADiatryma : public ACreatureBase
{
	GENERATED_BODY()
	
public:
	ADiatryma();

protected:
	virtual void BeginPlay() override;
};
