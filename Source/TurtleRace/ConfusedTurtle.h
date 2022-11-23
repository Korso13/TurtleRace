// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTurtle.h"
#include "ConfusedTurtle.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class TURTLERACE_API AConfusedTurtle : public ABaseTurtle
{
	GENERATED_BODY()

private:
	FTimerHandle InverseMovementTimer;

	FTimerHandle ResumeMovementTimer;

	bool bReverseMovement = false;

	void ReverseMovement();

	void ResumeMovement();

protected:
	virtual void BeginPlay() override;

	virtual void MoveForward(float DeltaTime) override;

public:
	virtual void Tick(float DeltaTime) override;

};
