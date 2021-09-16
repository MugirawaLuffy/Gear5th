#include "g5pch.h"
#include "Application.h"
#include "Log.h"
#include "Events/ApplicationEvent.h"

#include <GLFW/glfw3.h>

namespace Gear5th
{
	Gear5th::Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Gear5th::Application::~Application()
	{
	}

	void Application::Run()
	{


		while (m_Running)
		{
			glClearColor(0.025, 0.025, 0.08, 0.6);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}


