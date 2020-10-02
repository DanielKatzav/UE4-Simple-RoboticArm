// Fill out your copyright notice in the Description page of Project Settings.


#include "RobotArmJoint.h"

// Sets default values for this component's properties
URobotArmJoint::URobotArmJoint()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

URobotArmJoint::URobotArmJoint(int ID, FVector Geometry, double minLimit, double maxLimit, bool isTelescopic){

	this->ID = ID;
	this->name = GetName();
	this->Geometry = Geometry;
	this->minLimit = minLimit;
	this->maxLimit = maxLimit;
	this->isTelescopic = isTelescopic;
	UE_LOG(LogTemp, Warning, TEXT("Created"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Created")));

}

void* URobotArmJoint::operator new(size_t size)
{
	void* p = malloc(size); 
	return p;
}
// Called when the game starts
void URobotArmJoint::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("Created"));

	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URobotArmJoint::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

}

