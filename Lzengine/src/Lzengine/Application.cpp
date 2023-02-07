#include "Application.h"
#include "Lzengine/Events/ApplicationEvent.h"
#include "Lzengine/Log.h"

namespace LZE {

	Application::Application() {
	}

	Application::~Application() {
	}

	void Application::Run()
	{
		WindowResizeEvent e(1920,1080);
		LZE_TRACE(e);

		while (true);
	}

}