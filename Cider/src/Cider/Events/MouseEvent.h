#pragma once

#include "Event.h"

namespace Cider
{
    class CIDER_API MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float x, float y) : mouseX(x), mouseY(y) {}

        inline float GetX() const { return mouseX; }
        inline float GetY() const { return mouseY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: (" << mouseX << ", " << mouseY <<")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    protected:
        float mouseX, mouseY;
    };

    class CIDER_API MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float x, float y) : scrollX(x), scrollY(y) {}

        inline float GetX() const { return scrollX; }
        inline float GetY() const { return scrollY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: (" << scrollX << ", " << scrollY <<")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    protected:
        float scrollX, scrollY;
    };

    class CIDER_API MouseButtonEvent : public Event
    {
    public:
        inline int GetMouseButton() const { return button; }

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    protected:
        MouseButtonEvent(int button) : button(button) {}

        int button;
    };

    class CIDER_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class CIDER_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}
