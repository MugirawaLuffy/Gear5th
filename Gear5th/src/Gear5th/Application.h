#pragma once
#include "Events/Event.h"
#include "Core.h"
#include "Window.h"
#include "Core.h"
#include "Events/ApplicationEvent.h"
#include "Gear5th/LayerStack.h"
#include "Gear5th/Events/Event.h"


namespace Gear5th
{
	class GEAR5TH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};
	//Defined in Client
	Application* CreateApplication();
}



