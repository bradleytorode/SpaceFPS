// Fill out your copyright notice in the Description page of Project Settings.


#include "SlothQueryFilter.h"
#include "SpaceFPS/Calgreghard/Navigation/NavArea/NavArea_HighHeightJump.h"

USlothQueryFilter::USlothQueryFilter() {
	FNavigationFilterArea JumpArea;

	JumpArea.AreaClass = UNavArea_HighHeightJump::StaticClass();

	JumpArea.EnteringCostOverride = 10.f;

	Areas.Add(JumpArea);
	
	Areas[4].EnteringCostOverride = 999;
}