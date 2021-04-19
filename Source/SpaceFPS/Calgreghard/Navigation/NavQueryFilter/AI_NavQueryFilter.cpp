// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_NavQueryFilter.h"
#include "NavAreas/NavArea_Default.h"

UAI_NavQueryFilter::UAI_NavQueryFilter() {
	TSubclassOf<UNavArea_Default> ZoneDefault = TSubclassOf<UNavArea_Default>(UNavArea_Default::StaticClass());

	AddExcludedArea(ZoneDefault);
}