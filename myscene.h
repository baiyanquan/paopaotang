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
	//����ʱ����
	float ptime = 150.0f;
	//ը����ʱ����
	float btime = 0.0f;
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	//������Ｐ͸������ײ�㵽��ͼ
	void addPlayer(TMXTiledMap* map);
	void addcollidable(TMXTiledMap* map);
	//ը��λ�ò�ȫ֮����ת��
	Point set_tile(int x, int y);
	//�����ƶ����Ƽ�ը������
	void onEnter();
	void keyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	void keyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event);
	bool isPressed(cocos2d::EventKeyboard::KeyCode keycode);
	
	//��ʱ��
	//����
	virtual void update(float delta);
	//ը��λ����ײ
	void bomb_update(float delta);

	float x = 0;
	float y = 0;
	void menuItemPopback(Ref* pSender);
	// a selector callback
	// implement the "static create()" method manually
	CREATE_FUNC(myscene);
};
#endif