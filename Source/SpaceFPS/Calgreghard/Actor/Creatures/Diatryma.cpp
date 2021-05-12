// Fill out your copyright notice in the Description page of Project Settings.


#include "Diatryma.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SpaceFPS/Calgreghard/Actor/CreatureAIController.h"
#include "SpaceFPS/Calgreghard/Navigation/NavQueryFilter/SlothQueryFilter.h"


ADiatryma::ADiatryma() 
	: Super() {
	/*Object assigning*/
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SM(TEXT("SkeletalMesh'/Game/CalgreghardStuff/Assets/Creatures/Diatryma/diatryma.diatryma'"));
	if (SM.Succeeded()) {
		GetMesh()->SetSkeletalMesh(SM.Object);
	}

	ConstructorHelpers::FObjectFinder<UAnimBlueprint>AniBP(TEXT("AnimBlueprint'/Game/CalgreghardStuff/Animations/Diartryma/AniBP_Diatryma.AniBP_Diatryma'"));
	if (AniBP.Succeeded()) {
		GetMesh()->SetAnimClass(AniBP.Object->GeneratedClass);
	}

	ConstructorHelpers::FObjectFinder<UBehaviorTree>BTRef(TEXT("BehaviorTree'/Game/CalgreghardStuff/AI/BT/BT_Diatryma.BT_Diatryma'"));
	if (BTRef.Succeeded()) {
		BT = BTRef.Object;
	}

	/*Set Variables*/
	IdleLimit = 2;
	Health = MaxHealth = 100.f;
	WalkSpeed = 150.f;
	RunSpeed = 400.f;

	Predators.Add(APlayerCharacter::StaticClass());

	Sociality = ESociality::Loner;
	JumpCapabilities = EJumpHeight::ShortJump;

	NavQuery = USlothQueryFilter::StaticClass(); //FINISH THIS, Make query filter for sloth

	//Set movement component speed
	Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = WalkSpeed;
}

void ADiatryma::BeginPlay() {
	Super::BeginPlay();

	Cast<ACreatureAIController>(Controller)->SenseSight->PeripheralVisionAngleDegrees = 100.f;
}