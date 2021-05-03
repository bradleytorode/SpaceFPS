// Fill out your copyright notice in the Description page of Project Settings.


#include "Needler.h"

ANeedler::ANeedler() {
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SM(TEXT("SkeletalMesh'/Game/CalgreghardStuff/Assets/Creatures/Needles/needles_fbm/needles.needles'"));
	if (SM.Succeeded()) {
		GetMesh()->SetSkeletalMesh(SM.Object);
	}
}