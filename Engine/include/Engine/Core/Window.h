#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H

#include <raylib.h>
#include <string>

#include "Engine/Core/Core.h"

namespace Engine
{
	struct WindowProperties
	{
		std::string title;
		int width = 1024;
		int height = 600;
		int fps = 60;
		unsigned int flags = FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE;
	};

	class ENGINE_API Window
	{
	public:
		Window(const std::string& title, int width, int height, int fps);
		~Window();

		void Init();
		void Close();
		bool IsClosed() { return WindowShouldClose(); }

	private:
		WindowProperties properties;
	};
}

#endif
