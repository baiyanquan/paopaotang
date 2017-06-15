#include "myscene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

Scene* myscene::createScene()
{
	auto scene = Scene::create();
	auto layer = myscene::create();
	scene->addChild(layer);
	return scene;
}

// on "init" you need to initialize your instance
bool myscene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;

	}

	//加载瓦片地图
	map = TMXTiledMap::create("tiled/a_map.tmx");
	//缩放
	//地图在屏幕定层
	//加载人物
	addPlayer(map);
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Sprite* background = Sprite::create("BG.png");
	background->setScaleX(1280.0f / 800.0f);
	background->setScaleY(960.0f / 600.0f);
	background->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(background);
	map->setAnchorPoint(Vec2(0.0, 0.0));
	map->setPosition(Vec2(20, 41));
	background->addChild(map, 0);
	mytime = LabelTTF::create();
	mytime->setScale(2.0f);
	mytime->setPosition(Vec2(736, 553));
	background->addChild(mytime);
	Sprite* PopSpriteNormal = Sprite::create("back_to_menu.png", Rect(516, 58, 119, 30));
	Sprite* PopSpriteSelected = Sprite::create("back_to_menu.png", Rect(376, 58, 119, 30));
	MenuItemSprite* PopMenuItem = MenuItemSprite::create(PopSpriteNormal, PopSpriteSelected, CC_CALLBACK_1(myscene::menuItemPopback, this));
	PopMenuItem->setScaleX(131.0f / 119.0f);
	PopMenuItem->setScaleY(33.0f / 30.0f);
	PopMenuItem->setPosition(650,13);
	PopMenuItem->setAnchorPoint(Vec2(0.0, 0.0));
	Menu* mu = Menu::create(PopMenuItem, NULL);
	mu->setPosition(Vec2::ZERO);
	background->addChild(mu);
	this->scheduleUpdate();
	return true;
}
void myscene::addPlayer(TMXTiledMap* map)
{
	//加载对象层
	TMXObjectGroup* objGroup = map->getObjectGroup("object");
	//加载人物坐标对象
	ValueMap playerPointMap = objGroup->getObject("renwu_yellow");
	float playerX = playerPointMap.at("x").asFloat();
	float playerY = playerPointMap.at("y").asFloat();
	//人物定位
	wo.renwu->setPosition(Point(playerX, playerY));
	//锚点
	wo.renwu->setAnchorPoint(Point(0, 0));
	//缩放
	wo.renwu->setScaleX(50.0 / 62.0);
	//人物在地图定层
	map->addChild(wo.renwu, 5);
	//计时器？
	this->scheduleUpdate();

}
void myscene::keyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{

	if ((keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) && (wo.isMoving == false))
	{
		wo.isMoving = true;
		keys[keycode] = true;
		wo.moveright_action();
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) && (wo.isMoving == false))
	{
		wo.isMoving = true;
		keys[keycode] = true;
		wo.moveleft_action();
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_UP_ARROW) && (wo.isMoving == false))
	{
		wo.isMoving = true;
		keys[keycode] = true;
		wo.moveup_action();
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) && (wo.isMoving == false))
	{
		wo.isMoving = true;
		keys[keycode] = true;
		wo.movedown_action();
	}
	if (keycode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		if (wo.my_bomb.my_bomb_quantity > 0)
		{
			--wo.my_bomb.my_bomb_quantity;
			Sprite* newsp = wo.my_bomb.creat_bomb(wo.my_bomb_range);
			//炸弹定位
			newsp->setPosition(wo.renwu->getPosition());
			//锚点
			newsp->setAnchorPoint(Point(0, 0));
			x = newsp->getPositionX();
			y = newsp->getPositionY();
			//缩放
			newsp->setScale(0.9);

			for (int i = 1; i <= wo.my_bomb_range; ++i)
			{
				//炸波定位,下同
				wo.my_bomb.sprites_up[i - 1]->setPosition(wo.renwu->getPosition() + Vec2(0, 40 * i));
				//锚点，下同
				wo.my_bomb.sprites_up[i - 1]->setAnchorPoint(Point(0, 0));
				//炸波在地图定层，下同
				map->addChild(wo.my_bomb.sprites_up[i - 1], 5);

				wo.my_bomb.sprites_up[i - 1]->runAction(Hide::create());
			}
			for (int i = 1; i <= wo.my_bomb_range; ++i)
			{
				wo.my_bomb.sprites_down[i - 1]->setPosition(wo.renwu->getPosition() + Vec2(0, -40 * i));
				wo.my_bomb.sprites_down[i - 1]->setAnchorPoint(Point(0, 0));
				map->addChild(wo.my_bomb.sprites_down[i - 1], 5);
				wo.my_bomb.sprites_down[i - 1]->runAction(Hide::create());
			}
			for (int i = 1; i <= wo.my_bomb_range; ++i)
			{
				wo.my_bomb.sprites_left[i - 1]->setPosition(wo.renwu->getPosition() + Vec2(-40 * i, 0));
				wo.my_bomb.sprites_left[i - 1]->setAnchorPoint(Point(0, 0));
				map->addChild(wo.my_bomb.sprites_left[i - 1], 5);
				wo.my_bomb.sprites_left[i - 1]->runAction(Hide::create());
			}
			for (int i = 1; i <= wo.my_bomb_range; ++i)
			{
				wo.my_bomb.sprites_right[i - 1]->setPosition(wo.renwu->getPosition() + Vec2(40 * i, 0));
				wo.my_bomb.sprites_right[i - 1]->setAnchorPoint(Point(0, 0));
				map->addChild(wo.my_bomb.sprites_right[i - 1], 5);
				wo.my_bomb.sprites_right[i - 1]->runAction(Hide::create());
			}
			//炸弹在地图定层
			map->addChild(newsp, 5);
			wo.my_bomb.explode(newsp, wo.my_bomb_range);
			wo.die(x, y);
		}
	}
}
void myscene::keyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	if ((keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) && (wo.isMoving_right == true))
	{
		wo.renwu->stopActionByTag(4);
		keys[keycode] = false;
		wo.isMoving = false;
		wo.isMoving_right = false;
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) && (wo.isMoving_left == true))
	{
		wo.renwu->stopActionByTag(3);
		keys[keycode] = false;
		wo.isMoving = false;
		wo.isMoving_left = false;
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_UP_ARROW) && (wo.isMoving_up == true))
	{
		wo.renwu->stopActionByTag(1);
		keys[keycode] = false;
		wo.isMoving = false;
		wo.isMoving_up = false;
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) && (wo.isMoving_down == true))
	{
		wo.renwu->stopActionByTag(2);
		keys[keycode] = false;
		wo.isMoving = false;
		wo.isMoving_down = false;
	}
}
void myscene::update(float delta)
{
	Node::update(delta);
	ptime -= delta;
	char* mtime = new char[10];
	//此处只是显示分钟数和秒数  自己可以定义输出时间格式  
	sprintf(mtime, "%d:%d", (int)ptime / 60, (int)ptime % 60);
	mytime->setString(mtime);
	delete mtime;
	if (isPressed(EventKeyboard::KeyCode::KEY_UP_ARROW))
		wo.moveup();
	if (isPressed(EventKeyboard::KeyCode::KEY_DOWN_ARROW))
		wo.movedown();
	if (isPressed(EventKeyboard::KeyCode::KEY_LEFT_ARROW))
		wo.moveleft();
	if (isPressed(EventKeyboard::KeyCode::KEY_RIGHT_ARROW))
		wo.moveright();
}
bool myscene::isPressed(cocos2d::EventKeyboard::KeyCode keycode)
{
	return keys[keycode];
}
void myscene::onEnter()
{
	Scene::onEnter();
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(myscene::keyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(myscene::keyReleased, this);
	EventDispatcher* log = Director::getInstance()->getEventDispatcher();
	log->addEventListenerWithSceneGraphPriority(listener, wo.renwu);
}	
void myscene::menuItemPopback(Ref* pSender)
{
	Director::getInstance()->popToRootScene();
}


#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
exit(0);
#endif

/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

//EventCustom customEndEvent("game_scene_close_event");
//_eventDispatcher->dispatchEvent(&customEndEvent);










