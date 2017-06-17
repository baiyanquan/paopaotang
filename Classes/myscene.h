#ifndef __MYSCREAN_H__
#define __MYSCREAN_H__
#include "cocos2d.h"
#include "bazzi.h"
#include "SimpleAudioEngine.h"
#include<math.h>
#include<map>
#include<string>
#include <server.h>
#include "bazzi2.h"
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
public:
	static myscene* createScene();
	char datareceievecopy[6];
	virtual bool init();
	//加载
	void addPlayer_wo(TMXTiledMap* map);
	void addPlayer_ta(TMXTiledMap* map);
	void addcollidable(TMXTiledMap* map);
	void addbombdestroy(TMXTiledMap* map);
	//炸弹位置补全之坐标转换
	Point set_tile(int x, int y);
	//人物移动控制及炸弹控制
	void onEnter();
	void keyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	bool isPressed(cocos2d::EventKeyboard::KeyCode keycode);
	void receievestop(char data[6]);
	void receieveaction(char data[6]);
	//计时器
	//人物
	virtual void updatewo(float delta);
	virtual void updateta(float delta);
	//炸弹位置碰撞
	void wobomb_update(float delta);
	void tabomb_update(float delta);
	float tax = 0;
	float tay = 0;
	float wox = 0;
	float woy = 0;
	void menuItemPopback(Ref* pSender);
	// a selector callback
	// implement the "static create()" method manually
	CREATE_FUNC(myscene);
};
#endif