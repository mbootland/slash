// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class USphereComponent;

enum class EItemState : uint8
{
	EIS_Hovering,
	EIS_PickedUp
};

UCLASS()
class SLASH_API AItem : public AActor
{
	GENERATED_BODY()

	virtual void Tick(float DeltaTime) override;
public:	
	AItem();

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float Amplitude = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float RunningTime;

	UFUNCTION(BlueprintPure)
	float TransformedSin();

	UFUNCTION(BlueprintPure)
	float TransformedCos();

	template<typename T>
	T Avg(T First, T Second);

	UFUNCTION()
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(EditAnywhere)
	class UNiagaraComponent* EmbersEffect;

	EItemState ItemState = EItemState::EIS_Hovering;
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float TimeConstant = 5.f;
};

template<typename T>
inline T AItem::Avg(T First, T Second)
{
	return (First + Second) / 2;
}
