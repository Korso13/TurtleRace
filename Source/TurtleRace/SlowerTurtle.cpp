// Fill out your copyright notice in the Description page of Project Settings.


#include "SlowerTurtle.h"
#include "NavigationPointer.h"
#include "Components/AudioComponent.h"
#include "Particles/ParticleSystemComponent.h"

void ASlowerTurtle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(DestinationPoint)
	{
		if (DestinationPoint->GetActorLocation().X != this->GetActorLocation().X
			&& DestinationPoint->GetActorLocation().Y != this->GetActorLocation().Y)
		{
			MoveForward(DeltaTime);
		}
	}
	else if (MovementAudioEffect->IsPlaying())
	{
		MovementAudioEffect->Stop();
		MovementParticleEffect->DeactivateSystem();
	}
}

void ASlowerTurtle::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(MovementHaltTimer, this, &ASlowerTurtle::HaltMovement, 1.5f, true, 1.0f);
	GetWorld()->GetTimerManager().SetTimer(ResumeMovementTimer, this, &ASlowerTurtle::ResumeMovement, 1.5f, true, 1.5f);

	if (MovementAudioEffect && MovementParticleEffect)
	{
		MovementAudioEffect->Play();
		MovementParticleEffect->ActivateSystem();
	}
}

void ASlowerTurtle::HaltMovement()
{
	bShouldStop = true;

	if (MovementAudioEffect && MovementParticleEffect)
	{
		MovementAudioEffect->Stop();
		MovementParticleEffect->DeactivateSystem();
	}
}

void ASlowerTurtle::ResumeMovement()
{
	bShouldStop = false;

	if (MovementAudioEffect && MovementParticleEffect)
	{
		MovementAudioEffect->Play();
		MovementParticleEffect->ActivateSystem();
	}
}

void ASlowerTurtle::MoveForward(float DeltaTime)
{
	FVector Destination, TurtleLocation;
	Destination = DestinationPoint->GetActorLocation();
	TurtleLocation = this->GetActorLocation();
	Destination.Z = TurtleLocation.Z;
	FVector MovementVector = Destination - TurtleLocation;
	MovementVector.Normalize();
	this->SetActorLocation(TurtleLocation + MovementVector * Speed * DeltaTime * ((bShouldStop) ? 0 : 1));
}
