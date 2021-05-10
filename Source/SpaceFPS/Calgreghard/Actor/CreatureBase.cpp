// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatureBase.h"
#include "SpaceFPS/Calgreghard/Actor/CreatureAIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

ACreatureBase::ACreatureBase()
{
	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
}

void ACreatureBase::BeginPlay()
{
	Super::BeginPlay();

	/*Spawn paramaters*/
	FActorSpawnParameters spawnParams;
	spawnParams.Owner;

	/*Controller*/
	Controller = GetWorld()->SpawnActor<ACreatureAIController>(FVector(0.f), FRotator(0.f), spawnParams);
	Controller->Possess(this);

	Cast<ACreatureAIController>(Controller)->BBComp->SetValueAsObject(TEXT("PlayerKey"), UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = WalkSpeed;
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

		Cast<UCharacterMovementComponent>(GetMovementComponent())->MaxWalkSpeed = RunSpeed / (MaxHealth / Health);
	}
}

void ACreatureBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	Playerptr = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	if (FVector::Distance(GetActorLocation(), Playerptr->GetActorLocation()) > 7000 && !WasRecentlyRendered(1.f)) 
		SetLifeSpan(0.1f);
}

void ACreatureBase::Die()
{
	Cast<ACreatureAIController>(GetController())->SenseComp->OnPerceptionUpdated.Clear();

	Cast<ACreatureAIController>(GetController())->BBComp->SetValueAsEnum(TEXT("BehaviourKey"), EBehaviour::Dead);
}
