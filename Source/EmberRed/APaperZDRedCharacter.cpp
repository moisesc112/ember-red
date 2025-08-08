// Fill out your copyright notice in the Description page of Project Settings.

#include "APaperZDRedCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
//#include "InputAction.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h"

APaperZDRedCharacter::APaperZDRedCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}


void APaperZDRedCharacter::BeginPlay()
{
	Super::BeginPlay();

	check(GEngine != nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using PaperZDCharacter"));
	
	if (APlayerController* PC = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMapping.Get(), 0);
		}
	}
}

void APaperZDRedCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!LastDirection.IsZero())
		AddMovementInput(LastDirection);
}

void APaperZDRedCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(UpAction.Get(), ETriggerEvent::Started, this, &APaperZDRedCharacter::MoveUp);
		Input->BindAction(DownAction.Get(), ETriggerEvent::Started, this, &APaperZDRedCharacter::MoveDown);
		Input->BindAction(RightAction.Get(), ETriggerEvent::Started, this, &APaperZDRedCharacter::MoveRight);
		Input->BindAction(LeftAction.Get(), ETriggerEvent::Started, this, &APaperZDRedCharacter::MoveLeft);
	
		Input->BindAction(UpAction.Get(), ETriggerEvent::Completed, this, &APaperZDRedCharacter::StopMoveUp);
		Input->BindAction(DownAction.Get(), ETriggerEvent::Completed, this, &APaperZDRedCharacter::StopMoveDown);
		Input->BindAction(RightAction.Get(), ETriggerEvent::Completed, this, &APaperZDRedCharacter::StopMoveRight);
		Input->BindAction(LeftAction.Get(), ETriggerEvent::Completed, this, &APaperZDRedCharacter::StopMoveLeft);
	}
}

void APaperZDRedCharacter::MoveUp()
{
	MoveInDirection(-FVector::RightVector);
}

void APaperZDRedCharacter::MoveDown()
{
	MoveInDirection(FVector::RightVector);
}

void APaperZDRedCharacter::MoveRight()
{
	MoveInDirection(FVector::ForwardVector);
}

void APaperZDRedCharacter::MoveLeft()
{
	MoveInDirection(-FVector::ForwardVector);
}

void APaperZDRedCharacter::StopMoveUp()
{
	StopMovingInDirection(-FVector::RightVector);
}

void APaperZDRedCharacter::StopMoveDown()
{
	StopMovingInDirection(FVector::RightVector);
}

void APaperZDRedCharacter::StopMoveRight()
{
	StopMovingInDirection(FVector::ForwardVector);
}

void APaperZDRedCharacter::StopMoveLeft()
{
	StopMovingInDirection(-FVector::ForwardVector);
}

void APaperZDRedCharacter::MoveInDirection(const FVector& Direction)
{
	if (!ActiveDirections.Contains(Direction))
	{
		ActiveDirections.Add(Direction);
		LastDirection = Direction;
	}
}

void APaperZDRedCharacter::StopMovingInDirection(const FVector& Direction)
{
	ActiveDirections.Remove(Direction);

	if (ActiveDirections.Num() > 0)
	{
		LastDirection = ActiveDirections.Last();
	}
	else
	{
		LastDirection = FVector::ZeroVector;
	}
}