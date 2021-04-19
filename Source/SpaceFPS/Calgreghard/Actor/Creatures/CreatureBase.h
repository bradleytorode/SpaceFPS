// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpaceFPS/Calgreghard/Libraries/StructLibrary.h"
#include "CreatureBase.generated.h"

UCLASS()
class SPACEFPS_API ACreatureBase : public ACharacter
{
	GENERATED_BODY()

public:
	/*Variables*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Variables")
		FCreatureData CreatureData;

public:
	/*Functions*/
	void SetVariables(FCreatureData CData);
};
