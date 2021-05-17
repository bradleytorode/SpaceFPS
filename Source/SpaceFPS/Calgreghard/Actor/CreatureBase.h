// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpaceFPS/Brad/Character/PlayerCharacter.h"
#include "SpaceFPS/Brad/Inventory/InventoryComponent.h"
#include "SpaceFPS/Calgreghard/Libraries/EnumLibrary.h"
#include "SpaceFPS/Calgreghard/Libraries/StructLibrary.h"
#include "SpaceFPS/Calgreghard/Navigation/NavQueryFilter/AI_NavQueryFilter.h"
#include "Components/SphereComponent.h"
#include "CreatureBase.generated.h"

UCLASS(Abstract)
class SPACEFPS_API ACreatureBase : public ACharacter
{
	GENERATED_BODY()

public:
	/*Components*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBehaviorTree* BT;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UInventoryComponent* Inventory;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USphereComponent* DamageBox;

	/*Variables*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int Health = 10;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int MaxHealth = 100;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int IdleLimit = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		int Damage = 10.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float WalkSpeed = 400.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float RunSpeed = 800.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TArray<class TSubclassOf<ACharacter>> Predators;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		TArray<class TSubclassOf<ACharacter>> Prey;
	
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

	UFUNCTION(BlueprintCallable)
		void DoDamage(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
