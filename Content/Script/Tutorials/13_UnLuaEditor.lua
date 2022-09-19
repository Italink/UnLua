local UnLuaEditor = Class()

function UnLuaEditor:Startup()
	self.m_ToolbarWidget = NewObject(UE.UClass.Load("/Game/Tutorials/13_EditorBlueprint/CustomToolbar.CustomToolbar_C"),self,nil)
    self.m_TopLeftTabWidget = NewObject(UE.UClass.Load("/Game/Tutorials/13_EditorBlueprint/CustomTab.CustomTab_C"),self,nil)
    self.m_BottomLeftTabWidget = NewObject(UE.UClass.Load("/Game/Tutorials/13_EditorBlueprint/OpenDialog.OpenDialog_C"),self,nil)

	self:SetToolBarWidget(self.m_ToolbarWidget)
    self:SetTabWidget("Tab0",self.m_TopLeftTabWidget,false)
    self:SetTabWidget("Tab1",self.m_BottomLeftTabWidget,false)
	self:Show(UE.FVector2D(1600,800))
end

function UnLuaEditor:Shutdown()
	print("------------------------ Shown")
end

return UnLuaEditor
