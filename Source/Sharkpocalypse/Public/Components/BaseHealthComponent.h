// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseHealthComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHARKPOCALYPSE_API UBaseHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UBaseHealthComponent();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	virtual void SetHealth(float Value);

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Health")
	float MaxHealth = 100.0f;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Health")
	float Health;

};
