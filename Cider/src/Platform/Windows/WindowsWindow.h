#pragma once

#include <Cider/Window.h>

#include <GLFW/glfw3.h>

namespace Cider
{
    class WindowsWindow : public Window
    {
    public:
        WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow();

        void OnUpdate() override;

        virtual unsigned int GetWidth() const override { return data.width; }
        virtual unsigned int GetHeight() const override { return data.width; }

        virtual void SetEventCallback(const EventCallbackFn& callback) override { data.eventCallback = callback; }
        virtual void SetVSync(bool enabled) override;
        virtual bool IsVSync() const override;

    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();

        GLFWwindow* window;

        struct WindowData
        {
            std::string title;
            unsigned int width, height;
            bool vsync;

            EventCallbackFn eventCallback;
        };

        WindowData data;
    };
}
