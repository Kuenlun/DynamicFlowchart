#include <KDF.h>


class Sandbox : public KDF::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

KDF::Application* KDF::CreateApplication()
{
	return new Sandbox();
}