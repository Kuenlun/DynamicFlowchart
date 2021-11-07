#include "KDF/Events/ApplicationEvent.h"
#include "KDF/Log.h"

#include "Application.h"


namespace KDF
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		LOG_TRACE(e);

		while (true);
	}
}