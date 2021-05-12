// Fill out your copyright notice in the Description page of Project Settings.


#include "SurferQueryFilter.h"

USurferQueryFilter::USurferQueryFilter()
	: Super() {
	Areas[0].EnteringCostOverride = FLT_MAX; //Default area
	Areas[4].EnteringCostOverride = 1.f; //Water area
}