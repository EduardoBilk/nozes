#pragma once
#ifdef NZ_PLATFORM_WINDOWS

extern Nozes::Application* Nozes::CreateApplication();


int main(int argc, char** argv) {
	printf("É nozes!\n");
	auto app = Nozes::CreateApplication();
	app->Run();
	delete app;

}
#endif // NZ_PLATFORM_WINDOWS
