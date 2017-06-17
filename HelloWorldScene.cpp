#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;
extern int hahaha;
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
	Sprite* settingSpriteNormal = Sprite::create("settingmenuitem.png", Rect(516, 58, 119, 30));
	Sprite* settingSpriteSelected = Sprite::create("settingmenuitem.png", Rect(376, 58, 119, 30));
	MenuItemSprite* settingMenuItem = MenuItemSprite::create(settingSpriteNormal, settingSpriteSelected, CC_CALLBACK_1(HelloWorld::menuItemSettingCallback, this));
	settingMenuItem->setScale(2.0f);
	settingMenuItem->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height * 1 / 2);
	settingMenuItem->setAnchorPoint(Vec2(0.5, 0.5));
	Menu* mu = Menu::create(startMenuItem, settingMenuItem, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu);
	this->scheduleUpdate();
	return true;
}
void HelloWorld::update(float delta)
{
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(hahaha*0.01);
}
void HelloWorld::menuItemStartCallback(Ref* pSender)
{
	auto sc = myscene::createScene();
	auto reScene = TransitionShrinkGrow::create(1.0f, sc);
	Director::getInstance()->pushScene(reScene);
	SimpleAudioEngine::getInstance()->playEffect("tick.wav");
}
void HelloWorld::menuItemSettingCallback(Ref* pSender)
{
	auto sc = setting::createScene();
	auto reScene = TransitionCrossFade::create(1.0f, sc);
	Director::getInstance()->pushScene(reScene);
	SimpleAudioEngine::getInstance()->playEffect("tick.wav");
}
void HelloWorld::onEnter()
{
	Layer::onEnter();
}
void HelloWorld::onEnterTransitionDidFinish()
{
	Layer::onEnterTransitionDidFinish();
	SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3", true);
}
void HelloWorld::onExit()
{
	Layer::onExit();
}
void HelloWorld::OnExitTransitionDidStart()
{
	Layer::onExitTransitionDidStart();
}
void HelloWorld::cleanup()
{
	Layer::cleanup();
	SimpleAudioEngine::getInstance()->stopBackgroundMusic("background.mp3");
}
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    

