// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RobotArmJoint.generated.h"

using std::string;

// In meters
struct _Geometry {
	double width = 1;
	double height = 1;
	double length = 1;
};
//UINTERFACE(MinimalAPI, Blueprintable)
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CIMATRON_API URobotArmJoint : public UActorComponent
{
	GENERATED_BODY()
private:
	FString name;
	double minLimit = -180;	// in Degrees
	double maxLimit = 180;	// in Degrees
	bool isTelescopic = false;
	FVector Geometry;

	int ID = 0;

public:	
	// Sets default values for this component's properties
	URobotArmJoint();
	URobotArmJoint(int ID, FVector Geometry, double minLimit, double maxLimit, bool isTelescopic);
	void* operator new(size_t size);

	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void setState(double state);
	double getState();

		
};
