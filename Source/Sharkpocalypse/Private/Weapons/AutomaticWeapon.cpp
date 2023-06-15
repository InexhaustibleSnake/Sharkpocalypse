// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapons/AutomaticWeapon.h"

void AAutomaticWeapon::MakeShot()
{
	if (IsAmmoEmpty())
	{
		FireStop();

		return;
	}

	PlayCameraShake();

	if (!DefaultAmmo.InfiniteAmmo)
	{
		SetAmmo(--CurrentAmmo.Bullets);
	}

	FVector TraceStart, TraceEnd;

	if (!GetTraceData(TraceStart, TraceEnd))
	{
		FireStop();

		return;
	}

	FHitResult HitResult;

	MakeTrace(HitResult, TraceStart, TraceEnd);

	if (HitResult.bBlockingHit)
	{
		MakeDamage(HitResult);
	}
}

