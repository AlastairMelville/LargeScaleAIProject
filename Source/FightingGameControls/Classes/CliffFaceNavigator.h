// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CliffFaceNavigator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIGHTINGGAMECONTROLS_API UCliffFaceNavigator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCliffFaceNavigator();

	UFUNCTION(BlueprintCallable)
	void GetCliffVertices(UStaticMeshComponent* cliff);

private:
	UPROPERTY(EditAnywhere)
	TArray<FVector> CliffVertices;

	TArray<FVector> CliffLedges;
};
