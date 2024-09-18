// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FightingComponent.generated.h"


class UBaseAbilitySystemComponent;
class UMeleeAttackDataAsset;
class UAttackGameplayAbility;
class ATGD_NekkiCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TGD_NEKKI_API UFightingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFightingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<TObjectPtr<UMeleeAttackDataAsset>> ComboQueue;

	ATGD_NekkiCharacter* OwnerRef = nullptr;

	UPROPERTY(BlueprintReadOnly)
	int CurrentMeleeAttackDataIndex = 0;
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UAttackGameplayAbility> CurrentAttackAbility;

	UFUNCTION(BlueprintCallable)
	void ActivateCurrentAttackAbility();


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void DoAttack();
	
	
		
};
