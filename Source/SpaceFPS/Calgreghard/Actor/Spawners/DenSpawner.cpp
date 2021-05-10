// Fill out your copyright notice in the Description page of Project Settings.


#include "DenSpawner.h"
#include "NavigationSystem.h"
#include "SpaceFPS/Brad/Character/PlayerCharacter.h"
#include "SpaceFPS/Calgreghard/Actor/CreatureAIController.h"


ADenSpawner::ADenSpawner() 
	: Super() {

	TriggerZone->OnComponentBeginOverlap.AddDynamic(this, &ADenSpawner::EnterTriggerArea);
}

void ADenSpawner::SpawnCreatures() {
	Super::SpawnCreatures(); //Super

	/*Spawn parameters*/
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;

	/*Spawn in random location within bounds*/
	float spawnRadius = SpawnArea->GetStaticMesh()->GetBounds().BoxExtent.Size() * SpawnArea->GetRelativeScale3D().Size();

	int LoopLength = (SpawnCreatureClass.GetDefaultObject()->Sociality == ESociality::Pack) ?
		FMath::RandRange(SpawnCreatureClass.GetDefaultObject()->GroupSize.X, SpawnCreatureClass.GetDefaultObject()->GroupSize.Y) : 1;

	ACreatureBase* Alpha = nullptr;

	for (int i = 0; i < LoopLength; i++)
	{
		//QueryRequest.Execute(EEnvQueryRunMode::SingleResult, &ADenSpawner::EQSResult);

		FVector spawnLocation;

		if (Alpha != nullptr && SpawnCreatureClass.GetDefaultObject()->Sociality == ESociality::Pack)
			spawnLocation = Cast<UNavigationSystemV1>(GetWorld()->GetNavigationSystem())->GetRandomPointInNavigableRadius(
				GetWorld(), Alpha->GetActorLocation(), spawnRadius / 2, (ANavigationData*)0, SpawnCreatureClass.GetDefaultObject()->NavQuery);
		else
			spawnLocation = Cast<UNavigationSystemV1>(GetWorld()->GetNavigationSystem())->GetRandomPointInNavigableRadius(
				GetWorld(), GetActorLocation(), spawnRadius, (ANavigationData*)0, SpawnCreatureClass.GetDefaultObject()->NavQuery);

		ACreatureBase* Creature = GetWorld()->SpawnActor<ACreatureBase>(SpawnCreatureClass, spawnLocation, FRotator(0.f, 0.f, 0.f), SpawnParams);

		if (Creature != nullptr)
		{
			Creature->AddActorWorldRotation(FRotator(0.f, FMath::RandRange(0.f, 360.f), 0.f));
			CreaturesArray.Add(Creature);

			if (i == 0 && SpawnCreatureClass.GetDefaultObject()->Sociality == ESociality::Pack) {
				Creature->GetMesh()->SetRelativeScale3D(FVector(1.2f));
				Cast<ACreatureAIController>(Creature->Controller)->BBComp->SetValueAsObject(TEXT("AlphaCreatureKey"), Creature);
				Alpha = Creature;
			}
			else if (Alpha && SpawnCreatureClass.GetDefaultObject()->Sociality == ESociality::Pack) {
				Cast<ACreatureAIController>(Creature->Controller)->BBComp->SetValueAsObject(TEXT("AlphaCreatureKey"), Cast<UObject>(Alpha));
			}
		}
	}
}

void ADenSpawner::EnterTriggerArea(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<APlayerCharacter>(OtherActor) && (CreaturesArray.Num() < SpawnCreatureClass.GetDefaultObject()->GroupSize.Y || !CreaturesArray.IsValidIndex(0)))
		SpawnCreatures();
}

void ADenSpawner::BeginPlay()
{
	if (!SpawnCreatureClass)
		Destroy();

	Super::BeginPlay();

	/*Set trigger zone variables*/
	TriggerZone->SetStaticMesh(SpawnArea->GetStaticMesh());
	TriggerZone->GetStaticMesh()->SetMaterial(0, SpawnArea->GetMaterial(0));
	TriggerZone->SetRelativeScale3D(FVector(SpawnArea->GetRelativeScale3D().X * 1.5f));

}
