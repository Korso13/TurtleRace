// Fill out your copyright notice in the Description page of Project Settings.


#include "TurtleCaveSpawner.h"
#include "BaseTurtle.h"
#include "Components/AudioComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SceneComponent.h"
#include "NavigationPointer.h"
#include "Components/ArrowComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATurtleCaveSpawner::ATurtleCaveSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Cave scene"));
	RootComponent = SceneComponent;
	CaveMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cave mesh"));
	CaveMesh->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SpawnPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("Spawn Point"));
	SpawnPoint->AttachToComponent(CaveMesh, FAttachmentTransformRules::KeepRelativeTransform);
	SpawnAudioEffect = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio played on spawn"));
	SpawnAudioEffect->SetupAttachment(SceneComponent);
	SpawnParticleEffect = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("VSFX played on spawn"));
	SpawnParticleEffect->SetupAttachment(SceneComponent);
}

void ATurtleCaveSpawner::PlaySpawnSFX()
{
	if (SpawnAudioEffect && SpawnParticleEffect)
	{
		SpawnAudioEffect->Play();
		SpawnParticleEffect->ActivateSystem();
		SFXStopDelegate.BindLambda([&]() {SpawnParticleEffect->DeactivateSystem(); });
		GetWorld()->GetTimerManager().SetTimer(SFXStopTimer, SFXStopDelegate, 1.0f, false, -1.0f);
	}
}

void ATurtleCaveSpawner::SpawnTurtle()
{
	//GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Green, "PlayingSFX");
	if (TurtleClassType && DestinationPoint)
	{
		SpawnedTurtle = Cast<ABaseTurtle>(GetWorld()->SpawnActorDeferred<ABaseTurtle>(TurtleClassType, SpawnPoint->GetComponentTransform(), this, nullptr, ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding));
		SpawnedTurtle->SetNavigationPointer(DestinationPoint);
		UGameplayStatics::FinishSpawningActor(SpawnedTurtle, SpawnPoint->GetComponentTransform());
		PlaySpawnSFX();
	}
}

