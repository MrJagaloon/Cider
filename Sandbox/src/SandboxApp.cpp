#include <cdpch.h>
#include <Cider.h>
#include <iostream>

class ExampleLayer : public Cider::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override
	{
		CD_INFO("Example Layer Update");
	}

	void OnEvent(Cider::Event& e) override
	{
		CD_TRACE("{0}", e.ToString());
	}
};

class SandboxApp : public Cider::Application
{
public:
	SandboxApp()
	{
		PushLayer(new ExampleLayer());
	}

	~SandboxApp()
	{

	}

	void Run() override
	{
		Application::Run();
	}
};

Cider::Application* Cider::CreateApplication()
{
	return new SandboxApp();
}
