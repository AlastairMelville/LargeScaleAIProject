// Fill out your copyright notice in the Description page of Project Settings.

#include "FightingGameControls.h"
//#include "FGDefaultPawn.h"
#include "SwitchingBehaviours/BHDefaultPawn.h"
#include "SwitchingBehaviours/BHState.h"
#include "SwitchingBehaviours/BehaviourLink.h"

FStateMachineResult UBehaviourLink::TryLink(const ABHDefaultPawn* RefObject, const TArray<USM_InputAtom*>& DataSource, int32 DataIndex /*= 0*/, int32 RemainingSteps /*= -1*/)
{
	if (InputStateMachine && Move)
	{
		bool bCanCancel = false;
		for (const FVector2D& CancelWindow : CancelWindows)
		{
			if (RefObject->GetTimeInMove() == FMath::Clamp(RefObject->GetTimeInMove(), CancelWindow.X, CancelWindow.Y))
			{
				bCanCancel = true;
				break;
			}
		}
		// If no cancel windows are provided, assume the move is always available.
		if (bCanCancel || !CancelWindows.Num())
		{
			return InputStateMachine->RunState(RefObject, DataSource, DataIndex, RemainingSteps);
		}
	}
	return FStateMachineResult();
}
