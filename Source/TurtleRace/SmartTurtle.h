// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTurtle.h"
#include "SmartTurtle.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class TURTLERACE_API ASmartTurtle : public ABaseTurtle
{
	GENERATED_BODY()
	
protected:
	virtual void MoveForward(float DeltaTime) override;

public:
	virtual void Tick(float DeltaTime) override;
};
