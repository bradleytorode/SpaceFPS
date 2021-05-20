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
	UMaterial* R16;
	UMaterial* R1;
	UMaterial* Smooth;
	UMaterial* Rough;

public:
	ANeedler();

	virtual void TakeDamage(int dmgAmount) override;

	virtual void Die() override;

protected:
	virtual void BeginPlay() override;
};
