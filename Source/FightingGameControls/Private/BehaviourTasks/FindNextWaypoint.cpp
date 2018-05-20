// Fill out your copyright notice in the Description page of Project Settings.

#include "FightingGameControls.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviourTasks/FindNextWaypoint.h"


EBTNodeResult::Type UFindNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* blackboardComponent = OwnerComp.GetBlackboardComponent();
	int32 waypointIndex = blackboardComponent->GetValueAsInt(WaypointIndexKey.SelectedKeyName);

	return EBTNodeResult::Succeeded;
}
