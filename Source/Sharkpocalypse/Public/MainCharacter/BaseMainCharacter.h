// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseMainCharacter.generated.h"

class UCameraComponent;
class UWeaponComponent;
class UPlayerMovementComponent;

UCLASS()
class SHARKPOCALYPSE_API ABaseMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseMainCharacter(const FObjectInitializer& ObjInit);
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UCameraComponent* MainCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UWeaponComponent* WeaponComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UPlayerMovementComponent* PlayerMovementComponent;

	void MoveForward(float Amount);
	void MoveRight(float Amount);

};
