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
	
	SpawnWeapon();
	EquipWeapon(CurrentWeaponIndex);
}

void UWeaponComponent::SpawnWeapon()
{
	const auto PlayerCharacter = Cast<ACharacter>(GetOwner());

	auto SpawnedWeapon = GetWorld()->SpawnActor<ABaseWeapon>(WeaponData[CurrentWeaponIndex].WeaponClass);
	if (!PlayerCharacter || !GetWorld()) return;

	if (CurrentWeapon) CurrentWeapon->Destroy();

	SpawnedWeapon->SetOwner(PlayerCharacter);

	Weapons.Add(SpawnedWeapon);
}

void UWeaponComponent::EquipWeapon(int32 Index)
{
	if (Index < 0 || Index >= Weapons.Num())
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, "WARNING: Invalid weapon index");
		return;
	}

	const auto PlayerCharacter = Cast<ACharacter>(GetOwner());
	if (!PlayerCharacter) return;

	CurrentWeapon = Weapons[Index];

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
	CurrentWeaponIndex = (CurrentWeaponIndex + 1) % Weapons.Num();
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