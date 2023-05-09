#pragma once

#ifdef SH_PLATFORM_WINDOWS

	extern Shoonya::Application* Shoonya::CreateApplication();

	int main()
	{
		Shoonya::Log::Init();
		SH_CORE_WARN("Core Log Initiated!!!");
		int level = 10;
		SH_INFO("Client Log Level is set to {0}", level);
		auto app  = Shoonya::CreateApplication();
		app->Run();
		delete app;
		return 0;
	}

#endif