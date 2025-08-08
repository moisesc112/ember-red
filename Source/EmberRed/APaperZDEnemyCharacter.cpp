// Fill out your copyright notice in the Description page of Project Settings.


#include "APaperZDEnemyCharacter.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "ABattleManager.h"

APaperZDEnemyCharacter::APaperZDEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

    DetectionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DetectionBox"));
    DetectionBox->SetupAttachment(RootComponent);

    //BattleManager = CreateDefaultSubobject<ABattleManager>(TEXT("BattleManager"));
    //BattleManager->SetupAttachment(RootComponent);
}

void APaperZDEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (DetectionBox)
	{
		DetectionBox->OnComponentBeginOverlap.AddDynamic(this, &APaperZDEnemyCharacter::OnDetectionBoxBeginOverlap);
		DetectionBox->OnComponentEndOverlap.AddDynamic(this, &APaperZDEnemyCharacter::OnDetectionBoxEndOverlap);
	}
}

void APaperZDEnemyCharacter::OnDetectionBoxBeginOverlap(
    UPrimitiveComponent* OverlappedComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult
)
{
    if (OtherActor && OtherActor != this)
    {
        UE_LOG(LogTemp, Warning, TEXT("Detected actor: %s"), *OtherActor->GetName());
        // TODO: Trigger engage/attack logic

        FActorSpawnParameters Params;
        Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
        BattleManager = GetWorld()->SpawnActor<ABattleManager>(
            BattleManagerClass,
            GetActorLocation(), // or some hidden battle spot
            FRotator::ZeroRotator,
            Params
        );


        BattleManager->InitBattle(OtherActor, this);
        //DetectionBox->SetGenerateOverlapEvents(false);
    }
}

void APaperZDEnemyCharacter::OnDetectionBoxEndOverlap(
    UPrimitiveComponent* OverlappedComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex
)
{
    if (OtherActor && OtherActor != this)
    {
        UE_LOG(LogTemp, Warning, TEXT("Actor left detection range: %s"), *OtherActor->GetName());
        // TODO: Stop chasing logic
        //DetectionBox->SetGenerateOverlapEvents(true);
    }
}