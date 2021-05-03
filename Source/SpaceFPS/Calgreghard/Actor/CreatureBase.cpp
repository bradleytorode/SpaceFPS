// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatureBase.h"
#include "SpaceFPS/Calgreghard/Actor/CreatureAIController.h"
#include "GameFramework/CharacterMovementComponent.h"

ACreatureBase::ACreatureBase()
{
	ConstructorHelpers::FObjectFinder<UBehaviorTree>BTRef(TEXT("BehaviorTree'/Game/CalgreghardStuff/AI/BT/BT_Creatures.BT_Creatures'"));
	if (BTRef.Succeeded()) {
		BT = BTRef.Object;
	}

	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
}

void ACreatureBase::SetVariables(FCreatureData CData)
{
	CreatureData = CData;
	
	GetMesh()->SetSkeletalMesh(CreatureData.SKMesh);

	Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = CreatureData.walkSpeed;

	GetMesh()->SetAnimClass(CreatureData.SKAniBP->GeneratedClass);

	FActorSpawnParameters spawnParams;
	spawnParams.Owner;

	ACreatureAIController* SpawnController = GetWorld()->SpawnActor<ACreatureAIController>(FVector(0.f), FRotator(0.f), spawnParams);

	SpawnController->SenseSight->PeripheralVisionAngleDegrees = CData.PeripheralVision;

	Controller = SpawnController;

	Controller->Possess(this);
}

void ACreatureBase::TakeDamage(int dmgAmount)
{
	if (dmgAmount <= Health)
		Health -= dmgAmount;
	else
		Health = 0;

	if (Health <= 0) {
		Die();
	}
	else {
		Cast<ACreatureAIController>(GetController())->BBComp->SetValueAsEnum(TEXT("BehaviourKey"), EBehaviour::Alerted);

		Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = CreatureData.runSpeed / (CreatureData.maxHealth / Health);
	}
}

void ACreatureBase::Die()
{
	Cast<ACreatureAIController>(GetController())->SenseComp->OnPerceptionUpdated.Clear();

	Cast<ACreatureAIController>(GetController())->BBComp->SetValueAsEnum(TEXT("BehaviourKey"), EBehaviour::Dead);
}
