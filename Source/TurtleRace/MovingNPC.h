// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MovingNPC.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMovingNPC : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TURTLERACE_API IMovingNPC
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void MoveForward(float DeltaTime) = 0;
};
