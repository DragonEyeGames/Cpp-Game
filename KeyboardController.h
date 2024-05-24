#pragma once

#include "Game.h"
#include "ECS.h"
#include "Components.h"

class KeyboardController : public Component
{
public:
	TransformComponent *transform;

	bool up;
	bool down;
	bool left;
	bool right;

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();
	}

	void update() override
	{
		if (Game::event.type == SDL_KEYDOWN)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
					up = true;
					break;
			case SDLK_a:
					left = true;
					break;
			case SDLK_s:
					down = true;
					break;
			case SDLK_d:
					right = true;
					break;
			default:
				break;
			}
		}

		if (Game::event.type == SDL_KEYUP)
		{
			switch (Game::event.key.keysym.sym)
			{
			case SDLK_w:
				up = false;
				break;
			case SDLK_a:
				left = false;
				break;
			case SDLK_s:
				down = false;
				break;
			case SDLK_d:
				right = false;
				break;
			default:
				break;
			}
		}

		if (up) {
			transform->velocity.y = -1;
		}
		if (down) {
			transform->velocity.y = 1;
		}
		if (up && down) {
			transform->velocity.y = 0;
		}
		if (!(up || down)) {
			transform->velocity.y = 0;
		}
		if (left) {
			transform->velocity.x = -1;
		}
		if (right) {
			transform->velocity.x = 1;
		}
		if (left && right) {
			transform->velocity.x = 0;
		}
		if (!(left || right)) {
			transform->velocity.x = 0;
		}
	}
};
