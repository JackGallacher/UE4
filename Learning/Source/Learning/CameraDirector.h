// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CameraDirector.generated.h"


UCLASS()
class LEARNING_API ACameraDirector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACameraDirector();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere)AActor* CameraOne;//This exposes two variables that allow you to attach an actor to it. As this is our camera mnager class, we will attach two cameras to these two variables so we can control thier actions.
	UPROPERTY(EditAnywhere)AActor* CameraTwo;//Edit anywhere means we can change these actors in the code or the editor.

	float TimeToNextCameraChange;

	void SetupInput();//This function sets up the input in order to switch camera within the scene.
	void SwitchCamera();//This changes the camera based on the "ToggleCamera" bool value;

	bool ToggleCamera = false;//Boolean to tell us which camera to display.
};
