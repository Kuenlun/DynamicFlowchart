#pragma once

#include "KDF/Core.h"

#include "Window.h"
#include "KDF/LayerStack.h"
#include "KDF/Events/Event.h"
#include "KDF/Events/ApplicationEvent.h"



namespace KDF {

	class KDF_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_window;
		bool m_running = true;
		LayerStack m_layerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}


