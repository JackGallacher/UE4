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
	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Cyan, "BPNative has been called. As it has not been overridden in Blueprints, we are displaying this message from .cpp");
	//A BlueprinNativeEvent can be called in child classes of this class. So if you had some base code here for each actor,  a child of this class could call "BPNative_Implementation()", add its own code but also execute any code that is in the parent version of the function.
	//Just make sure to call Super::NativeFunction_Implementation in the child class to also execute the parent class code.	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//BPNative();//This executes the BluePrintNativeEvent, if it has been overriden in blueprints it runs that version. If not, it runs the _Implementation version You dont ever have to do this, you can just call the parent implementation from the event in blueprints to execute anything from the _Implementation/Parent.
	BPImplementable(40);//Sends the value of 40 to our BlueprintImplementableEvent which it can use to do whatever with...
}

