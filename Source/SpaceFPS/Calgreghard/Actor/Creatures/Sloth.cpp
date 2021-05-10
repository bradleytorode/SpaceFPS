// Fill out your copyright notice in the Description page of Project Settings.


#include "Sloth.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SpaceFPS/Calgreghard/Actor/CreatureAIController.h"
#include "SpaceFPS/Calgreghard/Navigation/NavQueryFilter/NeedlerQueryFilter.h"

ASloth::ASloth()
	: Super() {
	/*Object assigning*/
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SM(TEXT("SkeletalMesh'/Game/CalgreghardStuff/Assets/Creatures/SLoth/sloth.sloth'"));
	if (SM.Succeeded()) {
		GetMesh()->SetSkeletalMesh(SM.Object);
	}

	ConstructorHelpers::FObjectFinder<UAnimBlueprint>AniBP(TEXT("AnimBlueprint'/Game/CalgreghardStuff/Animations/Sloth/AniBP_Sloth.AniBP_Sloth'"));
	if (AniBP.Succeeded()) {
		GetMesh()->SetAnimClass(AniBP.Object->GeneratedClass);
	}

	ConstructorHelpers::FObjectFinder<UBehaviorTree>BTRef(TEXT("BehaviorTree'/Game/CalgreghardStuff/AI/BT/BT_Sloth.BT_Sloth'"));
	if (BTRef.Succeeded()) {
		BT = BTRef.Object;
	}

	/*Set Variables*/
	Health = MaxHealth = 100.f;
	WalkSpeed = 150.f;
	RunSpeed = 400.f;

	Sociality = ESociality::Pack;
	JumpCapabilities = EJumpHeight::LongJump;

	GroupSize = FVector2D(3.f, 5.f);

	NavQuery = UNeedlerQueryFilter::StaticClass(); //FINISH THIS, Make query filter for sloth

	//Set movement component speed
	Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = WalkSpeed;
}

void ASloth::BeginPlay()
{
	Super::BeginPlay();

	Cast<ACreatureAIController>(Controller)->SenseSight->PeripheralVisionAngleDegrees = 80.f;

}