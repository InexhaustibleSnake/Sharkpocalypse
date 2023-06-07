// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy/BaseEnemy.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/CapsuleComponent.h"
#include "Enemy/Components/EnemyHealthComponent.h"
#include "Components/WidgetComponent.h"
#include "UI/EnemyHealthBarWidget.h"

ABaseEnemy::ABaseEnemy()
{
	PrimaryActorTick.bCanEverTick = false;

	RootCollision = CreateDefaultSubobject<UCapsuleComponent>("RootCollision");
	SetRootComponent(RootCollision);

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMesh");
	SkeletalMesh->SetupAttachment(GetRootComponent());

	BodyCollision = CreateDefaultSubobject<UCapsuleComponent>("BodyCollision");
	BodyCollision->SetupAttachment(SkeletalMesh);

	HealthBarWidgetComponent = CreateDefaultSubobject<UWidgetComponent>("HealthBarWidgetComponent");
	HealthBarWidgetComponent->SetupAttachment(GetRootComponent());
	HealthBarWidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("FloatingPawnMovement");
	EnemyHealthComponent = CreateDefaultSubobject<UEnemyHealthComponent>("EnemyHealthComponent");
}

void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	EnemyHealthComponent->OnHealthChanged.AddDynamic(this, &ABaseEnemy::OnHealthChanged);
}

void ABaseEnemy::OnHealthChanged(float NewHealth)
{
	const auto HealthBarWidget = Cast<UEnemyHealthBarWidget>(HealthBarWidgetComponent->GetUserWidgetObject());
	if (!HealthBarWidget) return;

	HealthBarWidget->SetHealthBarPercent(EnemyHealthComponent->GetHealthPercent());

}
