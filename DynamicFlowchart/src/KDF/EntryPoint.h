#pragma once

#ifdef KDF_PLATFORM_WINDOWS

extern KDF::Application* KDF::CreateApplication();

int main(int argc, char** argv)
{
	auto app = KDF::CreateApplication();
	app->Run();
	delete app;
}

#endif