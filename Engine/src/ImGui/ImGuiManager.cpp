#include "Engine/ImGui/ImGuiManager.h"

namespace Engine
{
	ImGuiManager::ImGuiManager()
	{
		
	}

	ImGuiManager::~ImGuiManager()
	{
		rlImGuiShutdown();
	}

	void ImGuiManager::Init()
	{
		rlImGuiSetup(true);
	}
}