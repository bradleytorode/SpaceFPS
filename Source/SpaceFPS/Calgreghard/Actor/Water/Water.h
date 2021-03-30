// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpaceFPS/Calgreghard/Libraries/StructLibrary.h"
#include "Water.generated.h"

UCLASS()
class SPACEFPS_API AWater : public AActor
{
	GENERATED_BODY()
public:
	/*Components*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
		UStaticMeshComponent* smPlane;
	/*Variables*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Variables")
		UMaterialInstanceDynamic* DynMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Variables")
		FWaterProperties WaterProperties;
public:
	/*Functions*/
	//Constructor
	AWater();
};