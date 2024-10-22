// Fill out your copyright notice in the Description page of Project Settings.


#include "ArmJoint.h"
#include "RenderCore.h"

// Sets default values

AArmJoint::AArmJoint() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AArmJoint::AArmJoint(FVector Geometry, bool isTelescopic, FVector minLimit, FVector maxLimit, FVector Extension){
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->Geometry = Geometry;
	this->isTelescopic = isTelescopic;
	this->minLimit = minLimit;
	this->maxLimit = maxLimit;
	this->Extension = Extension;


}

bool AArmJoint::SetExtension(FVector NewState)
{
	if (NewState.X >= this->Extension.X)
		return false;
	else if (NewState.Y >= this->Extension.Y)
		return false;
	else if (NewState.Z >= this->minLimit.Z)
		return false;

	// TODO: Add extension new state

	return true;
}


// Called when the game starts or when spawned
void AArmJoint::BeginPlay()
{
	Super::BeginPlay();
	FVector Location = GetActorLocation();
	UE_LOG(LogTemp, Error, TEXT("Log error %f"), Location.X);
	this->t = 0;

	TArray< AActor* > tempChildActors, tempAttachedActors;
	AActor* owner = GetOwner();
	owner->GetAllChildActors(tempChildActors, true);
	GetAttachedActors(tempAttachedActors, true);

	uint32 count = tempChildActors.Num();
	uint32 countAttached = tempAttachedActors.Num();
	UE_LOG(LogTemp, Log, TEXT("Children count %d"), countAttached);

}


// Called every frame
void AArmJoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	t += DeltaTime;

	if(IsSelected())
		SetActorRotation(FQuat::MakeFromEuler(FVector(20*sin(this->t), 0, 0)));



}

