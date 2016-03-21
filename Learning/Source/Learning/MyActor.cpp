// Fill out your copyright notice in the Description page of Project Settings.

#include "Learning.h"
#include "MyActor.h"


// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TotalDamage = 200.0;//Sets the inital value for the TotalDamage variable.
	DamageTimeInSeconds = 1.0f;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();	
}

void AMyActor::PostInitProperties()//Is run when everything else is initialized.
{
	Super::PostInitProperties();//Calls PostInitProperties from the base (e.g. "Super" defined in the headset file as virtual).
	CalculateValues();//Calls the function that works out the current DPS based on Total Damage and Damage Time In Seconds.
}

void AMyActor::CalculateValues()//This function is marked as "BlueprintCallable". This means it can be called in Blueprints or .cpp.
{
	DamagePerSecond = TotalDamage / DamageTimeInSeconds;//Sets the default value for DamagePerSecond. If a default vlaue is not set, it will be set to zero or null.
}

#if WITH_EDITOR//Code inside this #ifdef declaration will only be used when the game is open in the editor. This will not be included in any build of the game.
void AMyActor::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)//This function recalculates any changed made to the variable of this object within the editor.
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	CalculateValues();
}
#endif

void AMyActor::BPNative_Implementation()//This is called when the "BlueprintNativeEvent" BPNative has not been overridden in the actor Blueprint.
{
	//GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Cyan, "BPNative has not been overridden in Blueprints, displaying this message from .cpp");
}

// Called every frame
void AMyActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	BPNative();
	BPImplementable();
}

