// Fill out your copyright notice in the Description page of Project Settings.


#include "InputCharacter.h"

#include <ThirdParty/ShaderConductor/ShaderConductor/External/DirectXShaderCompiler/include/dxc/DXIL/DxilConstants.h>

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AInputCharacter::AInputCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bUsePawnControlRotation = true;
	
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
	
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

// Called when the game starts or when spawned
void AInputCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	//add input mapping context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		//get local player subsystem
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			//add input context
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}
}

// Called every frame
void AInputCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MyClimbTest();
}

// Called to bind functionality to input
void AInputCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}

void AInputCharacter::Move(const FInputActionValue& InputValue)
{
	// FVector2D InputVector = InputValue.Get<FVector2D>(); 
	//
	// if (IsValid(Controller))
	// {
	// 	//get forward or right direction
	// 	const FRotator Rotation = Controller->GetControlRotation();
	// 	const FRotator YawRotation(0,Rotation.Yaw, 0); //only get yaw
	// 	
	// 	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	// 	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	// 	
	// 	//add movement input
	// 	AddMovementInput(ForwardDirection, InputVector.Y);
	// 	AddMovementInput(RightDirection, InputVector.X);
	// 	
	// }
}

void AInputCharacter::Look(const FInputActionValue& InputValue)
{
	// FVector2D InputVector = InputValue.Get<FVector2D>(); 
	//
	// if (IsValid(Controller))
	// {
	// 	AddControllerYawInput(InputVector.X);
	// 	AddControllerPitchInput(InputVector.Y);
	// }
	
}

// void AInputCharacter::Jump()
// {
// 	 ACharacter::Jump();
// }



