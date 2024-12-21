// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "TestCPPproject/ItemBase/Items/RollerBallitemBase.h"
#include "RollerBallGamemodeBase.generated.h"

class URollerballWidget;
/**
 * 
 */
UCLASS()
class TESTCPPPROJECT_API ARollerBallGamemodeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	int8 ItemsCollected {0};
	int8 ItemsInLevel {0};

	//defines widget types

	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<class UUserWidget> GameWidgetClass;

	UPROPERTY()
	URollerballWidget* GameWidget;
	

	
	virtual void BeginPlay() override;
	void UpdateItemText();

public:
	void ItemCollected();
};
