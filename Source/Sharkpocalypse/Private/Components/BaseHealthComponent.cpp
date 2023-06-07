// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/BaseHealthComponent.h"

UBaseHealthComponent::UBaseHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UBaseHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	SetHealth(MaxHealth);

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UBaseHealthComponent::OnTakeAnyDamage);
}

void UBaseHealthComponent::SetHealth(float Value) 
{
	Health = FMath::Clamp(Value, 0.0f, MaxHealth);
	OnHealthChanged.Broadcast(Health);
}

void UBaseHealthComponent::OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	SetHealth(Health - Damage);

	if (FMath::IsNearlyZero(Health))
	{
		GetOwner()->Destroy();
	}
}
