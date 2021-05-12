// Fill out your copyright notice in the Description page of Project Settings.


#include "Plant.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SpaceFPS/Calgreghard/Actor/CustomControllers/PlantController.h"
#include "SpaceFPS/Calgreghard/Navigation/NavQueryFilter/NeedlerQueryFilter.h"
#include "SpaceFPS/Calgreghard/Actor/Creatures/Diatryma.h"
#include "SpaceFPS/Calgreghard/Actor/Creatures/Dragonewt.h"
#include "SpaceFPS/Calgreghard/Actor/Creatures/Needler.h"
#include "SpaceFPS/Calgreghard/Actor/Creatures/Sloth.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

APlant::APlant() 
	: Super() {
	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -100.f));

	/*Object assigning*/
	ConstructorHelpers::FObjectFinder<USkeletalMesh>SM(TEXT("SkeletalMesh'/Game/CalgreghardStuff/Assets/Creatures/PlantMonster/plant.plant'"));
	if (SM.Succeeded()) {
		GetMesh()->SetSkeletalMesh(SM.Object);
	}

	ConstructorHelpers::FObjectFinder<UAnimBlueprint>AniBP(TEXT("AnimBlueprint'/Game/CalgreghardStuff/Animations/PlantMonster/AniBP_Plant.AniBP_Plant'"));
	if (AniBP.Succeeded()) {
		GetMesh()->SetAnimClass(AniBP.Object->GeneratedClass);
	}

	ConstructorHelpers::FObjectFinder<UBehaviorTree>BTRef(TEXT("BehaviorTree'/Game/CalgreghardStuff/AI/BT/BT_Plant.BT_Plant'"));
	if (BTRef.Succeeded()) {
		BT = BTRef.Object;
	}

	/*Set Variables*/
	IdleLimit = 2;
	Health = MaxHealth = 100.f;
	RunSpeed = 1000.f;

	Prey.Add(APlayerCharacter::StaticClass());
	Prey.Add(ADiatryma::StaticClass());
	Prey.Add(ADragonewt::StaticClass());
	Prey.Add(ANeedler::StaticClass());
	Prey.Add(ASloth::StaticClass());

	Sociality = ESociality::Loner;
	JumpCapabilities = EJumpHeight::ShortJump;

	NavQuery = UNeedlerQueryFilter::StaticClass(); //FINISH THIS, Make query filter for sloth

	//Set movement component speed
	Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = WalkSpeed;
}

void APlant::BeginPlay() {
	Super::BeginPlay();

	/*Custom controller setup*/
	Controller->Destroy();

	FActorSpawnParameters spawnParams;
	spawnParams.Owner;

	APlantController* spawnedController = GetWorld()->SpawnActor<APlantController>(spawnParams);
	spawnedController->Possess(this);

	Cast<ACreatureAIController>(Controller)->BBComp->SetValueAsObject(TEXT("PlayerKey"), UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = WalkSpeed;

	Cast<APlantController>(Controller)->SenseSight->SightRadius = 0.f;
}