#include "myscene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

myscene* myscene::createScene()
{
	return myscene::create();
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
	addPlayer_wo(map);
	addPlayer_ta(map);
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

	return true;
}
//加载函数
void myscene::addPlayer_wo(TMXTiledMap* map)
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
	this->schedule(schedule_selector(myscene::updatewo), 0.05f);
}
void myscene::addPlayer_ta(TMXTiledMap* map)
{
	//加载对象层
	TMXObjectGroup* objGroup = map->getObjectGroup("object");
	//加载人物坐标对象
	ValueMap playerPointMap = objGroup->getObject("renwu_red");
	float playerX = playerPointMap.at("x").asFloat();
	float playerY = playerPointMap.at("y").asFloat();
	//人物定位
	ta.renwu->setPosition(Point(playerX, playerY));
	//锚点
	ta.renwu->setAnchorPoint(Point(0, 0));
	//人物在地图定层
	map->addChild(ta.renwu, 4);
	//人物计时器
	this->schedule(schedule_selector(myscene::updateta), 0.05f);
}
void myscene::addcollidable(TMXTiledMap* map)
{
	wo.col.meta = map->getLayer("meta");
	wo.col.meta->setVisible(false);
	ta.col.meta = map->getLayer("meta");
	ta.col.meta->setVisible(false);
}
void myscene::addbombdestroy(TMXTiledMap* map)
{
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
	ta.bod.meta = map->getLayer("meta");
	ta.bod.meta->setVisible(false);
	ta.bod.a_undestroy = map->getLayer("a_undestroy");
	ta.bod.a_box = map->getLayer("a_box");
	ta.bod.a_movebox = map->getLayer("a_movebox");
	ta.bod.a_grass = map->getLayer("a_grass");
	ta.bod.b_undestroy = map->getLayer("b_undestroy");
	ta.bod.b_box = map->getLayer("b_box");
	ta.bod.b_movebox = map->getLayer("b_movebox");
	ta.bod.b_grass = map->getLayer("b_grass");
}
//wo按键控制函数
void myscene::keyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	//上下左右移动
	if ((keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) && (wo.isMoving == false))
	{
		datasend1[0] = '1';
		wo.isMoving = true;
		keys[keycode] = true;
		wo.moveright_action();
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) && (wo.isMoving == false))
	{
		datasend1[1] = '1';
		wo.isMoving = true;
		keys[keycode] = true;
		wo.moveleft_action();
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_UP_ARROW) && (wo.isMoving == false))
	{
		datasend1[2] = '1';
		wo.isMoving = true;
		keys[keycode] = true;
		wo.moveup_action();
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) && (wo.isMoving == false))
	{
		datasend1[3] = '1';
		wo.isMoving = true;
		keys[keycode] = true;
		wo.movedown_action();
	}
	//空格炸弹
	if (keycode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		datasend1[4] = '1';
		if (wo.my_bomb.my_bomb_quantity > 0)
		{
			--wo.my_bomb.my_bomb_quantity;
			Sprite* newsp = wo.my_bomb.creat_bomb(wo.my_bomb_range);
			//炸弹定位
			newsp->setPosition(set_tile(wo.renwu->getPositionX(), wo.renwu->getPositionY()));
			//锚点
			newsp->setAnchorPoint(Point(0, 0));
			//缩放
			newsp->setScale(0.9);
			wox = newsp->getPositionX();
			woy = newsp->getPositionY();
			//炸弹计时判断加入碰撞层（可同时含多个炸弹计时器）
			this->schedule(schedule_selector(myscene::wobomb_update), 0.05f);

			wo.range_up = wo.bod.bomb_up(wox, woy, wo.my_bomb_range);
			wo.range_down = wo.bod.bomb_down(wox, woy, wo.my_bomb_range);
			wo.range_left = wo.bod.bomb_left(wox, woy, wo.my_bomb_range);
			wo.range_right = wo.bod.bomb_right(wox, woy, wo.my_bomb_range);
			for (int i = 1; i <= wo.range_up; ++i)
			{
				//炸波定位,下同
				wo.my_bomb.sprites_up[i - 1]->setPosition(Vec2(wox, woy) + Vec2(0, 40 * i));
				//锚点，下同
				wo.my_bomb.sprites_up[i - 1]->setAnchorPoint(Point(0, 0));
				//缩放，下同
				wo.my_bomb.sprites_up[i - 1]->setScale(0.9);
				//炸波在地图定层，下同
				map->addChild(wo.my_bomb.sprites_up[i - 1], 4);

				wo.my_bomb.sprites_up[i - 1]->runAction(Hide::create());
			}
			for (int i = 1; i <= wo.range_down; ++i)
			{
				wo.my_bomb.sprites_down[i - 1]->setPosition(Vec2(wox, woy) + Vec2(0, -40 * i));
				wo.my_bomb.sprites_down[i - 1]->setAnchorPoint(Point(0, 0));
				wo.my_bomb.sprites_down[i - 1]->setScale(0.9);
				map->addChild(wo.my_bomb.sprites_down[i - 1], 4);
				wo.my_bomb.sprites_down[i - 1]->runAction(Hide::create());
			}
			for (int i = 1; i <= wo.range_left; ++i)
			{
				wo.my_bomb.sprites_left[i - 1]->setPosition(Vec2(wox, woy) + Vec2(-40 * i, 0));
				wo.my_bomb.sprites_left[i - 1]->setAnchorPoint(Point(0, 0));
				wo.my_bomb.sprites_left[i - 1]->setScale(0.9);
				map->addChild(wo.my_bomb.sprites_left[i - 1], 4);
				wo.my_bomb.sprites_left[i - 1]->runAction(Hide::create());
			}
			for (int i = 1; i <= wo.range_right; ++i)
			{
				wo.my_bomb.sprites_right[i - 1]->setPosition(Vec2(wox, woy) + Vec2(40 * i, 0));
				wo.my_bomb.sprites_right[i - 1]->setAnchorPoint(Point(0, 0));
				wo.my_bomb.sprites_right[i - 1]->setScale(0.9);
				map->addChild(wo.my_bomb.sprites_right[i - 1], 4);
				wo.my_bomb.sprites_right[i - 1]->runAction(Hide::create());
			}
			//炸弹在地图定层
			map->addChild(newsp, 4);
			//炸弹延时爆炸
			wo.my_bomb.explode(newsp, wo.my_bomb_range);
			//延时检测死亡及撤除碰撞层
			wo.die(wox, woy);
		}
	}
}
void myscene::keyReleased(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	if ((keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) && (wo.isMoving_right == true))
	{
		datasend1[0] = '0';
		wo.renwu->stopActionByTag(4);
		keys[keycode] = false;
		wo.isMoving = false;
		wo.isMoving_right = false;
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) && (wo.isMoving_left == true))
	{
		datasend1[1] = '0';
		wo.renwu->stopActionByTag(3);
		keys[keycode] = false;
		wo.isMoving = false;
		wo.isMoving_left = false;
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_UP_ARROW) && (wo.isMoving_up == true))
	{
		datasend1[2] = '0';
		wo.renwu->stopActionByTag(1);
		keys[keycode] = false;
		wo.isMoving = false;
		wo.isMoving_up = false;
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) && (wo.isMoving_down == true))
	{
		datasend1[3] = '0';
		wo.renwu->stopActionByTag(2);
		keys[keycode] = false;
		wo.isMoving = false;
		wo.isMoving_down = false;
	}
	if (keycode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		datasend1[4] = '0';
	}
}
//计时器函数
void myscene::updatewo(float delta)
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
}
void myscene::wobomb_update(float delta)
{
	btime += delta;
	if (wo.col.meta->getTileGIDAt(Vec2((int)(wox) / 40, 12 - (int)(woy) / 40)) == 4||btime>=2.0f/*过两秒仍无反应，则自动取消计时器*/)
	{
		this->unschedule(schedule_selector(myscene::wobomb_update));
		//叠加清零
		btime = 0.0f;
		return;
	}
	if (abs(wo.renwu->getPositionX() - wox)>20 || abs(wo.renwu->getPositionY() - woy)>20)
		wo.col.meta->setTileGID(4, Vec2((int)(wox) / 40, 12 - (int)(woy) / 40));
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
//ta
void myscene::receieveaction(char data[6])
{
	//上下左右移动
	if ((data[0] == '1') && (ta.isMoving == false))
	{
		ta.isMoving = true;
		ta.moveright_action();
	}
	if ((data[1] == '1') && (ta.isMoving == false))
	{
		ta.isMoving = true;
		ta.moveleft_action();
	}
	if ((data[2] == '1') && (ta.isMoving == false))
	{
		ta.isMoving = true;
		ta.moveup_action();
	}
	if ((data[3] == '1') && (ta.isMoving == false))
	{
		ta.isMoving = true;
		ta.movedown_action();
	}
	//空格炸弹
	if (data[4] == '1')
	{
		if (ta.my_bomb.my_bomb_quantity > 0)
		{
			--ta.my_bomb.my_bomb_quantity;
			Sprite* newsp = ta.my_bomb.creat_bomb(ta.my_bomb_range);
			//炸弹定位
			newsp->setPosition(set_tile(ta.renwu->getPositionX(), ta.renwu->getPositionY()));
			//锚点
			newsp->setAnchorPoint(Point(0, 0));
			//缩放
			newsp->setScale(0.9);
			tax = newsp->getPositionX();
			tay = newsp->getPositionY();
			//炸弹计时判断加入碰撞层（可同时含多个炸弹计时器）
			this->schedule(schedule_selector(myscene::tabomb_update), 0.05f);
			for (int i = 1; i <= ta.my_bomb_range; ++i)
			{
				//炸波定位,下同
				ta.my_bomb.sprites_up[i - 1]->setPosition(Vec2(tax, tay) + Vec2(0, 40 * i));
				//锚点，下同
				ta.my_bomb.sprites_up[i - 1]->setAnchorPoint(Point(0, 0));
				//缩放，下同
				ta.my_bomb.sprites_up[i - 1]->setScale(0.9);
				//炸波在地图定层，下同
				map->addChild(ta.my_bomb.sprites_up[i - 1], 4);

				ta.my_bomb.sprites_up[i - 1]->runAction(Hide::create());
			}
			for (int i = 1; i <= ta.my_bomb_range; ++i)
			{
				ta.my_bomb.sprites_down[i - 1]->setPosition(Vec2(tax, tay) + Vec2(0, -40 * i));
				ta.my_bomb.sprites_down[i - 1]->setAnchorPoint(Point(0, 0));
				ta.my_bomb.sprites_down[i - 1]->setScale(0.9);
				map->addChild(ta.my_bomb.sprites_down[i - 1], 4);
				ta.my_bomb.sprites_down[i - 1]->runAction(Hide::create());
			}
			for (int i = 1; i <= ta.my_bomb_range; ++i)
			{
				ta.my_bomb.sprites_left[i - 1]->setPosition(Vec2(tax, tay) + Vec2(-40 * i, 0));
				ta.my_bomb.sprites_left[i - 1]->setAnchorPoint(Point(0, 0));
				ta.my_bomb.sprites_left[i - 1]->setScale(0.9);
				map->addChild(ta.my_bomb.sprites_left[i - 1], 4);
				ta.my_bomb.sprites_left[i - 1]->runAction(Hide::create());
			}
			for (int i = 1; i <= ta.my_bomb_range; ++i)
			{
				ta.my_bomb.sprites_right[i - 1]->setPosition(Vec2(tax, tay) + Vec2(40 * i, 0));
				ta.my_bomb.sprites_right[i - 1]->setAnchorPoint(Point(0, 0));
				ta.my_bomb.sprites_right[i - 1]->setScale(0.9);
				map->addChild(ta.my_bomb.sprites_right[i - 1], 4);
				ta.my_bomb.sprites_right[i - 1]->runAction(Hide::create());
			}
			//炸弹在地图定层
			map->addChild(newsp, 4);
			//炸弹延时爆炸
			ta.my_bomb.explode(newsp, ta.my_bomb_range);
			//延时检测死亡及撤除碰撞层
			ta.die(tax, tay);
		}
	}
}
void myscene::receievestop(char data[6])
{
	if ((data[0] == '0') && (ta.isMoving_right == true))
	{
		ta.renwu->stopActionByTag(4);
		ta.isMoving = false;
		ta.isMoving_right = false;
	}
	if ((data[1] == '0') && (ta.isMoving_left == true))
	{
		ta.renwu->stopActionByTag(3);
		ta.isMoving = false;
		ta.isMoving_left = false;
	}
	if ((data[2] == '0') && (ta.isMoving_up == true))
	{
		ta.renwu->stopActionByTag(1);
		ta.isMoving = false;
		ta.isMoving_up = false;
	}
	if ((data[3] == '0') && (ta.isMoving_down == true))
	{
		ta.renwu->stopActionByTag(2);
		ta.isMoving = false;
		ta.isMoving_down = false;
	}
}
//计时器函数
void myscene::updateta(float delta)
{
	Node::update(delta);
	ptime -= delta;
	char* mtime = new char[10];
	//此处只是显示分钟数和秒数  自己可以定义输出时间格式  
	sprintf(mtime, "%d:%d", (int)ptime / 60, (int)ptime % 60);
	mytime->setString(mtime);
	delete mtime;
	if (datareceievecopy[2] == '1')
	{
		if (ta.col.collidable_up(wo.renwu->getPositionX(), ta.renwu->getPositionY(), ta.return_speed()))
		{
			return;
		}
		else
		{
			if (ta.col.col_move_up_left(ta.renwu->getPositionX(), ta.renwu->getPositionY(), ta.return_speed()))
			{
				ta.moveleft();
				return;
			}
			else if (ta.col.col_move_up_right(wo.renwu->getPositionX(), ta.renwu->getPositionY(), ta.return_speed()))
			{
				ta.moveright();
				return;
			}
		}
		ta.moveup();
	}
	if (datareceievecopy[3] == '1')
	{
		if (ta.col.collidable_down(ta.renwu->getPositionX(), ta.renwu->getPositionY(), ta.return_speed()))
		{
			return;
		}
		else
		{
			if (ta.col.col_move_down_left(ta.renwu->getPositionX(), ta.renwu->getPositionY(), ta.return_speed()))
			{
				ta.moveleft();
				return;
			}
			else if (ta.col.col_move_down_right(ta.renwu->getPositionX(), ta.renwu->getPositionY(), ta.return_speed()))
			{
				ta.moveright();
				return;
			}
		}
		ta.movedown();
	}
	if (datareceievecopy[1] == '1')
	{
		if (ta.col.collidable_left(ta.renwu->getPositionX(), ta.renwu->getPositionY(), ta.return_speed()))
		{
			return;
		}
		else
		{
			if (ta.col.col_move_left_up(ta.renwu->getPositionX(), ta.renwu->getPositionY(), ta.return_speed()))
			{
				ta.moveup();
				return;
			}
			else if (ta.col.col_move_left_down(ta.renwu->getPositionX(), ta.renwu->getPositionY(), ta.return_speed()))
			{
				ta.movedown();
				return;
			}
		}
		ta.moveleft();
	}
	if (datareceievecopy[0] == '1')
	{
		if (ta.col.collidable_right(ta.renwu->getPositionX(), ta.renwu->getPositionY(), ta.return_speed()))
		{
			return;
		}
		else
		{
			if (ta.col.col_move_right_up(ta.renwu->getPositionX(), ta.renwu->getPositionY(), ta.return_speed()))
			{
				ta.moveup();
				return;
			}
			else if (ta.col.col_move_right_down(ta.renwu->getPositionX(), ta.renwu->getPositionY(), ta.return_speed()))
			{
				wo.movedown();
				return;
			}
		}
		ta.moveright();
	}
}
void myscene::tabomb_update(float delta)
{
	btime += delta;
	if (ta.col.meta->getTileGIDAt(Vec2((int)(tax) / 40, 12 - (int)(tay) / 40)) == 4 || btime >= 2.0f/*过两秒仍无反应，则自动取消计时器*/)
	{
		this->unschedule(schedule_selector(myscene::tabomb_update));
		//叠加清零
		btime = 0.0f;
		return;
	}
	if (abs(ta.renwu->getPositionX() - tax)>20 || abs(ta.renwu->getPositionY() - tay)>20)
		ta.col.meta->setTileGID(4, Vec2((int)(tax) / 40, 12 - (int)(tay) / 40));
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
exit(0);
#endif

/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

//EventCustom customEndEvent("game_scene_close_event");
//_eventDispatcher->dispatchEvent(&customEndEvent);



