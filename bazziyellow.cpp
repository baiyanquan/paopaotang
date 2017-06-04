#include "bazziyellow.h"
USING_NS_CC;
void bazziyellow::moveup()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazziyellow1.png"),
		CCRectMake(67, 132, 62, 62));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazziyellow1.png"),
		CCRectMake(67, 204, 62, 62));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazziyellow1.png"),
		CCRectMake(67, 275, 62, 62));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazziyellow1.png"),
		CCRectMake(67, 348, 62, 62));
	animation->setRestoreOriginalFrame(false);
	animation->setDelayPerUnit(1.0 / 5.0);
	animation->setLoops(1);
	Animate* animate = Animate::create(animation);
	renwu->runAction(animate);
}
void bazziyellow::movedown()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazziyellow1.png"),
		CCRectMake(138, 132, 62, 62));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazziyellow1.png"),
		CCRectMake(138, 204, 62, 60));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazziyellow1.png"),
		CCRectMake(138, 275, 62, 62));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazziyellow1.png"),
		CCRectMake(139, 348, 62, 62));
	animation->setRestoreOriginalFrame(false);
	animation->setDelayPerUnit(1.0 / 5.0);
	animation->setLoops(1);
	Animate* animate = Animate::create(animation);
	renwu->runAction(animate);
}
void bazziyellow::moveright()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazziyellow1.png"),
		CCRectMake(234, 190, 62, 62));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazziyellow1.png"),
		CCRectMake(304, 190, 62, 60));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazziyellow1.png"),
		CCRectMake(376, 190, 62, 62));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazzi1.png"),
		CCRectMake(448, 190, 62, 62));
	animation->setRestoreOriginalFrame(false);
	animation->setDelayPerUnit(1.0 / 5.0);
	animation->setLoops(1);
	Animate* animate = Animate::create(animation);
	renwu->runAction(animate);
}
void bazziyellow::moveleft()
{
	Animation* animation = Animation::create();
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazziyellow2.png"),
		CCRectMake(282, 190, 62, 62));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazziyellow2.png"),
		CCRectMake(211, 190, 62, 60));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazziyellow2.png"),
		CCRectMake(139, 190, 62, 62));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bazziyellow2.png"),
		CCRectMake(70, 190, 62, 62));
	animation->setRestoreOriginalFrame(false);
	animation->setDelayPerUnit(1.0 / 6.0);
	animation->setLoops(1);
	Animate* animate = Animate::create(animation);
	renwu->runAction(animate);
}
