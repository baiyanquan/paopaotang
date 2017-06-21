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
	Sprite *renwu = Sprite::create("bazzi3.png", CCRectMake(371, 97, 44, 56));
	Bomb my_bomb;
	Collidable col;
	float Positionx = 0;
	float Positiony = 0;
	//人物属性
	//速度
	int speed = 5;
	//骑王八速度
	const int wangba_speed = 3;
	//泡泡数量
	int my_bomb_limits_quantity = 1;
	//水柱范围
	int my_bomb_range = 1;
	//命
	int life = 1;
	//前一个炸弹是否爆炸
	bool former_explode = true;
	bool is_die = false;
	//速度接口
	int return_speed();
	//移动
	void moveup();
	void moveup_action();
	void wangba_moveup_action();
	void movedown();
	void movedown_action();
	void wangba_movedown_action();
	void moveleft();
	void moveleft_action();
	void wangba_moveleft_action();
	void moveright();
	void moveright_action();
	void wangba_moveright_action();
	bool isMoving_up = false;
	bool isMoving_down = false;
	bool isMoving_left = false;
	bool isMoving_right = false;
	bool isMoving = false;
	//死亡检测
	void blown(float x, float y,int range_up, int range_down, int range_left, int range_right);
	void die(float x, float y,int range_up, int range_down, int range_left, int range_right);
	//道具检测与移除
	bool is_shoes(Bombdestroy& bod);
	bool is_bubble(Bombdestroy& bod);
	bool is_medicine(Bombdestroy& bod);
	bool is_tortoise(Bombdestroy& bod);
	//捡道具，加属性
	void pick_shoes();
	void pick_bubble();
	void pick_medicine();
	void pick_tortoise();
};
#endif