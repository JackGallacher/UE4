// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Countdown.generated.h"

UCLASS()
class LEARNING_API ACountdown : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACountdown();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere)int32 CountdownTime;//The variable we will use to store the current countdown value. Set as "EditAnywhere" so this value can be changed in the editor.
	UTextRenderComponent* CountdownText;//Where we will save our countdown text to.

	void UpdateTimerDisplay();//Function that will update the display of our timer based on the CountdonTime.	

	void AdvanceTimer();//This function will set the value of CoundownTime

	UFUNCTION(BlueprintNativeEvent)void CountdownHasFinished();//This function will trigger when the countdown has finished it is native so can be overriden in Blueprint. If it is not override the "_Implementation" version in .cpp will be run instead.
	virtual void CountdownHasFinished_Implementation();

	FTimerHandle CountdownTimerHandle;//This timer handle is used to stop the timer we create in BeginPlay. When its value reaches its end, we call this to stop it.
};

/*
- BlueprintCallable functions are written in C++ and can be called from the Blueprint Graph, but cannot be changed or overridden without editing C++ code. 
  Functions marked this way are usually features that have been programmed for non-programmer use, but that are not supposed to be changed or wouldn't make sense to change. 
  An easy example of this would be any kind of math function.

- BlueprintImplementableEvent functions are set up in a C++ header (.h) file, but the body of the function is written entirely in the Blueprint Graph, not in C++. 
  These are usually created to give a non-programmer the ability to create custom reactions to special situations that have no expected default action or standard behavior. 
  An example of this might be an event that happens when a powerup touches the player's ship in a spaceship game.

- BlueprintNativeEvent functions are like a combination of BlueprintCallable and BlueprintImplementableEvent functions. 
  They have default behaviors programmed in C++, but these can be supplemented or replaced by overriding in the Blueprint Graph. 
  When programming these, the C++ code always goes in a virtual function with _Implementation added to the end of the name, as shown below. 
  This is the most flexible option, so we will use it for this tutorial.
*/