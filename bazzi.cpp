#include "bazzi.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

//ÒÆ¶¯
void bazzi::moveup()
{
	auto a = MoveBy::create(0.01f, Vec2(0, return_speed()));
	renwu->runAction(a);
}
void bazzi::moveup_action()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
		CCRectMake(72, 138, 43, 56));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
		CCRectMake(71, 210, 44, 55));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
		CCRectMake(72, 280, 43, 56));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
		CCRectMake(71, 352, 44, 55));
	animation->setRestoreOriginalFrame(false);
	animation->setDelayPerUnit(0.1f);
	animation->setLoops(1);
	Animate* animate = Animate::create(animation);
	auto b = RepeatForever::create(animate);
	b->setTag(1);
	renwu->runAction(b);
	isMoving_up = true;
}
void bazzi::movedown()
{
	auto a = MoveBy::create(0.01f, Vec2(0, -return_speed()));
	renwu->runAction(a);
}
void bazzi::movedown_action()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
		CCRectMake(144, 137, 42, 57));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
		CCRectMake(144, 210, 42, 55));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
		CCRectMake(144, 279, 42, 57));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
		CCRectMake(144, 352, 42, 55));
	animation->setRestoreOriginalFrame(false);
	animation->setDelayPerUnit(0.1f);
	animation->setLoops(1);
	Animate* animate = Animate::create(animation);
	auto b = RepeatForever::create(animate);
	b->setTag(2);
	renwu->runAction(b);
	isMoving_down = true;
}
void bazzi::moveright()
{
	auto a = MoveBy::create(0.01f, Vec2(return_speed(), 0));
	renwu->runAction(a);
}
void bazzi::moveright_action()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
		CCRectMake(239, 196, 42, 56));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
		CCRectMake(308, 195, 44, 57));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
		CCRectMake(380, 196, 43, 56));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
		CCRectMake(452, 194, 41, 58));
	animation->setRestoreOriginalFrame(false);
	animation->setDelayPerUnit(0.1f);
	animation->setLoops(1);
	Animate* animate = Animate::create(animation);
	auto b = RepeatForever::create(animate);
	b->setTag(4);
	renwu->runAction(b);
	isMoving_right = true;
}
void bazzi::moveleft()
{
	auto a = MoveBy::create(0.01f, Vec2(-return_speed(), 0));
	renwu->runAction(a);
}
void bazzi::moveleft_action()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi2.png"),
		CCRectMake(286, 196, 42, 56));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi2.png"),
		CCRectMake(215, 195, 44, 57));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi2.png"),
		CCRectMake(144, 196, 43, 56));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi2.png"),
		CCRectMake(74, 194, 41, 58));
	animation->setRestoreOriginalFrame(false);
	animation->setDelayPerUnit(0.1f);
	animation->setLoops(1);
	Animate* animate = Animate::create(animation);
	auto b = RepeatForever::create(animate);
	b->setTag(3);
	renwu->runAction(b);
	isMoving_left = true;
}

//ËÀÍö
void bazzi::blown(float x, float y)
{
	//Õ¨»Ù
	bod.bombdestroy((int)(x), (int)(y), my_bomb_range);
	//³·ÏúÕ¨µ¯Åö×²
	if (col.meta->getTileGIDAt(Vec2((int)(x) / 40, 12 - (int)(y) / 40)) == 4)
		col.meta->removeTileAt(Vec2((int)(x) / 40, 12 - (int)(y) / 40));
	//ËÀÍö
	if ((renwu->getPositionY()-y>=0&& renwu->getPositionY()-y <= range_up * 40 && abs(x - renwu->getPositionX()) <= 20)
		|| (y-renwu->getPositionY()>=0&&y - renwu->getPositionY() <= range_down * 40 && abs(x - renwu->getPositionX()) <= 20)
		||(x-renwu->getPositionX()>=0&&x - renwu->getPositionX() <= range_left * 40 && abs(y - renwu->getPositionY()) <= 20)
		|| (renwu->getPositionX()-x>=0&&renwu->getPositionX() - x <= range_right * 40 && abs(y - renwu->getPositionY())<=20))
	{
		Animation* animation = Animation::create();
		animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
			CCRectMake(242, 345, 67, 67));
		animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
			CCRectMake(234, 264, 60, 60));
		animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
			CCRectMake(306, 264, 60, 60));
		animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
			CCRectMake(375, 190, 60, 60));
		animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
			CCRectMake(447, 264, 60, 60));
		animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
			CCRectMake(67, 425, 66, 71));
		animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
			CCRectMake(142, 434, 44, 61));
		animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
			CCRectMake(360, 434, 42, 61));
		animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
			CCRectMake(458, 431, 42, 61));
		animation->setRestoreOriginalFrame(false);
		animation->setDelayPerUnit(0.2f);
		animation->setLoops(1);
		Animate* animate = Animate::create(animation);
		renwu->runAction(Sequence::create(animate, NULL));
	}
}
void bazzi::die(float x, float y)
{
	auto delayTime = DelayTime::create(2.0f);
	renwu->runAction(Sequence::create(delayTime, CCCallFunc::create(CC_CALLBACK_0(bazzi::blown, this, x, y)), NULL));
}

//ËÙ¶È½Ó¿Ú
int bazzi::return_speed()
{
	return speed;
}