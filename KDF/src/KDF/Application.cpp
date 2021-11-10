#include "KDFpch.h"

#include <GLFW/glfw3.h>

#include "KDF/Events/ApplicationEvent.h"
#include "KDF/Log.h"

#include "Application.h"


namespace KDF
{
	Application::Application()
	{
		m_window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_window->OnUpdate();
		}
	}
}