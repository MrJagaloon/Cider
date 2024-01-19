#pragma once

#include <Cider/Core.h>
#include <Cider/Window.h>
#include <Cider/LayerStack.h>
#include <Cider/Events/KeyEvent.h>
#include <Cider/Events/MouseEvent.h>
#include <Cider/Events/ApplicationEvent.h>

namespace Cider 
{
	class CIDER_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> window;
		bool running;
		LayerStack layerStack;
	};

	// to be defined in client
	Application* CreateApplication();
}

