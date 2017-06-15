#ifndef __BAZZI_H__
#define __BAZZI_H__
#include "cocos2d.h"
#include "Bomb.h"
#include <math.h>
USING_NS_CC;
class bazzi
{
public:
	Sprite *renwu = Sprite::create("bazzi1.png", CCRectMake(371, 97, 44, 56));
	Bomb my_bomb;
	int return_speed();
	int my_bomb_range = 2;
	int my_bomb_limits_quantity = 2;
	float Positionx=0;
	float Positiony=0;
	void moveup();
	void moveup_action();
	void movedown();
	void movedown_action();
	void moveleft(); 
	void moveleft_action();
	void moveright();
	void moveright_action();
	void blown(float x, float y);
	void die(float x,float y);
	bool isMoving_up = false;
	bool isMoving_down = false;
	bool isMoving_left = false;
	bool isMoving_right = false;
	bool isMoving = false;
private:
	int speed=1;
};
#endif

