// Fill out your copyright notice in the Description page of Project Settings.


#include "AreaSpawner.h"
#include "NavigationSystem.h"
#include "SpaceFPS/Brad/Character/PlayerCharacter.h"
#include "SpaceFPS/Calgreghard/Actor/CreatureAIController.h"

AAreaSpawner::AAreaSpawner()
	: Super() {
	/*SpawnAndTriggerArea*/
	SpawnAndTriggerArea = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpawnAndTriggerArea"));
	SpawnAndTriggerArea->SetupAttachment(Root);

	ConstructorHelpers::FObjectFinder<UStaticMesh> SpawnAreaSM(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (SpawnAreaSM.Succeeded()) {
		SpawnAndTriggerArea->SetStaticMesh(SpawnAreaSM.Object);
	}

	//Set collision
	SpawnAndTriggerArea->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	SpawnAndTriggerArea->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	//Set material
	ConstructorHelpers::FObjectFinder<UMaterialInstance> SpawnAreaMat(TEXT("MaterialInstanceConstant'/Game/CalgreghardStuff/Assets/Objects/TranslusentMat/MI_Translucent.MI_Translucent'"));
	if (SpawnAreaMat.Succeeded()) {
		SpawnAndTriggerArea->SetMaterial(0, SpawnAreaMat.Object);
		SpawnAndTriggerArea->bHiddenInGame = true;

	}

	//Functionality
	SpawnAndTriggerArea->OnComponentBeginOverlap.AddDynamic(this, &AAreaSpawner::EnterArea);
	SpawnAndTriggerArea->OnComponentEndOverlap.AddDynamic(this, &AAreaSpawner::ExitArea);

	/*Tick*/
	PrimaryActorTick.TickInterval = 45.f;
}

void AAreaSpawner::BeginPlay() {
	Super::BeginPlay();

	if (SpawnCreatureClasses.Num() == 0)
		Destroy();
}

void AAreaSpawner::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	SpawnCreatures();
}

void AAreaSpawner::SpawnCreatures()
{
	Super::SpawnCreatures();

	/*Spawn parameters*/
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;

	/*Spawn in random location within bounds*/
	float spawnRadius = SpawnAndTriggerArea->GetStaticMesh()->GetBounds().BoxExtent.Size() * SpawnAndTriggerArea->GetRelativeScale3D().Size();

	TSubclassOf<ACreatureBase> SpawnCreatureClass = SpawnCreatureClasses[FMath::RandRange(0, SpawnCreatureClasses.Num() - 1)];

	int LoopLength = (SpawnCreatureClass.GetDefaultObject()->Sociality == ESociality::Pack) ?
		FMath::RandRange(SpawnCreatureClass.GetDefaultObject()->GroupSize.X, SpawnCreatureClass.GetDefaultObject()->GroupSize.Y) : 1;

	ACreatureBase* Alpha = nullptr;

	for (int i = 0; i < LoopLength; i++)
	{
		//QueryRequest.Execute(EEnvQueryRunMode::SingleResult, &ADenSpawner::EQSResult);

		FVector spawnLocation;

		if (Alpha != nullptr && SpawnCreatureClass.GetDefaultObject()->Sociality == ESociality::Pack)
			spawnLocation = GetRandomPointInNavigableRadius(GetWorld(), GetActorLocation(), spawnRadius, (ANavigationData*)0, SpawnCreatureClass.GetDefaultObject()->NavQuery);
		else
			spawnLocation = GetRandomPointInNavigableRadius(GetWorld(), GetActorLocation(), spawnRadius, (ANavigationData*)0, SpawnCreatureClass.GetDefaultObject()->NavQuery);

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

		//Creature->SetFolderPath(TEXT("Creatures/"));
	}

}

void AAreaSpawner::EnterArea(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	this->SetActorTickEnabled(true);
}

void AAreaSpawner::ExitArea(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	this->SetActorTickEnabled(false);
}