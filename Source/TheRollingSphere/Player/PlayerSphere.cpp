// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerSphere.h"
#include "Engine/CollisionProfile.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerSphere::APlayerSphere()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Sphere_Mesh
	Sphere_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere Mesh"));
	Sphere_Mesh->SetupAttachment(RootComponent);
	Sphere_Mesh->SetSimulatePhysics(true);
	Sphere_Mesh->SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshRef(TEXT("StaticMesh'/Engine/EngineMeshes/Sphere.Sphere'"));
	Sphere_Mesh->SetStaticMesh(SphereMeshRef.Object);
	Sphere_Mesh->SetRelativeScale3D(FVector::OneVector * 0.5f);

	//CameraBoom
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 1250.0f;
	CameraBoom->bDoCollisionTest = true;
	CameraBoom->bEnableCameraLag = true;

	//MainCamera
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Main Camera"));
	MainCamera->SetupAttachment(CameraBoom);
	//MainCamera->AttachToComponent(CameraBoom, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

// Called every frame
void APlayerSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CameraBoom->SetWorldLocation(Sphere_Mesh->GetComponentLocation());
}

// Called to bind functionality to input
void APlayerSphere::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("RollForward", this, &APlayerSphere::RollForward);
	PlayerInputComponent->BindAxis("RollRight", this, &APlayerSphere::RollRight);
	PlayerInputComponent->BindAxis("LookRight", this, &APlayerSphere::LookRight);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerSphere::LookUp);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerSphere::JumpInput);
	PlayerInputComponent->BindAction("QuitToMainMenu", IE_Pressed, this, &APlayerSphere::QuitToMainMenu);
}

void APlayerSphere::RollForward(float Value)
{
	//AddMovementInput(FVector::ForwardVector, Value, true);
	Sphere_Mesh->AddForce(CameraBoom->GetForwardVector() * Value * MovementSpeed);
}

void APlayerSphere::RollRight(float Value)
{
	//AddMovementInput(FVector::RightVector, Value, true);
	Sphere_Mesh->AddForce(CameraBoom->GetRightVector() * Value * MovementSpeed);
}

void APlayerSphere::LookRight(float Value)
{
	CameraBoom->AddRelativeRotation(FRotator(0.0f, Value * RotationSpeed, 0.0f));
}

void APlayerSphere::LookUp(float Value)
{
	float CurrentPitch = CameraBoom->GetRelativeRotation().Pitch;
	CurrentPitch += Value * RotationSpeed;
	CurrentPitch = FMath::Clamp(CurrentPitch, -75.0f, 0.0f);
	CameraBoom->SetRelativeRotation(FRotator(CurrentPitch, CameraBoom->GetRelativeRotation().Yaw, 0.0f));
}

void APlayerSphere::JumpInput()
{
	if (Sphere_Mesh->GetComponentVelocity().Z == 0.0f)
	{
		Jump(FVector::UpVector, JumpHeight);
	}
}

void APlayerSphere::Jump(FVector upVector, float height)
{
	Sphere_Mesh->AddImpulse(FVector::UpVector * height);
}

void APlayerSphere::QuitToMainMenu()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("MainMenu"));
}
