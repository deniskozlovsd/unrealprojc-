// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RollerballWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTCPPPROJECT_API URollerballWidget : public UUserWidget
{
	GENERATED_BODY()

	public:
	
	UFUNCTION(BlueprintImplementableEvent)
	void SetItemText(int32 ItemsCollected, int32 ItemsInLevel);
	
};
