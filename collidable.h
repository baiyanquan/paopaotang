#ifndef __COLLIDABLE_H__
#define __COLLIDABLE_H__
#include "cocos2d.h"
USING_NS_CC;

class Collidable
{	
public:
	//��ײ��
	TMXLayer* meta;
	//��ײ���ƶ���ȫ
	bool collidable_up(int x, int y, int speed);
	bool col_move_up_left(int x, int y, int speed);
	bool col_move_up_right(int x, int y, int speed);

	bool collidable_down(int x, int y,int speed);
	bool col_move_down_left(int x, int y, int speed);
	bool col_move_down_right(int x, int y, int speed);

	bool collidable_left(int x, int y, int speed);
	bool col_move_left_up(int x, int y, int speed);
	bool col_move_left_down(int x, int y, int speed);

	bool collidable_right(int x, int y, int speed);
	bool col_move_right_up(int x, int y, int speed);
	bool col_move_right_down(int x, int y, int speed);
};
#endif