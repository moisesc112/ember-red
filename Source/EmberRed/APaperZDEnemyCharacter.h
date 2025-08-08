// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "APaperZDRedCharacter.h"
#include "APaperZDEnemyCharacter.generated.h"

class UBoxComponent;

UCLASS()
class EMBERRED_API APaperZDEnemyCharacter : public APaperZDRedCharacter
{
	GENERATED_BODY()
	
public:
	APaperZDEnemyCharacter();


protected:
	virtual void BeginPlay() override;

    UFUNCTION()
    void OnDetectionBoxBeginOverlap(
        UPrimitiveComponent* OverlappedComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult& SweepResult
    );

    UFUNCTION()
    void OnDetectionBoxEndOverlap(
        UPrimitiveComponent* OverlappedComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex
    );

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Detection")
    UBoxComponent* DetectionBox;
};
