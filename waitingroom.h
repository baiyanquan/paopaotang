#ifndef __WAITING_ROOM_H__
#define __WAITING_ROOM_H__
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
class waitingroom : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(waitingroom);
};
#endif