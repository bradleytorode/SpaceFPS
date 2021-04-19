// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatureSpawner.h"
#include "NavigationSystem.h"

// Sets default values
ACreatureSpawner::ACreatureSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SpawnArea = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpawnArea"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> SpawnAreaSM(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	if (SpawnAreaSM.Succeeded()) {
		SpawnArea->SetStaticMesh(SpawnAreaSM.Object);

		SpawnArea->SetRelativeLocation(FVector(0.f));

		SpawnArea->SetCollisionProfileName(TEXT("NoCollision"));

		SpawnArea->bHiddenInGame = true;
	
		ConstructorHelpers::FObjectFinder<UMaterialInstance> SpawnAreaMat(TEXT("MaterialInstanceConstant'/Game/CalgreghardStuff/Assets/Objects/TranslusentMat/MI_Translucent.MI_Translucent'"));
		if (SpawnAreaMat.Succeeded()) {
			SpawnArea->SetMaterial(0, SpawnAreaMat.Object);
		}
	}


	ConstructorHelpers::FObjectFinder<UDataTable> CreatureDT(TEXT("DataTable'/Game/CalgreghardStuff/Database/DT_Creatures.DT_Creatures'"));
	if (CreatureDT.Succeeded()) {
		DTReference = CreatureDT.Object;
	}
}

// Called when the game starts or when spawned
void ACreatureSpawner::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;

	/*Set spawn creature*/
	FString RowNameString = UEnum::GetValueAsString(RowNameEnum.GetValue());

	RowName = (FName)RowNameString;

	SpawnCreatureData = *DTReference->FindRow<FCreatureData>(RowName, FString(""));

	float spawnRadius = 100 * SpawnArea->GetRelativeScale3D().Size();

	FVector spawnLocation = Cast<UNavigationSystemV1>(GetWorld()->GetNavigationSystem())->GetRandomPointInNavigableRadius(GetWorld(), GetActorLocation(), spawnRadius);

	CreaturesArray.Add(GetWorld()->SpawnActor<ACreatureBase>(spawnLocation, FRotator(0.f, 0.f, 0.f), SpawnParams));

	CreaturesArray[0]->SetVariables(SpawnCreatureData);
	
}

// Called every frame
void ACreatureSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

