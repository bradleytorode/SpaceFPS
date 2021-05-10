// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_NavQueryFilter.h"
#include "NavAreas/NavArea_Default.h"
#include "NavAreas/NavArea_LowHeight.h"
#include "NavAreas/NavArea_Null.h"
#include "NavAreas/NavArea_Obstacle.h"
#include "SpaceFPS/Calgreghard/Navigation/NavArea/NavArea_Water.h"

UAI_NavQueryFilter::UAI_NavQueryFilter() {

	FNavigationFilterArea DefaultArea;
	FNavigationFilterArea LowHeightArea;
	FNavigationFilterArea NullArea;
	FNavigationFilterArea ObstacleArea;
	FNavigationFilterArea WaterArea;

	DefaultArea.AreaClass = UNavArea_Default::StaticClass();
	LowHeightArea.AreaClass = UNavArea_LowHeight::StaticClass();
	NullArea.AreaClass = UNavArea_Null::StaticClass();
	ObstacleArea.AreaClass = UNavArea_Obstacle::StaticClass();
	WaterArea.AreaClass = UNavArea_Water::StaticClass();

	Areas.Add(DefaultArea); //0
	Areas.Add(LowHeightArea); //1
	Areas.Add(NullArea); //2
	Areas.Add(ObstacleArea); //3
	Areas.Add(WaterArea); //4

	Areas[2].EnteringCostOverride = 999;
}