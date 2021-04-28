// Fill out your copyright notice in the Description page of Project Settings.


#include "NavArea_Water.h"

UNavArea_Water::UNavArea_Water() {
	DefaultCost = 1.f;
	FixedAreaEnteringCost = FLT_MAX;

	DrawColor = FColor::Blue;
}