// Fill out your copyright notice in the Description page of Project Settings.


#include "NeedlerQueryFilter.h"

UNeedlerQueryFilter::UNeedlerQueryFilter() {
	Areas[5].EnteringCostOverride = 0.1f;
	Areas[5].TravelCostOverride = 0.0f;
	Areas[5].bIsExcluded = false;
}