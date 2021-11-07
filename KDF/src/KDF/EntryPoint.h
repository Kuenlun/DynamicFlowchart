#pragma once

#ifdef KDF_PLATFORM_WINDOWS

extern KDF::Application* KDF::CreateApplication();

int main(int argc, char** argv)
{
	KDF::Log::Init();
	LOG_CORE_TRACE("Initialized Log");
	LOG_CORE_DEBUG("Initialized Log");
	LOG_CORE_INFO("Initialized Log");
	LOG_CORE_WARN("Initialized Log");
	LOG_CORE_ERROR("Initialized Log");
	LOG_CORE_FATAL("Initialized Log");

	LOG_TRACE("Initialized Log");
	LOG_DEBUG("Initialized Log");
	LOG_INFO("Initialized Log");
	LOG_WARN("Initialized Log");
	LOG_ERROR("Initialized Log");
	LOG_FATAL("Initialized Log");



	auto app = KDF::CreateApplication();
	app->Run();
	delete app;
}

#endif