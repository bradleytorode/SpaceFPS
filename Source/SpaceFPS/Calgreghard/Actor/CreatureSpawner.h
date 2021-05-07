// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpaceFPS/Calgreghard/Libraries/EnumLibrary.h"
#include "SpaceFPS/Calgreghard/Libraries/StructLibrary.h"
#include "SpaceFPS/Calgreghard/Actor/CreatureBase.h"
#include "EnvironmentQuery/EnvQuery.h"
#include "EnvironmentQuery/EnvQueryManager.h"
#include "Templates/SharedPointer.h"
#include "CreatureSpawner.generated.h"

UCLASS(Abstract)
class SPACEFPS_API ACreatureSpawner : public AActor
{
	GENERATED_BODY()
	
public:
	/*Components*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* Root;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SpawnArea;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* TriggerZone;

	/*Private variables*/
	UPROPERTY()
		UDataTable* DTReference;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawn variables")
		FCreatureData SpawnCreatureData;
	/*UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn variables")
		TArray<class TSubclassOf<ACreatureBase>> CreaturesToSpawnClass;*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawn variables")
		TArray<ACreatureBase*> CreaturesArray;

	/*EQS*/
	FVector spawnLocation;
	UEnvQuery* SpawnLocationEQS;
	FEnvQueryRequest QueryRequest;
	

public:	
	// Sets default values for this actor's properties
	ACreatureSpawner();

	UFUNCTION(BlueprintCallable)
		virtual void SpawnCreatures();

	void EQSResult(TSharedPtr<FEnvQueryResult> results);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
