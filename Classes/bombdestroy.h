#ifndef __BOMBDESTROY_H__
#define __BOMBDESTROY_H__
#include "cocos2d.h"
#include "prop.h"
#include <vector>
USING_NS_CC;
using namespace std;

class Bombdestroy
{
public:
	Sprite* no_use = Sprite::create();
	TMXTiledMap* map;
	TMXLayer* meta ;
	TMXLayer* a_undestroy ;
	TMXLayer* a_box;
	TMXLayer* a_movebox ;
	TMXLayer* a_grass ;
	TMXLayer* b_undestroy;
	TMXLayer* b_box ;
	TMXLayer* b_movebox ;
	TMXLayer* b_grass ;
	shoesSprite shoes[15][13];
	bubbleSprite bubble[15][13];
	medicineSprite medicine[15][13];
	tortoiseSprite tortoise[15][13];
	//1Ь��2�ݣ�3ҩ��4����
	int prop[15][13];

	//ը����ײ
	int bomb_up(int x, int y, int range);
	int bomb_down(int x, int y, int range);
	int bomb_left(int x, int y, int range);
	int bomb_right(int x, int y, int range);
	//ը��ʵ��
	void bombdestroy(int x, int y, int range);
	void blink(Sprite* sprite);
	void shan(int x, int y, int range);
	void zhahui(int x, int y, int range);
	//ͳһ����ת��
	Vec2 turn_to_tile(int x, int y);
};
#endif