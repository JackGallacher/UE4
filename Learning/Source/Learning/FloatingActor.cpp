// Fill out your copyright notice in the Description page of Project Settings.

#include "Learning.h"
#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FloatModify = 20.0f;//Sets the initial value of FloatModify
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	//AActor::SetActorLocation(FVector(0.0f, 0.0f, 0.0f));//Sets the actors location within the scene.
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ObjectFloat(DeltaTime);//Calls the ObjectFloat funtion each second, passing the DeltaTime value from Tick.

						   //GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "Hello");//Prints debug message to screen. -1 prints next message underneath previous. 
						   //GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::SanitizeFloat(RandomFloat));//Prints generated random float to screen.
						   //GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, "X: " + FString::SanitizeFloat(AActor::GetActorLocation().X) + " Y: " + FString::SanitizeFloat(AActor::GetActorLocation().Y) + " Z: " + FString::SanitizeFloat(AActor::GetActorLocation().Z));//Prints the XYZ location of FloatingActor.
}
void AFloatingActor::ObjectFloat(float DeltaTime)
{
	RandomFloat = FMath::RandRange(0.6f, 1.4f);//Generates number between two floats.

	FVector NewLocation = GetActorLocation();//Gets the location of this actor in the scene.

	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));//Sets Delta Height for how far the object floats up and down. Sine gives a smooth waveline when used to is perfect for the bobbing up and down motion.
	float DeltaWidth = (FMath::Sin(RunningTime + (DeltaTime * RandomFloat)) - FMath::Sin(RunningTime));//Sets The width for how to the object will randomly move to the side and backwards.

	NewLocation.Z += DeltaHeight * FloatModify;//Takes the XYZ location of this actor, and each tick adds the DeltaHeight/DeltaWidth value multiplied by FloatModify which can be changed in the editor window.
	NewLocation.X += DeltaWidth * FloatModify;
	NewLocation.Y += DeltaWidth * FloatModify;

	RunningTime += DeltaTime;//Increments the RunningTime float with the value of DeltaTime.
	AActor::SetActorLocation(NewLocation);//Each tick, set the current actors location to the "NewLocation" vector position which is being updated every tick.
}

