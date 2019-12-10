// Fill out your copyright notice in the Description page of Project Settings.


#include "Antidote.h"
#include "Engine.h"
#include "TheophileCharacter.h"
#include "Materials/MaterialInstanceDynamic.h"


// Sets default values
AAntidote::AAntidote()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	CollisionBox->AttachTo(BaseMesh);
	RootComponent = BaseMesh;
}

// Called when the game starts or when spawned
void AAntidote::BeginPlay()
{
	Super::BeginPlay();
	
	Rotation.Add(0, 1, 0);
}

// Called every frame
void AAntidote::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	BaseMesh->AddLocalRotation(Rotation);
}

void AAntidote::Heal()
{
	auto player = Cast<ATheophileCharacter>(Player);
	player->Hp += Heal;
	player->StopPoison();
	//HKHeal = (1.0 - player->Hp) * Time / tduree;
}

void AAntidote::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if (Cast<ATheophileCharacter>(OtherActor) != nullptr)
	{
		
		auto player = Cast<ATheophileCharacter>(OtherActor);
		if (player != nullptr)
		{
			
			if (player->Hp >= 1 || player->Hp <= 0)
			{
				
				Destroy();
			}
			if (AntidoteSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, AntidoteSound, GetActorLocation());
			}
		}
	}
}
