// Fill out your copyright notice in the Description page of Project Settings.


#include "Spikes.h"
#include "Engine/CollisionProfile.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "../Player/PlayerSphere.h"

// Sets default values
ASpikes::ASpikes()
{
	//SpikesMesh
	SpikesMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Spikes Mesh"));
	SpikesMesh->SetupAttachment(RootComponent);
	SpikesMesh->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	SpikesMesh->SetNotifyRigidBodyCollision(true);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SpikesMeshRef(TEXT("StaticMesh'/Game/Meshes/Spikes.Spikes'"));
	SpikesMesh->SetStaticMesh(SpikesMeshRef.Object);
}

void ASpikes::BeginPlay()
{
	Super::BeginPlay();

	SpikesMesh->OnComponentHit.AddDynamic(this, &ASpikes::OnComponentHit);
}

void ASpikes::OnComponentHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{
	if (OtherActor->IsA(APlayerSphere::StaticClass()))
	{
		UGameplayStatics::OpenLevel(GetWorld(), *GetWorld()->GetMapName());
	}
}
