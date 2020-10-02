// Fill out your copyright notice in the Description page of Project Settings.


#include "ArmPivot.h"
#include "RobotArmMode.h"

// Sets default values
AArmPivot::AArmPivot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
AArmPivot::AArmPivot(FVector Geometry, FVector minLimit, FVector maxLimit)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->Geometry = Geometry;
	this->minLimit = minLimit;
	this->maxLimit = maxLimit;

}
bool AArmPivot::SetTheta(FVector NewState)
{	
	if (NewState.X < this->minLimit.X || NewState.X > this->maxLimit.X)
		return false;
	else if (NewState.Y < this->minLimit.Y || NewState.Y > this->maxLimit.Y)
		return false;
	else if (NewState.Z < this->minLimit.Z || NewState.Z > this->maxLimit.Z)
		return false;

	SetActorRotation(FQuat::MakeFromEuler(NewState));

	return true;
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

