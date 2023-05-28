// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy/BaseEnemy.h"

ABaseEnemy::ABaseEnemy()
{
	PrimaryActorTick.bCanEverTick = false;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh");
	SetRootComponent(SkeletalMesh);
}

void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}
