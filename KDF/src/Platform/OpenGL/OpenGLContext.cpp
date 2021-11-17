#include "KDFpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <Glad/glad.h>


namespace KDF {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_windowHandle(windowHandle)
	{
		KDF_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_windowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		KDF_CORE_ASSERT(status, "Failed to initialize Glad");

		CORE_LOG_INFO("OpenGL Info:");
		CORE_LOG_INFO("\tVendor {0}", glGetString(GL_VENDOR));
		CORE_LOG_INFO("\tRenderer {0}", glGetString(GL_RENDERER));
		CORE_LOG_INFO("\tVersion {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{


		glfwSwapBuffers(m_windowHandle);
	}

}