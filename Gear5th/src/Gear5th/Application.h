#pragma once
#include "Events/Event.h"
#include "Core.h"

namespace Gear5th
{
	class GEAR5TH_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	//Defined in Cient
	Application* CreateApplication();
}



