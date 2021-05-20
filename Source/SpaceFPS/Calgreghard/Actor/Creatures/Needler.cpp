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

	//Materials
	ConstructorHelpers::FObjectFinder<UMaterial>R16Ref(TEXT("Material'/Game/CalgreghardStuff/Assets/Creatures/Needles/needles_fbm/M_Needler_R1_6.M_Needler_R1_6'"));
	if (R16Ref.Succeeded()) {
		R16 = R16Ref.Object;
	}

	ConstructorHelpers::FObjectFinder<UMaterial>R1Ref(TEXT("Material'/Game/CalgreghardStuff/Assets/Creatures/Needles/needles_fbm/M_Needler_R1.M_Needler_R1'"));
	if (R1Ref.Succeeded()) {
		R1 = R1Ref.Object;
	}

	ConstructorHelpers::FObjectFinder<UMaterial>SmoothRef(TEXT("Material'/Game/CalgreghardStuff/Assets/Creatures/Needles/needles_fbm/M_Needler_Smooth.M_Needler_Smooth'"));
	if (SmoothRef.Succeeded()) {
		Smooth = SmoothRef.Object;
	}

	ConstructorHelpers::FObjectFinder<UMaterial>RoughRef(TEXT("Material'/Game/CalgreghardStuff/Assets/Creatures/Needles/needles_fbm/M_Needler_Rough.M_Needler_Rough'"));
	if (RoughRef.Succeeded()) {
		Rough = RoughRef.Object;
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

void ANeedler::TakeDamage(int dmgAmount)
{
	Super::TakeDamage(dmgAmount);

	float healthPercentage = Health / MaxHealth;

	if (healthPercentage < 0.3f) {
		GetMesh()->SetMaterial(0, Smooth);
	}
	else if (0.3f <= healthPercentage && healthPercentage < 0.5f) {
		GetMesh()->SetMaterial(0, R1);
	}
	else {
		GetMesh()->SetMaterial(0, R16);
	}
}

void ANeedler::Die()
{
	Super::Die();

	GetMesh()->SetMaterial(0, Rough);
}

void ANeedler::BeginPlay()
{
	Super::BeginPlay();

	Cast<ACreatureAIController>(Controller)->SenseSight->PeripheralVisionAngleDegrees = 110.f;
}
