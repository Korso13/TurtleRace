// Fill out your copyright notice in the Description page of Project Settings.


#include "ConfusedTurtle.h"
#include "NavigationPointer.h"
#include "Components/AudioComponent.h"
#include "Particles/ParticleSystemComponent.h"

void AConfusedTurtle::ReverseMovement()
{
	bReverseMovement = true;
}

void AConfusedTurtle::ResumeMovement()
{
	bReverseMovement = false;
}

void AConfusedTurtle::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(InverseMovementTimer, this, &AConfusedTurtle::ReverseMovement, 1.5f, true, 1.0f);
	GetWorld()->GetTimerManager().SetTimer(ResumeMovementTimer, this, &AConfusedTurtle::ResumeMovement, 1.5f, true, 1.5f);

	if (MovementAudioEffect && MovementParticleEffect)
	{
		MovementAudioEffect->Play();
		MovementParticleEffect->ActivateSystem();
	}
}

void AConfusedTurtle::MoveForward(float DeltaTime)
{
	FVector Destination, TurtleLocation;
	Destination = DestinationPoint->GetActorLocation();
	TurtleLocation = this->GetActorLocation();
	Destination.Z = TurtleLocation.Z;
	FVector MovementVector = Destination - TurtleLocation;
	if (bReverseMovement)
	{
		MovementVector.X = -MovementVector.X;
		MovementVector.Y = -MovementVector.Y;
	}
	MovementVector.Normalize();
	this->SetActorLocation(TurtleLocation + MovementVector * Speed * DeltaTime);
}

void AConfusedTurtle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(DestinationPoint)
	{
		if (DestinationPoint->GetActorLocation().X != this->GetActorLocation().X
			&& DestinationPoint->GetActorLocation().Y != this->GetActorLocation().Y)
		{
			MoveForward(DeltaTime);
		}
		else
		{
			GetWorld()->GetTimerManager().PauseTimer(InverseMovementTimer);
			GetWorld()->GetTimerManager().PauseTimer(ResumeMovementTimer);
		}
	}
}
