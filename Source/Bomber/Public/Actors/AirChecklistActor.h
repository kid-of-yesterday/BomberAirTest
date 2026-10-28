// Copyright (c) Yevhenii Selivanov.

#pragma once

#include "GameFramework/Actor.h"

#include "AirChecklistActor.generated.h"

/**
 * Simple test actor that holds a float value editable in Blueprints and allows adding to it.
 */
UCLASS(Blueprintable)
class BOMBER_API AAirChecklistActor : public AActor
{
	GENERATED_BODY()

public:
	/** Sets default values for this actor's properties */
	AAirChecklistActor();

	/** Adds the specified amount to the test value and logs the result. */
	UFUNCTION(BlueprintCallable, Category = "[Bomber]")
	void AddToValue(float Amount);

protected:
	/** The test value that can be edited in Blueprints and changed by AddToValue. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "[Bomber]")
	float TestValue = 55.f;
};
