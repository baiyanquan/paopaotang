#ifndef __MYSCREAN_H__
#define __MYSCREAN_H__
#include "cocos2d.h"
#include "bazzi.h"
#include "SimpleAudioEngine.h"
#include<math.h>
#include<map>
#include<string>
#include<bazzi2.h>
USING_NS_CC;
class myscene : public cocos2d::Scene
{
	bazzi wo;
	bazzi2 ta;
	TMXTiledMap* map;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;
	LabelTTF* mytime;
	//倒计时叠减
	float ptime = 150.0f;
	//炸弹计时叠加
	float btime = 0.0f;
	float btime2 = 0.0f;
public:
	static myscene* createScene();
	virtual bool init();
	//加载
	void addPlayer_yellow(TMXTiledMap* map);
	void addPlayer_red(TMXTiledMap* map);
	void addcollidable(TMXTiledMap* map);
	void addbombdestroy(TMXTiledMap* map);
	//炸弹位置补全之坐标转换
	Point set_tile(int x, int y);
	//人物移动控制及炸弹控制
	void onEnter();
	void keyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	bool isPressed(cocos2d::EventKeyboard::KeyCode keycode);
	void onEnterTransitionDidFinish();
	void onExit();
	void OnExitTransitionDidStart();
	void cleanup();
	//计时器
	//人物
	virtual void update1(float delta);
	virtual void update2(float delta);
	//炸弹位置碰撞
	void bomb_update(float delta);
	void bomb2_update(float delta);
	float x = 0;
	float y = 0;
	float x2 = 0;
	float y2 = 0;
	void menuItemPopback(Ref* pSender);
	// a selector callback
	// implement the "static create()" method manually
	CREATE_FUNC(myscene);
};
#endif
