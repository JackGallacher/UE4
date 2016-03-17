// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class LEARNING_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void ObjectFloat( float DeltaSeconds );	//Moves the object up and down, "float"

	float RunningTime = 0.0;//Inits the float value of RunningTime.
	float RandomFloat;//We will save a randm number to this variable

	UPROPERTY(EditAnywhere, Category = "Modifiers") float FloatModify;//Sets the default value of "FloatModify" but exposes it to the editor window so it can be set there.
};
