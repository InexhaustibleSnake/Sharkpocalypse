// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

USTRUCT(BlueprintType)
struct FAmmoData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	int32 Bullets;

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

protected:
	virtual void BeginPlay() override;
	bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const;

	void MakeTrace(FHitResult& HitResult, const FVector& TraceStart, const FVector& TraceEnd);

	virtual void MakeShot();

	void MakeDamage(const FHitResult& HitResult);

	bool GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRotation) const;

	AController* GetController() const;

	FVector GetMuzzleWorldLocation() const;

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
	FAmmoData AmmoData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	FAmmoData CurrentAmmo;

	AController* GetOwnerController() const;

private:
	FTimerHandle FireTimer;
	
};
