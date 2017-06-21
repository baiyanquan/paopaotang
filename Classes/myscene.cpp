#include "myscene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;
extern int hahaha;
myscene* myscene::createScene()
{
	return myscene::create();
}

// on "init" you need to initialize your instance
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
	//keys map初始化
	keys[EventKeyboard::KeyCode::KEY_W] = false;
	keys[EventKeyboard::KeyCode::KEY_S] = false;
	keys[EventKeyboard::KeyCode::KEY_A] = false;
	keys[EventKeyboard::KeyCode::KEY_D] = false;
	//加载瓦片地图
	map = TMXTiledMap::create("tiled/a_map.tmx");
	//加载人物
	addPlayer_yellow(map);
	addPlayer_red(map);
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
	background->addChild(bod.no_use);
	background->addChild(da_use);
	return true;
}
//加载函数
void myscene::addPlayer_yellow(TMXTiledMap* map)
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
	this->schedule(schedule_selector(myscene::update1), 0.05f);
}
void myscene::addPlayer_red(TMXTiledMap* map)
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
	this->schedule(schedule_selector(myscene::update2), 0.05f);
}
void myscene::addcollidable(TMXTiledMap* map)
{
	ta.col.meta = map->getLayer("meta");
	ta.col.meta->setVisible(false);
	wo.col.meta = map->getLayer("meta");
	wo.col.meta->setVisible(false);
}
void myscene::addbombdestroy(TMXTiledMap* map)
{
	bod.map = map;
	bod.meta = map->getLayer("meta");
	bod.meta->setVisible(false);
	bod.a_undestroy = map->getLayer("a_undestroy");
	bod.a_box = map->getLayer("a_box");
	bod.a_movebox = map->getLayer("a_movebox");
	bod.a_grass = map->getLayer("a_grass");
	bod.b_undestroy = map->getLayer("b_undestroy");
	bod.b_box = map->getLayer("b_box");
	bod.b_movebox = map->getLayer("b_movebox");
	bod.b_grass = map->getLayer("b_grass");
}
//按键控制函数
void myscene::keyPressed(cocos2d::EventKeyboard::KeyCode keycode, cocos2d::Event* event)
{
	//上下左右移动
	if ((keycode == EventKeyboard::KeyCode::KEY_UP_ARROW) && (wo.isMoving == false) && (wo.is_die == false))
	{
		wo.isMoving = true;
		keys[keycode] = true;
		if (wo.life == 1)
			wo.moveup_action();
		else
			wo.wangba_moveup_action();
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) && (wo.isMoving == false)&&(wo.is_die == false))
	{
		wo.isMoving = true;
		keys[keycode] = true;
		if (wo.life == 1)
			wo.movedown_action();
		else
			wo.wangba_movedown_action();
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) && (wo.isMoving == false)&&(wo.is_die == false))
	{
		wo.isMoving = true;
		keys[keycode] = true;
		if (wo.life == 1)
			wo.moveleft_action();
		else
			wo.wangba_moveleft_action();
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) && (wo.isMoving == false)&&(wo.is_die == false))
	{
		wo.isMoving = true;
		keys[keycode] = true;
		if (wo.life == 1)
			wo.moveright_action();
		else
			wo.wangba_moveright_action();
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_W) && (ta.isMoving == false) && (ta.is_die == false))
	{
		ta.isMoving = true;
		keys[keycode] = true;
		if (ta.life == 1)
			ta.moveup_action();
		else
			ta.wangba_moveup_action();
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_S) && (ta.isMoving == false) && (ta.is_die == false))
	{
		ta.isMoving = true;
		keys[keycode] = true;
		if (ta.life == 1)
			ta.movedown_action();
		else
			ta.wangba_movedown_action();
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_A) && (ta.isMoving == false) && (ta.is_die == false))
	{
		ta.isMoving = true;
		keys[keycode] = true;
		if (ta.life == 1)
			ta.moveleft_action();
		else
			ta.wangba_moveleft_action();
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_D) && (ta.isMoving == false) && (ta.is_die == false))
	{
		ta.isMoving = true;
		keys[keycode] = true;
		if (ta.life == 1)
			ta.moveright_action();
		else
			ta.wangba_moveright_action();
	}
	//空格炸弹
	if (keycode == EventKeyboard::KeyCode::KEY_KP_ENTER && (wo.is_die == false))
	{
		if (wo.my_bomb.my_bomb_quantity > 0)
		{
			--wo.my_bomb.my_bomb_quantity;
			Sprite* newsp = wo.my_bomb.creat_bomb(wo.my_bomb_range);
			//炸弹无重复定位
			Vec2 pos_now = set_tile(wo.renwu->getPositionX(), wo.renwu->getPositionY());
			if ((wo.former_explode == false&& pos_now == Vec2(x, y))||(ta.former_explode==false&&pos_now==Vec2(x2,y2)) )
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

			int range_up = bod.bomb_up(x, y, wo.my_bomb_range);
			int range_down = bod.bomb_down(x, y, wo.my_bomb_range);
			int range_left = bod.bomb_left(x, y, wo.my_bomb_range);
			int range_right = bod.bomb_right(x, y, wo.my_bomb_range);
			for (int i = 1; i <= range_up; ++i)
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
			for (int i = 1; i <= range_down; ++i)
			{
				wo.my_bomb.sprites_down[i - 1]->setPosition(Vec2(x, y) + Vec2(0, -40 * i));
				wo.my_bomb.sprites_down[i - 1]->setAnchorPoint(Point(0, 0));
				wo.my_bomb.sprites_down[i - 1]->setScale(0.9);
				map->addChild(wo.my_bomb.sprites_down[i - 1], 4);
				wo.my_bomb.sprites_down[i - 1]->runAction(Hide::create());
			}
			for (int i = 1; i <= range_left; ++i)
			{
				wo.my_bomb.sprites_left[i - 1]->setPosition(Vec2(x, y) + Vec2(-40 * i, 0));
				wo.my_bomb.sprites_left[i - 1]->setAnchorPoint(Point(0, 0));
				wo.my_bomb.sprites_left[i - 1]->setScale(0.9);
				map->addChild(wo.my_bomb.sprites_left[i - 1], 4);
				wo.my_bomb.sprites_left[i - 1]->runAction(Hide::create());
			}
			for (int i = 1; i <= range_right; ++i)
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
			auto delayTime1 = DelayTime::create(2.0f);
			da_use->runAction(Sequence::create(delayTime1, CCCallFunc::create(CC_CALLBACK_0(myscene::cancel1, this, x, y, wo.my_bomb_range)), NULL));
			wo.die(x, y,range_up, range_down, range_left, range_right);
			ta.die(x, y,range_up, range_down, range_left, range_right);
		}
	}
	//回车炸弹
	if (keycode == EventKeyboard::KeyCode::KEY_SPACE && (ta.is_die == false))
	{
		if (ta.my_bomb.my_bomb_quantity > 0) 
		{
			--ta.my_bomb.my_bomb_quantity;
			Sprite* newsp = ta.my_bomb.creat_bomb(ta.my_bomb_range);
			//炸弹无重复定位
			Vec2 pos_now = set_tile(ta.renwu->getPositionX(), ta.renwu->getPositionY());
			if ((ta.former_explode == false && pos_now == Vec2(x2, y2)) || (wo.former_explode == false && pos_now == Vec2(x, y)))
			{
				++ta.my_bomb.my_bomb_quantity;
				return;
			}
			newsp->setPosition(pos_now);
			//锚点
			newsp->setAnchorPoint(Point(0, 0));
			//缩放
			newsp->setScale(0.9);
			x2 = newsp->getPositionX();
			y2 = newsp->getPositionY();
			//炸弹未爆状态
			ta.former_explode = false;
			//炸弹计时判断加入碰撞层
			this->schedule(schedule_selector(myscene::bomb2_update), 0.01f);

			int range_up = bod.bomb_up(x2, y2, ta.my_bomb_range);
			int range_down = bod.bomb_down(x2, y2, ta.my_bomb_range);
			int range_left = bod.bomb_left(x2, y2, ta.my_bomb_range);
			int range_right = bod.bomb_right(x2, y2, ta.my_bomb_range);
			for (int i = 1; i <= range_up; ++i)
			{
				//炸波定位,下同
				ta.my_bomb.sprites_up[i - 1]->setPosition(Vec2(x2, y2) + Vec2(0, 40 * i));
				//锚点，下同
				ta.my_bomb.sprites_up[i - 1]->setAnchorPoint(Point(0, 0));
				//缩放，下同
				ta.my_bomb.sprites_up[i - 1]->setScale(0.9);
				//炸波在地图定层，下同
				map->addChild(ta.my_bomb.sprites_up[i - 1], 4);

				ta.my_bomb.sprites_up[i - 1]->runAction(Hide::create());
			}
			for (int i = 1; i <= range_down; ++i)
			{
				ta.my_bomb.sprites_down[i - 1]->setPosition(Vec2(x2, y2) + Vec2(0, -40 * i));
				ta.my_bomb.sprites_down[i - 1]->setAnchorPoint(Point(0, 0));
				ta.my_bomb.sprites_down[i - 1]->setScale(0.9);
				map->addChild(ta.my_bomb.sprites_down[i - 1], 4);
				ta.my_bomb.sprites_down[i - 1]->runAction(Hide::create());
			}
			for (int i = 1; i <= range_left; ++i)
			{
				ta.my_bomb.sprites_left[i - 1]->setPosition(Vec2(x2, y2) + Vec2(-40 * i, 0));
				ta.my_bomb.sprites_left[i - 1]->setAnchorPoint(Point(0, 0));
				ta.my_bomb.sprites_left[i - 1]->setScale(0.9);
				map->addChild(ta.my_bomb.sprites_left[i - 1], 4);
				ta.my_bomb.sprites_left[i - 1]->runAction(Hide::create());
			}
			for (int i = 1; i <= range_right; ++i)
			{
				ta.my_bomb.sprites_right[i - 1]->setPosition(Vec2(x2, y2) + Vec2(40 * i, 0));
				ta.my_bomb.sprites_right[i - 1]->setAnchorPoint(Point(0, 0));
				ta.my_bomb.sprites_right[i - 1]->setScale(0.9);
				map->addChild(ta.my_bomb.sprites_right[i - 1], 4);
				ta.my_bomb.sprites_right[i - 1]->runAction(Hide::create());
			}
			//炸弹在地图定层
			map->addChild(newsp, 4);
			//炸弹延时爆炸
			ta.my_bomb.explode(newsp, ta.my_bomb_range);
			//延时检测爆炸后多种事项
			auto delayTime2 = DelayTime::create(2.0f);
			da_use->runAction(Sequence::create(delayTime2, CCCallFunc::create(CC_CALLBACK_0(myscene::cancel2, this, x2, y2, ta.my_bomb_range)), NULL));
			ta.die(x2, y2,range_up, range_down, range_left, range_right);
			wo.die(x2, y2,range_up, range_down, range_left, range_right);
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
	if ((keycode == EventKeyboard::KeyCode::KEY_D) && (ta.isMoving_right == true))
	{
		ta.renwu->stopActionByTag(8);
		keys[keycode] = false;
		ta.isMoving = false;
		ta.isMoving_right = false;
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_A) && (ta.isMoving_left == true))
	{
		ta.renwu->stopActionByTag(7);
		keys[keycode] = false;
		ta.isMoving = false;
		ta.isMoving_left = false;
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_W) && (ta.isMoving_up == true))
	{
		ta.renwu->stopActionByTag(5);
		keys[keycode] = false;
		ta.isMoving = false;
		ta.isMoving_up = false;
	}
	if ((keycode == EventKeyboard::KeyCode::KEY_S) && (ta.isMoving_down == true))
	{
		ta.renwu->stopActionByTag(6);
		keys[keycode] = false;
		ta.isMoving = false;
		ta.isMoving_down = false;
	}
}
//计时器函数
void myscene::update1(float delta)
{
	Node::update(delta);
	ptime -= delta;
	char* mtime = new char[10];
	//此处只是显示分钟数和秒数  自己可以定义输出时间格式  
	sprintf(mtime, "%d:%d", (int)ptime / 60, (int)ptime % 60);
	mytime->setString(mtime);
	delete mtime;
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(hahaha*0.01);
	if (wo.is_die == true)
	{
		keys[EventKeyboard::KeyCode::KEY_RIGHT_ARROW] = false;
		keys[EventKeyboard::KeyCode::KEY_LEFT_ARROW] = false;
		keys[EventKeyboard::KeyCode::KEY_UP_ARROW] = false;
		keys[EventKeyboard::KeyCode::KEY_DOWN_ARROW] = false;
		auto delayTime = DelayTime::create(2.0f);
		da_use->runAction(Sequence::create(delayTime, CCCallFunc::create(CC_CALLBACK_0(myscene::ending, this)), NULL));
	}
	if (isPressed(EventKeyboard::KeyCode::KEY_UP_ARROW))
	{
		if (wo.col.collidable_up(wo.renwu->getPositionX(), wo.renwu->getPositionY(), wo.return_speed()))
		{
			return;
		}
		else
		{
			if (wo.col.col_move_up_left(wo.renwu->getPositionX(), wo.renwu->getPositionY(), wo.return_speed()))
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
	if (wo.is_shoes(bod))
		wo.pick_shoes();
	if (wo.is_bubble(bod))
		wo.pick_bubble();
	if (wo.is_medicine(bod))
		wo.pick_medicine();
	if (wo.is_tortoise(bod))
		wo.pick_tortoise();
}
void myscene::update2(float delta)
{
	Node::update(delta);
	if (ta.is_die == true)
	{
		keys[EventKeyboard::KeyCode::KEY_W] = false;
		keys[EventKeyboard::KeyCode::KEY_S] = false;
		keys[EventKeyboard::KeyCode::KEY_A] = false;
		keys[EventKeyboard::KeyCode::KEY_D] = false;
		auto delayTime = DelayTime::create(2.0f);
		da_use->runAction(Sequence::create(delayTime, CCCallFunc::create(CC_CALLBACK_0(myscene::ending, this)), NULL));
	}
	if (isPressed(EventKeyboard::KeyCode::KEY_W))
	{
		if (ta.col.collidable_up(ta.renwu->getPositionX(), ta.renwu->getPositionY(), ta.return_speed()))
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
			else if (ta.col.col_move_up_right(ta.renwu->getPositionX(), ta.renwu->getPositionY(), ta.return_speed()))
			{
				ta.moveright();
				return;
			}
		}
		ta.moveup();
	}
	if (isPressed(EventKeyboard::KeyCode::KEY_S))
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
	if (isPressed(EventKeyboard::KeyCode::KEY_A))
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
	if (isPressed(EventKeyboard::KeyCode::KEY_D))
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
				ta.movedown();
				return;
			}
		}
		ta.moveright();
	}
	if (ta.is_shoes(bod))
		ta.pick_shoes();
	if (ta.is_bubble(bod))
		ta.pick_bubble();
	if (ta.is_medicine(bod))
		ta.pick_medicine();
	if (ta.is_tortoise(bod))
		ta.pick_tortoise();
}
void myscene::bomb_update(float delta)
{
	btime += delta;
	if (wo.col.meta->getTileGIDAt(Vec2((int)(x) / 40, 12 - (int)(y) / 40)) == 4 || btime >= 2.0f/*过两秒仍无反应，则自动取消计时器*/)
	{
		this->unschedule(schedule_selector(myscene::bomb_update));
		//叠加清零
		btime = 0.0f;
		return;
	}
	if (abs(wo.renwu->getPositionX() - x)>20 || abs(wo.renwu->getPositionY() - y)>20)
		wo.col.meta->setTileGID(4, Vec2((int)(x) / 40, 12 - (int)(y) / 40));
}
void myscene::bomb2_update(float delta)
{
	btime2 += delta;
	if (ta.col.meta->getTileGIDAt(Vec2((int)(x2) / 40, 12 - (int)(y2) / 40)) == 4 || btime2 >= 2.0f/*过两秒仍无反应，则自动取消计时器*/)
	{
		this->unschedule(schedule_selector(myscene::bomb2_update));
		//叠加清零
		btime2 = 0.0f;
		return;
	}
	if (abs(ta.renwu->getPositionX() - x2)>20 || abs(ta.renwu->getPositionY() - y2)>20)
		ta.col.meta->setTileGID(4, Vec2((int)(x2) / 40, 12 - (int)(y2) / 40));
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
void myscene::onEnterTransitionDidFinish()
{
	Scene::onEnterTransitionDidFinish();
	SimpleAudioEngine::getInstance()->playBackgroundMusic("xiaoqu.mp3", true);
}
void myscene::onExit()
{
	Scene::onExit();
}
void myscene::OnExitTransitionDidStart()
{
	Scene::onExitTransitionDidStart();
}
void myscene::cleanup()
{
	Scene::cleanup();
	SimpleAudioEngine::getInstance()->stopBackgroundMusic("xiaoqu.mp3");
}
void myscene::cancel1(int x, int y, int range)
{
	//炸弹已爆状态
	wo.former_explode = true;
	//炸毁
	bod.zhahui(x, y, range);
}
void myscene::cancel2(int x, int y, int range)
{
	//炸弹已爆状态
	ta.former_explode = true;
	//炸毁
	bod.zhahui(x, y, range);
}
void myscene::ending()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Sprite* end = Sprite::create("win.png");
	end->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	this->addChild(end, 1);
	auto delayTime = DelayTime::create(5.0f);
	da_use->runAction(Sequence::create(delayTime, CCCallFunc::create(CC_CALLBACK_0(myscene::back, this)), NULL));
}
void myscene::back()
{
	Director::getInstance()->popToRootScene();
}
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
exit(0);
#endif

/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

//EventCustom customEndEvent("game_scene_close_event");
//_eventDispatcher->dispatchEvent(&customEndEvent);










