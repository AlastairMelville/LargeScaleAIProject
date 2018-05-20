// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SM_State.h"
#include "BHInputAtoms.generated.h"

UENUM(Blueprintable, meta = (BitFlags))
enum class ESituation : uint8
{
	Loving,
	Kind,
	Friendly,
	Boring,
	Neutral,
	Uncomfortable,
	Frustrating,
	Aggressive,
	Dangerous
};

//UENUM(Blueprintable, Meta = (Bitflags))
//enum class EHungerState : uint8 
//{
//	Full,
//	Peckish,
//	Hungry,
//	Starving
//};
//
//UENUM(Blueprintable, meta = (BitFlags))
//enum class EEnergyState : uint8
//{
//	Sleepy,
//	Tired,
//	Normal,
//	Energetic
//};

UENUM(Blueprintable, meta = (BitFlags))
enum class EBodyStates : uint8
{
	Hunger,
	Energy,
	Count UMETA(Hidden)
};

UENUM()
enum class EBodilyNeedState : uint8
{
	Fulfilled,
	StartedCraving,
	Craving,
	Count UMETA(Hidden)
};

/**
*
*/
UCLASS()
class FIGHTINGGAMECONTROLS_API UBodilyNeedInputAtom : public USM_InputAtom
{
	GENERATED_BODY()

public:
	// State of hunger.
	UPROPERTY(EditAnywhere)
	EBodilyNeedState BodilyNeed; // Motivation
};

/**
*
*/
UCLASS()
class FIGHTINGGAMECONTROLS_API UBHSituationInputAtom : public USM_InputAtom
{
	GENERATED_BODY()

public:
	// State of energy.
	UPROPERTY(EditAnywhere)
	ESituation Situation;
};
