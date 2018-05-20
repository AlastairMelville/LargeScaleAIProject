// Fill out your copyright notice in the Description page of Project Settings.

#include "FightingGameControls.h"
#include "FGInputAtoms.h"
#include "SwitchingBehaviours/BHState.h"


FStateMachineResult UBHState::LoopState(const UObject* RefObject,
	const TArray<USM_InputAtom*>& DataSource, int32 DataIndex, int32 RemainingSteps)
{
	return RunState(RefObject, DataSource, DataIndex + 1 + (int32)EFGInputButtons::Count, RemainingSteps - 1);
}
