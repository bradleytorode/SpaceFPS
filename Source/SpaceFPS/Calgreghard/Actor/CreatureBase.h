// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpaceFPS/Brad/Character/PlayerCharacter.h"
#include "SpaceFPS/Calgreghard/Libraries/EnumLibrary.h"
#include "SpaceFPS/Calgreghard/Libraries/StructLibrary.h"
#include "SpaceFPS/Calgreghard/Navigation/NavQueryFilter/AI_NavQueryFilter.h"
#include "CreatureBase.generated.h"

UCLASS(Abstract)
class SPACEFPS_API ACreatureBase : public ACharacter
{
	GENERATED_BODY()

public:
	/*Components*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBehaviorTree* BT;

	/*Variables*/
	/*UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool bifAlpha = false;*/

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int Health = 100;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int MaxHealth = 100;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int IdleLimit = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float WalkSpeed = 400.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float RunSpeed = 800.f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TEnumAsByte<EJumpHeight> JumpCapabilities = EJumpHeight::ShortJump;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TEnumAsByte<ESociality> Sociality = ESociality::Loner;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FVector2D GroupSize = FVector2D(1.f);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TSubclassOf<UAI_NavQueryFilter> NavQuery;

	ACharacter* Playerptr;

public:
	ACreatureBase();

protected:
	virtual void BeginPlay() override;
public:

	/*Functions*/
	UFUNCTION(BlueprintCallable)
	void TakeDamage(int dmgAmount);

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void Die();
};
