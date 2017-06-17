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
bool myscene::init()
{
	if (!Scene::init())
	{
		return false;

	}
	//keys map初始化
	keys[EventKeyboard::KeyCode::KEY_RIGHT_ARROW] = false;
	keys[EventKeyboard::KeyCode::KEY_LEFT_ARROW] = false;
	keys[EventKeyboard::KeyCode::KEY_UP_ARROW] = false;
	keys[EventKeyboard::KeyCode::KEY_DOWN_ARROW] = false;
	//加载瓦片地图
	map = TMXTiledMap::create("tiled/a_map.tmx");
	//加载人物
	addPlayer(map);
	//加载碰撞层
	addcollidable(map);
	//加载炸毁层
	addbombdestroy(map);

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
	PopMenuItem->setPosition(650, 13);
	PopMenuItem->setAnchorPoint(Vec2(0.0, 0.0));
	Menu* mu = Menu::create(PopMenuItem, NULL);
	mu->setPosition(Vec2::ZERO);
	background->addChild(mu);
	background->addChild(wo.bod.no_use);
	return true;
}
//加载函数
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
	//人物在地图定层
	map->addChild(wo.renwu, 4);
	//人物计时器
	this->schedule(schedule_selector(myscene::update), 0.05f);
}
void myscene::addcollidable(TMXTiledMap* map)
{
	wo.col.meta = map->getLayer("meta");
	wo.col.meta->setVisible(false);
}
void myscene::addbombdestroy(TMXTiledMap* map)
{
	wo.bod.map = map;
	wo.bod.meta =map->getLayer("meta");
	wo.bod.meta->setVisible(false);
	wo.bod.a_undestroy = map->getLayer("a_undestroy");
	wo.bod.a_box = map->getLayer("a_box");
	wo.bod.a_movebox =map->getLayer("a_movebox");
	wo.bod.a_grass = map->getLayer("a_grass");
	wo.bod.b_undestroy = map->getLayer("b_undestroy");
	wo.bod.b_box =map->getLayer("b_box");
	wo.bod.b_movebox =map->getLayer("b_movebox");
	wo.bod.b_grass = map->getLayer("b_grass");
}
//按键控制函数
void myscene::keyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	//上下左右移动
	if ((keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) && (wo.isMoving == false))
	{
		wo.isMoving = true;
		keys[keycode] = true;
		if (wo.life == 1)
			wo.moveright_action();
		else
			wo.wangba_moveright_action();
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) && (wo.isMoving == false))
	{
		wo.isMoving = true;
		keys[keycode] = true;
		if (wo.life == 1)
			wo.moveleft_action();
		else
			wo.wangba_moveleft_action();
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_UP_ARROW) && (wo.isMoving == false))
	{
		wo.isMoving = true;
		keys[keycode] = true;
		if (wo.life == 1)
			wo.moveup_action();
		else
			wo.wangba_moveup_action();
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) && (wo.isMoving == false))
	{
		wo.isMoving = true;
		keys[keycode] = true;
		if (wo.life == 1)
			wo.movedown_action();
		else
			wo.wangba_movedown_action();
	}
	//空格炸弹
	if (keycode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		if (wo.my_bomb.my_bomb_quantity > 0)
		{
			--wo.my_bomb.my_bomb_quantity;
			Sprite* newsp = wo.my_bomb.creat_bomb(wo.my_bomb_range);
			//炸弹无重复定位
			Vec2 pos_now = set_tile(wo.renwu->getPositionX(), wo.renwu->getPositionY());
			if (wo.former_explode==false&&pos_now == Vec2(x, y))
			{
				++wo.my_bomb.my_bomb_quantity;
				return;
			}
			newsp->setPosition(pos_now);
			//锚点
			newsp->setAnchorPoint(Point(0, 0));
			//缩放
			newsp->setScale(0.9);
			x = newsp->getPositionX();
			y = newsp->getPositionY();
			//炸弹未爆状态
			wo.former_explode = false;
			//炸弹计时判断加入碰撞层
			this->schedule(schedule_selector(myscene::bomb_update), 0.01f);

			int range_up = wo.bod.bomb_up(x, y, wo.my_bomb_range);
			int range_down = wo.bod.bomb_down(x, y, wo.my_bomb_range);
			int range_left = wo.bod.bomb_left(x, y, wo.my_bomb_range);
			int range_right = wo.bod.bomb_right(x, y, wo.my_bomb_range);
			for (int i = 1; i <=range_up; ++i)
			{
				//炸波定位,下同
				wo.my_bomb.sprites_up[i - 1]->setPosition(Vec2(x, y) + Vec2(0, 40 * i));
				//锚点，下同
				wo.my_bomb.sprites_up[i - 1]->setAnchorPoint(Point(0, 0));
				//缩放，下同
				wo.my_bomb.sprites_up[i - 1]->setScale(0.9);
				//炸波在地图定层，下同
				map->addChild(wo.my_bomb.sprites_up[i - 1], 4);

				wo.my_bomb.sprites_up[i - 1]->runAction(Hide::create());
			}
			for (int i = 1; i <=range_down; ++i)
			{
				wo.my_bomb.sprites_down[i - 1]->setPosition(Vec2(x, y) + Vec2(0, -40 * i));
				wo.my_bomb.sprites_down[i - 1]->setAnchorPoint(Point(0, 0));
				wo.my_bomb.sprites_down[i - 1]->setScale(0.9);
				map->addChild(wo.my_bomb.sprites_down[i - 1], 4);
				wo.my_bomb.sprites_down[i - 1]->runAction(Hide::create());
			}
			for (int i = 1; i <=range_left; ++i)
			{
				wo.my_bomb.sprites_left[i - 1]->setPosition(Vec2(x, y) + Vec2(-40 * i, 0));
				wo.my_bomb.sprites_left[i - 1]->setAnchorPoint(Point(0, 0));
				wo.my_bomb.sprites_left[i - 1]->setScale(0.9);
				map->addChild(wo.my_bomb.sprites_left[i - 1], 4);
				wo.my_bomb.sprites_left[i - 1]->runAction(Hide::create());
			}
			for (int i = 1; i <=range_right; ++i)
			{
				wo.my_bomb.sprites_right[i - 1]->setPosition(Vec2(x, y) + Vec2(40 * i, 0));
				wo.my_bomb.sprites_right[i - 1]->setAnchorPoint(Point(0, 0));
				wo.my_bomb.sprites_right[i - 1]->setScale(0.9);
				map->addChild(wo.my_bomb.sprites_right[i - 1], 4);
				wo.my_bomb.sprites_right[i - 1]->runAction(Hide::create());
			}
			//炸弹在地图定层
			map->addChild(newsp, 4);
			//炸弹延时爆炸
			wo.my_bomb.explode(newsp, wo.my_bomb_range);
			//延时检测爆炸后多种事项
			wo.die(x, y, range_up, range_down, range_left, range_right);
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
//计时器函数
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
	{
		if (wo.col.collidable_up(wo.renwu->getPositionX(), wo.renwu->getPositionY(),wo.return_speed()))
		{
			return;
		}
		else
		{
			if (wo.col.col_move_up_left(wo.renwu->getPositionX(), wo.renwu->getPositionY(),wo.return_speed()))
			{
				wo.moveleft();
				return;
			}
			else if (wo.col.col_move_up_right(wo.renwu->getPositionX(), wo.renwu->getPositionY(), wo.return_speed()))
			{
				wo.moveright();
				return;
			}
		}
		wo.moveup();
	}
	if (isPressed(EventKeyboard::KeyCode::KEY_DOWN_ARROW))
	{
		if (wo.col.collidable_down(wo.renwu->getPositionX(), wo.renwu->getPositionY(), wo.return_speed()))
		{
			return;
		}
		else
		{
			if (wo.col.col_move_down_left(wo.renwu->getPositionX(), wo.renwu->getPositionY(), wo.return_speed()))
			{
				wo.moveleft();
				return;
			}
			else if (wo.col.col_move_down_right(wo.renwu->getPositionX(), wo.renwu->getPositionY(), wo.return_speed()))
			{
				wo.moveright();
				return;
			}
		}
		wo.movedown();
	}
	if (isPressed(EventKeyboard::KeyCode::KEY_LEFT_ARROW))
	{
		if (wo.col.collidable_left(wo.renwu->getPositionX(), wo.renwu->getPositionY(), wo.return_speed()))
		{
			return;
		}
		else
		{
			if (wo.col.col_move_left_up(wo.renwu->getPositionX(), wo.renwu->getPositionY(), wo.return_speed()))
			{
				wo.moveup();
				return;
			}
			else if (wo.col.col_move_left_down(wo.renwu->getPositionX(), wo.renwu->getPositionY(), wo.return_speed()))
			{
				wo.movedown();
				return;
			}
		}
		wo.moveleft();
	}
	if (isPressed(EventKeyboard::KeyCode::KEY_RIGHT_ARROW))
	{
		if (wo.col.collidable_right(wo.renwu->getPositionX(), wo.renwu->getPositionY(), wo.return_speed()))
		{
			return;
		}
		else
		{
			if (wo.col.col_move_right_up(wo.renwu->getPositionX(), wo.renwu->getPositionY(), wo.return_speed()))
			{
				wo.moveup();
				return;
			}
			else if (wo.col.col_move_right_down(wo.renwu->getPositionX(), wo.renwu->getPositionY(), wo.return_speed()))
			{
				wo.movedown();
				return;
			}
		}
		wo.moveright();
	}
	if (wo.is_shoes(map))
		wo.pick_shoes();
	if (wo.is_bubble(map))
		wo.pick_bubble();
	if (wo.is_medicine(map))
		wo.pick_medicine();
	if (wo.is_tortoise(map))
		wo.pick_tortoise();
}
void myscene::bomb_update(float delta)
{
	btime += delta;
	if (wo.col.meta->getTileGIDAt(Vec2((int)(x) / 40, 12 - (int)(y) / 40)) == 4||btime>=2.0f/*过两秒仍无反应，则自动取消计时器*/)
	{
		this->unschedule(schedule_selector(myscene::bomb_update));
		//叠加清零
		btime = 0.0f;
		return;
	}
	if (abs(wo.renwu->getPositionX() - x)>20 || abs(wo.renwu->getPositionY() - y)>20)
		wo.col.meta->setTileGID(4, Vec2((int)(x) / 40, 12 - (int)(y) / 40));
}

//其他函数
//坐标转换
Point myscene::set_tile(int x, int y)
{
	int _x = x / 40 * 40;
	int _y = y / 40 * 40;
	if (x % 40 <= 20 && y % 40 <= 20)
		return Point(_x, _y);
	else if (x % 40 <= 20 && y % 40 > 20)
		return Point(_x, _y + 40);
	else if (x % 40 > 20 && y % 40 <= 20)
		return Point(_x + 40, _y);
	else if (x % 40 > 20 && y % 40 > 20)
		return Point(_x + 40, _y + 40);
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



