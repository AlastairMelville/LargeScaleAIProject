// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SM_State.h"
#include "BHState.generated.h"

/**
 * 
 */
UCLASS()
class FIGHTINGGAMECONTROLS_API UBHState : public USM_State
{
	GENERATED_BODY()
	

public:
	virtual FStateMachineResult LoopState(const UObject* RefObject, const TArray<USM_InputAtom *>& DataSource, int32 DataIndex, int32 RemainingSteps);
};
