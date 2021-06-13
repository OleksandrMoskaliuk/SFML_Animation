#include "Animation.h"

Animation::Animation(Engine& game, bool Right_or_Left, sf::Vector2i StandartPosition)
{
	this->game = &game;
	this->GameTime = &game.get_time_ptr();
	AnimPartInit(Player_Head, Right_or_Left, StandartPosition);
	AnimPartInit(Player_Chest, Right_or_Left, StandartPosition);
	AnimPartInit(Player_Right_arm, Right_or_Left, StandartPosition);
	AnimPartInit(Player_Left_arm, Right_or_Left, StandartPosition);
	AnimPartInit(Player_Right_leg, Right_or_Left, StandartPosition);
	AnimPartInit(Player_Left_leg, Right_or_Left, StandartPosition);
}

void Animation::Run_Animation()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		Step(300);
		Step(-300);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		Attack_Animation();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		//Player_Left_arm.sprite.setPosition()
	}

	Player_Head.Breathing(*GameTime);
	Player_Chest.Breathing(*GameTime);
	Player_Left_arm.Breathing(*GameTime);
	Player_Right_arm.Breathing(*GameTime);
	game->draw(Player_Head.sprite);
	game->draw(Player_Right_arm.sprite);
	game->draw(Player_Right_leg.sprite);
	game->draw(Player_Left_leg.sprite);
	game->draw(Player_Chest.sprite);
	game->draw(Player_Left_arm.sprite);

}
void Animation::Attack()
{
	save_position();
	const float SprintSpeed = 0.015f;
	const float max_distance = 10.0f;
	float distance = 0;
	const float RotationSpeed = 0.0001f;
	const float max_rotation = 30.0f;
	float rotation = 0;
	while (distance <= max_distance)
	{
		Player_Head.sprite.move(distance, 0);
		Player_Right_arm.sprite.move(distance, 0);
		Player_Right_leg.sprite.move(distance, 0);
		Player_Left_leg.sprite.move(distance, 0);
		Player_Chest.sprite.move(distance, 0);
		Player_Left_arm.sprite.move(distance, 0);

		game->ClearDisplay();
		game->draw(Player_Head.sprite);
		game->draw(Player_Right_arm.sprite);
		game->draw(Player_Right_leg.sprite);
		game->draw(Player_Left_leg.sprite);
		game->draw(Player_Chest.sprite);
		game->draw(Player_Left_arm.sprite);
		game->Display();
		distance += SprintSpeed * *GameTime;
	}

	while (distance >= 0)
	{
		Player_Head.sprite.move(-distance, 0);
		Player_Right_arm.sprite.move(-distance, 0);
		Player_Right_leg.sprite.move(-distance, 0);
		Player_Left_leg.sprite.move(-distance, 0);
		Player_Chest.sprite.move(-distance, 0);
		Player_Left_arm.sprite.move(-distance, 0);
		game->ClearDisplay();
		game->draw(Player_Head.sprite);
		game->draw(Player_Right_arm.sprite);
		game->draw(Player_Right_leg.sprite);
		game->draw(Player_Left_leg.sprite);
		game->draw(Player_Chest.sprite);
		game->draw(Player_Left_arm.sprite);
		game->Display();
		distance -= SprintSpeed * *GameTime;
	}
	load_position();
}
void Animation::Step(const int step_distance)
{
	float SprintSpeed = 0.2f;
	float distance = 0;
	if (step_distance > 0)
	{
		float point = (Player_Chest.sprite.getPosition().x + step_distance);
		while (Player_Chest.sprite.getPosition().x < point)
		{
			Player_Head.Breathing(*GameTime);
			Player_Chest.Breathing(*GameTime);
			Player_Left_arm.Breathing(*GameTime);
			Player_Right_arm.Breathing(*GameTime);
			Player_Head.sprite.move(SprintSpeed * *GameTime, 0);
			Player_Right_arm.sprite.move(SprintSpeed * *GameTime, 0);
			Player_Right_leg.sprite.move(SprintSpeed * *GameTime, 0);
			Player_Left_leg.sprite.move(SprintSpeed * *GameTime, 0);
			Player_Chest.sprite.move(SprintSpeed * *GameTime, 0);
			Player_Left_arm.sprite.move(SprintSpeed * *GameTime, 0);
			game->is_running();
			game->ClearDisplay();
			game->draw(Player_Head.sprite);
			game->draw(Player_Right_arm.sprite);
			game->draw(Player_Right_leg.sprite);
			game->draw(Player_Left_leg.sprite);
			game->draw(Player_Chest.sprite);
			game->draw(Player_Left_arm.sprite);
			game->Display();
		}
	}
	if (step_distance < 0)
	{
		float point = (Player_Chest.sprite.getPosition().x + step_distance);
		while (Player_Chest.sprite.getPosition().x > point)
		{
			Player_Head.Breathing(*GameTime);
			Player_Chest.Breathing(*GameTime);
			Player_Left_arm.Breathing(*GameTime);
			Player_Right_arm.Breathing(*GameTime);
			Player_Head.sprite.move(-(SprintSpeed * *GameTime), 0);
			Player_Right_arm.sprite.move(-(SprintSpeed * *GameTime), 0);
			Player_Right_leg.sprite.move(-(SprintSpeed * *GameTime), 0);
			Player_Left_leg.sprite.move(-(SprintSpeed * *GameTime), 0);
			Player_Chest.sprite.move(-(SprintSpeed * *GameTime), 0);
			Player_Left_arm.sprite.move(-(SprintSpeed * *GameTime), 0);
			game->is_running();
			game->ClearDisplay();
			game->draw(Player_Head.sprite);
			game->draw(Player_Right_arm.sprite);
			game->draw(Player_Right_leg.sprite);
			game->draw(Player_Left_leg.sprite);
			game->draw(Player_Chest.sprite);
			game->draw(Player_Left_arm.sprite);
			game->Display();
		}
	}
}
void Animation::Attack_Animation()
{

	const float RotateSpeed = 0.15f;
	float RotateAngle = Player_Left_arm.sprite.getRotation() - 5;

	while (Player_Left_arm.sprite.getRotation() >= RotateAngle)
	{
		game->is_running();
		Player_Left_arm.sprite.rotate(-(RotateSpeed) * (*GameTime));

		Player_Head.Breathing(*GameTime);
		Player_Chest.Breathing(*GameTime);
		Player_Left_arm.Breathing(*GameTime);
		Player_Right_arm.Breathing(*GameTime);
		Player_Left_arm.sprite.move(-(0.0015f) * (*GameTime), 0);
		game->ClearDisplay();

		game->draw(Player_Head.sprite);
		game->draw(Player_Right_arm.sprite);
		game->draw(Player_Right_leg.sprite);
		game->draw(Player_Left_leg.sprite);
		game->draw(Player_Chest.sprite);
		game->draw(Player_Left_arm.sprite);
		game->draw(Player_Left_arm.sprite);

		game->Display();
	}
}
void Animation::save_position()
{
	Head_Position = Player_Head.sprite.getPosition();
	Right_arm_Position = Player_Right_arm.sprite.getPosition();
	Right_leg_Position = Player_Right_leg.sprite.getPosition();
	Left_leg_Position = Player_Left_leg.sprite.getPosition();
	Chest_Position = Player_Chest.sprite.getPosition();
	Left_arm_Position = Player_Left_arm.sprite.getPosition();
}
void Animation::load_position()
{
	Player_Head.sprite.setPosition(Head_Position);
	Player_Right_arm.sprite.setPosition(Right_arm_Position);
	Player_Right_leg.sprite.setPosition(Right_leg_Position);
	Player_Left_leg.sprite.setPosition(Left_leg_Position);
	Player_Chest.sprite.setPosition(Chest_Position);
	Player_Left_arm.sprite.setPosition(Left_arm_Position);
}

