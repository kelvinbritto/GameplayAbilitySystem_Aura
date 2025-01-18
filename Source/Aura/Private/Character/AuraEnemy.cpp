// Copyright Druid Mechanics


#include "Character/AuraEnemy.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Aura/Aura.h"

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAuraEnemy::HighlightActor()
{
	USkeletalMeshComponent* EnemyMesh = GetMesh();
	if (EnemyMesh)
	{
		EnemyMesh->SetRenderCustomDepth(true);
		EnemyMesh->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	}

	if (Weapon)
	{
		Weapon->SetRenderCustomDepth(true);
		Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	}

}

void AAuraEnemy::UnHighlightActor()
{
	USkeletalMeshComponent* EnemyMesh = GetMesh();
	if (EnemyMesh)
	{
		EnemyMesh->SetRenderCustomDepth(false);
	}

	if (Weapon)
	{
		Weapon->SetRenderCustomDepth(false);
	}
	
}
