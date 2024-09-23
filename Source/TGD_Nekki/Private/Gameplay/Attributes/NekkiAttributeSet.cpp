// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/Attributes/NekkiAttributeSet.h"
#include "TGD_Nekki/TGD_NekkiCharacter.h"
#include "GameplayEffectExtension.h"
void UNekkiAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0, GetMaxHealth());
	}
}

void UNekkiAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	const auto Context = Data.EffectSpec.GetContext();
	const auto SourceNekkiChar = Cast<ATGD_NekkiCharacter>(Context.GetInstigator());
	const auto TargetNekkiChar = Cast<ATGD_NekkiCharacter>(Data.Target.GetAvatarActor());
	TargetNekkiChar->OnDamageTaken(SourceNekkiChar, Data.EvaluatedData.Magnitude);
}