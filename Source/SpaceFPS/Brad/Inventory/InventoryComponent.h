// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemBase.h"
#include "Weapons/WeaponBase.h"
#include "InventoryComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACEFPS_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	//Using a map to move items around freely without having to shift the entire array.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TMap<int, struct FItemData> Items;

	//Change to weapons when creating the weapons
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon Slots")
	TMap<int, AWeaponBase*> WeaponSlots;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 capacity = 8;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Quest Items")
	TMap<int, struct FItemData> KeyItems;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	bool AddItem(FItemData ItemToAdd);

	bool AddNonStackableItem(FItemData ItemToAdd);

	bool AddStackableItem(FItemData ItemToAdd);
	
	UFUNCTION(BlueprintCallable)
	bool AddWeapon(AWeaponBase* WeaponToAdd);

	UFUNCTION(BlueprintCallable)
	void DropItem(int foundKey);

	UFUNCTION(BlueprintCallable)
	void RemoveFromStack(FItemData ItemToRemove, int AmountToRemove);

	UFUNCTION(BlueprintCallable)
	void IncreaseCapacity();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
