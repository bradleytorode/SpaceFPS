// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory/ItemBase.h"
#include "KeyItems.generated.h"

/**
 * 
 */
UCLASS()
class SPACEFPS_API AKeyItems : public AItemBase
{
	GENERATED_BODY()

	
	virtual void Drop() override;
	
};
