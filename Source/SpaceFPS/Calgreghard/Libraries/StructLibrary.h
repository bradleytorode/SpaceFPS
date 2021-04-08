// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/SkeletalMesh.h"
#include "BehaviorTree/BehaviorTree.h"
#include "SpaceFPS/Calgreghard/Navigation/AI_NavQueryFilter.h"
#include "StructLibrary.generated.h"

USTRUCT(BlueprintType)
struct FWaterProperties {
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FColor WaterColour = FColor::Cyan;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float BottomOpacity = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float FadeDistance = 500.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Metalic = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Refraction = 0.9f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Roughness = 0.2f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Specular = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float TopOpacity = 0.75f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float WaveContrast = 0.2f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float WaveSize = 50.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float WaveSpeed = 0.01f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float WaveStrength = 7.5f;
};

USTRUCT(BlueprintType)
struct FCreatureData : public FTableRowBase {
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName CreatureName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		USkeletalMesh* SKMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UBehaviorTree* IdleBehaviour;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UAI_NavQueryFilter* NavQuery;
};