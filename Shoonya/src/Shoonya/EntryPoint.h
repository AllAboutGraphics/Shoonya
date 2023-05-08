#pragma once
#include <iostream>
#ifdef SH_PLATFORM_WINDOWS

	extern Shoonya::Application* Shoonya::CreateApplication();

	int main()
	{
		std::cout << "Hello World!" << std::endl;
		auto app = Shoonya::CreateApplication();
		app->Run();
		delete app;
		return 0;
	}

#endif