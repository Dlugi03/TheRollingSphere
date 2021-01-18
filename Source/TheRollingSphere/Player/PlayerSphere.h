// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PlayerSphere.generated.h"

UCLASS()
class THEROLLINGSPHERE_API APlayerSphere : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerSphere();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* Sphere_Mesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UCameraComponent* MainCamera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MovementSpeed = 1000000.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RotationSpeed = 5.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float JumpHeight = 1000000.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Movement input functions
	UFUNCTION()
		void RollForward(float Value);
	UFUNCTION()
		void RollRight(float Value);
	UFUNCTION()
		void LookRight(float Value);
	UFUNCTION()
		void LookUp(float Value);
	UFUNCTION()
		void Jump();
};