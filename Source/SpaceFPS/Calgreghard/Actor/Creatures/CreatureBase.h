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
	/*Components*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Variables")
		FCreatureData CreatureData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBehaviorTree* BT;

	/*Variables*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int Health = 100;

public:
	ACreatureBase();

	/*Functions*/
	void SetVariables(FCreatureData CData);

	UFUNCTION(BlueprintCallable)
	void TakeDamage(int dmgAmount);

	UFUNCTION(BlueprintCallable)
	void Die();
};
