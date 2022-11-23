// Fill out your copyright notice in the Description page of Project Settings.


#include "FinishLine.h"
#include "Components/BoxComponent.h"
#include "BaseTurtle.h"

// Sets default values
AFinishLine::AFinishLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	DetectionZone = CreateDefaultSubobject<UBoxComponent>("Finish detection");
	DetectionZone->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AFinishLine::BeginPlay()
{
	Super::BeginPlay();
	
	if (DetectionZone)
		DetectionZone->OnComponentBeginOverlap.AddDynamic(this, &AFinishLine::OnOverlapBegin);
}

void AFinishLine::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ABaseTurtle* Turtle = Cast<ABaseTurtle>(OtherActor);
	if (Turtle)
	{
		Turtle->OnFinishSFX();
		Turtle->SetNavigationPointer(nullptr);
	}
}

