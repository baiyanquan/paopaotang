#ifndef __BOMBDESTROY_H__
#define __BOMBDESTROY_H__
#include "cocos2d.h"
USING_NS_CC;

class Bombdestroy
{
public:
	TMXLayer* meta ;
	TMXLayer* a_undestroy ;
	TMXLayer* a_box;
	TMXLayer* a_movebox ;
	TMXLayer* a_grass ;
	TMXLayer* b_undestroy;
	TMXLayer* b_box ;
	TMXLayer* b_movebox ;
	TMXLayer* b_grass ;
	//ը����ײ
	int bomb_up(int x, int y, int range);
	int bomb_down(int x, int y, int range);
	int bomb_left(int x, int y, int range);
	int bomb_right(int x, int y, int range);
	//ը��ʵ��
	void bombdestroy(int x, int y, int range);
	//ͳһ����ת��
	Vec2 turn_to_tile(int x, int y);
};
#endif