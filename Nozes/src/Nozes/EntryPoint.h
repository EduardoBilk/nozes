#pragma once
#ifdef NZ_PLATFORM_WINDOWS

extern Nozes::Application* Nozes::CreateApplication();


int main(int argc, char** argv) {
	Nozes::Log::init();
	NZ_CORE_WARN("initialized Log");
	int a = 8;
	NZ_INFO("Olar! a={0}",a);

	auto app = Nozes::CreateApplication();
	app->Run();
	delete app;

}
#endif // NZ_PLATFORM_WINDOWS
