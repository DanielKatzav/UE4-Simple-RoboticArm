// Fill out your copyright notice in the Description page of Project Settings.


#include "RobotArmClass.h"

// Sets default values
ARobotArmClass::ARobotArmClass()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
ARobotArmClass::ARobotArmClass(FString name, int DoF)
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->DoF = DoF;
	this->name = name;
	this->Geometry = AActor::GetActorScale3D();

	for (int i = 0; i < DoF; i++) {
		URobotArmJoint* Joint = new URobotArmJoint(i, this->Geometry, -30.0, 30.0, false);
		ArmJoint.fill(Joint);
	}
	


}
// Called when the game starts or when spawned
void ARobotArmClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARobotArmClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARobotArmClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);



}

