#include "SMagicProjectile.h"
#include "SGameplayFunctionLibrary.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Camera/PlayerCameraManager.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

ASMagicProjectile::ASMagicProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	SphereComp->SetCollisionProfileName("Projectile");
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ASMagicProjectile::OnActorOverlap);
	RootComponent = SphereComp;
	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	EffectComp->SetupAttachment(SphereComp);

	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	MovementComp->InitialSpeed = 1000.0f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->bInitialVelocityInLocalSpace = true;
}

void ASMagicProjectile::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != GetInstigator())
	{
		//static FGameplayTag Tag = FGameplayTag::RequestGameplayTag("Status.Parrying");
		
		USActionComponent* ActionComponent = Cast<USActionComponent>(OtherActor->GetComponentByClass(USActionComponent::StaticClass()));
		if(ActionComponent && ActionComponent->ActiveGameplayTags.HasTag(ParryTag))
		{
			MovementComp->Velocity = -MovementComp->Velocity;
			SetInstigator(Cast<APawn>(OtherActor));
			return;
		}

		//Apply Damage & Impulse
		// if(USGameplayFunctionLibrary::ApplyDirectionalDamage(GetInstigator(), OtherActor, -20.0f, SweepResult))
		// {
		// 	Explode();
		// }
	}
}

void ASMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void ASMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
