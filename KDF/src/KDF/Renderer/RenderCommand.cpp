#include "KDFpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"


namespace KDF {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}