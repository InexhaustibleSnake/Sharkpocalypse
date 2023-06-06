// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/BaseWeapon.h"
#include "ShotgunWeapon.generated.h"

UCLASS()
class SHARKPOCALYPSE_API AShotgunWeapon : public ABaseWeapon
{
	GENERATED_BODY()
	
protected:
	virtual void MakeShot();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponData")
	int32 BulletsPerShot = 10;

};
