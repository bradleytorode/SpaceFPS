// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatureAIController.h"
#include "SpaceFPS/Calgreghard/Actor/Creatures/CreatureBase.h"
#include "SpaceFPS/Brad/Character/PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


ACreatureAIController::ACreatureAIController()
{
	/*Initialise AI behaviour tree and blackboard*/
	BTComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BTComp"));
	BBComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BBComp"));

	//Make ai perception components
	SenseComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("SenseComp"));
	SenseSight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SenseSight"));

	//Set perception
	SetPerceptionComponent(*SenseComp);

	//Set affiliation detection
	SenseSight->DetectionByAffiliation.bDetectEnemies = true;
	SenseSight->DetectionByAffiliation.bDetectFriendlies = true;
	SenseSight->DetectionByAffiliation.bDetectNeutrals = true;

	//AI perception variables setting
	SenseComp->SetDominantSense(*SenseSight->GetSenseImplementation());
	SenseComp->OnPerceptionUpdated.AddDynamic(this, &ACreatureAIController::OnPawnDetected);

	//Configure senses
	SenseComp->ConfigureSense(*SenseSight);

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

void ACreatureAIController::OnPawnDetected(const TArray<AActor*>& DetectedPawns)
{
	for (AActor * actor : DetectedPawns) {
		ACharacter* character = Cast<ACharacter>(actor);
		if (Cast<APlayerCharacter>(character)) {
			BBComp->SetValueAsEnum(TEXT("BehaviourKey"), EBehaviour::Alerted);

			Cast<UCharacterMovementComponent>(ControlledCreature->GetMovementComponent())->MaxWalkSpeed = ControlledCreature->CreatureData.runSpeed;
		}
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
