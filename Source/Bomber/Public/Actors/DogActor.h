// Copyright (c) Yevhenii Selivanov.

#pragma once

#include "GameFramework/Actor.h"

#include "DogActor.generated.h"

/** Breeds the dog can have. */
UENUM(BlueprintType)
enum class EDogBreed : uint8
{
	None,
	Labrador,
	Beagle,
	Shepherd,
	Poodle
};

/** Is called when the dog barks. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDogBarked, int32, TotalBarks);

/**
 * Simple dog actor with a name, breed and hunger that can bark and be fed.
 */
UCLASS(Blueprintable, BlueprintType)
class BOMBER_API ADogActor : public AActor
{
	GENERATED_BODY()

public:
	/** Sets default values for this actor's properties */
	ADogActor();

	/** Is called when the dog barks. */
	UPROPERTY(BlueprintAssignable, Category = "[Bomber]")
	FOnDogBarked OnDogBarked;

	/** Makes the dog bark, increments the bark counter and notifies listeners. */
	UFUNCTION(BlueprintCallable, Category = "[Bomber]")
	void Bark();

	/** Feeds the dog, reducing its hunger by the specified amount. */
	UFUNCTION(BlueprintCallable, Category = "[Bomber]")
	void Feed(float FoodAmount);

	/** Returns true if the dog's hunger is above the hungry threshold. */
	UFUNCTION(BlueprintPure, Category = "[Bomber]")
	bool IsHungry() const { return Hunger > HungryThreshold; }

	/** Returns the name of the dog. */
	UFUNCTION(BlueprintPure, Category = "[Bomber]")
	FORCEINLINE FName GetDogName() const { return DogName; }

	/** Returns the breed of the dog. */
	UFUNCTION(BlueprintPure, Category = "[Bomber]")
	FORCEINLINE EDogBreed GetBreed() const { return Breed; }

protected:
	/** The name of the dog. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "[Bomber]")
	FName DogName = TEXT("Rex");

	/** The breed of the dog. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "[Bomber]")
	EDogBreed Breed = EDogBreed::Labrador;

	/** Age of the dog in years. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "[Bomber]", meta = (ClampMin = "0", UIMin = "0"))
	int32 Age = 3;

	/** Current hunger level from 0 (full) to 100 (starving). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "[Bomber]", meta = (ClampMin = "0", ClampMax = "100", UIMin = "0", UIMax = "100"))
	float Hunger = 50.f;

	/** Hunger level above which the dog is considered hungry. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "[Bomber]", meta = (ClampMin = "0", ClampMax = "100"))
	float HungryThreshold = 70.f;

	/** How many times the dog has barked. */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category = "[Bomber]")
	int32 BarkCount = 0;
};
