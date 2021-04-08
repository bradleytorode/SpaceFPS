// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatureBase.h"

void ACreatureBase::SpawnActor(FVector SpawnLocation, FRotator SpawnRotation, FActorSpawnParameters SpawnParams)
{
	ACreatureBase* Creature = GetWorld()->SpawnActor<ACreatureBase>(SpawnLocation, SpawnRotation, SpawnParams);
	GetMesh()->SetSkeletalMesh(CreatureData.SKMesh);
}
