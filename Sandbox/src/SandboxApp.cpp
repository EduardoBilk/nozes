#include <Nozes.h>

class Sandbox : public Nozes::Application {
public:
	Sandbox(){

	}
	~Sandbox(){

	}
};
Nozes::Application* Nozes::CreateApplication() {
	return new Sandbox();
}