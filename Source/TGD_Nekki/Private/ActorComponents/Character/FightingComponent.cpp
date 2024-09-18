// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorComponents/Character/FightingComponent.h"
#include "Abilities/Attack/MeleeAttackDataAsset.h"
#include "Abilities/Attack/AttackGameplayAbility.h"
#include "TGD_Nekki/BaseAbilitySystemComponent.h"
#include "TGD_Nekki/TGD_NekkiCharacter.h"
#include "Abilities/GameplayAbility.h"
// Sets default values for this component's properties
UFightingComponent::UFightingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	OwnerRef = Cast<ATGD_NekkiCharacter>(GetOwner());
	// ...
}


// Called when the game starts
void UFightingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFightingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UFightingComponent::DoAttack()
{
	
	if (IsValid(OwnerRef))
	{
		const auto ASC = OwnerRef->GetAbilitySystemComponent();
		if (IsValid(ASC))
		{
			if (IsValid(CurrentAttackAbility))
			{
				if (ASC->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag("State.AnimNotify.CanDoNextAttack")))
				{

					CurrentMeleeAttackDataIndex++;
					if (CurrentMeleeAttackDataIndex >= ComboQueue.Num())
						CurrentMeleeAttackDataIndex = 0;
					CurrentAttackAbility->StartNextAttack();
					return;

				}
				else
				{
					return;
				}
			}
			else
			{
				CurrentMeleeAttackDataIndex = 0;
			}
			ActivateCurrentAttackAbility();
		}
		
	}
}

void UFightingComponent::ActivateCurrentAttackAbility()
{
	const auto ASC = OwnerRef->GetAbilitySystemComponent();
	if (IsValid(ASC))
	{
		FGameplayAbilitySpec AbilitySpec = ASC->BuildAbilitySpecFromClass(ComboQueue[CurrentMeleeAttackDataIndex]->AttackAbility, 1);
		ASC->GiveAbilityAndActivateOnce(AbilitySpec);
	}
}
