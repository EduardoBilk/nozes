#pragma once
#include "Core.h"

namespace Nozes {
	class NOZES_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	Application* CreateApplication();
}
