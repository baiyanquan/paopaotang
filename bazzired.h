#include "cocos2d.h"
USING_NS_CC;
class bazzired
{
public:
	Sprite *renwu = Sprite::create("bazzired1.png", CCRectMake(364, 90, 62, 62));
	void moveup();
	void movedown();
	void moveleft();
	void moveright();
};