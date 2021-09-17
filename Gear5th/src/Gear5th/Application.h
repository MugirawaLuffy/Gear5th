#pragma once
#include "Events/Event.h"
#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"

namespace Gear5th
{
	class GEAR5TH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	//Defined in Client
	Application* CreateApplication();
}



