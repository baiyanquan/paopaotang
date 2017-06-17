#ifndef __BOMB_H__
#define __BOMB_H__
#include "cocos2d.h"
#include <vector>
USING_NS_CC;

class Bomb
{
public:
	Sprite* creat_bomb(int quality);
	int my_bomb_quantity = 1;
	void explode(Sprite* object,int quality);
	void add_my_bomb_quantity();
	std::vector<Sprite*> sprites_up;
	std::vector<Sprite*> sprites_down;
	std::vector<Sprite*> sprites_left;
	std::vector<Sprite*> sprites_right;
};
#endif