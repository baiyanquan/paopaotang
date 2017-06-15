#ifndef __MYSCREAN_H__
#define __MYSCREAN_H__
#include "cocos2d.h"
#include "bazzi.h"
#include "SimpleAudioEngine.h"
#include<math.h>
#include<map>
#include<string>
USING_NS_CC;
class myscene : public cocos2d::Scene
{
	bazzi wo;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
	LabelTTF* mytime;
	//倒计时叠减
	float ptime = 150.0f;
	//炸弹计时叠加
	float btime = 0.0f;
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	//添加人物及透明化碰撞层到地图
	void addPlayer(TMXTiledMap* map);
	void addcollidable(TMXTiledMap* map);
	//炸弹位置补全之坐标转换
	Point set_tile(int x, int y);
	//人物移动控制及炸弹控制
	void onEnter();
	void keyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	bool isPressed(cocos2d::EventKeyboard::KeyCode keycode);
	
	//计时器
	//人物
	virtual void update(float delta);
	//炸弹位置碰撞
	void bomb_update(float delta);

	float x = 0;
	float y = 0;
	void menuItemPopback(Ref* pSender);
	// a selector callback
	// implement the "static create()" method manually
	CREATE_FUNC(myscene);
};
#endif