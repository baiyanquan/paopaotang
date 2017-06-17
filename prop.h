#include "cocos2d.h"
#include <string>
USING_NS_CC;

//Ò©Ë®
class medicineSprite :public Layer
{
public:
	Sprite* medicine;
	void medicineInit(int mX, int mY, TMXTiledMap* map);
	virtual bool init();
	void remove_medicine(TMXTiledMap* map);
};

//Ð¬×Ó
class shoesSprite :public Layer
{
public:
	Sprite* shoes;
	void shoesInit(int mX, int mY, TMXTiledMap* map);
	virtual bool init();
	void remove_shoes(TMXTiledMap* map);
};

//ÅÝÅÝ
class bubbleSprite :public cocos2d::Layer
{
public:
	Sprite*bubble;
	void bubbleInit(int mX, int mY, TMXTiledMap* map);
	virtual bool init();
	void remove_bubble(TMXTiledMap* map);
};

//Íõ°Ë
class tortoiseSprite :public Layer
{
public:
	Sprite*tortoise;
	void tortoiseInit(int mX, int mY, TMXTiledMap* map);
	virtual bool init();
	void remove_tortoise(TMXTiledMap* map);
};


