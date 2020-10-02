// Fill out your copyright notice in the Description page of Project Settings.


#include "ArmPivot.h"

// Sets default values
AArmPivot::AArmPivot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AArmPivot::BeginPlay()
{
	Super::BeginPlay();
	TArray< AActor* > tempChildActors;
	AActor* owner = GetOwner();
	GetAttachedActors(tempChildActors, true);

	uint32 count = 0;
	count = tempChildActors.Num();
	UE_LOG(LogTemp, Log, TEXT("Attached count %d"), count);
	

	this->t = 0;
}

// Called every frame
void AArmPivot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->t += DeltaTime;

	if (IsSelected())
		SetActorRotation(FQuat::MakeFromEuler(FVector(20 * sin(this->t), 0, 0)));
}

