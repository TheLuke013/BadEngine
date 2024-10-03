#include "Engine/Core/Application.h"

namespace Engine
{
	Application::Application()
		: window(new Window("Bad Engine", 1024, 600, 60)), imguiManager(new ImGuiManager())
	{
		isRunning = true;

		Log::Init("logs.txt");
		LOG_INFO("Engine Initialized");

		window->Init();
		imguiManager->Init();
	}

	Application::~Application()
	{
		window->Close();

		delete imguiManager;
		delete window;

		LOG_INFO("Engine Shutdown");
		Log::Shutdown();
	}

	void Application::Run()
	{
		OnReady();

		while (isRunning && !window->IsClosed())
		{
			OnUpdate(); //updates client-application

			BeginDrawing();

				ClearBackground(DARKGRAY);

				//process imgui if active
				if (imguiManager->IsActive())
				{
					rlImGuiBegin();

					bool open = true;
					ImGui::ShowDemoWindow(&open);

					rlImGuiEnd();
				}

			EndDrawing();
		}
	}

	void Application::Quit()
	{
		isRunning = false;
	}
}