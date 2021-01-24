// Fill out your copyright notice in the Description page of Project Settings.


#include "FalldownTriggerRestart.h"
#include "Components/BoxComponent.h"
#include "Engine/CollisionProfile.h"
#include "Kismet/GameplayStatics.h"
#include "../Player/PlayerSphere.h"

// Sets default values
AFalldownTriggerRestart::AFalldownTriggerRestart()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	RootComponent = TriggerBox;
	TriggerBox->SetCollisionProfileName(UCollisionProfile::BlockAllDynamic_ProfileName);
	TriggerBox->SetNotifyRigidBodyCollision(true);
}

// Called when the game starts or when spawned
void AFalldownTriggerRestart::BeginPlay()
{
	Super::BeginPlay();
	
	TriggerBox->OnComponentHit.AddDynamic(this, &AFalldownTriggerRestart::OnComponentHit);
}

void AFalldownTriggerRestart::OnComponentHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComponent, FVector NormalImpulse, const FHitResult & Hit)
{
	if (OtherActor->IsA(APlayerSphere::StaticClass()))
	{
		UGameplayStatics::OpenLevel(GetWorld(), *GetWorld()->GetMapName());
	}
}

