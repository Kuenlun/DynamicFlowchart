#pragma once

#include "KDF/Core.h"
#include "KDF/Events/Event.h"
#include "KDF/Events/ApplicationEvent.h"
#include "Window.h"


namespace KDF {

	class KDF_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_window;
		bool m_running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}


