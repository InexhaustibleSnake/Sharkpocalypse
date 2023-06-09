// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapons/ShotgunWeapon.h"

void AShotgunWeapon::MakeShot()
{
	Super::MakeShot();

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

	FHitResult HitResult;

	for (int i = 0; i <= BulletsPerShot; ++i)
	{
		if (!GetTraceData(TraceStart, TraceEnd))
		{
			FireStop();
			return;
		}

		MakeTrace(HitResult, TraceStart, TraceEnd);

		if (HitResult.bBlockingHit)
		{
			MakeDamage(HitResult);
		}
	}
}
