// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MovingNPC.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseTurtle.generated.h"

class USkeletalMeshComponent;
class UAudioComponent;
class UParticleSystemComponent;
class USceneComponent;
class ANavigationPointer;

UCLASS(Abstract)
class TURTLERACE_API ABaseTurtle : public AActor, public IMovingNPC
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseTurtle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	USceneComponent* SceneComponent;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	USkeletalMeshComponent* TurtleBody;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UAudioComponent* MovementAudioEffect;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UParticleSystemComponent* MovementParticleEffect;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UAudioComponent* FinishAudioEffect;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UParticleSystemComponent* FinishParticleEffect;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category="Turtle Settings")
	float Speed = 150.0;

	ANavigationPointer* DestinationPoint = nullptr;

	virtual void MoveForward(float DeltaTime) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetNavigationPointer(ANavigationPointer* InPointer);

	void OnFinishSFX() const;
};
