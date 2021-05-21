// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EnumLibrary.generated.h"

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

UENUM(BlueprintType) 
enum EJumpHeight {
	NoJump		UMETA(DisplayName = "No Jump"),
	ShortJump	UMETA(DisplayName = "Short Jump"),
	MediumJump	UMETA(DisplayName = "Medium Jump"),
	LongJump	UMETA(DisplayName = "Long Jump")
};