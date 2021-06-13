#pragma once
#include "..\Engine\Engine.h"

#ifndef ANIMATION_H
#define ANIMATION_H



class Animation
{
private:
	sf::Vector2f Head_Position;
	sf::Vector2f Right_arm_Position;
	sf::Vector2f Right_leg_Position;
	sf::Vector2f Left_leg_Position;
	sf::Vector2f Chest_Position;
	sf::Vector2f Left_arm_Position;
	sf::Vector2i Standart_Position;
	Engine* game;
	float* GameTime = nullptr;
	bool Right_or_Left = false;
private:
	struct Active_Square {
		sf::Vector2i begin_point;
		sf::Vector2i end_point;
		Active_Square()
		{
			begin_point.x = 0;
			begin_point.y = 0;
			end_point.x = 150;
			end_point.y = 300;
		}

	}ActiveSquare; //new idea(not implemented yet);
	struct Head
	{
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;
		const char* path = "Images/Head.png";
		bool Animation_Triger = true;
		float Anim_Area = -1;
		float Anim_Speed = 0.004f;

		void Breathing(const float& Game_time)
		{
			if (Anim_Area > 2) { Animation_Triger = false; }
			if (Anim_Area < -2) { Animation_Triger = true; }

			if (Animation_Triger) // (true) anim range ++ 
			{
				sprite.move(0, (Game_time * Anim_Speed));
				Anim_Area += Game_time * Anim_Speed;
			}
			else  //  (false) anim range --
			{
				sprite.move(0, -(Game_time * Anim_Speed));
				Anim_Area -= Game_time * Anim_Speed;
			}
		}
	}Player_Head;
	struct Chest
	{
		const char* path = "Images/Chest.png";
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;
		bool Animation_Triger = true;
		float Anim_Area = 0;
		float Anim_Speed = 0.004f;
		void Breathing(const float& Game_time)
		{
			if (Anim_Area > 2) { Animation_Triger = false; }
			if (Anim_Area < -2) { Animation_Triger = true; }

			if (Animation_Triger) // (true) anim range ++ 
			{
				sprite.move(0, (Game_time * Anim_Speed));
				Anim_Area += Game_time * Anim_Speed;
			}
			else  //  (false) anim range --
			{
				sprite.move(0, -(Game_time * Anim_Speed));
				Anim_Area -= Game_time * Anim_Speed;
			}
		}
	}Player_Chest;
	struct Right_arm
	{
		const char* path = "Images/Right_Arm.png";
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;
		bool Animation_Triger = true;
		float Anim_Area = -1;
		float Anim_Speed = (float)0.004;
		void Breathing(const float& Game_time)
		{
			if (Anim_Area > 2) { Animation_Triger = false; }
			if (Anim_Area < -2) { Animation_Triger = true; }

			if (Animation_Triger) // (true) anim range ++ 
			{
				sprite.move(0, (Game_time * Anim_Speed));
				Anim_Area += Game_time * Anim_Speed;
			}
			else  //  (false) anim range --
			{
				sprite.move(0, -(Game_time * Anim_Speed));
				Anim_Area -= Game_time * Anim_Speed;
			}

		}

	}Player_Right_arm;
	struct Left_arm
	{
		const char* path = "Images/Left_Arm.png";
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;
		bool Animation_Triger = true;
		float Anim_Area = (float)-1.5;
		float Anim_Speed = (float)0.004;
		void Breathing(const float& Game_time)
		{
			if (Anim_Area > 2) { Animation_Triger = false; }
			if (Anim_Area < -2) { Animation_Triger = true; }

			if (Animation_Triger) // (true) anim range ++ 
			{
				sprite.move(0, (Game_time * Anim_Speed));
				Anim_Area += Game_time * Anim_Speed;
			}
			else  //  (false) anim range --
			{
				sprite.move(0, -(Game_time * Anim_Speed));
				Anim_Area -= Game_time * Anim_Speed;
			}
		}

	}Player_Left_arm;
	struct Right_leg
	{
		const char* path = "Images/Right_Leg.png";
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;
		bool Animation_Triger = true;
		float Anim_Area = 0;
		float Anim_Speed = (float)0.004;
		void Breathing(const float& Game_time)
		{
			if (Anim_Area > 2) { Animation_Triger = false; }
			if (Anim_Area < -2) { Animation_Triger = true; }

			if (Animation_Triger) // (true) anim range ++ 
			{
				sprite.move(0, (Game_time * Anim_Speed));
				Anim_Area += Game_time * Anim_Speed;
			}
			else  //  (false) anim range --
			{
				sprite.move(0, -(Game_time * Anim_Speed));
				Anim_Area -= Game_time * Anim_Speed;
			}
		}

	}Player_Right_leg;
	struct Left_leg
	{
		const char* path = "Images/Left_Leg.png";
		sf::Image image;
		sf::Texture texture;
		sf::Sprite sprite;
		bool Animation_Triger = true;
		float Anim_Area = 0;
		float Anim_Speed = (float)0.004;
		void Breathing(const float& Game_time)
		{
			if (Anim_Area > 2) { Animation_Triger = false; }
			if (Anim_Area < -2) { Animation_Triger = true; }

			if (Animation_Triger) // (true) anim range ++ 
			{
				sprite.move(0, (Game_time * Anim_Speed));
				Anim_Area += Game_time * Anim_Speed;
			}
			else  //  (false) anim range --
			{
				sprite.move(0, -(Game_time * Anim_Speed));
				Anim_Area -= Game_time * Anim_Speed;
			}
		}
	}Player_Left_leg;
public:
	Animation(Engine& game, bool Right_or_Left, sf::Vector2i StandartPosition);
	~Animation(){}
	void Run_Animation();
private:
	template <typename T>
	void AnimPartInit(T& body_part, bool Right_or_Left, sf::Vector2i StandartPosition)
	{
		body_part.image.loadFromFile(body_part.path);
		body_part.image.createMaskFromColor(sf::Color::White);
		body_part.texture.loadFromImage(body_part.image);
		body_part.sprite.setTexture(body_part.texture);

		if (Right_or_Left) {}
		else { body_part.sprite.setScale(-1, 1); }
		body_part.sprite.setPosition((float)StandartPosition.x, (float)StandartPosition.y);
	}
	void Attack();
	void Step(const int step_distance);
	void Attack_Animation();
	void save_position();
	void load_position();
};
#endif // ANIMATION_H