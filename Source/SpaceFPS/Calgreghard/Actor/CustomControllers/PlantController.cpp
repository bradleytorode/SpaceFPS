// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantController.h"

APlantController::APlantController()
	: Super() {

	SenseSight->SightRadius = 0.f;

}

void APlantController::OnPawnDetected(const TArray<AActor*>& DetectedPawns) {
	Super::OnPawnDetected(DetectedPawns);

	ControlledCreature->GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.f));
}