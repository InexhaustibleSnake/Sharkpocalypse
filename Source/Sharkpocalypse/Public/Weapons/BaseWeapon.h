// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAmmoChange, int32, NewAmmo);

USTRUCT(BlueprintType)
struct FAmmoData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	int32 Bullets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	int32 MaxBullets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	bool InfiniteAmmo;
};

UCLASS()
class SHARKPOCALYPSE_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseWeapon();

	virtual void FireStart();
	void FireStop();

	virtual void SetAmmo(float Amount);

	UPROPERTY(BlueprintCallable)
	FOnAmmoChange OnAmmoChange;

	bool IsAmmoEmpty() const { return !DefaultAmmo.InfiniteAmmo && CurrentAmmo.Bullets == 0; }
	bool IsAmmoFull() const { return CurrentAmmo.Bullets == DefaultAmmo.Bullets; }

	UFUNCTION(BlueprintCallable)
	FAmmoData GetAmmoData() const { return CurrentAmmo; }

protected:
	virtual void BeginPlay() override;
	bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const;

	void MakeTrace(FHitResult& HitResult, const FVector& TraceStart, const FVector& TraceEnd);

	virtual void MakeShot();

	void MakeDamage(const FHitResult& HitResult);

	bool GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRotation) const;

	AController* GetController() const;

	FVector GetMuzzleWorldLocation() const;

	void PlayCameraShake();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	FName MuzzleSocketName = "MuzzleSocket";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponData")
	float TraceLength = 1000.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponData")
	float BulletSpread = 2.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponData")
	float FireRate = 0.1f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponData")
	float Damage = 10.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponData")
	TSubclassOf<UCameraShakeBase> CameraShake;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponData")
	FAmmoData DefaultAmmo;

	FAmmoData CurrentAmmo;

private:
	FTimerHandle FireTimer;

};
