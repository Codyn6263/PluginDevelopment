#include "UI/UMGJigsawPanel.h"

#include "Components/GridSlot.h"
#include "UI/UMGJigsawSlot.h"

void UUMGJigsawPanel::NativePreConstruct()
{
	if (!slotClass) return;

	for (int x = 0; x < gridSize.X; x++)
	{
		for (int y = 0; y < gridSize.Y; y++)
		{
			UUMGJigsawSlot* spawnedSlot = Cast<UUMGJigsawSlot>(CreateWidget(this, slotClass, FName("Jigsaw Slot")));
			gridPanel->AddChildToGrid(spawnedSlot);

			if (IsValid(spawnedSlot))
			{
				UGridSlot* gridSlot = Cast<UGridSlot>(spawnedSlot->Slot);

				if (IsValid(gridSlot))
				{
					gridSlot->SetColumn(x);
					gridSlot->SetRow(y);
				}
			}

			spawnedSlot->setJigsawPanel(this);
		}
	}
}

void UUMGJigsawPanel::NativeConstruct()
{
	for (UWidget* widget : gridPanel->GetAllChildren())
	{
		if (UUMGJigsawSlot* jigsawSlot = Cast<UUMGJigsawSlot>(widget))
			gridSlots.Add(jigsawSlot);
	}
}