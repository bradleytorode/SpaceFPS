// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatureBase.h"
#include "SpaceFPS/Calgreghard/Actor/Creatures/CreatureAIController.h"

ACreatureBase::ACreatureBase()
{
	Target = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Target"));
	ConstructorHelpers::FObjectFinder<UStaticMesh>TargetMesh(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	if (TargetMesh.Succeeded()) {
		Target->SetStaticMesh(TargetMesh.Object);
	}


	ConstructorHelpers::FObjectFinder<UBehaviorTree>BTRef(TEXT("BehaviorTree'/Game/CalgreghardStuff/AI/BT/BT_Creatures.BT_Creatures'"));
	if (BTRef.Succeeded()) {
		BT = BTRef.Object;
	}

	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
}

void ACreatureBase::SetVariables(FCreatureData CData)
{
	CreatureData = CData;
	
	GetMesh()->SetSkeletalMesh(CData.SKMesh);

	GetMesh()->SetAnimClass(CData.SKAniBP->GeneratedClass);

	FActorSpawnParameters spawnParams;
	spawnParams.Owner;

	ACreatureAIController* SpawnController = GetWorld()->SpawnActor<ACreatureAIController>(FVector(0.f), FRotator(0.f), spawnParams);

	SpawnController->SenseSight->PeripheralVisionAngleDegrees = CData.PeripheralVision;

	Controller = SpawnController;

	Controller->Possess(this);
}