// BootSoft


#include "Characters/SlashAnimInstance.h"
#include "Characters/MainCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void USlashAnimInstance::NativeInitializeAnimation()
{
    Super::NativeInitializeAnimation();

    MainCharacter = Cast<AMainCharacter>(TryGetPawnOwner());
    if (MainCharacter)
    {
        MainCharacterMovement = MainCharacter->GetCharacterMovement();
    }
}

void USlashAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
    Super::NativeUpdateAnimation(DeltaTime);

    if (MainCharacterMovement)
    {
        GroundSpeed = UKismetMathLibrary::VSizeXY(MainCharacterMovement->Velocity);
        IsFalling = MainCharacterMovement->IsFalling();
        CharacterState = MainCharacter->GetCharacterState();
    }
}