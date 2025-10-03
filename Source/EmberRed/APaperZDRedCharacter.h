// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "InputActionValue.h"
#include "APaperZDRedCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;

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

	USpringArmComponent* GetSpringArmComponent();
	UCameraComponent* GetCameraComponent();

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> InputMapping;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> UpAction;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> DownAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> RightAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> LeftAction;


	FVector2D CurrentInput = FVector2D::ZeroVector;
	FVector LastDirection = FVector::ZeroVector;
	
	TArray<FVector> ActiveDirections;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComponent;

};
