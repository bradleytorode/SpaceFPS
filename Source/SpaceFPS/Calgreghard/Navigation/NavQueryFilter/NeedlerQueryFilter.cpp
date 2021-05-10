// Fill out your copyright notice in the Description page of Project Settings.


#include "NeedlerQueryFilter.h"
#include "SpaceFPS/Calgreghard/Navigation/NavArea/NavArea_LowHeightJump.h"

UNeedlerQueryFilter::UNeedlerQueryFilter() {
	FNavigationFilterArea LowJumpArea;

	LowJumpArea.AreaClass = UNavArea_LowHeightJump::StaticClass();

	LowJumpArea.EnteringCostOverride = 1.f;

	Areas.Add(LowJumpArea);

	Areas[4].EnteringCostOverride = 999;

}