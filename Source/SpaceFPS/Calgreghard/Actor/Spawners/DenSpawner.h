// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Calgreghard/Actor/CreatureSpawner.h"
#include "SpaceFPS/Calgreghard/Libraries/EnumLibrary.h"
#include "SpaceFPS/Calgreghard/Libraries/StructLibrary.h"
#include "SpaceFPS/Calgreghard/Actor/CreatureBase.h"
#include "DenSpawner.generated.h"

UCLASS()
class SPACEFPS_API ADenSpawner : public ACreatureSpawner
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn variables")
		class TSubclassOf<ACreatureBase> SpawnCreatureClass;
	
public:
	ADenSpawner();

	virtual void SpawnCreatures() override;

	UFUNCTION()
	void EnterTriggerArea(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
