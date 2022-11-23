// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTurtle.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/AudioComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SceneComponent.h"
#include "NavigationPointer.h"

// Sets default values
ABaseTurtle::ABaseTurtle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Turtle scene"));
	RootComponent = SceneComponent;
	TurtleBody = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Turtle mesh"));
	TurtleBody->SetupAttachment(RootComponent);
	MovementAudioEffect = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio played on movement"));
	MovementAudioEffect->SetupAttachment(TurtleBody);
	MovementParticleEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("VSFX played on movement"));
	MovementParticleEffect->SetupAttachment(TurtleBody);
	FinishAudioEffect = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio played on finish"));
	FinishAudioEffect->SetupAttachment(TurtleBody);
	FinishParticleEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("VSFX played on finish"));
	FinishParticleEffect->SetupAttachment(TurtleBody);
}

// Called when the game starts or when spawned
void ABaseTurtle::BeginPlay()
{
	Super::BeginPlay();
	
	if (MovementAudioEffect && MovementParticleEffect)
	{
		MovementAudioEffect->Play();
		MovementParticleEffect->ActivateSystem();
	}
}

// Called every frame
void ABaseTurtle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseTurtle::SetNavigationPointer(ANavigationPointer* InPointer)
{
	DestinationPoint = InPointer;
}

void ABaseTurtle::OnFinishSFX() const
{
	if (FinishAudioEffect && FinishParticleEffect)
	{
		FinishAudioEffect->Play();
		FinishParticleEffect->ActivateSystem();
	}
	if (MovementAudioEffect && MovementParticleEffect)
	{
		MovementAudioEffect->Stop();
		MovementParticleEffect->DeactivateSystem();
	}
}

void ABaseTurtle::MoveForward(float DeltaTime)
{
	return;
}