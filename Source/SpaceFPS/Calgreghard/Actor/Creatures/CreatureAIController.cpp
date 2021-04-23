// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatureAIController.h"
#include "SpaceFPS/Calgreghard/Actor/Creatures/CreatureBase.h"

ACreatureAIController::ACreatureAIController()
{
	/*Initialise AI*/
	BTComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BTComp"));
	BBComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BBComp"));

	SenseComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("SenseComp"));

	SenseSight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SenseSight"));
	
	SetPerceptionComponent(*SenseComp);

	GetPerceptionComponent()->ConfigureSense(*SenseSight);
}


void ACreatureAIController::OnPossess(APawn* InPawn) {
	Super::OnPossess(InPawn);

	ControlledCreature = Cast<ACreatureBase>(InPawn);

	if (ControlledCreature) {
		if (ControlledCreature->BT->BlackboardAsset) {
			BBComp->InitializeBlackboard(*(ControlledCreature->BT->BlackboardAsset));
		}

		BTComp->StartTree(*ControlledCreature->BT);

	}
}

void ACreatureAIController::GetActorEyesViewPoint(FVector& out_Location, FRotator& out_Rotation) const
{
	if (ControlledCreature) {
		FTransform EyesTransform = ControlledCreature->GetMesh()->GetSocketTransform(TEXT("EyeSocket"));

		out_Location = EyesTransform.GetLocation();
		out_Rotation = EyesTransform.GetRotation().Rotator();
	}
}
