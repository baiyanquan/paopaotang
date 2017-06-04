#include "cocos2d.h"
USING_NS_CC;
class bazziyellow
{
public:
	Sprite *renwu = Sprite::create("bazziyellow1.png", CCRectMake(364, 90, 62, 62));
	void moveup();
	void movedown();
	void moveleft();
	void moveright();
};