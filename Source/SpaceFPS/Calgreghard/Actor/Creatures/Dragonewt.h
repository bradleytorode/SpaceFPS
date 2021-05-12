// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Calgreghard/Actor/CreatureBase.h"
#include "Dragonewt.generated.h"

UCLASS()
class SPACEFPS_API ADragonewt : public ACreatureBase
{
	GENERATED_BODY()
	
public:
	ADragonewt();

protected:
	virtual void BeginPlay() override;
};
