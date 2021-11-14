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
			//LOG_INFO("ExampleLayer::Update");

			if (KDF::Input::IsKeyPressed(KDF_KEY_TAB))
				LOG_TRACE("Tab key is pressed (poll)!");
		}

		void OnEvent(KDF::Event& event) override
		{
			if (event.GetEventType() == KDF::EventType::KeyPressed) {
				KDF::KeyPressedEvent& e = (KDF::KeyPressedEvent&)event;
				if (e.GetKeyCode() == KDF_KEY_TAB)
					LOG_TRACE("Tab key is pressed!");
				LOG_TRACE("{0}", (char)e.GetKeyCode());
			}
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