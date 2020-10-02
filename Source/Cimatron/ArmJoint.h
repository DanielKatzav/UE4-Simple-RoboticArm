// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <array>
#include "CoreMinimal.h"
#include "RobotArmJoint.h"
#include "GameFramework/Actor.h"
#include "ArmJoint.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CIMATRON_API AArmJoint : public AActor
{
	GENERATED_BODY()
private:
	float t = 0;

	FVector minLimit = FVector(-180, -180, -180);		// in Degrees
	FVector maxLimit = FVector(180, 180, 180);			// in Degrees
	FVector Extension = FVector(0, 0, 0);				// in Meters
	bool isTelescopic = false;
	FVector Geometry;

	
public:	
	// Sets default values for this actor's properties
	AArmJoint();
	AArmJoint(FVector Geometry, bool isTelecopic, FVector minLimit, FVector maxLimit, FVector Extension);

	bool SetExtension(FVector NewState);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
