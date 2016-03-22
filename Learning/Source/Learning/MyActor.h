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

	//Used to update values when changed within the editor.
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	UFUNCTION(BlueprintCallable, Category = "Damage")void CalculateValues();//Calculates the current DamagePerSecond.
																			//"UFUNCTION" exposes functions to the reflection system. "BlueprintCallable" exposes its use to blueprints, meaing it can be called like any other Blueprint function, but this one has been decleared in .cpp. 

	UPROPERTY(EditAnywhere, Category = "Damage", BlueprintReadWrite) int TotalDamage;//The "Category" element puts this variable in its own named category. We can then apply the same category to other variables.	
																					 //"BlueprintReadWrite" allows this varialbe to be read and altered within blueprints.

	UPROPERTY(EditAnywhere, Category = "Damage", BlueprintReadWrite) float DamageTimeInSeconds;
	UPROPERTY(VisibleAnywhere, Category = "Damage", BlueprintReadOnly, Transient) float DamagePerSecond;//"VisibleAnywhere" marks this is viewable, but not editable outside the code. "Transient" means this value is filled at zero at runtime.
																										//"BlueprintReadOnly" means this variable can be read and used by the blueprints but not modified. 


	UFUNCTION(BlueprintImplementableEvent, Category = "Damage") void BPImplementable(float MyNumber);//"BlueprintImplementableEvent" means that this function declared in .cpp but is overridden/has its behavior written in Blueprints. If it is not implemented in blueprints, it is ignored.
																									//You can also send variable data to the blueprint (data from code which you use in your implementable event such as health ext.) which you can branch from in Blueprints.
	
	UFUNCTION(BlueprintNativeEvent, Category = "Damage") void BPNative();//"BlueprintNativeEvent" means that this function declared in .cpp is designed to be overridden by Blueprints. If it it not overriden, the default execution from the code will occucur using the fucntion name + "_Implementation" e.g. BPNative_Implementation();
	void BPNative_Implementation();//You need to explicitly decalare the _Implementation of a BlueprintNativeEvent

};
