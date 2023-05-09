#include "Application.h"

// For Testing
#include "Shoonya\EventsHandler\ApplicationEvent.h"
#include "Shoonya\Log.h"

Shoonya::Application::Application()
{
}

Shoonya::Application::~Application()
{
}

void Shoonya::Application::Run()
{
	WindowResizeEvent e(1280, 720);
	if (e.IsInCategory(EventCategoryApplication)) { SH_TRACE(e); }
	if (e.IsInCategory(EventCategoryInput))		  { SH_TRACE(e); }	//Won't execute becuase the category is not input
	while (true);
}