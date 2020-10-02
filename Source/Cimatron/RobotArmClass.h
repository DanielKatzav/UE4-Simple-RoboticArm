// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <array> 
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RobotArmJoint.h"
#include "RobotArmClass.generated.h"

using std::string;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CIMATRON_API ARobotArmClass : public APawn {
	GENERATED_BODY()
private:
	int DoF = 3;
	FString name;
	FVector Geometry;
	std::array<URobotArmJoint*, 10> ArmJoint;

public:
	// Sets default values for this pawn's properties
	ARobotArmClass();
	ARobotArmClass(FString name, int DoF);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//UPROPERTY(EditAnywhere)

};
