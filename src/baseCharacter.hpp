#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>

#pragma once

class BaseCharacter
{
public:
	sf::Keyboard::Key up;
	bool upIsPressed = false;
	sf::Keyboard::Key right;
	bool rightIsPressed = false;
	sf::Keyboard::Key down;
	bool downIsPressed = false;
	sf::Keyboard::Key left;
	bool leftIsPressed = false;
	sf::Keyboard::Key attack;
	bool attackIsPressed = false;
	sf::Keyboard::Key dodge;
	bool dodgeIsPressed = false;
	sf::Keyboard::Key skill;
	bool skillIsPressed = false;

	float reward = 0;
	float fastestVelocity = 0;
	float closestDist = 0;


	bool evenFrame = false;

	int direction;
	bool canTurn = true;

	bool player2;

	bool dead = false;
	int winCount = 0;

	int inputHorizontal = 0;
	int inputVertical = 0;

	bool inputAttack = false;
	bool inputDodge = false;
	bool inputSkill = false;


	float velocity = 0;
	float mass = 1;

	float position;
	float width = 16;

	float top = 64;
	float gravity = 0;

	bool canWalk = true;
	float walkSpeed = 1;
	float walkSpeedMax = 1;
	float friction = 0.8f;

	sf::RectangleShape sprite;

	sf::RectangleShape Stamina[3] = {sf::RectangleShape(sf::Vector2f(6,3)),sf::RectangleShape(sf::Vector2f(6,3)),sf::RectangleShape(sf::Vector2f(6,3))};

	bool canBlock = true;
	int blocking = 0;
	bool blocked = false;


	bool canDodge = true;
	bool isDodging = false;
	float dodgeForce = 7;
	float dodges = 3;
	float MaxDodges = 3;
	float dodgeCharge = 0.042f;


	bool canAttack = true;
	bool isCharging = false;
	bool isAttacking = false;
	int AttackFrames = 8;
	int AttackCancelableFrames = 4;
	int attackFrame = 0;
	float charge = 0;
	float chargeSpeed = 1;
	float maxCharge = 10;

	bool isGrabing = false;
	bool canGrab = true;
	int grabFrame = 0;
	int grabFrames = 5;
	int firstActiveGrabFrame = 2;

	float staminaUse = 1.f;
	float staminaRegain = 0.1f;
	float exhaustion = 0;

	int firstActiveAttackFrame = 3;
	int lastActiveAttackFrame = 4;

	float attackVelocity = 12;
	bool hitboxActive = false;
	int attackState = 0;
	float highAttackRange = 32;
	float attackRange = 75;
	float lowAttackRange = 32;

	float distToEdge1;
	float distToEdge2;

	sf::Texture legsTexture;
	sf::IntRect legsRectSource = sf::IntRect(0, 0, 34, 36);
	sf::Sprite legsSprite = sf::Sprite(legsTexture, legsRectSource);

	std::vector<int> legsAnimation[6] = {
		std::vector<int>{ 0 },
		std::vector<int>{ 0, 1, 2, 3 },
		std::vector<int>{ 0, 3, 2, 1 },
		std::vector<int>{ 4 },
		std::vector<int>{ 4, 5, 6, 7 },
		std::vector<int>{ 4, 7, 6, 5 } 
	};
	std::vector<int> legsAnimationStepLength[6] = {
		std::vector<int>{ 0 },
		std::vector<int>{ 4,3,1,2 },
		std::vector<int>{ -3,-4,-2,-1 },
		std::vector<int>{ 0 },
		std::vector<int>{ -4,-3,-1,-2 },
		std::vector<int>{ 3,4,2,1 }
	};
	std::vector<int> legsAnimationBodyOffset[6] = {
	std::vector<int>{ 0 },
	std::vector<int>{ 0, -1, -2, -1 },
	std::vector<int>{ 0, -1, -2, -1 },
	std::vector<int>{ 0 },
	std::vector<int>{ 0, -1, -2, -1 },
	std::vector<int>{ 0, -1, -2, -1 }
	};
	int currentLegsAnimation;
	int currentLegsFrame = 0;

