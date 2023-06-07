// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BaseHealthComponent.h"
#include "PlayerHealthComponent.generated.h"

UCLASS()
class SHARKPOCALYPSE_API UPlayerHealthComponent : public UBaseHealthComponent
{
	GENERATED_BODY()
	
public:


protected:
	virtual void SetHealth(float Value) override;

};
