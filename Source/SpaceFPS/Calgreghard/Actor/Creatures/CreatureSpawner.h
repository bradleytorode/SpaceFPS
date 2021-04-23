// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpaceFPS/Calgreghard/Libraries/EnumLibrary.h"
#include "SpaceFPS/Calgreghard/Libraries/StructLibrary.h"
#include "SpaceFPS/Calgreghard/Actor/Creatures/CreatureBase.h"
#include "CreatureSpawner.generated.h"

UCLASS()
class SPACEFPS_API ACreatureSpawner : public AActor
{
	GENERATED_BODY()
	
public:
	/*Components*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SpawnArea;

	/*Private variables*/
	UPROPERTY(BlueprintReadOnly)
		FName RowName;
	UPROPERTY()
		UDataTable* DTReference;

	UPROPERTY(EditAnywhere)
		class UStaticMesh* SpawnAreaMesh;

	UPROPERTY(EditAnywhere)
		TEnumAsByte<ECreatureNames> RowNameEnum;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FCreatureData SpawnCreatureData;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TArray<ACreatureBase*> CreaturesArray;

public:	
	// Sets default values for this actor's properties
	ACreatureSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
