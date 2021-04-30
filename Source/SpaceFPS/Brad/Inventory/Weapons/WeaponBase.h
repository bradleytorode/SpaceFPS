// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpaceFPS/Brad/Inventory/ItemBase.h"
#include "WeaponBase.generated.h"

/**
 * 
 */
UCLASS()
class SPACEFPS_API AWeaponBase : public AItemBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	int WeaponDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	int FireRate;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	int MagSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	int Range;

	//UFUNCTION(BlueprintCallable)
	//void UpgradeWeapon();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon Mechanics")
	void Shoot();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Weapon Mechanics")
	void Reload();

};
