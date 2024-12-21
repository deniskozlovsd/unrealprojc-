// Fill out your copyright notice in the Description page of Project Settings.


#include "RollerBallGamemodeBase.h"

#include "RollerballWidget.h"
#include "Kismet/GameplayStatics.h"

void ARollerBallGamemodeBase::BeginPlay()
{
	//create array of items and return number of them positioned on a map
	TArray<AActor*> Items;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ARollerBallitemBase::StaticClass(), Items);
	ItemsInLevel = Items.Num();

	if (GameWidgetClass)
	{
		GameWidget = Cast<URollerballWidget>(CreateWidget(GetWorld(), GameWidgetClass));
		if (GameWidget)
		{
			GameWidget->AddToViewport();
			UpdateItemText();
		}
	}
}

void ARollerBallGamemodeBase::UpdateItemText()
{
	GameWidget->SetItemText(ItemsCollected, ItemsInLevel);

}

void ARollerBallGamemodeBase::ItemCollected()
{
	ItemsCollected++;
	UpdateItemText();
}
