// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestCPPproject/Game/RollerballPlayer.h"
#include "RollerBallitemBase.generated.h"


UCLASS()
class TESTCPPPROJECT_API ARollerBallitemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARollerBallitemBase();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//Define Componentes
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	UStaticMeshComponent * Mesh;
	
	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION(BlueprintNativeEvent)
	void Collected();


};
