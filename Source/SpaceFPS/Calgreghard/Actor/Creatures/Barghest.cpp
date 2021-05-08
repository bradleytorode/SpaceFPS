// Fill out your copyright notice in the Description page of Project Settings.


#include "Barghest.h"

ABarghest::ABarghest() 
	: Super() {

	USkeletalMeshComponent* Mane = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mane"));
	Mane->SetupAttachment(GetMesh());
	USkeletalMeshComponent* Tail = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Tail"));
	Tail->SetupAttachment(GetMesh());

	ConstructorHelpers::FObjectFinder<USkeletalMesh>SKMesh(TEXT("SkeletalMesh'/Game/CalgreghardStuff/Assets/Creatures/Barghest/Meshes/SK_BARGHEST.SK_BARGHEST'"));
	if (SKMesh.Succeeded()) {
		GetMesh()->SetSkeletalMesh(SKMesh.Object);
	}

	ConstructorHelpers::FObjectFinder<USkeletalMesh>SKMane(TEXT("SkeletalMesh'/Game/CalgreghardStuff/Assets/Creatures/Barghest/Meshes/SK_BARGHEST_MANE.SK_BARGHEST_MANE'"));
	if (SKMane.Succeeded()) {
		Mane->SetSkeletalMesh(SKMane.Object);
	}

	ConstructorHelpers::FObjectFinder<USkeletalMesh>SKTail(TEXT("SkeletalMesh'/Game/CalgreghardStuff/Assets/Creatures/Barghest/Meshes/SK_BARGHEST_TAIL.SK_BARGHEST_TAIL'"));
	if (SKTail.Succeeded()) {
		Tail->SetSkeletalMesh(SKTail.Object);
	}

	Mane->SetMasterPoseComponent(GetMesh());
	Tail->SetMasterPoseComponent(GetMesh());

}