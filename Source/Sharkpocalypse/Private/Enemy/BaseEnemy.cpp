// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy/BaseEnemy.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/CapsuleComponent.h"

ABaseEnemy::ABaseEnemy()
{
	PrimaryActorTick.bCanEverTick = false;
	
	//CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("CapsuleComponent");
	//FRotator CapsuleRotation(0.0f, 0.0f, 0.0f);
	//CapsuleComponent->SetRelativeRotation(CapsuleRotation);
	//SetRootComponent(CapsuleComponent);

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh");
	SetRootComponent(SkeletalMesh);
	FRotator RootRotation(0.0f, -90.0f, 90.0f);
	SkeletalMesh->SetRelativeRotation(RootRotation);

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("FloatingPawnMovement");
}

void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}
