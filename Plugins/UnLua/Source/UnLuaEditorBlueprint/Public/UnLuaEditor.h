// Copyright Epic Games, Inc. All Rights Reserved.

/**
 * Blueprint for editor utilities
 */

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UnLuaTabLayout.h"
#include "Blueprint/UserWidget.h"
#include "LuaEnvLocator.h"
#include "UnLuaEditor.generated.h"

UCLASS(Abstract, Blueprintable, meta = (ShowWorldContextPin))
class UNLUAEDITORBLUEPRINT_API UUnLuaEditor : public UObject
{
	GENERATED_UCLASS_BODY()

	UFUNCTION( BlueprintImplementableEvent, Category = "Editor")
	void Startup();

	UFUNCTION(BlueprintImplementableEvent, Category = "Editor")
	void Shutdown();

	UFUNCTION()
	void TryStartup();

	UFUNCTION(BlueprintCallable, Category = "Editor")
	void TryShutdown();

	UFUNCTION(BlueprintCallable)
	void SetTabWidget(FName TabId, UUserWidget* UserWidget,bool CanClose = false);

	UFUNCTION(BlueprintCallable)
	void SetToolbarWidget(UUserWidget* ToolbarWidget);

	UFUNCTION(BlueprintCallable)
	void Show(FVector2D WindowSize = FVector2D(1600,850));

	virtual UWorld* GetWorld() const override;
protected:
	TSharedPtr<FTabManager> GetTabManager();

public:
	UPROPERTY(EditAnywhere)
	FText WindowTitle;

	UPROPERTY(EditAnywhere)
	bool UseLevelEditorTabManager = true;

	UPROPERTY(EditAnywhere)
	TArray<TSoftClassPtr<UObject>> LuaBindClasses;

	UPROPERTY(EditAnywhere)
	FUnLuaTabLayout TabLayout;

	TSharedPtr<SWindow> CurrentWindow;
	UUserWidget* ToolbarWidget = nullptr;

	TSharedPtr<SDockingArea> CurrentArea;
	
	TSharedPtr<FTabManager::FLayout> Layout;

	struct TabWigdetInfo {
		FName TabId;
		UUserWidget* UserWidget;
		bool CanClose;
	};
	TMap<FName, TabWigdetInfo> TabWidgetInfos;
	bool bNeedRecreateLayout = true;
	TSharedPtr<UnLua::FLuaEditorEnv> EditorEnv;
};
