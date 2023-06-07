// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/EnemyHealthBarWidget.h"
#include "Components/ProgressBar.h"

void UEnemyHealthBarWidget::SetHealthBarPercent(float Percent)
{
	if (!EnemyHealthBar) return;

	const auto HealthBarVisibility = (/*Percent > PercentVisibilityThreshold || */FMath::IsNearlyZero(Percent)) ? ESlateVisibility::Hidden : ESlateVisibility::Visible;

	EnemyHealthBar->SetVisibility(HealthBarVisibility);

	EnemyHealthBar->SetPercent(Percent);
}
