#pragma once

#include "KDF/Core.h"
#include "Events/Event.h"
#include "Window.h"


namespace KDF {

	class KDF_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_window;
		bool m_running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}


