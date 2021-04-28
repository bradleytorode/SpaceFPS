// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_NavQueryFilter.h"
#include "NavAreas/NavArea_Default.h"
#include "NavAreas/NavArea_LowHeight.h"
#include "NavAreas/NavArea_Null.h"
#include "NavAreas/NavArea_Obstacle.h"
#include "SpaceFPS/Calgreghard/Navigation/NavArea/NavArea_Water.h"
#include "SpaceFPS/Calgreghard/Navigation/NavArea/NavArea_Shubbery.h"

UAI_NavQueryFilter::UAI_NavQueryFilter() {
	/*Default Area*/
	FNavigationFilterArea DefaultArea;
	DefaultArea.AreaClass = UNavArea_Default::StaticClass();

	/*Low height*/
	FNavigationFilterArea LowHeightArea;
	LowHeightArea.AreaClass = UNavArea_LowHeight::StaticClass();
	LowHeightArea.TravelCostOverride = 1.1f;

	/*Null*/
	FNavigationFilterArea NullArea;
	NullArea.AreaClass = UNavArea_Null::StaticClass();
	NullArea.bIsExcluded = true;

	/*Obstacle*/
	FNavigationFilterArea ObstacleArea;
	ObstacleArea.AreaClass = UNavArea_Obstacle::StaticClass();
	ObstacleArea.bIsExcluded = true;

	/*Water*/
	FNavigationFilterArea WaterArea;
	WaterArea.AreaClass = UNavArea_Water::StaticClass();
	WaterArea.bIsExcluded = true;

	/*Shrubbery*/
	FNavigationFilterArea ShrubberyArea;
	ShrubberyArea.AreaClass = UNavArea_Shubbery::StaticClass();
	ShrubberyArea.bIsExcluded = true;

	Areas.Add(DefaultArea);
	Areas.Add(LowHeightArea);
	Areas.Add(NullArea);
	Areas.Add(ObstacleArea);
	Areas.Add(WaterArea);
	Areas.Add(ShrubberyArea);

	for (FNavigationFilterArea area : Areas)
	{
		area.bOverrideEnteringCost = true;
		area.bOverrideTravelCost = true;
	}
}