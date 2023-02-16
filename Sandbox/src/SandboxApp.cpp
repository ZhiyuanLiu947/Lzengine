#include <Lzengine.h>

class ExampleLayer : public LZE::Layer {
public:
    ExampleLayer() : Layer("Example") {}

    void OnUpdate() override {
        LZE_INFO("ExampleLayer::Update in the application: Sandbox");
    }

    void OnEvent(LZE::Event& event) override {
        LZE_TRACE("{0}", event);
    }
};

class Sandbox : public LZE::Application {
public:
    Sandbox() {
        PushLayer(new ExampleLayer());
    }

    ~Sandbox() {}
};

LZE::Application* LZE::CreateApplication() {
    return new Sandbox();
}