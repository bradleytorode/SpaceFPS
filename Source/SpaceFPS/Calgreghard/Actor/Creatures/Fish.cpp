// Fill out your copyright notice in the Description page of Project Settings.


#include "Fish.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SpaceFPS/Calgreghard/Actor/CreatureAIController.h"
#include "SpaceFPS/Calgreghard/Navigation/NavQueryFilter/FishQueryFilter.h"
#include "SpaceFPS/Calgreghard/Actor/Creatures/Serpent.h"

AFish::AFish()
	: Super() {
	/*Object assigning*/
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SM(TEXT("SkeletalMesh'/Game/CalgreghardStuff/Assets/Creatures/Fish/fish.fish'"));
	if (SM.Succeeded()) {
		GetMesh()->SetSkeletalMesh(SM.Object);
	}

	ConstructorHelpers::FObjectFinder<UAnimBlueprint>AniBP(TEXT("AnimBlueprint'/Game/CalgreghardStuff/Animations/Fish/AniBP_Fish.AniBP_Fish'"));
	if (AniBP.Succeeded()) {
		GetMesh()->SetAnimClass(AniBP.Object->GeneratedClass);
	}

	ConstructorHelpers::FObjectFinder<UBehaviorTree>BTRef(TEXT("BehaviorTree'/Game/CalgreghardStuff/AI/BT/BT_Fish.BT_Fish'"));
	if (BTRef.Succeeded()) {
		BT = BTRef.Object;
	}

	/*Set Variables*/
	IdleLimit = 1;
	Health = MaxHealth = 100.f;
	WalkSpeed = 40.f;
	RunSpeed = 200.f;
	
	Prey.Add(APlayerCharacter::StaticClass());
	Predators.Add(ASerpent::StaticClass());

	Sociality = ESociality::Pack;
	JumpCapabilities = EJumpHeight::ShortJump;

	GroupSize = FVector2D(3.f, 5.f);

	NavQuery = UFishQueryFilter::StaticClass();

	//Set movement component speed
	Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = WalkSpeed;

	GetMesh()->SetRelativeLocation(FVector(0.f));
}

void AFish::BeginPlay()
{
	Super::BeginPlay();

	Cast<ACreatureAIController>(Controller)->SenseSight->PeripheralVisionAngleDegrees = 80.f;

}
