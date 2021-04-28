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
	UStaticMeshComponent* Target;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Variables")
	FCreatureData CreatureData;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UBehaviorTree* BT;

private:
	UPROPERTY(VisibleAnywhere)
	int Health = 100;

public:
	ACreatureBase();

	/*Getters*/
	FORCEINLINE int GetHealth() { return Health; }

	/*Functions*/
	void SetVariables(FCreatureData CData);	

	UFUNCTION(BlueprintCallable)
	void TakeDamage(int dmgNumber);

	UFUNCTION(BlueprintCallable)
	void Die();
};
