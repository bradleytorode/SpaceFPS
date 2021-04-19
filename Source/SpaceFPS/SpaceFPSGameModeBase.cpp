// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceFPSGameModeBase.h"
#include "SpaceFPS/Brad/Character/PlayerCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASpaceFPSGameModeBase::ASpaceFPSGameModeBase()
	: Super()
{
	//Set deault pawn to PlayerCharacter_BP
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Character/BP_PlayerCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
	*/
}