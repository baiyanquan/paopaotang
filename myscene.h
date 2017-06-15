#ifndef __MYSCREAN_H__
#define __MYSCREAN_H__
#include "cocos2d.h"
#include "bazzi.h"
#include "SimpleAudioEngine.h"
#include<math.h>
#include<map>
#include<string>
using namespace cocos2d;
class myscene : public cocos2d::Scene
{
	//声明地图成员
	TMXTiledMap* map;
	//声明人物成员
	bazzi wo;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys = { { EventKeyboard::KeyCode::KEY_RIGHT_ARROW,false },{ EventKeyboard::KeyCode::KEY_LEFT_ARROW,false },{ EventKeyboard::KeyCode::KEY_UP_ARROW,false },{ EventKeyboard::KeyCode::KEY_DOWN_ARROW,false } };
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	//将人物加入地图的函数声明
	void addPlayer(TMXTiledMap* map);

	//人物移动控制及炸弹控制
	void onEnter();
	void keyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void die(float at);
	bool isPressed(cocos2d::EventKeyboard::KeyCode keycode);
	virtual void update(float delta);
	float x = 0;
	float y = 0;
	void menuItemPopback(Ref* pSender);
private:
	LabelTTF* mytime;
	float ptime=150.0f;
	// a selector callback
	// implement the "static create()" method manually
	CREATE_FUNC(myscene);
};
#endif

