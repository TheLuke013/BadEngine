#include "Engine/Core/Window.h"

namespace Engine
{
	Window::Window(const std::string& title, int width, int height, int fps)
	{
		properties.title = title;
		properties.width = width;
		properties.height = height;
		properties.fps = fps;
	}

	Window::~Window()
	{
		
	}

	void Window::Init()
	{
		SetConfigFlags(properties.flags);
		InitWindow(properties.width, properties.height, properties.title.c_str());
		SetTargetFPS(properties.fps);
	}

	void Window::Close()
	{
		CloseWindow();
	}
}