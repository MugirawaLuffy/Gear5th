/*
Window class is a layer of abstraction that will enable GLFW (vulkan, openGL) to run alongside Win32 Api and DirectX 11
without needing to change entire code sections or frameworks
*/

#pragma once

#include "g5pch.h" //precompiled headers cuz I like my compilation hitting god speed

#include "Gear5th/Core.h"
#include "Gear5th/Events/Event.h"

namespace Gear5th
{
	struct WindowProps		//properties the window should have
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Gear5th Engine x64",
						unsigned int width = 1280,
						unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{}
	};

	//Interface for desktop based windows (including windows, linux, mac)(excluding mobile based windows)
					//who wants to code mobile games anyways

	class GEAR5TH_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

//  --------------   virtuals for every deriving class to override  --------
		virtual ~Window() {} 
		virtual void  OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		//window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}