// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatureSpawner.h"
#include "NavigationSystem.h"
#include "Templates/SharedPointer.h"


// Sets default values
ACreatureSpawner::ACreatureSpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root"));
	Root->SetupAttachment(RootComponent);

	/*Spawn area*/
	SpawnArea = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpawnArea"));
	SpawnArea->SetupAttachment(Root);

	ConstructorHelpers::FObjectFinder<UStaticMesh> SpawnAreaSM(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	if (SpawnAreaSM.Succeeded()) {
		SpawnArea->SetStaticMesh(SpawnAreaSM.Object);
	}

	//Set default variables
	SpawnArea->SetCollisionProfileName(TEXT("NoCollision"), false);
	SpawnArea->bHiddenInGame = true;

	//Set material
	ConstructorHelpers::FObjectFinder<UMaterialInstance> SpawnAreaMat(TEXT("MaterialInstanceConstant'/Game/CalgreghardStuff/Assets/Objects/TranslusentMat/MI_Translucent.MI_Translucent'"));
	if (SpawnAreaMat.Succeeded()) {
		SpawnArea->SetMaterial(0, SpawnAreaMat.Object);
	}

	/*Trigger zone*/
	TriggerZone = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TriggerZone"));
	TriggerZone->SetupAttachment(Root);

	TriggerZone->SetVisibility(false);
	TriggerZone->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	TriggerZone->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	/*Creatures database*/
	ConstructorHelpers::FObjectFinder<UDataTable> CreatureDT(TEXT("DataTable'/Game/CalgreghardStuff/Database/DT_Creatures.DT_Creatures'"));
	if (CreatureDT.Succeeded()) {
		DTReference = CreatureDT.Object;
	}

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
void ACreatureSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

