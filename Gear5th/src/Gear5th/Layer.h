#pragma once

#include "Gear5th/Core.h"
#include "Gear5th/Events/Event.h"

namespace Gear5th
{
	class GEAR5TH_API Layer // __declspec(dllexport) //makes class available to sources linking to Gear5th.dll
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected: std::string m_DebugName;
	};
}



