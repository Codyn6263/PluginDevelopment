#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UMG_Button.generated.h"

#pragma region Forward Declarations
class UTextBlock;
#pragma endregion

#pragma region Delegates
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonClicked, bool, Pressed);
#pragma endregion

/**
 * 
 */
UCLASS()
class UUMG_Button : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativePreConstruct() override;

	#pragma region Components
	UPROPERTY(BlueprintReadWrite, meta=(BindWidget))
	TObjectPtr<UTextBlock> BTN_ButtonText;
	#pragma endregion

public:
	#pragma region Delegate Declarations
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Button|Delegates")
	FOnButtonClicked OnButtonClicked;
	#pragma endregion

	#pragma region Parameters
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Button Parameters", DisplayName="Button Text")
		FText buttonText;
	#pragma endregion
};
