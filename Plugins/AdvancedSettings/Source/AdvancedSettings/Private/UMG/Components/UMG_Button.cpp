#include "UMG/Components/UMG_Button.h"
#include "Components/TextBlock.h"

void UUMG_Button::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (IsValid(BTN_ButtonText))
		BTN_ButtonText->SetText(buttonText);
}
