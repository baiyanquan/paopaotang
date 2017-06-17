#include "prop.h"
#include "cocos2d.h"
#include "bazzi.h"
USING_NS_CC;

bubbleSprite*bubbleSprite::create_bubble(int mX, int mY, TMXTiledMap* map)
{
	bubbleSprite*bubble = new bubbleSprite();
	if (bubble&&bubble->init())
	{
		bubble->autorelease();
		bubble->bubbleInit(mX, mY, map);
		return bubble;
	}
	CC_SAFE_DELETE(bubble);
	return NULL;
}
bool bubbleSprite::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}
void bubbleSprite::bubbleInit(int mX, int mY, TMXTiledMap* map)
{
	bubble = Sprite::create("bubble.png");
	bubble->setPosition(mX, mY);
	addChild(bubble, 4);
}
void bubbleSprite::eaten_bubble(bubbleSprite* bub1, bazzi* ba1)
{
	bub1->setVisible(false);
	if (ba1->bubble_number< 5)
	{
		ba1->bubble_number += 1;
	}
}
//void eaten_shoes()
//{
//	bazzi::shoes_number++;
//}
//ÅİÅİ
shoesSprite*shoesSprite::create_shoes(int mX, int mY, TMXTiledMap* map)
{
	shoesSprite*shoes = new shoesSprite();
	if (shoes&&shoes->init())
	{
		shoes->autorelease();
		shoes->shoesInit(mX, mY, map);
		return shoes;
	}
	CC_SAFE_DELETE(shoes);
	return NULL;
}
bool shoesSprite::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}
void shoesSprite::shoesInit(int mX, int mY, TMXTiledMap* map)
{
	shoes = Sprite::create("shoes.png");
	shoes->setPosition(mX, mY);
	addChild(shoes, 4);
}
void shoesSprite::eaten_shoes(shoesSprite* sho1, bazzi* ba1)
{
	sho1->setVisible(false);
	if (ba1->shoes_number < 5)
	{
		ba1->shoes_number += 1;
	}
}
//Ğ¬×Ó
medicineSprite*medicineSprite::create_medicine(int mX, int mY, TMXTiledMap* map)
{
	medicineSprite*medicine = new medicineSprite();
	if (medicine&&medicine->init())
	{
		medicine->autorelease();
		medicine->medicineInit(mX, mY, map);
		return medicine;
	}
	CC_SAFE_DELETE(medicine);
	return NULL;
}
bool medicineSprite::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}
void medicineSprite::medicineInit(int mX, int mY, TMXTiledMap* map)
{
	medicine = Sprite::create("medicine.png");
	medicine->setPosition(mX, mY);
	addChild(medicine, 4);
}
void medicineSprite::eaten_medicine(medicineSprite* med1, bazzi* ba1)
{
	med1->setVisible(false);
	if (ba1->medicine_number < 5)
	{
		ba1->medicine_number += 1;
	}
}
//Ò©Ë®
tortoiseSprite*tortoiseSprite::create_tortoise(int mX, int mY, TMXTiledMap* map)
{
	tortoiseSprite*tortoise = new tortoiseSprite();
	if (tortoise&&tortoise->init())
	{
		tortoise->autorelease();
		tortoise->tortoiseInit(mX, mY, map);
		return tortoise;
	}
	CC_SAFE_DELETE(tortoise);
	return NULL;
}
bool tortoiseSprite::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}
void tortoiseSprite::tortoiseInit(int mX, int mY, TMXTiledMap* map)
{
	tortoise = Sprite::create("tortoise.png");
	tortoise->setPosition(mX, mY);
	addChild(tortoise, 4);
}
void tortoiseSprite::eaten_tortoise(tortoiseSprite* tor1, bazzi* ba1)
{
	tor1->setVisible(false);
	ba1->tortoise = true;
}
//Íõ°Ë
//int main()
//{
//	bubbleSprite* bub1 = bubbleSprite::create_bubble(40, 40);
//	removeChild(bub1, true);
//	bub1->setVisible(false);
//
//}