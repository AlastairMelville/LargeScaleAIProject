// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraActor.h"
#include "FGCameraActor.generated.h"

/**
 * 
 */
UCLASS()
class FIGHTINGGAMECONTROLS_API AFGCameraActor : public ACameraActor
{
	GENERATED_BODY()
	
public:
	AFGCameraActor();
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY()
	AActor* PlayerOne;

	UPROPERTY()
	AActor* PlayerTwo;

	UPROPERTY()
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
	float VerticalOffset;
};
