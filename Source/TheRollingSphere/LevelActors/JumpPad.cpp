// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpPad.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/CollisionProfile.h"

// Sets default values
AJumpPad::AJumpPad()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//JumpPadMesh
	JumpPadMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Spikes Mesh"));
	RootComponent = JumpPadMesh;
	JumpPadMesh->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> JumpPadMeshRef(TEXT("StaticMesh'/Game/Meshes/LaunchPad.LaunchPad'"));
	JumpPadMesh->SetStaticMesh(JumpPadMeshRef.Object);
}