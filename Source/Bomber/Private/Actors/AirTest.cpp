// Copyright (c) Yevhenii Selivanov.

#include "Actors/AirTest.h"

// Bomber
#include "Bomber.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(AirTest)

// Sets default values for this actor's properties
AAirTest::AAirTest()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Adds the specified amount to the test value and logs the result
void AAirTest::AddToValue(float Amount)
{
	TestValue += Amount;
	UE_LOG(LogBomber, Log, TEXT("%s: Added %f, TestValue is now %f"), *GetName(), Amount, TestValue);
}
