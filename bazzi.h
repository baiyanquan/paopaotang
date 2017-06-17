#ifndef __BAZZI_H__
#define __BAZZI_H__
#include "cocos2d.h"
#include "Bomb.h"
#include "collidable.h"
#include "bombdestroy.h"
#include <math.h>
USING_NS_CC;
class bazzi
{
public:
	Sprite *renwu = Sprite::create("bazzi1.png", CCRectMake(371, 97, 44, 56));
	Bomb my_bomb;
	Collidable col;
	Bombdestroy bod;
	float Positionx = 0;
	float Positiony = 0;
	//��������
	//�ٶ�
	int speed = 5;
	//�������ٶ�
	const int wangba_speed = 3;
	//��������
	int my_bomb_limits_quantity = 1;
	//ˮ����Χ
	int my_bomb_range = 1;
	//��
	int life = 1;
	//ǰһ��ը���Ƿ�ը
	bool former_explode = true;

	//�ٶȽӿ�
	int return_speed();
	//�ƶ�
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
	//�������
	void blown(float x, float y, int range_up, int range_down, int range_left, int range_right);
	void die(float x, float y,int range_up,int range_down,int range_left,int range_right);
	//���߼�����Ƴ�
	bool is_shoes(TMXTiledMap* map);
	bool is_bubble(TMXTiledMap* map);
	bool is_medicine(TMXTiledMap* map);
	bool is_tortoise(TMXTiledMap* map);
	//����ߣ�������
	void pick_shoes();
	void pick_bubble();
	void pick_medicine();
	void pick_tortoise();
};
#endif