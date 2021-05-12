// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Calgreghard/Actor/CreatureSpawner.h"
#include "SpaceFPS/Calgreghard/Libraries/EnumLibrary.h"
#include "SpaceFPS/Calgreghard/Libraries/StructLibrary.h"
#include "SpaceFPS/Calgreghard/Actor/CreatureBase.h"
#include "AreaSpawner.generated.h"

UCLASS(Abstract)
class SPACEFPS_API AAreaSpawner : public ACreatureSpawner
{
	GENERATED_BODY()

public:
	/*Components*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* SpawnAndTriggerArea;

	/*Variables*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<class TSubclassOf<ACreatureBase>> SpawnCreatureClasses;

public:
	/*Constructor*/
	AAreaSpawner();
	
	/*overriden functions*/
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
		
	virtual void SpawnCreatures() override;

	/*Collision delegates*/
	UFUNCTION()
		void EnterArea(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void ExitArea(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
