// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	if (!FPSCameraComponent)
	{
		FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
		FPSCameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));
		FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
		FPSCameraComponent->bUsePawnControlRotation = true;
	}

	if (!FPSMesh) {
		FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
		FPSMesh->SetupAttachment(FPSCameraComponent);
		FPSMesh->bCastDynamicShadow = false;
		FPSMesh->CastShadow = false;
	}

	if (!Ammo)
	{
		Ammo = CreateDefaultSubobject<UAmmoComponent>(TEXT("AmmoComponent"));
	}

	GetMesh()->SetOwnerNoSee(true);

	UE_LOG(LogTemp, Warning, TEXT("Character Constructor Called"));

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	PlayerWidget = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD<AFPSGameHud>()->GameWidgetContainer;

	PlayerWidget->SetAmmoText(Ammo->CurrentAmmo, Ammo->MaxAmmo);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Movement
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	// Look
	PlayerInputComponent->BindAxis("LookHorizontal", this, &APlayerCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookVertical", this, &APlayerCharacter::AddControllerPitchInput);

	// Jump
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::EndJump);

	// Fire
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerCharacter::StartFire);

	// Reload
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &APlayerCharacter::Reload);

	// Pause
	PlayerInputComponent->BindAction("Pause", IE_Pressed, this, &APlayerCharacter::PauseGame);

}

void APlayerCharacter::MoveForward(float value)
{
	FVector Direction = GetActorForwardVector();
	AddMovementInput(Direction, value);
}

void APlayerCharacter::MoveRight(float value)
{
	FVector Direction = GetActorRightVector();
	AddMovementInput(Direction, value);
}

void APlayerCharacter::StartJump()
{
	Jump();
}

void APlayerCharacter::EndJump()
{
	bPressedJump = false;
}

void APlayerCharacter::StartFire()
{
	if (!Ammo->UseAmmo()) return;

	PlayerWidget->SetAmmoText(Ammo->CurrentAmmo, Ammo->MaxAmmo);

	UE_LOG(LogTemp, Warning, TEXT("Fire raycast"));

	FHitResult OutHit;
	FVector Start = FPSCameraComponent->GetComponentLocation();

	FVector ForwardVector = FPSCameraComponent->GetForwardVector();
	FVector End = ((ForwardVector * ShotDistance) + Start);
	FCollisionQueryParams CollisionParams;

	 
	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, .3f, 0, 2);

	if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECollisionChannel::ECC_Visibility, CollisionParams))
	{
		if (ATargetBase* target = Cast<ATargetBase>(OutHit.GetActor()))
			target->Hit(OutHit.GetComponent()->GetName());
	}

}

void APlayerCharacter::PauseGame()
{
	AFPSGameHud* FPSHUD = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHUD<AFPSGameHud>();

	FPSHUD->ShowPauseMenu(FPSHUD->PauseGameWidget);
}

void APlayerCharacter::Reload()
{
	if (!Ammo->IsReloading)
		Ammo->ReloadGun();

	PlayerWidget->SetAmmoText(Ammo->MaxAmmo, Ammo->MaxAmmo);
}

