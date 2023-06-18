// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter/Components/WeaponComponent.h"
#include "GameFramework/Character.h"
#include "Weapons/BaseWeapon.h"

UWeaponComponent::UWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	CurrentWeaponIndex = 0;
}

void UWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	EquipWeapon(CurrentWeaponIndex);
}

void UWeaponComponent::FireStart()
{
	CurrentWeapon->FireStart();
}

void UWeaponComponent::FireStop()
{
	CurrentWeapon->FireStop();
}

void UWeaponComponent::EquipWeapon(int32 Index)
{
	if (Index < 0 || Index >= WeaponData.Num())
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, "WARNING: Invalid weapon index");
		return;
	}

	const auto PlayerCharacter = Cast<ACharacter>(GetOwner());
	if (!PlayerCharacter) return;

	if (CurrentWeapon) CurrentWeapon->Destroy();

	CurrentWeapon = GetWorld()->SpawnActor<ABaseWeapon>(WeaponData[CurrentWeaponIndex].WeaponClass);
	CurrentWeapon->SetOwner(GetOwner());

	AttachWeaponToSocket(WeaponAttachSocket, PlayerCharacter->GetMesh(), CurrentWeapon);
}

void UWeaponComponent::AttachWeaponToSocket(FName& SocketName, USceneComponent* Scene, ABaseWeapon* Weapon)
{
	if (!Scene || !Weapon) return;

	FAttachmentTransformRules AttachmentTransformRules(EAttachmentRule::SnapToTarget, false);

	Weapon->AttachToComponent(Scene, AttachmentTransformRules, WeaponAttachSocket);
}

void UWeaponComponent::IncrementWeaponIndex()
{
	CurrentWeaponIndex = (CurrentWeaponIndex + 1) % WeaponData.Num();
	EquipWeapon(CurrentWeaponIndex);
}

bool UWeaponComponent::TryGetCurrentWeaponAmmoData(FAmmoData& AmmoData) const
{
	if (CurrentWeapon)
	{
		AmmoData = CurrentWeapon->GetAmmoData();
		return true;
	}

	return false;
}

void UWeaponComponent::AddWeaponToInventory(FWeaponData& WeaponToAdd)
{
	if (!WeaponToAdd.WeaponClass && WeaponData.Contains(WeaponToAdd)) return;

	WeaponData.Add(WeaponToAdd);
}
