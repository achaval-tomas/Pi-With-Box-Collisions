#include "Physics.hpp"

/*-------------------------------------------- GENERAL ENTITIES CLASS --------------------------------------------*/
Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex)
:pos(p_pos), tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	SDL_QueryTexture(p_tex, NULL, NULL, &currentFrame.w, &currentFrame.h);
}

SDL_Texture* Entity::getTex(){
	return tex;
}

SDL_Rect Entity::getCurrentFrame(){
	return currentFrame;
}

bool Box::checkCollision(Box* p_box1, Box* p_box2)
{	
	return p_box1->getPos().x + 50 >= p_box2->getPos().x;	
}

void Box::handleCollision(Box* p_box1, Box* p_box2){
	long long int m1 = p_box1->getMass();
	long long int m2 = p_box2->getMass();
	long double v1 = p_box1->getVel();
	long double v2 = p_box2->getVel();

	p_box1->setVel((2*m2*v2 + (m1-m2)*v1)/(m1+m2));
	p_box2->setVel((2*m1*v1 - (m1-m2)*v2)/(m1+m2));
}

void Box::handleMomentum(Box* p_box1, Box* p_box2){
	p_box1->setPos(Vector2f(p_box1->getPos().x + p_box1->getVel()/2, p_box1->getPos().y));
	p_box2->setPos(Vector2f(p_box2->getPos().x + p_box2->getVel()/2, p_box2->getPos().y));
}