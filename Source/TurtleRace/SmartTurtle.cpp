// Fill out your copyright notice in the Description page of Project Settings.


#include "SmartTurtle.h"
#include "NavigationPointer.h"

void ASmartTurtle::MoveForward(float DeltaTime)
{
	FVector Destination, TurtleLocation;
	Destination = DestinationPoint->GetActorLocation();
	TurtleLocation = this->GetActorLocation();
	Destination.Z = TurtleLocation.Z;
	FVector MovementVector = Destination - TurtleLocation;
	MovementVector.Normalize();
	this->SetActorLocation(TurtleLocation + MovementVector * Speed * DeltaTime);
}

void ASmartTurtle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (DestinationPoint)
	{
		if (DestinationPoint->GetActorLocation().X != this->GetActorLocation().X
			&& DestinationPoint->GetActorLocation().Y != this->GetActorLocation().Y)
		{
			MoveForward(DeltaTime);
		}
	}
}

