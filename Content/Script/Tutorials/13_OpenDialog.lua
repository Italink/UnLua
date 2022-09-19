--
-- DESCRIPTION
--
-- @COMPANY **
-- @AUTHOR **
-- @DATE ${date} ${time}
--

---@type OpenDialog_C
local M = UnLua.Class()

--function M:Initialize(Initializer)
--end

--function M:PreConstruct(IsDesignTime)
--end

function M:Construct()
	self.Button.OnClicked:Add(self,function()
		UE.UUnLuaEditorBPLibrary.CreateAndShowDialog(self,UE.UClass.Load("/Game/Tutorials/13_EditorBlueprint/CustomDialog.CustomDialog_C"),"Dialog",UE.FVector2D(600,600))
	end
    )
end

--function M:Tick(MyGeometry, InDeltaTime)
--end

return M
