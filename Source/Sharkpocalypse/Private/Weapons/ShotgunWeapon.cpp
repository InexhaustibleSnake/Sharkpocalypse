// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapons/ShotgunWeapon.h"

void AShotgunWeapon::MakeShot()
{
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
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("123")));
		if (HitResult.bBlockingHit)
		{
			MakeDamage(HitResult);
		}
	}
}
