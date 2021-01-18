// Fill out your copyright notice in the Description page of Project Settings.


#include "Spikes.h"
#include "Engine/CollisionProfile.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ASpikes::ASpikes()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//SpikesMesh
	SpikesMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Spikes Mesh"));
	RootComponent = SpikesMesh;
	SpikesMesh->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SpikesMeshRef(TEXT("StaticMesh'/Game/Meshes/Spikes.Spikes'"));
	SpikesMesh->SetStaticMesh(SpikesMeshRef.Object);
}