	sf::Texture upperBodyTexture;
	sf::IntRect upperBodyRectSource = sf::IntRect(0, 0, 127, 96);
	sf::Sprite upperBodySprite = sf::Sprite(upperBodyTexture, upperBodyRectSource);

	sf::Texture upperBodyColorTexture;
	sf::Sprite upperBodyColorSprite = sf::Sprite(upperBodyColorTexture, upperBodyRectSource);

	sf::Texture slashEffectsTexture;
	sf::IntRect slashEffectsRectSource = sf::IntRect(0, 0, 210, 128);
	sf::Sprite slashEffectsSprite = sf::Sprite(slashEffectsTexture, slashEffectsRectSource);

	std::vector<int> upperBodyAnimation[24] = {
		std::vector<int>{0},
		std::vector<int>{1},
		std::vector<int>{2},
		std::vector<int>{3},
		std::vector<int>{6},
		std::vector<int>{9},
		std::vector<int>{3,3,4,5,5,5},
		std::vector<int>{6,6,7,8,8,8},
		std::vector<int>{9,9,10,11,11},
		std::vector<int>{4,4,4},
		std::vector<int>{7,7,7},
		std::vector<int>{10,10,10},
		std::vector<int>{12},
		std::vector<int>{13},
		std::vector<int>{14},
		std::vector<int>{15},
		std::vector<int>{18},
		std::vector<int>{21},
		std::vector<int>{15,15,16,17,17,17},
		std::vector<int>{18,18,19,20,20,20},
		std::vector<int>{21,21,22,23,23,23},
		std::vector<int>{16,16,16},
		std::vector<int>{19,19,19},
		std::vector<int>{22,22,22}
	};
	int currentUpperBodyAnimation;
	int currentUpperBodyFrame = 0;

	BaseCharacter(bool isPlayer2)
	{
		legsTexture.loadFromFile("Legs.png");
		upperBodyTexture.loadFromFile("UpperBody.png");
		upperBodyColorTexture.loadFromFile("UpperBodyColor.png");
		slashEffectsTexture.loadFromFile("SlashEffects.png");
		Stamina[0].setFillColor(sf::Color::Green);
		Stamina[1].setFillColor(sf::Color::Green);
		Stamina[2].setFillColor(sf::Color::Green);

		if (!isPlayer2)
		{
			currentLegsAnimation = 0;
			currentUpperBodyAnimation = 1;
			up = sf::Keyboard::W;
			right = sf::Keyboard::D;
			down = sf::Keyboard::S;
			left = sf::Keyboard::A;
			attack = sf::Keyboard::U;
			dodge = sf::Keyboard::I;
			skill = sf::Keyboard::O;
			sprite.setFillColor(sf::Color::Blue);
			upperBodyColorSprite.setColor(sf::Color::Blue);
			SetPosition(96);
			direction = 1;
			player2 = false;
		}
		else
		{
			currentLegsAnimation = 3;
			currentUpperBodyAnimation = 13;
			up = sf::Keyboard::Up;
			right = sf::Keyboard::Right;
			down = sf::Keyboard::Down;
			left = sf::Keyboard::Left;
			attack = sf::Keyboard::Numpad7;
			dodge = sf::Keyboard::Numpad8;
			skill = sf::Keyboard::Numpad9;
			sprite.setFillColor(sf::Color::Red);
			upperBodyColorSprite.setColor(sf::Color::Red);
			SetPosition(416);
			direction = -1;
			player2 = true;
		}

		legsRectSource.left = legsAnimation[currentLegsAnimation][currentLegsFrame] * 34;
		legsSprite.setTextureRect(legsRectSource);

		upperBodyRectSource.left = upperBodyAnimation[currentUpperBodyAnimation][currentUpperBodyFrame] * 127;
		upperBodySprite.setTextureRect(upperBodyRectSource);
		upperBodyColorSprite.setTextureRect(upperBodyRectSource);
	}

