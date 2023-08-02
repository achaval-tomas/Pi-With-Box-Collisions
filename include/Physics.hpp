#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Math.hpp"
#include <vector>

class Entity {
public:
	Entity(Vector2f p_pos, SDL_Texture* p_tex);

	inline Vector2f& getPos() {return pos;}
	inline void setPos(Vector2f p_pos){ pos = p_pos; }

	SDL_Texture* getTex();

	SDL_Rect getCurrentFrame();

private:
	Vector2f pos;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};

class Box : public Entity {
public:
	Box(Vector2f p_pos, SDL_Texture* p_tex, long long int p_mass, long double p_velocity)
	:Entity(p_pos, p_tex), mass(p_mass), velocity(p_velocity)
	{ }

	bool checkCollision(Box* p_box1, Box* p_box2);
	void handleCollision(Box* p_box1, Box* p_box2);

	void handleMomentum(Box* p_box1, Box* p_box2);

	long long int getMass(){return mass;}

	long double getVel(){return velocity;}
	void setVel(long double p_vel){velocity = p_vel;}

private:
	long long int mass;
	long double velocity;
};