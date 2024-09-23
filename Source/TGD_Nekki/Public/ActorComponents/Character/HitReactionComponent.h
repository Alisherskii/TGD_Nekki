// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HitReactionComponent.generated.h"


class ATGD_NekkiCharacter;
UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TGD_NEKKI_API UHitReactionComponent : public UActorComponent
{
	friend class ATGD_NekkiCharacter;
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHitReactionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintNativeEvent)
	void HitReact(ATGD_NekkiCharacter* Instigator);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
