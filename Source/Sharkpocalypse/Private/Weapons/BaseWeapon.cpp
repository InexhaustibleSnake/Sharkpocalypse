// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapons/BaseWeapon.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"

ABaseWeapon::ABaseWeapon()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	SetRootComponent(WeaponMesh);

}

void ABaseWeapon::FireStart()
{
	MakeTrace();
}

void ABaseWeapon::FireStop()
{
}

void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseWeapon::MakeTrace()
{
	FVector TraceStart, TraceEnd;
	FRotator TraceRotation;

	const auto Player = Cast<ACharacter>(GetOwner());
	Player->GetController()->GetPlayerViewPoint(TraceStart, TraceRotation);

	TraceEnd = TraceStart + TraceRotation.Vector() * TraceLength;

	DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red, false, 3.0f);

}

FVector ABaseWeapon::GetMuzzleWorldLocation()
{
	return WeaponMesh->GetSocketLocation(MuzzleSocketName);
}
