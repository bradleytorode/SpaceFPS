// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatureAIController.h"
#include "SpaceFPS/Calgreghard/Actor/CreatureBase.h"
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
	SenseHearing = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("SenseHearing"));

	//Set perception
	SetPerceptionComponent(*SenseComp);

	//Set affiliation detection
	SenseSight->DetectionByAffiliation.bDetectEnemies = true;
	SenseSight->DetectionByAffiliation.bDetectFriendlies = true;
	SenseSight->DetectionByAffiliation.bDetectNeutrals = true;
	SenseHearing->DetectionByAffiliation.bDetectEnemies = true;
	SenseHearing->DetectionByAffiliation.bDetectFriendlies = true;
	SenseHearing->DetectionByAffiliation.bDetectNeutrals = true;

	//AI perception variables setting
	SenseComp->SetDominantSense(*SenseSight->GetSenseImplementation());
	SenseComp->OnPerceptionUpdated.AddDynamic(this, &ACreatureAIController::OnPawnDetected);

	//Configure senses
	SenseComp->ConfigureSense(*SenseSight);
	SenseComp->ConfigureSense(*SenseHearing);

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
	for (AActor* DetectedPawn : DetectedPawns) {

		ACharacter* DetectedCharacter = Cast<ACharacter>(DetectedPawn);

		if (Cast<APlayerCharacter>(DetectedCharacter)) {
			if (ControlledCreature->Predators.Find(DetectedCharacter->GetClass())) {
				BBComp->SetValueAsEnum(TEXT("BehaviourKey"), EBehaviour::Alerted);
				BBComp->SetValueAsObject(TEXT("ActivePredatorKey"), DetectedCharacter);
				BBComp->SetValueAsVector(TEXT("LastSeenLocationKey"), DetectedCharacter->GetActorLocation());

				Cast<UCharacterMovementComponent>(ControlledCreature->GetMovementComponent())->MaxWalkSpeed = ControlledCreature->RunSpeed;

				break;
			}
			else if (ControlledCreature->Prey.Find(DetectedCharacter->GetClass())) {
				BBComp->SetValueAsEnum(TEXT("BehaviourKey"), EBehaviour::Attacking);
				BBComp->SetValueAsObject(TEXT("ActivePreyKey"), DetectedCharacter);
				BBComp->SetValueAsVector(TEXT("LastSeenLocationKey"), DetectedCharacter->GetActorLocation());

				Cast<UCharacterMovementComponent>(ControlledCreature->GetMovementComponent())->MaxWalkSpeed = ControlledCreature->RunSpeed;

				break;
			}
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
