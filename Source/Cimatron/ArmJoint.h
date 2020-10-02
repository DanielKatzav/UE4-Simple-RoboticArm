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
	bool MoveArm(int ID);
	FTimer Timer;
	float t = 0;

	std::array<URobotArmJoint*, 10> ArmJoint;
	
public:	
	// Sets default values for this actor's properties
	AArmJoint();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
