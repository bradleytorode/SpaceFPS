// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnumLibrary.generated.h"

UENUM(BlueprintType)
enum ECreatureNames {
	Needles		UMETA(DisplayName = "Needles"),
	Sloth		UMETA(DisplayName = "Sloth"),
	MiniWyvern	UMETA(DisplayName = "MiniWyvern")
};

UENUM(BlueprintType)
enum EBehaviour {
	Idle		UMETA(DisplayName = "Idle"),
	Moving		UMETA(DisplayName = "Moving"),
	Alerted		UMETA(DisplayName = "Alerted"),
	Attacking	UMETA(DisplayName = "Attacking"),
	Dead		UMETA(DisplayName = "Dead")
};

UENUM(BlueprintType)
enum ESociality {
	Loner		UMETA(DisplayName = "Loner"),
	Pack		UMETA(DisplayName = "Pack")
};