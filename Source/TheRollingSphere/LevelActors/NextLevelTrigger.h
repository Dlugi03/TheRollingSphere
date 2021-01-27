// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NextLevelTrigger.generated.h"

UCLASS()
class THEROLLINGSPHERE_API ANextLevelTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANextLevelTrigger();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UBoxComponent* TriggerBox;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName LevelToOpen = "Level_1";

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION()
		void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

};
