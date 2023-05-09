#pragma once

#include <sstream>
#include "Event.h"

namespace Shoonya
{
#pragma region Parent Class
	class SHOONYA_API KeyEvent : public Event
	{
		protected:
			int m_KeyCode;
			//Constructor : Keeping Constructor Abstracted so that it can only be created by its child classes.
			KeyEvent(int keyCode) : m_KeyCode(keyCode) {}

		public:
			inline int GetKeyCode() { return m_KeyCode; }

			EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	};
#pragma endregion

#pragma region Child Classes
	class SHOONYA_API KeyPressedEvent : public KeyEvent
	{
		private:
			int m_RepeatCount;

		public:
			KeyPressedEvent(int keyCode, int repeatCount) : KeyEvent(keyCode), m_RepeatCount(repeatCount) {}

			inline int GetRepeatCount() const { return m_RepeatCount; }

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KeyPressedEvent : " << m_KeyCode << " ( " << m_RepeatCount << " ) ";
				return ss.str();
			}
			EVENT_CLASS_TYPE(KeyPressed)
	};
	
	class SHOONYA_API KeyReleasedEvent : public KeyEvent
	{
		public:
			KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "KeyReleaseEvent : " << m_KeyCode;
				return ss.str();
			}
			EVENT_CLASS_TYPE(KeyReleased)
	};
#pragma endregion
}