// Fill out your copyright notice in the Description page of Project Settings.


#include "Barghest.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SpaceFPS/Calgreghard/Actor/CreatureAIController.h"
#include "SpaceFPS/Calgreghard/Navigation/NavQueryFilter/SlothQueryFilter.h"
#include "SpaceFPS/Calgreghard/Actor/Creatures/Diatryma.h"
#include "SpaceFPS/Calgreghard/Actor/Creatures/Needler.h"
#include "SpaceFPS/Calgreghard/Actor/Creatures/Dragonewt.h"
#include "SpaceFPS/Calgreghard/Actor/Creatures/Sloth.h"

ABarghest::ABarghest() 
	: Super() {
	/*Object assigning*/
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SM(TEXT("SkeletalMesh'/Game/CalgreghardStuff/Assets/Creatures/Barghest/Meshes/SK_BARGHEST.SK_BARGHEST'b"));
	if (SM.Succeeded()) {
		GetMesh()->SetSkeletalMesh(SM.Object);
	}

	ConstructorHelpers::FObjectFinder<UAnimBlueprint>AniBP(TEXT("AnimBlueprint'/Game/CalgreghardStuff/Animations/Barghest/AniBP_Barghest.AniBP_Barghest'"));
	if (AniBP.Succeeded()) {
		GetMesh()->SetAnimClass(AniBP.Object->GeneratedClass);
	}

	ConstructorHelpers::FObjectFinder<UBehaviorTree>BTRef(TEXT("BehaviorTree'/Game/CalgreghardStuff/AI/BT/BT_Barghest.BT_Barghest'"));
	if (BTRef.Succeeded()) {
		BT = BTRef.Object;
	}

	/*Set Variables*/
	IdleLimit = 2;
	Health = MaxHealth = 100.f;
	WalkSpeed = 140.f;
	RunSpeed = 600.f;

	Prey.Add(APlayerCharacter::StaticClass());
	Prey.Add(ADiatryma::StaticClass());
	Prey.Add(ADragonewt::StaticClass());
	Prey.Add(ANeedler::StaticClass());
	Prey.Add(ASloth::StaticClass());

	Sociality = ESociality::Loner;
	JumpCapabilities = EJumpHeight::ShortJump;

	GroupSize = FVector2D(3.f, 5.f);

	NavQuery = USlothQueryFilter::StaticClass();

	//Set movement component speed
	Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = WalkSpeed;


	/*Mane and tail*/
	USkeletalMeshComponent* Mane = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mane"));
	Mane->SetupAttachment(GetMesh());
	USkeletalMeshComponent* Tail = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Tail"));
	Tail->SetupAttachment(GetMesh());

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

void ABarghest::BeginPlay() {
	Super::BeginPlay();

	Cast<ACreatureAIController>(Controller)->SenseSight->PeripheralVisionAngleDegrees = 80.f;
}