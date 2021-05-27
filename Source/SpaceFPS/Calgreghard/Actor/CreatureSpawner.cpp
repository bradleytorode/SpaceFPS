// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatureSpawner.h"
#include "NavigationSystem.h"
#include "Templates/SharedPointer.h"


// Sets default values
ACreatureSpawner::ACreatureSpawner()
{
	//Default never tick
	this->SetActorTickEnabled(false);
	PrimaryActorTick.bStartWithTickEnabled = false;

	Root = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root"));
	Root->SetupAttachment(RootComponent);

	/*Spawning EQS*/
	ConstructorHelpers::FObjectFinder<UEnvQuery> SpawnQuery(TEXT("EnvQuery'/Game/CalgreghardStuff/AI/EQS/Queries/EQS_SpawnOutOfSight.EQS_SpawnOutOfSight'"));
	if (SpawnQuery.Succeeded()) {
		SpawnLocationEQS = SpawnQuery.Object;

		QueryRequest = FEnvQueryRequest(SpawnLocationEQS, ACreatureSpawner::StaticClass());
	}

}

void ACreatureSpawner::SpawnCreatures()
{

}

void ACreatureSpawner::EQSResult(TSharedPtr<FEnvQueryResult> results)
{
	if (results.IsValid()) {
		TArray<FVector> EQSLocations;
		results.Get()->GetAllAsLocations(EQSLocations);

		spawnLocation = EQSLocations[FMath::RandRange(0.f, (float)EQSLocations.Num())];
	}
}

// Called when the game starts or when spawned
void ACreatureSpawner::BeginPlay()
{
	Super::BeginPlay();

	//SpawnCreatures();
}

// Called every frame
void ACreatureSpawner::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}

