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
	Idle		UMETA(DisplayName = "Idle"),
	Moving		UMETA(DisplayName = "Moving"),
	Dead		UMETA(DisplayName = "Dead"),
	Max			UMETA(DisplayName = "Max")
};

UENUM(BlueprintType)
enum ESociality {
	Solitary	UMETA(DisplayName = "Solitary"),
	Pack		UMETA(DisplayName = "Pack")
};