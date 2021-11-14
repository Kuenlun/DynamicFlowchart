#include <KDF.h>


class ExampleLayer : public KDF::Layer
{
	public:
		ExampleLayer() :
			Layer("Example")
		{
		}

		void OnUpdate() override
		{
			LOG_INFO("ExampleLayer::Update");
		}

		void OnEvent(KDF::Event& event) override
		{
			LOG_TRACE("{0}", event);
		}
};


class Sandbox : public KDF::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new KDF::ImGuiLayer());
	}

	~Sandbox()
	{
	}
};

KDF::Application* KDF::CreateApplication()
{
	return new Sandbox();
}