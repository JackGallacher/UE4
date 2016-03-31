// Fill out your copyright notice in the Description page of Project Settings.

#include "Learning.h"
#include "Countdown.h"


// Sets default values
ACountdown::ACountdown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;//Disabled update for this actor as we do not need the Tick() function.

	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountdownNumber"));//Creates our CountdownText as a URenderTextComponent and sets its name in the editor to "CountdownText".
	CountdownText->SetHorizontalAlignment(EHTA_Center);//Positions the CountdownText in the middle of the screen.
	CountdownText->SetWorldSize(150.0f);//Sets the scale of our CountdownText.
	RootComponent = CountdownText;//Sets the RootComponent of this Actor to be our CountdownText.

	CountdownTime = 3;//Sets the timer variable size to 3.
}

// Called when the game starts or when spawned
void ACountdown::BeginPlay()
{
	Super::BeginPlay();

	UpdateTimerDisplay();//Calls the function that sets the text property of our CountdownText.
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ACountdown::AdvanceTimer, 1.0f, true);//Sets up the current timer with our CountdownTimerHandle, this object, calling the AdvanceTimer function each iteration and specifying the timer tick rate of 1.0f.	
}

// Called every frame
void ACountdown::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ACountdown::UpdateTimerDisplay()
{
	CountdownText->SetText(FString::FromInt(FMath::Max(CountdownTime, 0)));//Sets the text of our CoundownText varaible to CountdownTime which has been converted to a String. FMax finds the highest value between two numbers. So in this case Countdown time and 0.
}

void ACountdown::AdvanceTimer()
{
	CountdownTime --;
	UpdateTimerDisplay();//Calls out timer update function to display the new value of CountdownTime.
	if(CountdownTime < 1)
	{
		//We're done counting down, so stop running the timer.
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		CountdownHasFinished();//Calls out finish funtion for the timer.
	}
}

void ACountdown::CountdownHasFinished_Implementation()//This executes when the CountdownHasFinished function has not been overridden in Blueprints.
{
	//Change the CountdownText to somthing that states the countdown has finished.
	CountdownText->SetText(TEXT("GO!"));
}

