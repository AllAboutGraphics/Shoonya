#pragma once

#include "Core.h"

namespace Shoonya
{
	class SHOONYA_API Application
	{
		public:
			Application();
			virtual ~Application();
			void Run();
	};

	//To be defined in the client application
	Application* CreateApplication();
}