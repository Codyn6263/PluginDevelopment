#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UMGJigsawSlot.generated.h"

class UUMGJigsawPanel;
class UImage;

/**
 * 
 */
UCLASS(Blueprintable)
class ADVANCEDINVENTORYSYSTEM_API UUMGJigsawSlot : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

private:
	UFUNCTION()
		UUMGJigsawSlot* getSlots(FIntPoint directions);

public:
	UFUNCTION(BlueprintCallable)
		int getGroupID() { return groupID; }

	UFUNCTION(BlueprintCallable)
		void setGroupID(int newID) { groupID = newID; }

	UFUNCTION(BlueprintCallable)
		bool getLocked() { return bIsLocked; }

	UFUNCTION(BlueprintCallable)
		void setIsLocked(bool isLocked) { bIsLocked = isLocked; }

	UFUNCTION(BlueprintCallable)
		void setJigsawPanel(UUMGJigsawPanel* panel) { jigsawPanel = panel; }

private:
	/*
	 * This effectively links slots together to use for modifying groups of slots at runtime,
	 * such as locking/unlocking groups. Example of this is when you expand your inventory in
	 * Prey (2016).
	 */
	UPROPERTY(EditDefaultsOnly, Category="Jigsaw Slot")
		int groupID = 0;

	/*
	 * If a slot is locked it cannot hold any data or be hidden to make room for an item.
	 */
	UPROPERTY(EditDefaultsOnly, Category = "Jigsaw Slot")
		bool bIsLocked = false;

	/*
	 * The owning jigsaw panel, set at the creation of this slot
	 */
	UPROPERTY()
		TObjectPtr<UUMGJigsawPanel> jigsawPanel;

	/*
	 * Image to test features
	 */
	UPROPERTY(meta=(BindWidget))
		TObjectPtr<UImage> testImage;
};
