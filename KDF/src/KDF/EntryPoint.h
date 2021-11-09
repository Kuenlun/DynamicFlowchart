#pragma once

#ifdef KDF_PLATFORM_WINDOWS

extern KDF::Application* KDF::CreateApplication();

int main(int argc, char** argv)
{
	KDF::Log::Init();
	CORE_LOG_TRACE("Initialized Log");
	CORE_LOG_DEBUG("Initialized Log");
	CORE_LOG_INFO("Initialized Log");
	CORE_LOG_WARN("Initialized Log");
	CORE_LOG_ERROR("Initialized Log");
	CORE_LOG_FATAL("Initialized Log");

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