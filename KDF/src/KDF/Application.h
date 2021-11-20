#pragma once

#include "KDF/Core.h"

#include "Window.h"
#include "KDF/LayerStack.h"
#include "KDF/Events/Event.h"
#include "KDF/Events/ApplicationEvent.h"

#include "KDF/ImGui/ImGuiLayer.h"

#include "KDF/Renderer/VertexArray.h"
#include "KDF/Renderer/Shader.h"
#include "KDF/Renderer/Buffer.h"

#include "KDF/Renderer/OrthographicCamera.h"


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

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}


