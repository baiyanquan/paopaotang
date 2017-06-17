#include "prop.h"
USING_NS_CC;
//ÅÝÅÝ
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
	bubble->setAnchorPoint(Vec2(0, 0));
	map->addChild(bubble, 4);
}
void bubbleSprite::remove_bubble(TMXTiledMap* map)
{
	map->removeChild(bubble);
}
//Ð¬×Ó
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
	shoes->setAnchorPoint(Vec2(0, 0));
	map->addChild(shoes, 4);
}
void shoesSprite::remove_shoes(TMXTiledMap* map)
{
	map->removeChild(shoes);
}
//Ò©Ë®
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
	medicine->setAnchorPoint(Vec2(0, 0));
	map->addChild(medicine, 4);
}
void medicineSprite::remove_medicine(TMXTiledMap* map)
{
	map->removeChild(medicine);
}
//Íõ°Ë
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
	tortoise->setAnchorPoint(Vec2(0, 0));
	map->addChild(tortoise, 4);
}
void tortoiseSprite::remove_tortoise(TMXTiledMap* map)
{
	map->removeChild(tortoise);
}