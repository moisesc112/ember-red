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

	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputMappingContext> InputMapping;

	UPROPERTY(EditAnywhere, Category = "Input")
	TSoftObjectPtr<UInputAction> MoveAction;
	
	FVector2D CurrentInput = FVector2D::ZeroVector;
	FVector2D LastDirection = FVector2D::ZeroVector;

};
