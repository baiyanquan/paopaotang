#include "setting.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;
int hahaha = 30;
Scene* setting::createScene()
{
	auto scene = Scene::create();
	auto layer = setting::create();
	scene->addChild(layer);
	return scene;
}
bool setting::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Sprite* background = Sprite::create("myscean1.png");
	background->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(background);
	Sprite* PopSpriteNormal = Sprite::create("back_to_menu.png", Rect(516, 58, 119, 30));
	Sprite* PopSpriteSelected = Sprite::create("back_to_menu.png", Rect(376, 58, 119, 30));
	MenuItemSprite* PopMenuItem = MenuItemSprite::create(PopSpriteNormal, PopSpriteSelected, CC_CALLBACK_1(setting::menuItemPopback, this));
	PopMenuItem->setScale(2.0f);
	PopMenuItem->setPosition(origin.x + visibleSize.width * 4 / 5, origin.y + visibleSize.height * 1 / 6);
	PopMenuItem->setAnchorPoint(Vec2(0.5, 0.5));
	Menu* mu = Menu::create(PopMenuItem, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu);
	Slider* slider = Slider::create();
	slider->loadBarTexture("ground.png");
	slider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png","");
	slider->loadProgressBarTexture("progress.png");
	slider->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	slider->setMaxPercent(100);
	slider->setPercent(30);
	slider->addEventListener(CC_CALLBACK_2(setting::onChangedSlider, this));
	this->addChild(slider);
	label = Text::create("0","Arial",24);
	label->setColor(Color3B(0, 0, 0));
	label->setPosition(slider->getPosition() - Vec2(0, 60));
	label->setString(StringUtils::format("Volume 30"));
	this->addChild(label);
	return true;
}
void setting::menuItemPopback(Ref* pSender)
{
	Director::getInstance()->popScene();
}
void setting::onEnter()
{
	Scene::onEnter();
}
void setting::onEnterTransitionDidFinish()
{
	Scene::onEnterTransitionDidFinish();
	SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3", true);
}
void setting::onExit()
{
	Scene::onExit();
}
void setting::OnExitTransitionDidStart()
{
	Scene::onExitTransitionDidStart();
}
void setting::cleanup()
{
	Scene::cleanup();
	SimpleAudioEngine::getInstance()->stopBackgroundMusic("background.mp3");
}
void setting::onChangedSlider(Ref* pSender, Slider::EventType type)
{
	if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
	{
		Slider*slider = dynamic_cast<Slider*>(pSender);
	    int percent = slider->getPercent();
		hahaha = percent;
		label->setString(StringUtils::format("Volume %d", percent));
		SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(percent*0.01);
	}
}