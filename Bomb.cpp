#include "Bomb.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
Sprite* Bomb::creat_bomb(int quality)
{
	sprites_up.clear();
	sprites_down.clear();
	sprites_left.clear();
	sprites_right.clear();
	Sprite* bomb = Sprite::create("bomb.png", Rect(24, 40, 48, 48));
	for (int i = 1; i <= quality; ++i)
	{
		if(i!=quality)
			sprites_up.push_back(Sprite::create("bomb.png", Rect(28, 344, 40, 40)));
		else
			sprites_up.push_back(Sprite::create("bomb.png", Rect(28, 185, 40, 40)));
	}
	for (int i = 1; i <= quality; ++i)
	{
		if (i != quality)
			sprites_down.push_back(Sprite::create("bomb.png", Rect(28, 419, 40, 40)));
		else
			sprites_down.push_back(Sprite::create("bomb.png", Rect(28, 260, 40, 40)));
	} 
	for (int i = 1; i <= quality; ++i)
	{
		if (i != quality)
			sprites_left.push_back(Sprite::create("bomb.png", Rect(271, 419, 40, 40)));
		else
			sprites_left.push_back(Sprite::create("bomb.png", Rect(272, 260, 40, 40)));
	}
	for (int i = 1; i <= quality; ++i)
	{
		if (i != quality)
			sprites_right.push_back(Sprite::create("bomb.png", Rect(271, 345, 40, 40)));
		else
			sprites_right.push_back(Sprite::create("bomb.png", Rect(276, 185, 40, 40)));
	}
	return bomb;
}
void Bomb::explode(Sprite* object , int quality)
{
	Animation* animation = Animation::create();
	auto delayTime = DelayTime::create(2.0f);
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bomb.png"),
		CCRectMake(28, 114, 40, 40));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bomb.png"),
		CCRectMake(85, 114, 40, 40));
	animation->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bomb.png"),
		CCRectMake(143, 115, 40, 40));
	animation->setRestoreOriginalFrame(false);
	animation->setDelayPerUnit(1.0 / 5.0);
	animation->setLoops(1);
	Animate* animate = Animate::create(animation);
	Animation* animation_up = Animation::create();
	Animation* animation_down = Animation::create();
	Animation* animation_left= Animation::create();
	Animation* animation_right = Animation::create();
	animation_up->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bomb.png"),
		CCRectMake(28, 185, 40, 40));
	animation_up->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bomb.png"),
		CCRectMake(86, 184, 40, 40));
	animation_up->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bomb.png"),
		CCRectMake(145, 184, 40, 40));
	animation_up->setRestoreOriginalFrame(false);
	animation_up->setDelayPerUnit(1.0 / 5.0);
	animation_up->setLoops(1);
	animation_down->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bomb.png"),
		CCRectMake(28, 260, 40, 40));
	animation_down->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bomb.png"),
		CCRectMake(86, 260, 40, 40));
	animation_down->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bomb.png"),
		CCRectMake(145, 260, 40, 40));
	animation_down->setRestoreOriginalFrame(false);
	animation_down->setDelayPerUnit(1.0 / 5.0);
	animation_down->setLoops(1);
	animation_left->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bomb.png"),
		CCRectMake(272, 260, 40, 40));
	animation_left->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bomb.png"),
		CCRectMake(333, 260, 40, 40));
	animation_left->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bomb.png"),
		CCRectMake(389, 260, 40, 40));
	animation_left->setRestoreOriginalFrame(false);
	animation_left->setDelayPerUnit(1.0 / 5.0);
	animation_left->setLoops(1);
	animation_right->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bomb.png"),
		CCRectMake(276, 185, 40, 40));
	animation_right->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bomb.png"),
		CCRectMake(334, 185, 40, 40));
	animation_right->addSpriteFrameWithTexture(TextureCache::sharedTextureCache()->addImage("bomb.png"),
		CCRectMake(393, 185, 40, 40));
	animation_right->setRestoreOriginalFrame(false);
	animation_right->setDelayPerUnit(1.0 / 5.0);
	animation_right->setLoops(1);
	Animate* animate_up = Animate::create(animation_up);
	Animate* animate_down = Animate::create(animation_down);
	Animate* animate_left = Animate::create(animation_left);
	Animate* animate_right = Animate::create(animation_right);
	object->runAction(Sequence::create(delayTime, animate, CallFunc::create(CC_CALLBACK_0(Bomb::add_my_bomb_quantity, this)), CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, object)), NULL));
	for (int i = 1; i <= quality; ++i)
	{
		if (i != quality)
			sprites_up[i - 1]->runAction(Sequence::create(delayTime, Show::create(), Blink::create(3.0 / 5.0, 10), CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, sprites_up[i - 1])), NULL));
		else
			sprites_up[i - 1]->runAction(Sequence::create(delayTime, Show::create(), animate_up, CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, sprites_up[i - 1])), NULL));
	}
	for (int i = 1; i <= quality; ++i)
	{
		if (i != quality)
			sprites_down[i - 1]->runAction(Sequence::create(delayTime, Show::create(), Blink::create(3.0 / 5.0, 10), CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, sprites_down[i - 1])), NULL));
		else
			sprites_down[i - 1]->runAction(Sequence::create(delayTime, Show::create(), animate_down, CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, sprites_down[i - 1])), NULL));
	}
	for (int i = 1; i <= quality; ++i)
	{
		if (i != quality)
			sprites_left[i - 1]->runAction(Sequence::create(delayTime, Show::create(), Blink::create(3.0 / 5.0, 10), CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, sprites_left[i - 1])), NULL));
		else
			sprites_left[i - 1]->runAction(Sequence::create(delayTime, Show::create(), animate_left, CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, sprites_left[i - 1])), NULL));
	}
	for (int i = 1; i <= quality; ++i)
	{
		if (i != quality)
			sprites_right[i - 1]->runAction(Sequence::create(delayTime, Show::create(), Blink::create(3.0 / 5.0, 10), CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, sprites_right[i - 1])), NULL));
		else
			sprites_right[i - 1]->runAction(Sequence::create(delayTime, Show::create(), animate_right, CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, sprites_right[i - 1])), NULL));
	}
}
void Bomb::add_my_bomb_quantity()
{
	++my_bomb_quantity;
}