// Fill out your copyright notice in the Description page of Project Settings.

#include "FightingGameControls.h"
#include "DrawDebugHelpers.h"
#include "CliffFaceNavigator.h"


// Sets default values for this component's properties
UCliffFaceNavigator::UCliffFaceNavigator() : CliffVertices{}, CliffLedges{}
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

void UCliffFaceNavigator::GetCliffVertices(UStaticMeshComponent* cliff)
{
	if (IsValidLowLevel() && cliff && cliff->GetStaticMesh()->RenderData && cliff->GetStaticMesh()->RenderData->LODResources.Num() > 0)
	{
		FPositionVertexBuffer* VertexBuffer = &cliff->GetStaticMesh()->RenderData->LODResources[0].PositionVertexBuffer;
		if (VertexBuffer)
		{
			const int32 VertexCount = VertexBuffer->GetNumVertices();

			float redColourGradient = 0.0f;
			FColor color = FColor::Cyan;

			for (int32 Index = 0; Index < VertexCount; Index++)
			{
				redColourGradient = (float)Index / (float)(VertexCount - 1);
				if (redColourGradient >= 0.5f)
				{
					color = FColor::Red;
				}

				if (GetOwner())
				{
					//This is in the Static Mesh Actor Class, so it is location and tranform of the SMActor
					const FVector WorldSpaceVertexLocation = GetOwner()->GetActorLocation() + GetOwner()->GetTransform().TransformVector(VertexBuffer->VertexPosition(Index));
					CliffVertices.Add(WorldSpaceVertexLocation);
					DrawDebugLine(GetWorld(), WorldSpaceVertexLocation, WorldSpaceVertexLocation + FVector(0.0f, 0.0f, 10.0f), color, true);
				}
			}
		}
	}
}
