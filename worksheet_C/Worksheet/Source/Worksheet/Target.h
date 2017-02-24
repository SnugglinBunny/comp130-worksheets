// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Target.generated.h"

UCLASS()
class WORKSHEET_API ATarget : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATarget();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/**This is the Static Mesh for the component*/
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* TargetMesh;

	/**This is the Function called when health falls below 0*/
	void DestroyTarget();

	/**This is health value*/
	float Health;

	/**This function takes the value and damages the target for that amount*/
	void DamageTarget(float Damage);
	
};
