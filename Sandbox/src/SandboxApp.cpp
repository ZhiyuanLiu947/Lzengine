#include <Lzengine.h>

class Sandbox : public LZE::Application {
public:
	Sandbox() {}

	~Sandbox() {}
};

LZE::Application* LZE::CreateApplication() {
	return new Sandbox();
}