// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "AIController.h"
#include "PatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	//Get points
	APawn* ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();	
	UPatrolRoute* PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();

	if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }

	TArray<AActor*> PatrollPoints = PatrolRoute->GetPatrolPoints();
	if (PatrollPoints.Num() == 0) { return EBTNodeResult::Failed; }

	//set waypoint
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32 Index = BlackboardComp->GetValueAsInt(_Index.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrollPoints[Index]);

	int32 NextIndex = ++Index % PatrollPoints.Num();
	BlackboardComp->SetValueAsInt(_Index.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;
}
