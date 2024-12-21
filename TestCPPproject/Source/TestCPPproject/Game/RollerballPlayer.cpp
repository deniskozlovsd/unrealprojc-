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

	//sets physics to true
	Mesh->SetSimulatePhysics(true);

	//DDB - dynamic delicate binding
	Mesh->OnComponentHit.AddDynamic(this, &ARollerballPlayer::CustomOnHit);

}

// Called when the game starts or when spawned
void ARollerballPlayer::BeginPlay()
{
	
	Super::BeginPlay();
	//account for mass in MoveForce
	MoveForce *= Mesh->GetMass();
	JumpImpulse *= Mesh->GetMass();  
	
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

// Called to bind functionality to input

void ARollerballPlayer::MoveRight(float value)
{
	const FVector Right = Camera->GetRightVector() * MoveForce * value;
	Mesh->AddForce(Right);
}

void ARollerballPlayer::MoveForward(float value)
{
	const FVector Forward = Camera->GetForwardVector() * MoveForce * value;
	Mesh->AddForce(Forward);
}

void ARollerballPlayer::Jump()
{
	if (jumpCount >= MaxJumpCount) {return;} //capping the jumps
	Mesh->AddImpulse(FVector(0,0,JumpImpulse));
	jumpCount++;
}

void ARollerballPlayer::CustomOnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit )
{
	const float HitDirection = Hit.Normal.Z;
	if (HitDirection > 0)
	{
		jumpCount = 0;
	}
}



