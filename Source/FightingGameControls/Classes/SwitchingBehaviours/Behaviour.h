// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"
#include "Animation/AnimMontage.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Behaviour.generated.h"


struct FLinkToFollow;
class UBehaviourLink;
class ABHDefaultPawn;

/**
 * 
 */
UCLASS()
class FIGHTINGGAMECONTROLS_API UBehaviour: public UDataAsset
{
	GENERATED_BODY()

public:
	// Tries all links, returns the best one to follow and the result of the state machine that got there.
	FLinkToFollow TryLinks(const ABHDefaultPawn* RefObject, const TArray<USM_InputAtom*>& DataSource, int32 DataIndex = 0, int32 RemainingSteps = -1);

	// Animation to play while doing this move.
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName MoveName;

	// Animation to play while doing this move.
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UAnimMontage* Animation;

	// Behaviour tree to change to when doing this move.
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UObject* BehaviorTree;

	// Links from this move to others.
	UPROPERTY(EditAnywhere)
	TArray<UBehaviourLink*> LinkedMoves;

	// Clears input buffer when entering this state.
	UPROPERTY(EditAnywhere)
	uint32 bClearInputOnEntry : 1;

	// Clears input buffer when exiting this state.
	UPROPERTY(EditAnywhere)
	uint32 bClearInputOnExit : 1;
};
