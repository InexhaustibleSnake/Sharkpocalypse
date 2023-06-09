// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter/BaseMainCharacter.h"
#include "Camera/CameraComponent.h"
#include "MainCharacter/Components/WeaponComponent.h"
#include "MainCharacter/Components/PlayerMovementComponent.h"

ABaseMainCharacter::ABaseMainCharacter(const FObjectInitializer& ObjInit)
	: Super(ObjInit.SetDefaultSubobjectClass<UPlayerMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = true;

	MainCamera = CreateDefaultSubobject<UCameraComponent>("MainCamera");
	MainCamera->SetupAttachment(GetRootComponent());
	MainCamera->bUsePawnControlRotation = true;

	FAttachmentTransformRules AttachmentTransformRules(EAttachmentRule::SnapToTarget, false);
	GetMesh()->SetupAttachment(MainCamera);

	WeaponComponent = CreateDefaultSubobject<UWeaponComponent>("WeaponComponent");
	PlayerMovementComponent = Cast<UPlayerMovementComponent>(GetMovementComponent());
}

void ABaseMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABaseMainCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ABaseMainCharacter::StopJumping);

	PlayerInputComponent->BindAction("Shoot", IE_Pressed, WeaponComponent, &UWeaponComponent::FireStart);
	PlayerInputComponent->BindAction("Shoot", IE_Released, WeaponComponent, &UWeaponComponent::FireStop);

	PlayerInputComponent->BindAction("NextWeapon", IE_Released, WeaponComponent, &UWeaponComponent::IncrementWeaponIndex);

	DECLARE_DELEGATE_OneParam(FSprinting, bool);
	PlayerInputComponent->BindAction<FSprinting>("Sprint", IE_Pressed, PlayerMovementComponent, &UPlayerMovementComponent::ChangeMovementSpeed, true);
	PlayerInputComponent->BindAction<FSprinting>("Sprint", IE_Released, PlayerMovementComponent, &UPlayerMovementComponent::ChangeMovementSpeed, false);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABaseMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseMainCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MouseX", this, &ABaseMainCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("MouseY", this, &ABaseMainCharacter::AddControllerPitchInput);
}

void ABaseMainCharacter::MoveForward(float Amount)
{
	AddMovementInput(GetActorForwardVector(), Amount);
}

void ABaseMainCharacter::MoveRight(float Amount)
{
	AddMovementInput(GetActorRightVector(), Amount);
}