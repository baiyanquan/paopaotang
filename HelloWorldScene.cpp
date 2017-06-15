#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
	auto scene = Scene::create();
	auto layer = HelloWorld::create();
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Sprite* background = Sprite::create("myscean1.png");
	background->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(background);
	Sprite* startSpriteNormal = Sprite::create("startgame.png", Rect(516, 58, 119, 30));
	Sprite* startSpriteSelected = Sprite::create("startgame.png", Rect(376, 58, 119, 30));
	MenuItemSprite* startMenuItem =MenuItemSprite::create(startSpriteNormal, startSpriteSelected, CC_CALLBACK_1(HelloWorld::menuItemStartCallback, this));
	startMenuItem->setScale(2.0f);
	startMenuItem->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height*3 / 4);
	startMenuItem->setAnchorPoint(Vec2(0.5, 0.5));
	Menu* mu = Menu::create(startMenuItem, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu);
	return true;
}
void HelloWorld::menuItemStartCallback(Ref* pSender)
{
	auto sc = myscene::createScene();
	auto reScene = TransitionShrinkGrow::create(1.0f, sc);
	Director::getInstance()->pushScene(reScene);
}




    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    

