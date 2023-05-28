// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseEnemy.generated.h"

class USkeletalMeshComponent;

UCLASS()
class SHARKPOCALYPSE_API ABaseEnemy : public APawn
{
	GENERATED_BODY()

public:
	ABaseEnemy();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent* SkeletalMesh;

};