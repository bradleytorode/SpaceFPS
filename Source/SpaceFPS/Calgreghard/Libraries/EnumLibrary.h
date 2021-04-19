// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnumLibrary.generated.h"

UENUM(BlueprintType)
enum ECreatureNames {
	Needles		UMETA(DisplayName = "Needles"),
	Sloth		UMETA(DisplayName = "Sloth")
};

UENUM(BlueprintType)
enum EBehaviour {
	None		UMETA(DisplayName = "None"),
	Idle		UMETA(DisplayName = "Idle"),
	Moving		UMETA(DisplayName = "Moving")
};