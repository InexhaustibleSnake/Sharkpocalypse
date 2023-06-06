// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/BaseWeapon.h"
#include "AutomaticWeapon.generated.h"

UCLASS()
class SHARKPOCALYPSE_API AAutomaticWeapon : public ABaseWeapon
{
	GENERATED_BODY()
	
protected:
	virtual void MakeShot() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponData")
	float Damage = 10.0f;

};
