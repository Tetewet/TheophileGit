// Fill out your copyright notice in the Description page of Project Settings.


#include "ATheophileCharacter.h"
#include "PoisonTrap.h"

// Sets default values
APoisonTrap::APoisonTrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	BaseMesh->SetSimulatePhysics(true);
	RootComponent = BaseMesh;
}

// Called when the game starts or when spawned
void APoisonTrap::BeginPlay()
{
	Super::BeginPlay();

	PoisonTrapMaterial = BaseMesh->CreateDynamicMaterialInstance(0);

}

void APoisonTrap::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (Cast<ATheophileCharacter>(OtherActor) != nullptr)
	{
		auto player = Cast<ATheophileCharacter>(OtherActor);
		if (player != nullptr)
		{
			player->Hp -= Damage;
			player->IsPoisoned = true;
			Destroy();
		}
	}
}

// Called every frame
void APoisonTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateMaterial();
}

void UpdateMaterial()
{
	PoisonTrapMaterial->SetScalarParameterValue(TEXT("Blue"), Blue);
}
