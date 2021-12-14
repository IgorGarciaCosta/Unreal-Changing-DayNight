// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DirectionalLight.h"
#include "DayNightCycle.generated.h"

UCLASS()
class NIGHTDAYPROJ_API ADayNightCycle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADayNightCycle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		void RotateSky(float DeltaTime, bool bDay, bool bNight);

	UFUNCTION()
		bool ControlFunction();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "sky")
		AActor* sun;
	UPROPERTY(EditAnywhere, Category = "sky")
		ADirectionalLight* lightSource;
	UPROPERTY(EditAnywhere, Category = "sky")
		float turnRate;
	UPROPERTY()
		float turnRateBackUp;
	UPROPERTY(EditAnywhere, Category = "sky")
		float DayValue;
	UPROPERTY(EditAnywhere, Category = "sky")
		float NightValue;
	UPROPERTY(VisibleAnywhere, Category = "sky")
		bool bStopChanging;
	UPROPERTY()
		bool bDayTime;
	UPROPERTY()
		bool bNightTime;
	UPROPERTY()
		bool ControlVariable;

	UFUNCTION(BlueprintCallable)
		void ChangeToDay();
	UFUNCTION(BlueprintCallable)
		void ChangeToNight();
};
