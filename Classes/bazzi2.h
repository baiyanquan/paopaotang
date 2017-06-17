#ifndef __BAZZI2_H__
#define __BAZZI2_H__
#include "cocos2d.h"
#include "Bomb.h"
#include "collidable.h"
#include "bombdestroy.h"
#include <math.h>
USING_NS_CC;
class bazzi2
{
public:
	Sprite *renwu = Sprite::create("bazzi2.png", CCRectMake(371, 97, 44, 56));
	Bomb my_bomb;
	Collidable col;
	Bombdestroy bod;
	int my_bomb_range = 2;
	int range_up = 0;
	int range_down = 0;
	int range_left = 0;
	int range_right = 0;
	int my_bomb_limits_quantity = 2;
	float Positionx = 0;
	float Positiony = 0;
	//道具
	int shoes_number = 0;
	int medicine_number = 0;
	int bubble_number = 0;
	bool tortoise = false;

	//移动
	void moveup();
	void moveup_action();
	void movedown();
	void movedown_action();
	void moveleft();
	void moveleft_action();
	void moveright();
	void moveright_action();
	bool isMoving_up = false;
	bool isMoving_down = false;
	bool isMoving_left = false;
	bool isMoving_right = false;
	bool isMoving = false;
	//速度接口
	int return_speed();
	//死亡
	void blown(float x, float y);
	void die(float x, float y);
private:
	int speed = 2.1;
};
#endif