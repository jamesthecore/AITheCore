#pragma once

#include "CoreMinimal.h"
#include "UserWidget.h"
#include "TC_WidgetAggro.generated.h"

class ATC_AICharacterBase;
class UProgressBar;

UCLASS()
class UTC_WidgetAggro : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetCharacterOwner(ATC_AICharacterBase* CharacterBase);

protected:
	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
		UProgressBar* AggroProgressBar = nullptr;
	UPROPERTY(BlueprintReadWrite)
		ATC_AICharacterBase* CharacterOwner;
};