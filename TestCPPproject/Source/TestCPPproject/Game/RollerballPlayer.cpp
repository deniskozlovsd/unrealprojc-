// Fill out your copyright notice in the Description page of Project Settings.


#include "RollerballPlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ARollerballPlayer::ARollerballPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	RootComponent = Mesh;
	SpringArm->SetupAttachment(Mesh);
	Camera->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void ARollerballPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

//// Called every frame
//void ARollerballPlayer::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

void ARollerballPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//test
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//Custom input axis binding
	InputComponent->BindAxis("MoveForward", this, &ARollerballPlayer::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ARollerballPlayer::MoveRight);
	//Custom Action binding
	InputComponent->BindAction("Jump", IE_Pressed, this, &ARollerballPlayer::Jump);
	
}

void ARollerballPlayer::MoveRight(float value)
{
}

void ARollerballPlayer::MoveForward(float value)
{
}

void ARollerballPlayer::Jump()
{
}

// Called to bind functionality to input
void ARollerballPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

