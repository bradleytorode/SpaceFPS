// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//Initialise inventory slots
	for (int i = 0; i < capacity; i++)
	{
		Items.Add(i, FItemData());
	}

	//Initialise weapon slots
	for (int i = 0; i < 4; i++)
	{
		WeaponSlots.Add(i, NULL);
	}



}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

//Inventory checking if the item is stackable or non stackable through the addItem function.
bool UInventoryComponent::AddItem(FItemData ItemToAdd)
{
		if (ItemToAdd.MaxStackSize == 1)
		{
			//If function returns false, this will be unavailable.
			return AddNonStackableItem(ItemToAdd);
			
		}
		else
		{
			//If function returns false, this will be unavailable.
			return AddStackableItem(ItemToAdd);
		}

}

//
bool UInventoryComponent::AddNonStackableItem(FItemData ItemToAdd)
{
	bool bMapKeyFree = false;

	//Checks for a slot that is free in the inventory. If slot is free add item. Otherwise break.
	for (int i = 0; i < Items.Num(); i++)
	{
		if (Items[i].ItemID == -1) {
			Items[i] = ItemToAdd;
			bMapKeyFree = true;
			break;
		}
	}

	return bMapKeyFree;

}


//
bool UInventoryComponent::AddStackableItem(FItemData ItemToAdd)
{

	bool bMapKeyFree = false;

	//Checking there is an index
	int ItemIndex = -1;

	for (int i = 0; i < Items.Num(); i++)
	{
		if (ItemToAdd.ItemID == Items[i].ItemID && Items[i].CurrentStackSize < Items[i].MaxStackSize)
		{
			if (Items[i].CurrentStackSize + ItemToAdd.CurrentStackSize > Items[i].MaxStackSize) {
				ItemToAdd.CurrentStackSize -= Items[i].MaxStackSize - Items[i].CurrentStackSize;
				Items[i].CurrentStackSize = Items[i].MaxStackSize;
			}
			else
			{
				Items[i].CurrentStackSize += ItemToAdd.CurrentStackSize;
				bMapKeyFree = true;
				ItemIndex = -1;
				break;
			}
		}
		if (Items[i].ItemID == -1) {
			Items[i] = ItemToAdd;
			bMapKeyFree = true;
			if (ItemIndex == -1) {
				ItemIndex = i;
				break;
			}
		}
	}

	if (ItemIndex != -1) {
		Items[ItemIndex] = ItemToAdd;
	}

	return bMapKeyFree;

}


//
bool UInventoryComponent::AddWeapon(AWeaponBase* WeaponToAdd)
{

	bool bWeaponMapKeyFree = false;

	for (int i = 0; i < WeaponSlots.Num(); i++)
	{
		if (WeaponSlots[i] == NULL) {
			WeaponSlots[i] = WeaponToAdd;
			bWeaponMapKeyFree = true;
			break;
		}
	}

	return bWeaponMapKeyFree;
}


//
void UInventoryComponent::DropItem(int foundKey)
{
	FVector ActorLocation = FVector(GetOwner()->GetActorLocation() + (GetOwner()->GetActorForwardVector() * 150.f));
	FRotator ActorRotation;

	FActorSpawnParameters ItemSpawnParams;
	ItemSpawnParams.Owner = GetOwner();

	AItemBase* DroppedItem = GetWorld()->SpawnActor<AItemBase>(ActorLocation, ActorRotation, ItemSpawnParams);
	DroppedItem->Drop(Items[foundKey]);

	Items[foundKey] = FItemData();


}
                                          
void UInventoryComponent::RemoveFromStack(FItemData ItemToRemove, int AmountToRemove = 1)
{

}

void UInventoryComponent::IncreaseCapacity()
{
	//When this function is called add 4 to items capacity.
	capacity += 4;
	for (int i = 0; i < 4; i++)
	{
		Items.Add(i, FItemData());
	}
}



// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

