// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Calgreghard/Actor/CreatureBase.h"
#include "Needler.generated.h"

UCLASS()
class SPACEFPS_API ANeedler : public ACreatureBase
{
	GENERATED_BODY()
	
public:
	ANeedler();

protected:
	virtual void BeginPlay() override;
};
