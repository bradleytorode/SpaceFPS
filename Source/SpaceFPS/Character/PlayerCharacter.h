// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Containers/Array.h"
#include "Inventory/InventoryComponent.h"
#include "PlayerCharacter.generated.h"


UCLASS()
class SPACEFPS_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	//The Camera component the player will see.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Mesh)
	class USkeletalMeshComponent* PlayerMesh;

	UPROPERTY(VisibleAnywhere, Category = Mesh)
	class USkeletalMeshComponent* Weapon;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory)
	class UInventoryComponent* Inventory;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Health;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<AItemBase*> ItemsInRange;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Movement Functions
	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Value);
	void LookUpAtRate(float Value);


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
		float BaseTurnRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
		float BaseLookUpRate;

	//Inventroy Functions
	void Interact();

	void PickupItem();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
