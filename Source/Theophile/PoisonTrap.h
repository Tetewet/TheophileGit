// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "PoisonTrap.generated.h"

UCLASS()
class THEOPHILE_API APoisonTrap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APoisonTrap();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditAnywhere)
		class ATheophileCharacter* Player;

	UPROPERTY(EditAnywhere)
		float Damage = 0.1;

	UPROPERTY(EditAnywhere)
		float Period = 1.f;

private:
	class UMaterialInstanceDynamic* PoisonTrapMaterial;
	float Blue = 1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	void UpdateMaterial();
};
