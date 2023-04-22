#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UMG_SettingsMenu.generated.h"

#pragma region Forward Declarations
class UUMG_Button;
#pragma endregion

#pragma region Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSettingsToggled, bool, Toggled);
#pragma endregion

/**
 * 
 */
UCLASS()
class UUMG_SettingsMenu : public UUserWidget
{
	GENERATED_BODY()

private:


public:
	#pragma region Delegate Declarations
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Settings|Delegates")
	FOnSettingsToggled onSettingsToggled;
	#pragma endregion

};
