// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerMovementComponent.generated.h"

UCLASS()
class SHARKPOCALYPSE_API UPlayerMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	void ChangeMovementSpeed(bool Sprinting);

	UFUNCTION(BlueprintCallable)
	bool IsPlayerSprinting() const { return IsSprinting; }

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	float WalkingSpeed = 300.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
	float SprintingSpeed = 750.0f;

private:
	bool IsSprinting = false;

};
