#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/GridPanel.h"
#include "UMGJigsawPanel.generated.h"

class UUMGJigsawSlot;

/**
 * 
 */
UCLASS(Blueprintable)
class ADVANCEDINVENTORYSYSTEM_API UUMGJigsawPanel : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
		TArray<UUMGJigsawSlot*> GetJigsawSlots() { return gridSlots; };

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

private:
	UPROPERTY()
		TArray<TObjectPtr<UUMGJigsawSlot>> gridSlots;

	UPROPERTY(meta=(BindWidget))
		TObjectPtr<UGridPanel> gridPanel;

	UPROPERTY(EditDefaultsOnly, Category = "Jigsaw Panel")
		FIntPoint gridSize = FIntPoint(1, 1);

	UPROPERTY(EditDefaultsOnly, Category = "Jigsaw Panel")
		TSubclassOf<UUMGJigsawSlot> slotClass;
};
