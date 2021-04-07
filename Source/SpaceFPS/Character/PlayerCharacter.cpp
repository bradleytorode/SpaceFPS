// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"



// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set Collision Component size
	GetCapsuleComponent()->InitCapsuleSize(55.0f, 90.0f);

	//Setting up Spring Arm
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArm->SetupAttachment(RootComponent);

	//Create the Camera
<<<<<<< HEAD:Source/SpaceFPS/PlayerCharacter.cpp
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
=======
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
	CameraComponent->SetupAttachment(SpringArm);

	//Setting up a skeletal mesh for arms which will be implemented later
	PlayerMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("PlayerMesh"));
	PlayerMesh->SetupAttachment(RootComponent);
>>>>>>> Bradley-Branch:Source/SpaceFPS/Character/PlayerCharacter.cpp

	//Setting default turn and lookup rates
	BaseTurnRate = 45.0f;
	BaseLookUpRate = 45.0f;
	
	
	//Setting up a skeletal mesh for a weapon implemented later on.
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	Weapon->SetOnlyOwnerSee(true);	// only the owning player will see this mesh
	Weapon->bCastDynamicShadow = false;
	Weapon->CastShadow = false;
	//Weapon->SetupAttachment("PlayerHandSocket");

	Inventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));

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
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &APlayerCharacter::Interact);
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &APlayerCharacter::PickupItem);
	
	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);

	PlayerInputComponent->BindAxis("TurnRate", this, &APlayerCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &APlayerCharacter::LookUpAtRate);

}

void APlayerCharacter::MoveForward(float Value)
{
	if ((Controller) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);

	}
}

void APlayerCharacter::MoveRight(float Value)
{
	if ((Controller) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void APlayerCharacter::TurnAtRate(float Value)
{
	AddControllerYawInput(Value * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void APlayerCharacter::LookUpAtRate(float Value)
{
	AddControllerPitchInput(Value * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void APlayerCharacter::Interact()
{

}

void APlayerCharacter::PickupItem()
{
	//GetCapsuleComponent()->BeginComponentOverlap(OverlapInfo,
}
