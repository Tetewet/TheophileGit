// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Math/Rotator.h"
#include "Antidote.generated.h"

UCLASS()
class UNREALEXERCISES_API AAntidote : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAntidote();

	UPROPERTY(EditAnywhere)
		float Heal = 0.5;

	UPROPERTY(EditAnywhere)
		float Time = 0.5;

	UPROPERTY(VisibleAnywhere)
		FRotator Rotation;

	UPROPERTY(EditAnywhere)
		AActor* Player;

	UPROPERTY(VisibleAnywhere)
		UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditAnywhere)
		class USoundBase* AntidoteSound;

private:
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Heal();
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
