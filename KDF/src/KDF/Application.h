#pragma once

#include "KDF/Core.h"

#include "Window.h"
#include "KDF/LayerStack.h"
#include "KDF/Events/Event.h"
#include "KDF/Events/ApplicationEvent.h"

#include "KDF/Core/Timestep.h"

#include "KDF/ImGui/ImGuiLayer.h"


namespace KDF {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}


