// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"

class USkeletalMeshComponent;
class ABaseWeapon;

USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	TSubclassOf<ABaseWeapon> WeaponClass;

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHARKPOCALYPSE_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UWeaponComponent();

	virtual void FireStart();
	void FireStop();

	void IncrementWeaponIndex();

protected:
	virtual void BeginPlay() override;

	void EquipWeapon(int32 Index);

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TArray<FWeaponData> WeaponData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	FName WeaponAttachSocket;

	int32 CurrentWeaponIndex;

	UPROPERTY()
	TArray<ABaseWeapon*> Weapons;

	UPROPERTY()
	ABaseWeapon* CurrentWeapon = nullptr;

private:
	void SpawnWeapon();
	void AttachWeaponToSocket(FName& SocketName, USceneComponent* Scene, ABaseWeapon* Weapon);

};
