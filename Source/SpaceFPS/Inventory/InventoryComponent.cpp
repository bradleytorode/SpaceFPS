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
		Items.Add(i, NULL);
	}


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
bool UInventoryComponent::AddItem(AItemBase* ItemToAdd)
{
		if (ItemToAdd->ItemDetails.MaxStackSize == 1)
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
bool UInventoryComponent::AddNonStackableItem(AItemBase* ItemToAdd)
{
	bool bMapKeyFree = false;

	for (int i = 0; i < Items.Num(); i++)
	{
		if (Items[i] == NULL) {
			Items[i] = ItemToAdd;
			bMapKeyFree = true;
			break;
		}
	}

	return bMapKeyFree;

}


//
bool UInventoryComponent::AddStackableItem(AItemBase* ItemToAdd)
{

	bool bMapKeyFree = false;

	//Checking there is an index
	int ItemIndex = -1;

	for (int i = 0; i < Items.Num(); i++)
	{
		if (ItemToAdd == Items[i] && Items[i]->ItemDetails.CurrentStackSize < Items[i]->ItemDetails.MaxStackSize)
		{
			if (Items[i]->ItemDetails.CurrentStackSize + ItemToAdd->ItemDetails.CurrentStackSize > Items[i]->ItemDetails.MaxStackSize) {
				Items[i]->ItemDetails.CurrentStackSize = Items[i]->ItemDetails.MaxStackSize;
				ItemToAdd->ItemDetails.CurrentStackSize -= Items[i]->ItemDetails.MaxStackSize - Items[i]->ItemDetails.CurrentStackSize;
			}
			else
			{
				Items[i]->ItemDetails.CurrentStackSize += ItemToAdd->ItemDetails.CurrentStackSize;
				bMapKeyFree = true;
				ItemIndex = -1;
				break;
			}
		}
		if (Items[i] == NULL) {
			Items[i] = ItemToAdd;
			bMapKeyFree = true;
			if (ItemIndex != -1) {
				ItemIndex = i;
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
//	FVector ActorLocation;
//	FRotator ActorRotation;
//
//
//	//AItemBase* DroppedItem = GetWorld()->SpawnActor<AItemBase>(,);
//	//DroppedItem->ItemDetails = Items[foundKey]->ItemDetails;
//	Items[foundKey] = NULL;
//	if (Items[foundKey]->GetClass() == AItemBase::StaticClass());
}
                                          
void UInventoryComponent::RemoveFromStack(AItemBase* ItemToRemove, int AmountToRemove = 1)
{

}

void UInventoryComponent::IncreaseCapacity()
{
	capacity += 4;
	for (int i = 0; i < 4; i++)
	{
		Items.Add(i, NULL);
	}
}



// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