	void Reset()
	{
		reward = 0;
		fastestVelocity = 0;
		closestDist = 0;
		velocity = 0;
		dead = false;
		top = 64;
		gravity = 0;
		dodges = MaxDodges;
		if (!player2)
		{
			currentLegsAnimation = 0;
			currentUpperBodyAnimation = 1;
			sprite.setFillColor(sf::Color::Blue);
			SetPosition(96);
			direction = 1;
		}
		else
		{
			currentLegsAnimation = 3;
			currentUpperBodyAnimation = 13;
			sprite.setFillColor(sf::Color::Red);
			SetPosition(416);
			direction = -1;
		}
		currentLegsFrame = 0;
		currentUpperBodyFrame = 0;
	}

	void TrueReset()
	{
		reward = 0;
		fastestVelocity = 0;
		closestDist = 0;
		velocity = 0;
		dead = false;
		top = 64;
		gravity = 0;
		winCount = 0;
		dodges = MaxDodges;
		if (!player2)
		{
			currentLegsAnimation = 0;
			currentUpperBodyAnimation = 1;
			sprite.setFillColor(sf::Color::Blue);
			SetPosition(96);
			direction = 1;
		}
		else
		{
			currentLegsAnimation = 3;
			currentUpperBodyAnimation = 13;
			sprite.setFillColor(sf::Color::Red);
			SetPosition(416);
			direction = -1;
		}
		currentLegsFrame = 0;
		currentUpperBodyFrame = 0;
	}

	void Input(std::vector<double> inputs)
	{
		if (inputs[0] >= 1 && inputs[1] <= 1)
		{
			inputVertical = 1;
		}
		else if (inputs[0] <= 1 && inputs[1] >= 1)
		{
			inputVertical = -1;
		}
		else
		{
			inputVertical = 0;
		}

		if (inputs[2] >= 1 && inputs[3] <= 1)
		{
			inputHorizontal = 1;
		}
		else if (inputs[2] <= 1 && inputs[3] >= 1)
		{
			inputHorizontal = -1;
		}
		else
		{
			inputHorizontal = 0;
		}

		inputAttack = inputs[4] >= 1;
		inputDodge = inputs[5] >= 1;
		inputSkill = inputs[6] >= 1;
	}
	void Input()
	{
		if (upIsPressed && !downIsPressed)
		{
			inputVertical = 1;
		}
		else if (downIsPressed && !upIsPressed)
		{
			inputVertical = -1;
		}
		else
		{
			inputVertical = 0;
		}

		if (rightIsPressed && !leftIsPressed)
		{
			inputHorizontal = 1;
		}
		else if (leftIsPressed && !rightIsPressed)
		{
			inputHorizontal = -1;
		}
		else
		{
			inputHorizontal = 0;
		}

		inputAttack = attackIsPressed;
		inputDodge = dodgeIsPressed;
		inputSkill = skillIsPressed;
	}

	void SetPosition(float pos)
	{
		position = pos;
		slashEffectsSprite.setPosition(pos-105,top-64);
		Stamina[0].setPosition(pos - 10, top-10);
		Stamina[1].setPosition(pos - 3, top-10);
		Stamina[2].setPosition(pos + 4, top-10);
		legsSprite.setPosition(sf::Vector2f(pos - 17, top + 28));
		upperBodySprite.setPosition(sf::Vector2f(pos - 63, top - 30 - legsAnimationBodyOffset[currentLegsAnimation][currentLegsFrame]));
		upperBodyColorSprite.setPosition(sf::Vector2f(pos - 63, top - 30 - legsAnimationBodyOffset[currentLegsAnimation][currentLegsFrame]));
		sprite.setPosition(sf::Vector2f(pos - width, top));
	}


	void AddForce(float force)
	{
		velocity += force / mass;
	}

	/*
	void Skill()
	{
		if (inputSkill)
		{
			if (canGrab)
			{
				isGrabing = true;
				grabFrame = 0;
				canAttack = false;
				canGrab = false;
				canTurn = false;
			}
		}
		else if (grabFrame > grabFrames)
		{
			canGrab = true;
		}

		if (isGrabing)
		{
			if (grabFrame == firstActiveGrabFrame)
			{
				hitboxActive = true;
				attackState = 2;
			}
			if (grabFrame > grabFrames)
			{
				canTurn = true;
				canAttack = true;
				isGrabing = false;
				grabFrame = 0;
			}
			grabFrame++;
		}
	}
	*/

