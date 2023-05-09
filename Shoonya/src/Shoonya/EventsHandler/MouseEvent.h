#pragma once

#include <sstream>
#include "Event.h"

namespace Shoonya
{
	class SHOONYA_API MouseMovedEvent : public Event
	{
		private:
			float m_MouseX;
			float m_MouseY;

		public:
			MouseMovedEvent(int mouseX, int mouseY) : m_MouseX(mouseX), m_MouseY(mouseY) {}

			inline float GetX() const { return m_MouseX; }
			inline float GetY() const { return m_MouseY; }

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseMovedEvent : " << m_MouseX << ", " << m_MouseY;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

	class SHOONYA_API MouseScrolledEvent : public Event
	{
		private:
			float m_OffsetX;
			float m_OffsetY;

		public:
			MouseScrolledEvent(float offsetX, float offsetY) : m_OffsetX(offsetX), m_OffsetY(offsetY) {}
			
			inline float GetXOffset() const { return m_OffsetX; }
			inline float GetYOffset() const { return m_OffsetY; }

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseScrolledEvent : " << m_OffsetX << m_OffsetY;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	};

#pragma region Parent Class
	class SHOONYA_API MouseButtonEvent : public Event
	{
		protected:
			int m_Button;
			//Constructor : Keeping Constructor Abstracted so that it can only be created by its child classes.
			MouseButtonEvent(int button) : m_Button(button) {}

		public:
			inline int GetMouseButton() const { return m_Button; }
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryMouseButton | EventCategoryInput)

	};
#pragma endregion

#pragma region Child Classes
	class SHOONYA_API MouseButtonPressedEvent : public MouseButtonEvent
	{
		public:
			MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseButtonPressedEvent : " << m_Button;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class SHOONYA_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
		
		public:
			MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

			std::string ToString() const override
			{
				std::stringstream ss;
				ss << "MouseButtonreleaseEvent : " << m_Button;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseButtonReleased)
	};
#pragma endregion
}