// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "SpaceFPS/Calgreghard/Actor/CreatureBase.h"
#include "CreatureAIController.generated.h"

UCLASS()
class SPACEFPS_API ACreatureAIController : public AAIController
{
	GENERATED_BODY()

public:
	/*AI components*/
	UBehaviorTreeComponent* BTComp;
	UBlackboardComponent* BBComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UAIPerceptionComponent* SenseComp;
	//Perception configs
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UAISenseConfig_Sight* SenseSight;

	ACreatureBase* ControlledCreature;

public:
	ACreatureAIController();

	virtual void OnPossess(APawn* InPawn) override;

	UFUNCTION()
	void OnPawnDetected(const TArray<AActor*>& DetectedPawns);

	virtual void GetActorEyesViewPoint(FVector& out_Location, FRotator& out_Rotation) const override;
};