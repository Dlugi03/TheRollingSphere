// Fill out your copyright notice in the Description page of Project Settings.


#include "HitDestructible.h"
#include "Engine/CollisionProfile.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AHitDestructible::AHitDestructible()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//MainMesh
	MainMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Main Mesh"));
	MainMesh->SetupAttachment(RootComponent);
	MainMesh->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MainMeshRef(TEXT("StaticMesh'/Game/Meshes/LaunchPad.LaunchPad'"));
	MainMesh->SetStaticMesh(MainMeshRef.Object);
	MainMesh->SetNotifyRigidBodyCollision(true);
}

// Called when the game starts or when spawned
void AHitDestructible::BeginPlay()
{
	Super::BeginPlay();
	
	MainMesh->OnComponentHit.AddDynamic(this, &AHitDestructible::OnComponentHit);
}

void AHitDestructible::OnComponentHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{
	HP -= OtherActor->GetVelocity().Size();
	//Check HP
	if (HP <= 0.0f)
	{
		Destroy();
	}
}

