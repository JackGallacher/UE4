// Fill out your copyright notice in the Description page of Project Settings.

#include "Learning.h"
#include "FloatingActor.h"




// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	//AActor::SetActorLocation(FVector(0.0f, 0.0f, 0.0f));//Sets the actors location within the scene.
}

// Called every frame
void AFloatingActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	//ObjectFloat(DeltaTime);//Calls the ObjectFloat funtion each second, passing the DeltaTime value from Tick.

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "Hello");//Prints debug message to screen. -1 prints next message underneath previous. 


}
void AFloatingActor::ObjectFloat(float DeltaTime)
{
	FVector NewLocation = GetActorLocation();//Gets the location of this actor in the scene.
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));//Sets Deltaheight.
	NewLocation.Z += DeltaHeight * 20.0f;//Takes the Z location of this actor, and each tick adds the DeltaHeight value multiplied by 20.
	RunningTime += DeltaTime;//Increments the RunningTime float with the value of DeltaTime.
	AActor::SetActorLocation(NewLocation);//Each tick, set the current actors location to the "NewLocation" vector position which is being updated every tick.
}

