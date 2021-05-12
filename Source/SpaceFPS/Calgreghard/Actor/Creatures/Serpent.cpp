// Fill out your copyright notice in the Description page of Project Settings.


#include "Serpent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SpaceFPS/Calgreghard/Actor/CreatureAIController.h"
#include "SpaceFPS/Calgreghard/Navigation/NavQueryFilter/SurferQueryFilter.h"
#include "SpaceFPS/Calgreghard/Actor/Creatures/Fish.h"

ASerpent::ASerpent() 
	: Super() {
	/*Object assigning*/
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SM(TEXT("SkeletalMesh'/Game/CalgreghardStuff/Assets/Creatures/Serpent/serpent.serpent'"));
	if (SM.Succeeded()) {
		GetMesh()->SetSkeletalMesh(SM.Object);
	}

	ConstructorHelpers::FObjectFinder<UAnimBlueprint>AniBP(TEXT("AnimBlueprint'/Game/CalgreghardStuff/Animations/Serpent/AniBP_Serpent.AniBP_Serpent'"));
	if (AniBP.Succeeded()) {
		GetMesh()->SetAnimClass(AniBP.Object->GeneratedClass);
	}

	ConstructorHelpers::FObjectFinder<UBehaviorTree>BTRef(TEXT("BehaviorTree'/Game/CalgreghardStuff/AI/BT/BT_Serpent.BT_Serpent'"));
	if (BTRef.Succeeded()) {
		BT = BTRef.Object;
	}

	/*Set Variables*/
	IdleLimit = 2;
	Health = MaxHealth = 100.f;
	WalkSpeed = 160.f;
	RunSpeed = 800.f;

	Prey.Add(APlayerCharacter::StaticClass());
	Prey.Add(AFish::StaticClass());

	Sociality = ESociality::Loner;
	JumpCapabilities = EJumpHeight::ShortJump;

	GroupSize = FVector2D(3.f, 5.f);

	NavQuery = USurferQueryFilter::StaticClass(); 

	//Set movement component speed
	Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = WalkSpeed;

	GetMesh()->SetRelativeLocation(FVector(0.f));
}

void ASerpent::BeginPlay()
{
	Super::BeginPlay();

	Cast<ACreatureAIController>(Controller)->SenseSight->PeripheralVisionAngleDegrees = 110.f;

}
