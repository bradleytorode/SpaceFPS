// Fill out your copyright notice in the Description page of Project Settings.


#include "NavArea_Shubbery.h"

UNavArea_Shubbery::UNavArea_Shubbery() {
	DefaultCost = 1.f;
	FixedAreaEnteringCost = FLT_MAX;

	DrawColor = FColor::Green;
}