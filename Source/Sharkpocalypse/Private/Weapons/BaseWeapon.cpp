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

void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseWeapon::MakeShot() {}

void ABaseWeapon::FireStart()
{
	GetWorld()->GetTimerManager().SetTimer(FireTimer, this, &ABaseWeapon::MakeShot, FireRate, true);
}

void ABaseWeapon::FireStop()
{
	GetWorld()->GetTimerManager().ClearTimer(FireTimer);
}

void ABaseWeapon::SetAmmo(float Amount)
{
	CurrentAmmo.Bullets = FMath::Clamp(Amount, 0, DefaultAmmo.Bullets);

	OnAmmoChange.Broadcast(CurrentAmmo.Bullets);
}

bool ABaseWeapon::GetTraceData(FVector& TraceStart, FVector& TraceEnd) const
{
	FRotator TraceRotation;
	if (!GetPlayerViewPoint(TraceStart, TraceRotation)) return false;

	const auto HalfRad = FMath::DegreesToRadians(BulletSpread);
	const FVector ShootDirection = FMath::VRandCone(TraceRotation.Vector(), HalfRad);

	TraceEnd = TraceStart + ShootDirection * TraceLength;

	return true;
}

void ABaseWeapon::MakeDamage(const FHitResult& HitResult)
{
	const auto Actor = HitResult.GetActor();
	if (!Actor) return;

	FPointDamageEvent PointDamageEvent;
	PointDamageEvent.HitInfo = HitResult;
	Actor->TakeDamage(Damage, PointDamageEvent, GetController(), this);
}

void ABaseWeapon::MakeTrace(FHitResult& HitResult, const FVector& TraceStart, const FVector& TraceEnd)
{
	if (!GetWorld()) return;

	DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red, false, 2.0f);

	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility);
}

bool ABaseWeapon::GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRotation) const
{
	if (!GetController()) return false;

	GetController()->GetPlayerViewPoint(ViewLocation, ViewRotation);

	return true;
}

FVector ABaseWeapon::GetMuzzleWorldLocation() const
{
	return WeaponMesh->GetSocketLocation(MuzzleSocketName);
}

AController* ABaseWeapon::GetController() const
{
	const auto PlayerPawn = Cast<APawn>(GetOwner());
	return PlayerPawn ? PlayerPawn->GetController() : nullptr;
}

void ABaseWeapon::PlayCameraShake()
{
	const auto PlayerPawn = Cast<APawn>(GetOwner());
	if (!PlayerPawn) return;

	const auto PlayerController = Cast<APlayerController>(PlayerPawn->GetController());
	if (!PlayerController || !PlayerController->PlayerCameraManager) return;

	PlayerController->PlayerCameraManager->StartCameraShake(CameraShake);
}
