#pragma once

#include "Event.h"


namespace Gear5th
{
	class GEAR5TH_API KeyEvent : public Event
	{
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:							//protected constructor because only inheriting types shall construct Key Events
		KeyEvent(int keycode)
			: mKeyCode(keycode)
		{}

		int m_KeyCode;
	};

	class GEAR5TH_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount)
		{}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats";
			return ss.str();
		}			//slow as fuck but only used for debugging purposes, will not slow down actual runtime, thank god

		EVENT_CLASS_TYPE(KeyPressed) //defined in Event.h
	private:
		int m_RepeatCount;
	};

	class GEAR5TH_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode)
		{}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss;
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}