#include "bazzi2.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace CocosDenshion;

//�ƶ�
void bazzi2::moveup()
{
	auto a = MoveBy::create(0.01f, Vec2(0, return_speed()));
	renwu->runAction(a);
}
void bazzi2::moveup_action()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
		CCRectMake(72, 138, 43, 56));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
		CCRectMake(71, 210, 44, 55));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
		CCRectMake(72, 280, 43, 56));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
		CCRectMake(71, 352, 44, 55));
	animation->setRestoreOriginalFrame(false);
	animation->setDelayPerUnit(0.1f * 5 / return_speed());
	animation->setLoops(1);
	Animate* animate = Animate::create(animation);
	auto b = RepeatForever::create(animate);
	b->setTag(5);
	renwu->runAction(b);
	isMoving_up = true;
}
void bazzi2::wangba_moveup_action()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzihongse1.png"),
		CCRectMake(0, 0, 43, 76));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzihongse2.png"),
		CCRectMake(0, 0, 43, 76));
	animation->setRestoreOriginalFrame(false);
	animation->setDelayPerUnit(0.1f * 5 / return_speed());
	animation->setLoops(1);
	Animate* animate = Animate::create(animation);
	auto b = RepeatForever::create(animate);
	b->setTag(5);
	renwu->runAction(b);
	isMoving_up = true;

}
void bazzi2::movedown()
{
	auto a = MoveBy::create(0.01f, Vec2(0, -return_speed()));
	renwu->runAction(a);
}
void bazzi2::movedown_action()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
		CCRectMake(144, 137, 42, 57));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
		CCRectMake(144, 210, 42, 55));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
		CCRectMake(144, 279, 42, 57));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
		CCRectMake(144, 352, 42, 55));
	animation->setRestoreOriginalFrame(false);
	animation->setDelayPerUnit(0.1f * 5 / return_speed());
	animation->setLoops(1);
	Animate* animate = Animate::create(animation);
	auto b = RepeatForever::create(animate);
	b->setTag(6);
	renwu->runAction(b);
	isMoving_down = true;
}
void bazzi2::wangba_movedown_action()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzihongse3.png"),
		CCRectMake(0, 0, 44, 77));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzihongse4.png"),
		CCRectMake(0, 0, 44, 77));
	animation->setRestoreOriginalFrame(false);
	animation->setDelayPerUnit(0.1f * 5 / return_speed());
	animation->setLoops(1);
	Animate* animate = Animate::create(animation);
	auto b = RepeatForever::create(animate);
	b->setTag(6);
	renwu->runAction(b);
	isMoving_down = true;

}
void bazzi2::moveright()
{
	auto a = MoveBy::create(0.01f, Vec2(return_speed(), 0));
	renwu->runAction(a);
}
void bazzi2::moveright_action()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
		CCRectMake(239, 196, 42, 56));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
		CCRectMake(308, 195, 44, 57));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
		CCRectMake(380, 196, 43, 56));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
		CCRectMake(452, 194, 41, 58));
	animation->setRestoreOriginalFrame(false);
	animation->setDelayPerUnit(0.1f * 5 / return_speed());
	animation->setLoops(1);
	Animate* animate = Animate::create(animation);
	auto b = RepeatForever::create(animate);
	b->setTag(8);
	renwu->runAction(b);
	isMoving_right = true;
}
void bazzi2::wangba_moveright_action()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzihongse5.png"),
		CCRectMake(0, 0, 46, 78));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzihongse6.png"),
		CCRectMake(0, 0, 46, 78));
	animation->setRestoreOriginalFrame(false);
	animation->setDelayPerUnit(0.1f * 5 / return_speed());
	animation->setLoops(1);
	Animate* animate = Animate::create(animation);
	auto b = RepeatForever::create(animate);
	b->setTag(8);
	renwu->runAction(b);
	isMoving_right = true;

}
void bazzi2::moveleft()
{
	auto a = MoveBy::create(0.01f, Vec2(-return_speed(), 0));
	renwu->runAction(a);
}
void bazzi2::moveleft_action()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi4.png"),
		CCRectMake(286, 196, 42, 56));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi4.png"),
		CCRectMake(215, 195, 44, 57));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi4.png"),
		CCRectMake(144, 196, 43, 56));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi4.png"),
		CCRectMake(74, 194, 41, 58));
	animation->setRestoreOriginalFrame(false);
	animation->setDelayPerUnit(0.1f * 5 / return_speed());
	animation->setLoops(1);
	Animate* animate = Animate::create(animation);
	auto b = RepeatForever::create(animate);
	b->setTag(7);
	renwu->runAction(b);
	isMoving_left = true;
}
void bazzi2::wangba_moveleft_action()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzihongse7.png"),
		CCRectMake(0, 0, 46, 76));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzihongse8.png"),
		CCRectMake(0, 0, 46, 78));
	animation->setRestoreOriginalFrame(false);
	animation->setDelayPerUnit(0.1f * 5 / return_speed());
	animation->setLoops(1);
	Animate* animate = Animate::create(animation);
	auto b = RepeatForever::create(animate);
	b->setTag(7);
	renwu->runAction(b);
	isMoving_left = true;

}

