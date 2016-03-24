// Fill out your copyright notice in the Description page of Project Settings.

#include "Learning.h"
#include "MyPawn.h"


// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Sets this pawn to be controlled by the lowest numbered player.
	AutoPossessPlayer = EAutoReceiveInput::Player0;//Allows this pawn to be controlled by player input. "Player0" is just the first player in the game.

	//Create a dummy root component we can attach things to.
	AActor::RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));//"RootComponent" defines the transform (location, rotation, scale) of this actor.

	//Create a camera and a visible object.
	//UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));//Creates a camera that focuses on this pawn due to it being attached to its RootComponent.
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));//Allows us to add a static mesh to this pawn. (An object to make it visible such as a cube/cylinder)

	//Attach our camera and visible object to our root compontent. Offset and rotate the camera.
	//OurCamera->AttachTo(RootComponent);//Attaches the camera we created to our RootComponent.
	//OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));//Sets the location of the camera.
	//OurCamera->SetRelativeRotation(FRotator(-40.0f, 0.0f, 0.0f));//Sets the rotation of our camera.
	OurVisibleComponent->AttachTo(RootComponent);//Attaches our SceneComponent "OurVisibleComponent" to the RootComponent. 
}

void AMyPawn::Move_XAxis(float AxisValue)//Move at the value of "DefaultAcceleration" per second forward or backwards.
{
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * DefaultAcceleration;//FMath::Clamp makes sure that a value can only be between two values. In this case it is -1 and 1 or "Backwards" and "Forwards"
}

void AMyPawn::Move_YAxis(float AxisValue)//Move at 100 units per second right or left.
{
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.0f, 1.0f) * DefaultAcceleration;
}

void AMyPawn::StartGrowing()//Trigger the bool "bGrowing" to true.
{
	bGrowing = true;
}

void AMyPawn::StopGrowing()//Trigger the bool "bGrowing" to false.
{
	bGrowing = false;
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AMyPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	//Handle growing and shrinking based on the status of "bGrowing".
	float CurrentScale = OurVisibleComponent->GetComponentScale().X;//Gets the current scale of the static mesh we have attached to this script that makes it visible. It is what we are going to increase/decrease in size.
	if (bGrowing)
	{
		CurrentScale += DeltaTime;//Increase the size of the mesh over DeltaTime when the grow boolean is true.
	}
	else
	{
		CurrentScale -= (DeltaTime * 0.5f);//Decrease the size of the mesh at half the speed that it grown if the boolean is false.
	}
	CurrentScale = FMath::Clamp(CurrentScale, 1.0f, 2.0f);//This clamps the scale size so it doesnt go below starting size (1.0f) and doesn't increase to above double size (2.0f).
	OurVisibleComponent->SetWorldScale3D(FVector(CurrentScale));//Sets the 3D scale of the mesh attached to this pawn to be that of the CurrentScale (CurrentScale = 1.5 -> Mesh size is 150% more than starting size).

	if (CurrentVelocity.IsZero() == false)//Checks if the velocity of our Pawn is zero, if it is not, execute this code.
	{
		FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);//Sets the vector "NewLocation" to the current location of our pawn plus its current velocity multiplied by DeltaTime.
		SetActorLocation(NewLocation);//Sets the location of our pawn to the "NewLocation" vector.
		DefaultAcceleration = DefaultAcceleration + 5.0f;//Increases the Accleration over time based on how long the button has been held down. Explicit for clarity.
	}
	else
	{
		DefaultAcceleration = 100.0f;//Resets the DefaultAcceleration back to normal when a movement button has been released.
	}
	//GEngine->AddOnScreenDebugMessage(0,5.0f, FColor::Cyan, "Pawn Speed: " + FString::SanitizeFloat(DefaultAcceleration));//Prints current Pawn speed.

	if (!CurrentVelocity.IsZero() && bGrowing)//This checks if the Pawn is moving and if the "StartGrowing" button is being pressed at the same time. If so, it increases the scale of the Pawn to 200%.
	{
		CurrentScale = 2.0f;
		OurVisibleComponent->SetWorldScale3D(FVector(CurrentScale));
	}
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	//Respond when the input button for "Grow" (Set in Project Setting -> Input) is pressed/released.
	InputComponent->BindAction("Grow", IE_Pressed, this, &AMyPawn::StartGrowing);//When the button linked to "Grow" is pressed, call the function "StartGrowing".
	InputComponent->BindAction("Grow", IE_Released, this, &AMyPawn::StopGrowing);//When the button linked to "Grow" is released, call the function "StopGrowing".

	//Respond every frame to the values of our two movment axis, "MoveX" and "MoveY" Binds these inputs to the Pawn axis so movement along them is enabled.
	InputComponent->BindAxis("MoveX", this, &AMyPawn::Move_XAxis);//When the button linked to "MoveX" is pressed, call the function "Move_XAxis".
	InputComponent->BindAxis("MoveY", this, &AMyPawn::Move_YAxis);//When the button linked to "MoveY" is pressed, call the function "Move_YAxis".
}

