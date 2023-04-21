#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FAdvancedSettingsModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
