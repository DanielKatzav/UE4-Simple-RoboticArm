// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RobotArmMode.generated.h"

/*
 *
 * 
 */
UENUM(BlueprintType)
	enum CtrlMode {
		Manual,
		Test,
		POI
	};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CIMATRON_API ARobotArmMode : public AGameModeBase
{
	GENERATED_BODY()

private:
	CtrlMode ControlMode = CtrlMode::Manual;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	ARobotArmMode();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "RobotArmMode")
		void SetCurrentMode(CtrlMode NewMode) { this->ControlMode = NewMode; };
	UFUNCTION(BlueprintCallable, Category = "RobotArmMode")
		CtrlMode GetCurrentMode() { return ControlMode; };


};