//����
void bazzi2::blown(float x, float y,int range_up, int range_down, int range_left, int range_right)
{
	//����ը����ײ
	col.meta->removeTileAt(Vec2((int)(x) / 40, 12 - (int)(y) / 40));
	//����
	if ((renwu->getPositionY() - y >= 0 && renwu->getPositionY() - y <= range_up * 40 + 20 && abs(x - renwu->getPositionX()) <= 20)
		|| (y - renwu->getPositionY() >= 0 && y - renwu->getPositionY() <= range_down * 40 + 20 && abs(x - renwu->getPositionX()) <= 20)
		|| (x - renwu->getPositionX() >= 0 && x - renwu->getPositionX() <= range_left * 40 + 20 && abs(y - renwu->getPositionY()) <= 20)
		|| (renwu->getPositionX() - x >= 0 && renwu->getPositionX() - x <= range_right * 40 + 20 && abs(y - renwu->getPositionY()) <= 20))
	{
		if (life == 2)
			--life;
		else
		{
			is_die = true;
			renwu->stopAllActions();
			Animation* animation = Animation::create();
			animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
				CCRectMake(242, 345, 67, 67));
			animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
				CCRectMake(234, 264, 60, 60));
			animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
				CCRectMake(306, 264, 60, 60));
			animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
				CCRectMake(375, 190, 60, 60));
			animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
				CCRectMake(447, 264, 60, 60));
			animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
				CCRectMake(67, 425, 66, 71));
			animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
				CCRectMake(142, 434, 44, 61));
			animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
				CCRectMake(360, 434, 42, 61));
			animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi3.png"),
				CCRectMake(458, 431, 42, 61));
			animation->setRestoreOriginalFrame(false);
			animation->setDelayPerUnit(0.2f);
			animation->setLoops(1);
			Animate* animate = Animate::create(animation);
			renwu->runAction(Sequence::create(animate, NULL));
			SimpleAudioEngine::getInstance()->playEffect("die.wav");
		}
	}
}
void bazzi2::die(float x, float y,int range_up, int range_down, int range_left, int range_right)
{
	auto delayTime = DelayTime::create(2.0f);
	renwu->runAction(Sequence::create(delayTime, CCCallFunc::create(CC_CALLBACK_0(bazzi2::blown, this, x, y,range_up, range_down, range_left, range_right)), NULL));
}

//�ٶȽӿ�
int bazzi2::return_speed()
{
	if (life == 1)
		return speed;
	else
		return wangba_speed;
}

//���߼��
bool bazzi2::is_shoes(Bombdestroy& bod)
{
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			if (abs(renwu->getPositionX() - i * 40) <= 20 && abs(renwu->getPositionY() - (480 - j * 40)) <= 20
				&& bod.prop[i][j] == 1)
			{
				bod.shoes[i][j].remove_shoes(bod.map);
				bod.prop[i][j] = 0;
				if (speed<10)
					return true;
			}
		}
	}
	return false;
}
bool bazzi2::is_bubble(Bombdestroy& bod)
{
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			if (abs(renwu->getPositionX() - i * 40) <= 20 && abs(renwu->getPositionY() - (480 - j * 40)) <= 20
				&& bod.prop[i][j] == 2)
			{
				bod.bubble[i][j].remove_bubble(bod.map);
				bod.prop[i][j] = 0;
				return true;
			}
		}
	}
	return false;
}
bool bazzi2::is_medicine(Bombdestroy& bod)
{
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			if (abs(renwu->getPositionX() - i * 40) <= 20 && abs(renwu->getPositionY() - (480 - j * 40)) <= 20
				&& bod.prop[i][j] == 3)
			{
				bod.medicine[i][j].remove_medicine(bod.map);
				bod.prop[i][j] = 0;
				return true;
			}
		}
	}
	return false;
}
bool bazzi2::is_tortoise(Bombdestroy& bod)
{
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			if (abs(renwu->getPositionX() - i * 40) <= 20 && abs(renwu->getPositionY() - (480 - j * 40)) <= 20
				&& bod.prop[i][j] == 4)
			{
				bod.tortoise[i][j].remove_tortoise(bod.map);
				bod.prop[i][j] = 0;
				if (life == 1)
					return true;
			}
		}
	}
	return false;
}

//�����
void bazzi2::pick_shoes()
{
	++speed;
}
void bazzi2::pick_bubble()
{
	++my_bomb_limits_quantity;
	++my_bomb.my_bomb_quantity;
}
void bazzi2::pick_medicine()
{
	++my_bomb_range;
}
void bazzi2::pick_tortoise()
{
	++life;
}