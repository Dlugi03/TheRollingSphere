// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpPad.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/CollisionProfile.h"
#include "../Player/PlayerSphere.h"

// Sets default values
AJumpPad::AJumpPad()
{
	//JumpPadMesh
	JumpPadMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Spikes Mesh"));
	//RootComponent = JumpPadMesh;
	JumpPadMesh->SetupAttachment(RootComponent);
	JumpPadMesh->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	JumpPadMesh->SetNotifyRigidBodyCollision(true);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> JumpPadMeshRef(TEXT("StaticMesh'/Game/Meshes/LaunchPad.LaunchPad'"));
	JumpPadMesh->SetStaticMesh(JumpPadMeshRef.Object);
}

void AJumpPad::BeginPlay()
{
	Super::BeginPlay();

	JumpPadMesh->OnComponentHit.AddDynamic(this, &AJumpPad::OnComponentHit);
}

void AJumpPad::OnComponentHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("hit jumppad"));
	if (OtherActor->IsA(APlayerSphere::StaticClass()))
	{
		Cast<APlayerSphere>(OtherActor)->Jump(JumpPadMesh->GetUpVector(), LaunchHeight);
	}
}
