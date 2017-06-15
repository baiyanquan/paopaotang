#include "waitingroom.h"
#include "SimpleAudioEngine.h"

Scene* waitingroom::createScene()
{
	return waitingroom::create();
}
bool waitingroom::init()
{
	if (!Scene::init())
	{
		return false;

	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Sprite* background = Sprite::create("waitingroom.png");
	background->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(background);
	return true;
}