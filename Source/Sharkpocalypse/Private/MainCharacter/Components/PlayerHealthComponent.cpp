// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter/Components/PlayerHealthComponent.h"

void UPlayerHealthComponent::SetHealth(float Value)
{
	Super::SetHealth(Value);

	OnHealthChanged.Broadcast(Health);
}
