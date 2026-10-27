// Copyright (c) Yevhenii Selivanov

#pragma once

#include "UObject/Object.h"

#include "BmrLanguage.generated.h"

class UTexture2D;

/**
 * Describes one of the languages supported by the game.
 */
UCLASS(Blueprintable, BlueprintType, EditInlineNew, DefaultToInstanced)
class BOMBER_API UBmrLanguage : public UObject
{
	GENERATED_BODY()

public:
	/** Returns the culture code of this language, e.g: "en", "uk". */
	UFUNCTION(BlueprintPure, Category = "[Bomber]")
	FORCEINLINE FString GetCultureCode() const { return CultureCode; }

	/** Returns the localized name of this language. */
	UFUNCTION(BlueprintPure, Category = "[Bomber]")
	FORCEINLINE FText GetDisplayName() const { return DisplayName; }

	/** Returns the name of this language written in this language itself, e.g: "Українська". */
	UFUNCTION(BlueprintPure, Category = "[Bomber]")
	FORCEINLINE FText GetNativeName() const { return NativeName; }

	/** Returns true if text in this language is written from right to left. */
	UFUNCTION(BlueprintPure, Category = "[Bomber]")
	FORCEINLINE bool IsRightToLeft() const { return bIsRightToLeft; }

	/** Returns the flag icon of this language, could be not loaded yet. */
	UFUNCTION(BlueprintPure, Category = "[Bomber]")
	FORCEINLINE TSoftObjectPtr<UTexture2D> GetFlagIcon() const { return FlagIcon; }

	/** Returns true if this language is currently applied to the game. */
	UFUNCTION(BlueprintPure, Category = "[Bomber]")
	bool IsCurrentLanguage() const;

	/** Applies this language to the game.
	 * @return true if the culture was changed successfully. */
	UFUNCTION(BlueprintCallable, Category = "[Bomber]")
	bool ApplyLanguage() const;

protected:
	/** The culture code of this language, e.g: "en", "uk". */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "[Bomber]", meta = (BlueprintProtected))
	FString CultureCode = TEXT("en");

	/** The localized name of this language. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "[Bomber]", meta = (BlueprintProtected))
	FText DisplayName = FText::GetEmpty();

	/** The name of this language written in this language itself, e.g: "Українська". */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "[Bomber]", meta = (BlueprintProtected))
	FText NativeName = FText::GetEmpty();

	/** Is set if text in this language is written from right to left. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "[Bomber]", meta = (BlueprintProtected))
	bool bIsRightToLeft = false;

	/** The flag icon of this language to be shown in the settings. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "[Bomber]", meta = (BlueprintProtected))
	TSoftObjectPtr<UTexture2D> FlagIcon = nullptr;
};
