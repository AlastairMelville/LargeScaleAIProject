// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FindNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class FIGHTINGGAMECONTROLS_API UFindNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	

protected:
	UPROPERTY(EditAnywhere)
	struct FBlackboardKeySelector WaypointIndexKey;
};
