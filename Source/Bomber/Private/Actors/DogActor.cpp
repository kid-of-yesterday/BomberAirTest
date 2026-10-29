// Copyright (c) Yevhenii Selivanov.

#include "Actors/DogActor.h"

// Bomber
#include "Bomber.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(DogActor)

// Sets default values for this actor's properties
ADogActor::ADogActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Makes the dog bark, increments the bark counter and notifies listeners
void ADogActor::Bark()
{
	++BarkCount;
	UE_LOG(LogBomber, Log, TEXT("%s: %s says Woof! (barks: %d)"), *GetName(), *DogName.ToString(), BarkCount);
	OnDogBarked.Broadcast(BarkCount);
}

// Feeds the dog, reducing its hunger by the specified amount
void ADogActor::Feed(float FoodAmount)
{
	Hunger = FMath::Clamp(Hunger - FoodAmount, 0.f, 100.f);
	UE_LOG(LogBomber, Log, TEXT("%s: %s was fed %f, Hunger is now %f"), *GetName(), *DogName.ToString(), FoodAmount, Hunger);
}
