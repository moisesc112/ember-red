// Fill out your copyright notice in the Description page of Project Settings.


#include "ABattleManager.h"

// Sets default values
ABattleManager::ABattleManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABattleManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABattleManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABattleManager::InitBattle(AActor* CurrentPlayerTrainer, AActor* CurrentEnemyTrainer)
{
	PlayerTrainer = CurrentPlayerTrainer;
	EnemyTrainer = CurrentEnemyTrainer;

	StartBattle();
}

void ABattleManager::StartBattle()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("Current Player is Red"));
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("Current Enemy is Blue"));

	EndBattle();
}

void ABattleManager::EndBattle()
{
	Destroy();
}
