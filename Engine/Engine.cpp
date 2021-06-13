#include "Engine.h"

Engine::Engine()
{
	window.pollEvent(my_event);
}
Engine::Engine(int x, int y) :Engine()
{
	mode.width = x;
	mode.height = y;
	window.create(mode, "SFML_Window");
}
Engine::Engine(int x, int y, bool fullscreen_on) :Engine(x, y)
{
	//fulscreen mode + coordinates
	if (fullscreen_on)
	{
		window.create(mode, "SFML_Window", sf::Style::Fullscreen);
		window.pollEvent(my_event);
	}
	else
	{
		window.create(mode, "SFML_Window");
		window.pollEvent(my_event);
	}
}

bool Engine::is_running()//General function for Game window;
{
	while (window.pollEvent(my_event))
	{
		if (my_event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
	Game_time = (float)(clock.getElapsedTime().asMicroseconds());
	Game_time /= GameSpeedPrescaler;
	clock.restart();
	return window.isOpen();
}
sf::RenderWindow& Engine::get_window()
{
	return window;
}
float& Engine::get_time()
{
	return (Game_time);
}






