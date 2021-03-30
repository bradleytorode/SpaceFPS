// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set Collision Component size
	GetCapsuleComponent()->InitCapsuleSize(55.0f, 90.0f);

	//Create the Camera
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	CameraComponent->SetupAttachment(GetCapsuleComponent());
<<<<<<< HEAD
	CameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f));
=======
	//CameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
>>>>>>> Callum-Branch
	CameraComponent->bUsePawnControlRotation = true;

	//Setting up a skeletal mesh for arms which will be implemented later
	PlayerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PlayerMesh"));
	PlayerMesh->SetOnlyOwnerSee(true);
	PlayerMesh->SetupAttachment(CameraComponent);
	PlayerMesh->bCastDynamicShadow = false;
<<<<<<< HEAD
	PlayerMesh->CastShadow = false;
	//PlayerMesh->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	//PlayerMesh->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));
=======
	PlayerMesh->CastShadow = false;/*
	PlayerMesh->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
	PlayerMesh->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);*/
>>>>>>> Callum-Branch

	//Setting up a skeletal mesh for a weapon implemented later on.
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetOnlyOwnerSee(true);	// only the owning player will see this mesh
	Weapon->bCastDynamicShadow = false;
	Weapon->CastShadow = false;
	//Weapon->SetupAttachment("PlayerHandSocket");


}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}



// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Check that the input component exists
	check(PlayerInputComponent);

	//Bind Jump event
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	
	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &ACharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &ACharacter::AddControllerYawInput);
}

void APlayerCharacter::MoveForward(float val)
{
	if (val != 0.0f)
	{
		// add movement in forward/backward direction
		AddMovementInput(GetActorForwardVector(), val);
	}
}

void APlayerCharacter::MoveRight(float val)
{
	if (val != 0.0f)
	{
		// add movement left/right direction
		AddMovementInput(GetActorRightVector(), val);
	}
}