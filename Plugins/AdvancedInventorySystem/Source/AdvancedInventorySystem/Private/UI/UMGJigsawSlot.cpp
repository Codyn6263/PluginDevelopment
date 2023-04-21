#include "UI/UMGJigsawSlot.h"

#include "Components/GridSlot.h"
#include "Components/Image.h"
#include "UI/UMGJigsawPanel.h"

void UUMGJigsawSlot::NativeConstruct()
{
	getSlots(FIntPoint(2, 2));
}

UUMGJigsawSlot* UUMGJigsawSlot::getSlots(FIntPoint directions)
{
	TArray<UUMGJigsawSlot*> jigsawSlots = jigsawPanel->GetJigsawSlots();

	for (UUMGJigsawSlot* jigsawSlot : jigsawSlots)
	{
		UGridSlot* indexedGridSlot = Cast<UGridSlot>(jigsawSlot->Slot);
		int indexedX = indexedGridSlot->Column;
		int indexedY = indexedGridSlot->Row;

		int X = Cast<UGridSlot>(this->Slot)->Column;
		int Y = Cast<UGridSlot>(this->Slot)->Row;

		if (X + indexedX > 0 && X + indexedX <= directions.X)
		{
			// X is within range
			if (Y + indexedY > 0 && Y + indexedY <= directions.Y)
			{
				// Y is within range
				testImage->SetColorAndOpacity(FColor::Orange);
				if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, TEXT("FOUND SLOT")); }
			}
		}
	}

	return nullptr;
}
