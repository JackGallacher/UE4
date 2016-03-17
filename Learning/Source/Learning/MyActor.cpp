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
	DamagePerSecond = TotalDamage / DamageTimeInSeconds;//Sets the default value for DamagePerSecond. If a default vlaue is not set, it will be set to zero or null.
}

// Called every frame
void AMyActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

