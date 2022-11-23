// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurtleCaveSpawner.generated.h"

class ABaseTurtle;
class ANavigationPointer;
class UAudioComponent;
class UParticleSystemComponent;
class USceneComponent;
class UArrowComponent;
class UStaticMeshComponent;

UCLASS(Abstract)
class TURTLERACE_API ATurtleCaveSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurtleCaveSpawner();

private:
	ABaseTurtle* SpawnedTurtle;

	void PlaySpawnSFX();

	FTimerHandle SFXStopTimer;
	FTimerDelegate SFXStopDelegate;

protected:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	USceneComponent* SceneComponent;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UStaticMeshComponent* CaveMesh;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UArrowComponent* SpawnPoint;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UAudioComponent* SpawnAudioEffect;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UParticleSystemComponent* SpawnParticleEffect;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<ABaseTurtle> TurtleClassType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ANavigationPointer* DestinationPoint;

public:	

	UFUNCTION(BlueprintCallable)
	void SpawnTurtle();
};
