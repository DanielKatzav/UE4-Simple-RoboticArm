// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArmPivot.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CIMATRON_API AArmPivot : public AActor
{
	GENERATED_BODY()

private:
	float t = 0;
	FVector minLimit = FVector(-180,-180,-180);		// in Degrees
	FVector maxLimit = FVector(180, 180, 180);		// in Degrees
	FVector Geometry;

public:	
	// Sets default values for this actor's properties
	AArmPivot();
	AArmPivot(FVector Geometry, FVector minLimit, FVector maxLimit);
	bool SetTheta(FVector NewState);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
