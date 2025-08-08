// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABattleManager.generated.h"

UCLASS()
class EMBERRED_API ABattleManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABattleManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void StartBattle();
	void EndBattle();


	AActor* PlayerTrainer = nullptr;
	AActor* EnemyTrainer = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void InitBattle(AActor* PlayerTrainer, AActor* EnemyTrainer);

};
