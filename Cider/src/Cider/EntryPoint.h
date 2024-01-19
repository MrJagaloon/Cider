#pragma once

#include "./Application.h"

#ifdef CD_PLATFORM_WINDOWS

extern Cider::Application* Cider::CreateApplication();

int main(int argc, char** argv)
{
	Cider::Log::Init();
	CD_CORE_INFO("Starting Cider Engine");

	CD_CORE_INFO("Creating and starting Application");
	Cider::Application* app = Cider::CreateApplication();

	app->Run();
	delete app;

	CD_CORE_INFO("Exiting Cider Engine");
}

#endif
