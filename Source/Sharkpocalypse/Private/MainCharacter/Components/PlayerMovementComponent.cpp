// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter/Components/PlayerMovementComponent.h"

void UPlayerMovementComponent::ChangeMovementSpeed(bool Sprinting)
{
	if (Sprinting)
	{
		IsSprinting = true;
		MaxWalkSpeed = SprintingSpeed;
	}
	else
	{
		IsSprinting = false;
		MaxWalkSpeed = WalkingSpeed;
	}
}
