// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory/ItemBase.h"
#include "ConsumableBase.generated.h"



UENUM()
enum EConsumableType
{
	Health				UMETA(DisplayName = "Health"),
	DamageIncrease		UMETA(DisplayName = "Damage"),
	DamageResistance	UMETA(DisplayName = "Resistance"),
	Movement			UMETA(DisplayName = "Movespeed"),
	HealAndSpeed		UMETA(DisplayName = "Health and Speed")

};

/**
 * 
 */
UCLASS()
class SPACEFPS_API AConsumableBase : public AItemBase
{
	GENERATED_BODY()

public:


	//value that will be used dependent on the case and switch in the Use function
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Consume")
	int ConsumeModifier;


	UFUNCTION(BlueprintCallable)
	virtual void Use();





};
