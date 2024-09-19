// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AttackGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class TGD_NEKKI_API UAttackGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	friend class UFightingComponent;
protected:
	UFUNCTION(BlueprintNativeEvent)
	void StartNextAttack();
	UFUNCTION(BlueprintCallable)
		TArray<AActor*> SortArrayByAngle(AActor* PrimaryActor, TArray<AActor*> InArray);
	UFUNCTION(BlueprintCallable)
	float GetAngleBetweenTwoActorsCustom(AActor* PrimaryActor, AActor* OtherActor);

};
