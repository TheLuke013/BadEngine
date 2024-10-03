#ifndef ENGINE_IMGUI_H
#define ENGINE_IMGUI_H

#include "Engine/Core/Core.h"

#include <ImGui/imgui.h>
#include <ImGui/rlImGui.h>

namespace Engine
{
	class ENGINE_API ImGuiManager
	{
	public:
		ImGuiManager();
		~ImGuiManager();

		void Init();

		bool IsActive() { return isActive; }
		void Activate() { isActive = true; }
		void Disable() { isActive = false; }

	private:
		bool isActive = true;
	};
}

#endif
