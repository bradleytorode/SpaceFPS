// Fill out your copyright notice in the Description page of Project Settings.


#include "Needler.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SpaceFPS/Calgreghard/Actor/CreatureAIController.h"
#include "Animation/AnimBlueprint.h"
#include "SpaceFPS/Calgreghard/Navigation/NavQueryFilter/NeedlerQueryFilter.h"

ANeedler::ANeedler() 
	: Super() {
	/*Object assigning*/
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SM(TEXT("SkeletalMesh'/Game/CalgreghardStuff/Assets/Creatures/Needles/needles_fbm/needles.needles'"));
	if (SM.Succeeded()) {
		GetMesh()->SetSkeletalMesh(SM.Object);
	}

	ConstructorHelpers::FObjectFinder<UAnimBlueprint>AniBP(TEXT("AnimBlueprint'/Game/CalgreghardStuff/Animations/Needler/AniBP_Needler.AniBP_Needler'"));
	if (AniBP.Succeeded()) {
		GetMesh()->SetAnimClass(AniBP.Object->GeneratedClass);
	}

	ConstructorHelpers::FObjectFinder<UBehaviorTree>BTRef(TEXT("BehaviorTree'/Game/CalgreghardStuff/AI/BT/BT_Needler.BT_Needler'"));
	if (BTRef.Succeeded()) {
		BT = BTRef.Object;
	}

	/*Set Variables*/
	Health = MaxHealth = 100.f;
	IdleLimit = 2;
	WalkSpeed = 150.f;
	RunSpeed = 700.f;
	
	Predators.Add(APlayerCharacter::StaticClass());
	
	NavQuery = UNeedlerQueryFilter::StaticClass();

	//Set movement component speed
	Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = WalkSpeed;
}

void ANeedler::BeginPlay()
{
	Super::BeginPlay();

	Cast<ACreatureAIController>(Controller)->SenseSight->PeripheralVisionAngleDegrees = 110.f;
}
