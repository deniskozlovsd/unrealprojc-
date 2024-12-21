// Fill out your copyright notice in the Description page of Project Settings.


#include "RollerBallitemBase.h"
#include "Components/StaticMeshComponent.h"
#include "TestCPPproject/Game/RollerBallGamemodeBase.h"


class ARollerBallGamemodeBase;
// Sets default values
ARollerBallitemBase::ARollerBallitemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ARollerBallitemBase::OverlapBegin);

}

// Called when the game starts or when spawned
void ARollerBallitemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARollerBallitemBase::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	//check if thing that touching is player
	if (Cast<ARollerballPlayer>(OtherActor) != nullptr)
	{
		Collected(); //in that case object is collected
	}
}

void ARollerBallitemBase::Collected_Implementation()
{
	//return current gamemode
	ARollerBallGamemodeBase* GameMode = Cast<ARollerBallGamemodeBase>(GetWorld()->GetAuthGameMode());

	if (GameMode)
		{
			GameMode->ItemCollected();
		}
	
}

