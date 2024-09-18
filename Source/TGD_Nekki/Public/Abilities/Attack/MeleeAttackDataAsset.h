// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MeleeAttackDataAsset.generated.h"


/**
 * 
 */
class UGameplayAbility;
class UAttackGameplayAbility;
UCLASS()
class TGD_NEKKI_API UMeleeAttackDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	friend class UFightingComponent;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGameplayAbility> AttackAbility;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UAnimMontage> Montage;
};
