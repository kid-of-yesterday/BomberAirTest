// Copyright (c) Yevhenii Selivanov.

#include "Actors/AirChecklistActor.h"

// Bomber
#include "Bomber.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(AirChecklistActor)

// Sets default values for this actor's properties
AAirChecklistActor::AAirChecklistActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Adds the specified amount to the test value and logs the result
void AAirChecklistActor::AddToValue(float Amount)
{
	TestValue += Amount;
	UE_LOG(LogBomber, Log, TEXT("%s: Added %f, TestValue is now %f"), *GetName(), Amount, TestValue);
}
