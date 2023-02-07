#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace LZE {

	class __declspec(dllexport) Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client application
	Application* CreateApplication();
}

