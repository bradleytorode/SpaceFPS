// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

UCLASS()
class SPACEFPS_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	class UStaticMeshComponent* ItemMesh;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	class UTexture2D* ItemIcon;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 ItemID;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FText Name;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FText ItemDescription;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	bool bIsEssential;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int CurrentStackSize;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int MaxStackSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		int value;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Drop();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
