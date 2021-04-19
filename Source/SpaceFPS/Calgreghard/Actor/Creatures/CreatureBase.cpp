// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatureBase.h"

void ACreatureBase::SetVariables(FCreatureData CData)
{
	CreatureData = CData;
	GetMesh()->SetSkeletalMesh(CData.SKMesh);
	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.f));
}
