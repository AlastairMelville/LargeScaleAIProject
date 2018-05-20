// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "FightingGameControlsGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FIGHTINGGAMECONTROLS_API AFightingGameControlsGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	virtual void StartPlay() override;

	void SpawnSecondPlayer();

	// This will be spawned when the game starts.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ACameraActor* MainGameCamera;
};
