// Copyright (c) Yevhenii Selivanov

#include "Localization/BmrLanguage.h"

// UE
#include "Internationalization/Internationalization.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(BmrLanguage)

// Returns true if this language is currently applied to the game
bool UBmrLanguage::IsCurrentLanguage() const
{
	return FInternationalization::Get().GetCurrentCulture()->GetName() == CultureCode;
}

// Applies this language to the game
bool UBmrLanguage::ApplyLanguage() const
{
	if (CultureCode.IsEmpty())
	{
		return false;
	}

	return FInternationalization::Get().SetCurrentCulture(CultureCode);
}
