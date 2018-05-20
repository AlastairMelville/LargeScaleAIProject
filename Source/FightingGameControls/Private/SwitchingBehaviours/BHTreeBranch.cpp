// Fill out your copyright notice in the Description page of Project Settings.

#include "FightingGameControls.h"
#include "FGDefaultPawn.h"
#include "SwitchingBehaviours/BHTreeBranch.h"


USM_State* UBHTreeBranch::TryBranch(const UObject* RefObject, const TArray<USM_InputAtom*>& DataSource,
	int32 DataIndex, int32 &OutDataIndex)
{
	// We deliberately do not call Super. We are 100% replacing the logic.

	OutDataIndex = DataIndex;

	if (RequiredBodilyNeeds & ForbiddenBodilyNeeds)
	{
		UE_LOG(LogTemp, Warning, TEXT("Impassable condition: Required button is also forbidden."));
		return nullptr;
	}

	// Make sure we have at least the minimum data here.
	if ((DataIndex + (int32)EBodyStates::Count) >= DataSource.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("Error: Not enough data"));
		return nullptr;
	}

	// The first piece of data must be a DirectionalInput
	if (UBHSituationInputAtom* DirectionalInput = Cast<UBHSituationInputAtom>(DataSource[DataIndex]))
	{
		if (!(AcceptableSituations & (1<<(int32)DirectionalInput->Situation)))
		{
			return nullptr;
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Error: No directional input at index %i"), DataIndex);
		return nullptr;
	}
	++OutDataIndex;

	bool bRequiredButtonPressed = false;
	for (int32 i = 0; i < (int32)EBodyStates::Count; ++i, ++OutDataIndex)
	{
		if (UBodilyNeedInputAtom* ButtonAtom = Cast<UBodilyNeedInputAtom>(DataSource[OutDataIndex]))
		{
			if (RequiredBodilyNeeds & (1<<i))
			{
				if (ButtonAtom->BodilyNeed == EBodilyNeedState::StartedCraving)
				{
					bRequiredButtonPressed = true;
					continue;
				}
				else if (ButtonAtom->BodilyNeed == EBodilyNeedState::Craving)
				{
					continue;
				}
				return nullptr;
			}
			else if (ForbiddenBodilyNeeds & (1<<i))
			{
				// Any state other than having just pressed the forbidden button is OK, even holding it down.
				if (ButtonAtom->BodilyNeed != EBodilyNeedState::Fulfilled)
				{
					continue;
				}
				return nullptr;
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Error: Expected %i button inputs, only found %i."), (int32)EBodyStates::Count, i);
			return nullptr;
		}
	}
	// If there were any required buttons, make sure at least one of them was just pressed.
	if (RequiredBodilyNeeds && !bRequiredButtonPressed)
	{
		return nullptr;
	}

	return DestinationState;
}
