#pragma once

#include "KDF/Core.h"

#include "Window.h"
#include "KDF/LayerStack.h"
#include "KDF/Events/Event.h"
#include "KDF/Events/ApplicationEvent.h"

#include "KDF/ImGui/ImGuiLayer.h"

// TEMPORARY
#include "KDF/Renderer/Shader.h"
#include "KDF/Renderer/Buffer.h"


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

		inline Window& GetWindow() { return *m_window; }

		inline static Application& Get() { return *s_instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_running = true;
		LayerStack m_layerStack;

		unsigned int m_vertexArray;
		std::unique_ptr<Shader> m_shader;
		std::unique_ptr<VertexBuffer> m_VertexBuffer;
		std::unique_ptr<IndexBuffer> m_IndexBuffer;

	private:
		static Application* s_instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}


