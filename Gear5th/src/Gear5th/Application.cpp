#include "g5pch.h"
#include "Application.h"
#include "Log.h"
#include "Events/ApplicationEvent.h"
namespace Gear5th
{
	Gear5th::Application::Application()
	{
	}

	Gear5th::Application::~Application()
	{
	}

	void Application::Run()
	{
		
		
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			G5_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			G5_TRACE(e);
		}
		while (true);
	}
}


