#include "cdpch.h"
#include "WindowsWindow.h"
#include "Cider/Events/ApplicationEvent.h"
#include "Cider/Events/MouseEvent.h"
#include "Cider/Events/KeyEvent.h"

namespace Cider
{
    static bool glfwInitialized = false;

    static void GLFWErrorCallback(int error, const char* description)
    {
        CD_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    Window* Window::Create(const WindowProps& props)
    {
        return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const WindowProps& props)
    {
        Init(props);
    }

    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    void WindowsWindow::Init(const WindowProps& props)
    {
        data.title = props.title;
        data.width = props.width;
        data.height = props.height;

        CD_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

        if (!glfwInitialized)
        {
            int success = glfwInit();
            CD_CORE_ASSERT(success, "Could not initialize GLFW!");
            glfwSetErrorCallback(GLFWErrorCallback);
            glfwInitialized = true;
        }

        window = glfwCreateWindow((int)props.width, (int)props.height, props.title.c_str(), NULL, NULL);
        glfwMakeContextCurrent(window);
        glfwSetWindowUserPointer(window, &data);
        SetVSync(false);

        // glfw callbacks
        glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) 
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                data.width = width;
                data.height = height;
                WindowResizeEvent e(width, height);
                data.eventCallback(e);
            });
        glfwSetWindowCloseCallback(window, [](GLFWwindow* window)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                WindowCloseEvent e;
                data.eventCallback(e);
            });
        glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

                switch (action)
                {
                case GLFW_PRESS:
                {
                    KeyPressedEvent e(key, 0);
                    data.eventCallback(e);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent e(key, 1);
                    data.eventCallback(e);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent e(key);
                    data.eventCallback(e);
                    break;
                }
                default:
                    break;
                }
            });
        glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

                switch (action)
                {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent e(button);
                    data.eventCallback(e);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonPressedEvent e(button);
                    data.eventCallback(e);
                    break;
                }
                default:
                    break;
                }
            });
        glfwSetScrollCallback(window, [](GLFWwindow* window, double x, double y)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                MouseScrolledEvent e(x, y);
                data.eventCallback(e);
            });
        glfwSetCursorPosCallback(window, [](GLFWwindow* window, double x, double y)
            {
                WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
                MouseMovedEvent e(x, y);
                data.eventCallback(e);
            });
    }

    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(window);
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        glfwSwapInterval(enabled ? 1 : 0);
        data.vsync = enabled;
    }

    bool WindowsWindow::IsVSync() const
    {
        return data.vsync;
    }
}
