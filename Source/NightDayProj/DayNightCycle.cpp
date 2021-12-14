// Fill out your copyright notice in the Description page of Project Settings.


#include "DayNightCycle.h"
#include "Engine/Engine.h"
#include <Runtime/Core/Public/Misc/OutputDeviceNull.h>

// Sets default values
ADayNightCycle::ADayNightCycle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DayValue = -30.f;
	NightValue = 70.f;
	bStopChanging = false;
	bDayTime = false;
	bNightTime = false;
	ControlVariable = false;

}

// Called when the game starts or when spawned
void ADayNightCycle::BeginPlay()
{
	Super::BeginPlay();
	turnRateBackUp = turnRate;
	
}

void ADayNightCycle::RotateSky(float DeltaTime, bool bDay, bool bNight)
{
	if (lightSource) {
		lightSource->AddActorLocalRotation(FRotator(DeltaTime * turnRate), 0, 0);
		FRotator sunLoc = lightSource->GetActorRotation();
		float sunPitch = sunLoc.Pitch;

		//if the set time is day, should rotate just until day time and stop
		if (bDay) {
			if (sunPitch > -35 && sunPitch < -25) {
				bStopChanging = true;
				turnRate = 0.f;
			}
		}
		//if the set time is night, should rotate just until night time and stop
		else if (bNight) {
			if (sunPitch < 80 && sunPitch > 75) {
				bStopChanging = true;
				turnRate = 0.f;
			}
		}
		
	}

	if (sun) {

		FOutputDeviceNull ar;
		sun->CallFunctionByNameWithArguments(TEXT("UpdateSunDirection"), ar, NULL, true);

	}
}



bool ADayNightCycle::ControlFunction()
{
	ControlVariable = !ControlVariable;
	//return ControlVariable;
	return true;
}

// Called every frame
void ADayNightCycle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (ControlFunction()) {
		if (bDayTime) {
			RotateSky(DeltaTime, true, false);

		}
		else if (bNightTime) {
			RotateSky(DeltaTime, false, true);

		}
		
	}
	 
}



void ADayNightCycle::ChangeToDay()
{
	bDayTime = true;
	bNightTime = false;
	turnRate = turnRateBackUp;
	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Green, TEXT("DAY PRESSED"));
}

void ADayNightCycle::ChangeToNight()
{
	bNightTime = true;
	bDayTime = false;
	turnRate = turnRateBackUp;
	GEngine->AddOnScreenDebugMessage(-1, 30.f, FColor::Green, TEXT("NIGHT PRESSED"));

}

