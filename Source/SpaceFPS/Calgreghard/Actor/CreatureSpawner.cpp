// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatureSpawner.h"
#include "NavigationSystem.h"

// Sets default values
ACreatureSpawner::ACreatureSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	/*Spawn area*/
	SpawnArea = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpawnArea"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> SpawnAreaSM(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	if (SpawnAreaSM.Succeeded()) {
		SpawnArea->SetStaticMesh(SpawnAreaSM.Object);
	}

	//Set default variables
	SpawnArea->SetCollisionProfileName(TEXT("NoCollision"));
	SpawnArea->bHiddenInGame = true;

	//Set material
	ConstructorHelpers::FObjectFinder<UMaterialInstance> SpawnAreaMat(TEXT("MaterialInstanceConstant'/Game/CalgreghardStuff/Assets/Objects/TranslusentMat/MI_Translucent.MI_Translucent'"));
	if (SpawnAreaMat.Succeeded()) {
		SpawnArea->SetMaterial(0, SpawnAreaMat.Object);
	}

	/*Creatures database*/
	ConstructorHelpers::FObjectFinder<UDataTable> CreatureDT(TEXT("DataTable'/Game/CalgreghardStuff/Database/DT_Creatures.DT_Creatures'"));
	if (CreatureDT.Succeeded()) {
		DTReference = CreatureDT.Object;
	}
}

void ACreatureSpawner::SpawnCreatures()
{
	/*Spawn parameters*/
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;


	/*Spawn in random location within bounds*/
	float spawnRadius = SpawnArea->GetStaticMesh()->GetBounds().BoxExtent.Size();

	FVector spawnLocation = Cast<UNavigationSystemV1>(GetWorld()->GetNavigationSystem())->GetRandomPointInNavigableRadius(GetWorld(), GetActorLocation(), spawnRadius, (ANavigationData*)0, CreaturesToSpawnClass[0].GetDefaultObject()->CreatureData.NavQuery);

	for (int i = 0; i < CreaturesToSpawnClass.Num(); i++)
	{
		int LoopLength = 1;
		if (CreaturesToSpawnClass[0].GetDefaultObject()->CreatureData.Sociality == ESociality::Pack)
			LoopLength = FMath::RandRange(3.f, 5.f);

		for (int j = 0; j < LoopLength; j++)
		{
			ACreatureBase* Creature = GetWorld()->SpawnActor<ACreatureBase>(CreaturesToSpawnClass[i], spawnLocation, FRotator(0.f, 0.f, 0.f), SpawnParams);
			Creature->AddActorWorldRotation(FRotator(0.f, FMath::RandRange(0.f, 360.f), 0.f));
			CreaturesArray.Add(Creature);
		}
	}
}

// Called when the game starts or when spawned
void ACreatureSpawner::BeginPlay()
{
	Super::BeginPlay();

	SpawnCreatures();
}

// Called every frame
void ACreatureSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

