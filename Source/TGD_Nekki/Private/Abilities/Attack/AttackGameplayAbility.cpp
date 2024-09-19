// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/Attack/AttackGameplayAbility.h"

void UAttackGameplayAbility::StartNextAttack_Implementation()
{

}

TArray<AActor*> UAttackGameplayAbility::SortArrayByAngle(AActor* PrimaryActor,TArray<AActor*> InArray)
{

	InArray.Sort([&](AActor& FirstActor, AActor& SecondActor)
		{
			
			return GetAngleBetweenTwoActorsCustom(PrimaryActor, &FirstActor) < GetAngleBetweenTwoActorsCustom(PrimaryActor, &SecondActor);
		});
	return InArray;
}

float UAttackGameplayAbility::GetAngleBetweenTwoActorsCustom(AActor* PrimaryActor, AActor* OtherActor)
{
	
	FVector DirectionVectorToOtherActor = OtherActor->GetActorLocation() - PrimaryActor->GetActorLocation();
	DirectionVectorToOtherActor.Normalize();
	const auto PrimaryActorForwardVector = PrimaryActor->GetActorForwardVector();
	return FMath::Abs(FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(PrimaryActorForwardVector, DirectionVectorToOtherActor))));

}