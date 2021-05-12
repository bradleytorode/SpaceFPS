// Fill out your copyright notice in the Description page of Project Settings.


#include "FishQueryFilter.h"
#include "SpaceFPS/Calgreghard/Navigation/NavArea/NavArea_Water.h"

UFishQueryFilter::UFishQueryFilter() {
	for (FNavigationFilterArea filter : Areas) {
		if (filter.AreaClass != UNavArea_Water::StaticClass()) {
			filter.EnteringCostOverride = FLT_MAX;
		}
		else {
			filter.EnteringCostOverride = 1.f;
		}
	}
}