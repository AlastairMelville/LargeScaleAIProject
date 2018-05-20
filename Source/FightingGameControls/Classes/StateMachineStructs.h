// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "StateMachineStructs.generated.h"


class UBehaviourLink;
struct FStateMachineResult;

USTRUCT()
struct FLinkToFollow
{
	GENERATED_BODY()

	FLinkToFollow()
	{
		Link = nullptr;
	}

	UPROPERTY()
	UBehaviourLink* Link;

	UPROPERTY()
	FStateMachineResult SMR;
};
