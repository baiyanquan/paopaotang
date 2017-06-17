#include "cocos2d.h"
#include"bazzi.h"
#include <string>
USING_NS_CC;


class medicineSprite :public Layer
{
public:
	Sprite*medicine;
	static medicineSprite* create_medicine(int mX, int mY, TMXTiledMap* map);
	/*{
	Sprite* medicine = CCSprite::create("medicine.png");
	medicine->setPosition(ccp(80, 120));
	}*/
	void medicineInit(int mX, int mY, TMXTiledMap* map);
	virtual bool init();
	void eaten_medicine(medicineSprite* med1, bazzi* ba1);
};

//药水结束
class shoesSprite :public Layer
{
public:
	Sprite*shoes;
	static shoesSprite* create_shoes(int mX, int mY, TMXTiledMap* map);
	void shoesInit(int mX, int mY, TMXTiledMap* map);
	virtual bool init();
	void eaten_shoes(shoesSprite* sho1, bazzi* ba1);
};

//鞋子结束
class bubbleSprite :public cocos2d::Layer
{
public:
	Sprite*bubble;
	static bubbleSprite* create_bubble(int mX, int mY, TMXTiledMap* map);
	void bubbleInit(int mX, int mY, TMXTiledMap* map);
	virtual bool init();
	void eaten_bubble(bubbleSprite* bub1, bazzi* ba1);
};
//泡泡
class tortoiseSprite :public Layer
{
public:
	Sprite*tortoise;
	static tortoiseSprite* create_tortoise(int mX, int mY, TMXTiledMap* map);
	void tortoiseInit(int mX, int mY, TMXTiledMap* map);
	virtual bool init();
	void eaten_tortoise(tortoiseSprite* tor1, bazzi* ba1);
};


