#pragma once

#ifdef LZE_PLATFORM_WINDOWS

extern LZE::Application* LZE::CreateApplication();

int main(int argc, char** argv) {

    LZE::Log::Init();
    LZE_CORE_INFO("LZEngine initialized.");
    LZE_INFO("Application initialized.");

    printf("LZEngine initialized.");
    auto app = LZE::CreateApplication();
    app->Run();
    delete app;
}

#endif