// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "InputActionValue.h"
#include "APaperZDRedCharacter.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class EMBERRED_API APaperZDRedCharacter : public APaperZDCharacter
{
	GENERATED_BODY()
	
public:
	APaperZDRedCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

	void Move(const FInputActionValue& Value);

	void MoveInDirection(const FVector& Direction);
	void StopMovingInDirection(const FVector& Direction);

	void MoveUp();
	void MoveDown();
	void MoveRight();
	void MoveLeft();

	void StopMoveUp();
	void StopMoveDown();
	void StopMoveRight();
	void StopMoveLeft();

	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputMappingContext> InputMapping;

	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputAction> UpAction;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputAction> DownAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputAction> RightAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputAction> LeftAction;


	FVector2D CurrentInput = FVector2D::ZeroVector;
	FVector LastDirection = FVector::ZeroVector;
	
	TArray<FVector> ActiveDirections;
};
