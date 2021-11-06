#pragma once

#ifdef KDF_PLATFORM_WINDOWS

extern KDF::Application* KDF::CreateApplication();

int main(int argc, char** argv)
{
	KDF::Log::Init();
	KDF::Log::GetCoreLogger()->warn("Initialized Log");
	KDF::Log::GetClientLogger()->info("Initialized Log");

	auto app = KDF::CreateApplication();
	app->Run();
	delete app;
}

#endif