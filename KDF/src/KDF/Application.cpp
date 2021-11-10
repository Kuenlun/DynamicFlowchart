#include "KDFpch.h"
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
			m_window->OnUpdate();
		}
	}
}