#pragma once

#include "Event.h"

namespace Cider
{
    class CIDER_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) : width(width), height(height) {}

        inline unsigned int GetWidth() const { return width; }
        inline unsigned int GetHeight() const { return height; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: (" << width << ", " << height <<")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    private:
        unsigned int width, height;
    };

    class CIDER_API WindowMovedEvent : public Event
    {
    public:
        WindowMovedEvent(unsigned int x, unsigned int y) : x(x), y(y) {}

        inline int GetX() const { return x; }
        inline int GetY() const { return y; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowMovedEvent: (" << x << ", " << y <<")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowMoved)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    private:
        int x, y;
    };

    class CIDER_API WindowFocusEvent : public Event
    {
    public:
        WindowFocusEvent() {}

        std::string ToString() const override { return "WindowFocusEvent"; }

        EVENT_CLASS_TYPE(WindowFocus)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class CIDER_API WindowLostFocusEvent : public Event
    {
    public:
        WindowLostFocusEvent() {}

        std::string ToString() const override { return "WindowLostFocusEvent"; }

        EVENT_CLASS_TYPE(WindowLostFocus)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class CIDER_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}

        std::string ToString() const override { return "WindowCloseEvent"; }

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class CIDER_API AppTickEvent : public Event
    {
    public:
        AppTickEvent() {}

        std::string ToString() const override { return "AppTickEvent"; }

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class CIDER_API AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() {}

        std::string ToString() const override { return "AppUpdateEvent"; }

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class CIDER_API AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() {}

        std::string ToString() const override { return "AppRenderEvent"; }

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}
