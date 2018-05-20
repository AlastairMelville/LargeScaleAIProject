// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SM_State.h"
#include "BHInputAtoms.h"
#include "BHTreeBranch.generated.h"

/**
 * 
 */
UCLASS()
class FIGHTINGGAMECONTROLS_API UBHTreeBranch : public USM_BranchBase
{
	GENERATED_BODY()
	
public:	
	/** Consumes 2 types of input - Direction + Button(s). */
	virtual USM_State* TryBranch(const UObject* RefObject, const TArray<USM_InputAtom*>& DataSource,
		int32 DataIndex, int32 &OutDataIndex) override;

protected:
	// These buttons must be Just Pressed or Held Down. If any are checked, at least one must be Just Pressed.
	UPROPERTY(EditAnywhere, Meta = (Bitmask, BitmaskEnum = "EBodyStates"))
	int32 RequiredBodilyNeeds;

	// These buttons must all be Up.
	UPROPERTY(EditAnywhere, Meta = (Bitmask, BitmaskEnum = "EBodyStates"))
	int32 ForbiddenBodilyNeeds;

	// Required control-stick directions - at least one of these must match the current input direction.
	UPROPERTY(EditAnywhere, Meta = (Bitmask, BitmaskEnum = "ESituation"))
	int32 AcceptableSituations;
};
