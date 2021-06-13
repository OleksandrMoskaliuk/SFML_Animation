#include "main.h"

int main()
{
	Engine engine(1280, 720);
	Animation animator_1(engine, false, sf::Vector2i(150, 0));
	Animation animator_2(engine, true, sf::Vector2i(1130, 200));
	while (engine.is_running())
	{
		engine.ClearDisplay();

		animator_1.Run_Animation();
		animator_2.Run_Animation();

		engine.Display();
	}

    return 0;
}