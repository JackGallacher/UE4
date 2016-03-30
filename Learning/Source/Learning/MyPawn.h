// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class LEARNING_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere)USceneComponent* OurVisibleComponent;//"EditAnywhere" can be changed in the code or editor. "UPROPERTY" prevent the variable from being reset when the game is launched. This is what we will add a mesh to to make this pawn visible.

																//Input functions. These will update the values stored in the Input Variable below, which will determine what the Pawn will do during runtime (move/grow).
	void Move_XAxis(float AxisValue);
	void Move_YAxis(float AxisValue);
	void StartGrowing();
	void StopGrowing();

	//Input Variables
	FVector CurrentVelocity;
	bool bGrowing;

	UPROPERTY(EditAnywhere, Category = "Acceleration")float DefaultAcceleration = 100.0f;//Sets the normal Pawn acceleration, is visble and can be changed within the editor.

};
