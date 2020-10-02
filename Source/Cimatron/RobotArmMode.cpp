// Fill out your copyright notice in the Description page of Project Settings.


#include "RobotArmMode.h"
ARobotArmMode::ARobotArmMode(){

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


// Called when the game starts or when spawned
void ARobotArmMode::BeginPlay(){
	Super::BeginPlay();

}


void ARobotArmMode::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

