#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "cocos2d.h"
#include "myscene.h"
#include "waitingroom.h"
#include "setting.h"
class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
	void menuItemStartCallback(Ref* pSender);
	void menuItemSettingCallback(Ref* pSender);
	void onEnter();
	void onEnterTransitionDidFinish();
	void onExit();
	void OnExitTransitionDidStart();
	void cleanup();
	virtual void update(float delta);
    // a selector callback
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
