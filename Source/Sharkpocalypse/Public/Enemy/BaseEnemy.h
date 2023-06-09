// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseEnemy.generated.h"

class USkeletalMeshComponent;
class UFloatingPawnMovement;
class UCapsuleComponent;
class UEnemyHealthComponent;
class UWidgetComponent;

UCLASS()
class SHARKPOCALYPSE_API ABaseEnemy : public APawn
{
	GENERATED_BODY()

public:
	ABaseEnemy();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnHealthChanged(float NewHealth);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UFloatingPawnMovement* FloatingPawnMovement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UCapsuleComponent* RootCollision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UCapsuleComponent* BodyCollision;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UEnemyHealthComponent* EnemyHealthComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UWidgetComponent* HealthBarWidgetComponent;

};
