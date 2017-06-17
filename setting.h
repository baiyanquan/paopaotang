#ifndef __SETTING_H__
#define __SETTING_H__
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;
USING_NS_CC;
class setting : public cocos2d::Scene
{
public:
	Text* label;
	static cocos2d::Scene* createScene();
	virtual bool init();
	void menuItemPopback(Ref* pSender);
	void onEnter();
	void onEnterTransitionDidFinish();
	void onExit();
	void OnExitTransitionDidStart();
	void cleanup();
	void onChangedSlider(Ref* pSender, Slider::EventType type);
	// a selector callback
	// implement the "static create()" method manually
	CREATE_FUNC(setting);
};

#endif
