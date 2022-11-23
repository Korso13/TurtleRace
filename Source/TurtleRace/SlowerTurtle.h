// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTurtle.h"
#include "SlowerTurtle.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class TURTLERACE_API ASlowerTurtle : public ABaseTurtle
{
	GENERATED_BODY()
	
private:
	FTimerHandle MovementHaltTimer;

	FTimerHandle ResumeMovementTimer;

	bool bShouldStop = false;

	void HaltMovement();

	void ResumeMovement();

protected:
	virtual void BeginPlay() override;

	virtual void MoveForward(float DeltaTime) override;

public:
	virtual void Tick(float DeltaTime) override; 
};
