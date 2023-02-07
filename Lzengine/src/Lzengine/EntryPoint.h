#pragma once

#ifdef LZE_PLATFORM_WINDOWS

extern LZE::Application* LZE::CreateApplication();
	
int main(int argc, char** argv) {

	LZE::Log::Init();
	LZE_CORE_WARN("Log started, this is a warning message for core logger");
	LZE_CORE_ERROR("Log started, this is a error message for core logger");

	int a = 10;
	LZE_INFO("This is a info message for client logger with a variable {0}", a);

	printf("Lzengine started...");
	auto app = LZE::CreateApplication();
	app->Run();
	delete app;
}

#endif