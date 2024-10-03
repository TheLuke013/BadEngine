#include "Engine/Core/Application.h"

namespace Engine
{
	Application::Application()
		: window(new Window("Bad Engine", 1024, 600))
	{
		isRunning = true;

		Log::Init("logs.txt");
		LOG_INFO("Engine Initialized");

		window->Init();
	}

	Application::~Application()
	{
		//window.Close();

		LOG_INFO("Engine Shutdown");
		Log::Shutdown();
	}

	void Application::Run()
	{
		SetTargetFPS(60);

		OnReady();

		while (isRunning && !window->IsClosed())
		{
			OnUpdate(); //updates client-application

			BeginDrawing();

				ClearBackground(SKYBLUE);

			EndDrawing();
		}
	}

	void Application::Quit()
	{
		isRunning = false;
	}
}