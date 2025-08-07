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
	//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Green, TEXT("Tick!"));

}

void APaperZDRedCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (MoveAction)
		{
			Input->BindAction(MoveAction.Get(), ETriggerEvent::Triggered, this, &APaperZDRedCharacter::Move);
		}
	}

}

void APaperZDRedCharacter::Move(const FInputActionValue& Value)
{
	CurrentInput = Value.Get<FVector2D>();
	
	if (CurrentInput.IsNearlyZero())
	{
		LastDirection = FVector2D::ZeroVector;
		return;
	}																																																																																		LastDirection = CurrentInput;

	if (FMath::Abs(CurrentInput.X) > 0.f && CurrentInput.Y == 0.f)
	{
		LastDirection = FVector2D(CurrentInput.X, 0.f);
	}
	else if (FMath::Abs(CurrentInput.Y) > 0.f && CurrentInput.X == 0.f)
	{
		LastDirection = FVector2D(0.f, CurrentInput.Y);
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, CurrentInput.ToString());
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, LastDirection.ToString());


	
	if (LastDirection.X > 0.f && CurrentInput.Y == 0.f)
		AddMovementInput(FVector::ForwardVector, 1.0f);
	else if (LastDirection.X > 0.f && CurrentInput.Y > 0.f)
		AddMovementInput(FVector::RightVector, 1.0f);
	else if (LastDirection.X > 0.f && CurrentInput.Y < 0.f)
		AddMovementInput(FVector::RightVector, -1.0f);

	else if (LastDirection.X < 0.f && CurrentInput.Y == 0.f)
		AddMovementInput(FVector::ForwardVector, -1.0f);
	else if (LastDirection.X < 0.f && CurrentInput.Y > 0.f)
		AddMovementInput(FVector::RightVector, 1.0f);
	else if (LastDirection.X < 0.f && CurrentInput.Y < 0.f)
		AddMovementInput(FVector::RightVector, -1.0f);

	else if (LastDirection.Y < 0.f && CurrentInput.X == 0.f)
		AddMovementInput(FVector::RightVector, -1.0f);
	else if (LastDirection.Y < 0.f && CurrentInput.X > 0.f)
		AddMovementInput(FVector::ForwardVector, 1.0f);
	else if (LastDirection.Y < 0.f && CurrentInput.X < 0.f)
		AddMovementInput(FVector::ForwardVector, -1.0f);

	else if (LastDirection.Y > 0.f && CurrentInput.X == 0.f)
		AddMovementInput(FVector::RightVector, 1.0f);
	else if (LastDirection.Y > 0.f && CurrentInput.X > 0.f)
		AddMovementInput(FVector::ForwardVector, 1.0f);
	else if (LastDirection.Y > 0.f && CurrentInput.X < 0.f)
		AddMovementInput(FVector::ForwardVector, -1.0f);

}