	void ResetInput()
	{
		inputHorizontal = 0;
		inputVertical = 0;
		inputAttack = false;
		inputDodge = false;
		inputSkill = false;
	}


	bool Tick()
	{
		//Skill();
		blocking = inputVertical;

		if (dodges <= MaxDodges)
		{
			dodges += dodgeCharge;
		}
		if (inputDodge)
		{
			if (canDodge && dodges >= 1)
			{
				dodges -= 1;
				canDodge = false;
				if ((inputHorizontal < 0 && velocity > 0) || (inputHorizontal > 0 && velocity < 0))
				{
					velocity = 0;
				}
				AddForce(dodgeForce * inputHorizontal);
			}
		}
		else
		{
			canDodge = true;
		}
		if (dodges >= 3)
		{
			Stamina[0].setFillColor(sf::Color::Green);
			Stamina[1].setFillColor(sf::Color::Green);
			Stamina[2].setFillColor(sf::Color::Green);
		}
		else if (dodges >= 2)
		{
			Stamina[0].setFillColor(sf::Color::Green);
			Stamina[1].setFillColor(sf::Color::Green);
			Stamina[2].setFillColor(sf::Color::Black);
		}
		else if(dodges >= 1)
		{
			Stamina[0].setFillColor(sf::Color::Green);
			Stamina[1].setFillColor(sf::Color::Black);
			Stamina[2].setFillColor(sf::Color::Black);
		}
		else
		{
			Stamina[0].setFillColor(sf::Color::Black);
			Stamina[1].setFillColor(sf::Color::Black);
			Stamina[2].setFillColor(sf::Color::Black);
		}

		if (evenFrame)
		{
			currentLegsFrame++;
			evenFrame = false;
			if (currentLegsFrame == legsAnimation[currentLegsAnimation].size())
			{
				switch (inputHorizontal)
				{
				case -1:
					if (direction == 1)
					{
						if (currentLegsAnimation != 2)
						{
							currentLegsAnimation = 2;
							break;
						}
						position += legsAnimationStepLength[currentLegsAnimation][0];
						break;
					}
					if (currentLegsAnimation != 4)
					{
						currentLegsAnimation = 4;
						break;
					}
					position += legsAnimationStepLength[currentLegsAnimation][0];
					break;

				case 0:
					if (direction == 1)
					{
						currentLegsAnimation = 0;
						break;
					}
					currentLegsAnimation = 3;
					break;

				case 1:
					if (direction == 1)
					{
						if (currentLegsAnimation != 1)
						{
							currentLegsAnimation = 1;
							break;
						}
						position += legsAnimationStepLength[currentLegsAnimation][0];
						break;
					}
					if (currentLegsAnimation != 5)
					{
						currentLegsAnimation = 5;
						break;
					}
					position += legsAnimationStepLength[currentLegsAnimation][0];
					break;
				}
				currentLegsFrame = 0;
			}
			if (currentLegsFrame != 0)
			{
				position += legsAnimationStepLength[currentLegsAnimation][currentLegsFrame];
			}

			currentUpperBodyFrame++;

			if (currentUpperBodyFrame == firstActiveAttackFrame && ((currentUpperBodyAnimation > 5 && currentUpperBodyAnimation < 9)||(currentUpperBodyAnimation > 17 && currentUpperBodyAnimation < 21)))
			{
				hitboxActive = true;
			}
			if (currentUpperBodyFrame == lastActiveAttackFrame)
			{
				hitboxActive = false;
			}


			if (currentUpperBodyFrame == upperBodyAnimation[currentUpperBodyAnimation].size())
			{
				if (canBlock)
				{
					if (direction == 1)
					{
						if (blocking + 1 < currentUpperBodyAnimation)
						{
							currentUpperBodyAnimation--;
						}
						if (blocking + 1 > currentUpperBodyAnimation)
						{
							currentUpperBodyAnimation++;
						}
						if (currentLegsAnimation > 2)
						{
							currentUpperBodyAnimation = blocking + 1;
						}
					}
					else
					{
						if (blocking + 1 < currentUpperBodyAnimation-12)
						{
							currentUpperBodyAnimation--;
						}
						if (blocking + 1 > currentUpperBodyAnimation-12)
						{
							currentUpperBodyAnimation++;
						}
						if (currentLegsAnimation < 12 || currentLegsAnimation > 14)
						{
							currentUpperBodyAnimation = blocking + 13;
						}
					}
				}

				if (currentUpperBodyAnimation > 8 && currentUpperBodyAnimation < 12 || currentUpperBodyAnimation > 20)
				{
					currentUpperBodyAnimation -= 9;
					attackFrame = 0;
					isAttacking = false;
					canAttack = true;
					canWalk = true;
					canDodge = true;
					canBlock = true;
					canTurn = true;
					canGrab = true;
					exhaustion += staminaUse;
				}
				else if (inputAttack && !isCharging && canAttack)
				{
					canBlock = false;
					isCharging = true;
					canGrab = false;
					canAttack = false;
					canTurn = false;
					canBlock = false;
					currentUpperBodyAnimation = direction == 1 ? inputVertical + 1 + 3 : inputVertical + 1 + 15;
				}
				else if (isCharging)
				{
					if (inputAttack)
					{
						if (direction == 1)
						{
							if (inputVertical + 1 < currentUpperBodyAnimation - 3)
							{
								currentUpperBodyAnimation--;
							}
							if (inputVertical + 1 > currentUpperBodyAnimation - 3)
							{
								currentUpperBodyAnimation++;
							}
						}
						else
						{
							if (inputVertical + 1 < currentUpperBodyAnimation - 15)
							{
								currentUpperBodyAnimation--;
							}
							if (inputVertical + 1 > currentUpperBodyAnimation - 15)
							{
								currentUpperBodyAnimation++;
							}
						}
						charge += chargeSpeed;
						
					}
					else 
					{
						currentUpperBodyAnimation = direction == 1 ? inputVertical + 7 : inputVertical + 19;
						slashEffectsRectSource.left = (std::clamp<int>(-direction, 0, 2) * 3 + inputVertical + 1) * 210;
						slashEffectsSprite.setTextureRect(slashEffectsRectSource);
						attackState = inputVertical;
						canWalk = false;
						isAttacking = true;
						isCharging = false;
						AddForce(charge * inputHorizontal);
						charge = 0;
						attackFrame = 0;
					}
				}
				else if (isAttacking)
				{
					currentUpperBodyAnimation -= 6;
					attackFrame = 0;
					isAttacking = false;
					canAttack = true;
					canWalk = true;
					canDodge = true;
					canBlock = true;
					canTurn = true;
					canGrab = true;
					exhaustion += staminaUse;
				}
				currentUpperBodyFrame = 0;
			}

		}
		else
		{
			evenFrame = true;
		}


		legsRectSource.left = legsAnimation[currentLegsAnimation][currentLegsFrame]*34;
		legsSprite.setTextureRect(legsRectSource);

		upperBodyRectSource.left = upperBodyAnimation[currentUpperBodyAnimation][currentUpperBodyFrame] * 127;
		upperBodySprite.setTextureRect(upperBodyRectSource);
		upperBodyColorSprite.setTextureRect(upperBodyRectSource);

		SetPosition(position + velocity);

		if (fabs(velocity) > fastestVelocity)
		{
			fastestVelocity = fabs(velocity);
		}

		if (exhaustion > 0)
		{
			exhaustion -= staminaRegain;
		}

		if (velocity < 0)
		{
			velocity += friction;
			if (velocity > 0)
			{
				velocity = 0;
			}
		}
		else if (velocity > 0)
		{
			velocity -= friction;
			if (velocity <= 0)
			{
				velocity = 0;
			}
		}
		distToEdge1 = 440 - (position - width);
		distToEdge2 = (position + width) - 72;


		blocked = false;

		if (distToEdge1 <= 0 || distToEdge2 <= 0)
		{
			sprite.setFillColor(sf::Color::Magenta);
			gravity += 2;
			top += gravity;
			if (!dead)
			{
				dead = true;
				return true;
			}
		}
		return false;

	}


private:

};
