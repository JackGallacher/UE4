// Fill out your copyright notice in the Description page of Project Settings.

#include "Learning.h"
#include "CameraDirector.h"
#include "Kismet/GameplayStatics.h"//This gives us access to some useful general purpose functions.
#include "GameFramework/DefaultPawn.h"


// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
	SetupInput();
}

// Called every frame
void ACameraDirector::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	const float TimeBetweenCameraChanges = 2.0f;
	const float SmoothBlendTime = 0.75f;
	TimeToNextCameraChange -= DeltaTime;

	//if (TimeToNextCameraChange <= 0.0f)
	//{
		//TimeToNextCameraChange += TimeBetweenCameraChanges;

		//Find the actor that handles control for the local player.
		APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if (OurPlayerController)
		{
			//if ((OurPlayerController->GetViewTarget() != CameraOne) && (CameraOne != nullptr))
			if (ToggleCamera == false)
			{
				//Cut instantly to camera one.
				//OurPlayerController->SetViewTarget(CameraOne);

				//Blend smoothly to camera one.
				OurPlayerController->SetViewTargetWithBlend(CameraOne, SmoothBlendTime);
			}
			//else if ((OurPlayerController->GetViewTarget() != CameraTwo) && (CameraTwo != nullptr))
			if(ToggleCamera == true)
			{
				//Blend smoothly to camera two.
				OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
			}
		}
	//}

}
void ACameraDirector::SetupInput()//This function binds the "Switch Camera" input control to this Actors "SwitchCamera" function.
{
	InputComponent->BindAction("Switch Camera", IE_Pressed, this, &ACameraDirector::SwitchCamera);//When the button linked to "Switch Camera" is pressed, call the function "SwitchCamera".
}

void ACameraDirector::SwitchCamera()
{
	if (ToggleCamera == false)
	{
		ToggleCamera = true;
	}
	else
	{
		ToggleCamera = false;
	}
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, "Switch Camera button pressed.");
}

