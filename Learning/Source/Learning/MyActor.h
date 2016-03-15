// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class LEARNING_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//Called after this object contructor and properties have been initilized.
	virtual void PostInitProperties() override;

	UPROPERTY(EditAnywhere, Category = "Damage", BlueprintReadWrite) int TotalDamage;//The "Category" element puts this variable in its own named category. We can then apply the same category to other variables.	
																					 //"BlueprintReadWrite" allows this varialbe to be read and altered within blueprints.

	UPROPERTY(EditAnywhere, Category = "Damage", BlueprintReadWrite) float DamageTimeInSeconds;
	UPROPERTY(VisibleAnywhere, Category = "Damage", BlueprintReadOnly, Transient) float DamagePerSecond;//"VisibleAnywhere" marks this is viewable, but not editable outside the code. "Transient" means this value is filled at zero at runtime.
																										//"BlueprintReadOnly" means this variable can be read and used by the blueprints but not modified. 

};
