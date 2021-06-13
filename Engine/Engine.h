#pragma once
#include <SFML/Graphics.hpp>

#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
private:
	sf::Clock clock;
	sf::VideoMode mode;
	sf::Event my_event;
	float Game_time = (float)(clock.getElapsedTime().asMicroseconds());
	float camera_speed = (float)(0.2);
	int GameSpeedPrescaler = 1000;
	sf::RenderWindow window;
public:
	Engine();
	Engine(int x, int y); 
	Engine(int x, int y, bool fullscreen_on); 
	~Engine() {};
	bool is_running(); 
	sf::RenderWindow& get_window();
	float& get_time();
	float& get_time_ptr()
	{
		return Game_time;
	}
	void ClearDisplay() 
	{
		window.clear(); 
	}
	void Display() 
	{
		window.display(); 
	}
	template <typename T>
	void draw(T& sprite)
	{
		window.draw(sprite);
	}
};

#endif // !ENGINE_H