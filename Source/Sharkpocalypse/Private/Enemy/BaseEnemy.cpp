// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy/BaseEnemy.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/CapsuleComponent.h"
#include "Enemy/Components/EnemyHealthComponent.h"

ABaseEnemy::ABaseEnemy()
{
	PrimaryActorTick.bCanEverTick = false;

	RootCollision = CreateDefaultSubobject<UCapsuleComponent>("RootCollision");
	SetRootComponent(RootCollision);

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh");
	SkeletalMesh->SetupAttachment(GetRootComponent());

	BodyCollision = CreateDefaultSubobject<UCapsuleComponent>("BodyCollision");
	BodyCollision->SetupAttachment(SkeletalMesh);

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("FloatingPawnMovement");
	EnemyHealthComponent = CreateDefaultSubobject<UEnemyHealthComponent>("EnemyHealthComponent");
}

void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}
