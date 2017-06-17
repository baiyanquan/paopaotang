#include "bombdestroy.h"
USING_NS_CC;

int Bombdestroy::bomb_up(int x, int y, int range)
{
	Vec2 pos = turn_to_tile(x, y);
	for (int i = 0; i <= range; ++i)
	{
		if (pos.y - i < 0)
			return i - 1;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x, pos.y - i))
			|| a_box->getTileGIDAt(Vec2(pos.x, pos.y - i))
			|| a_movebox->getTileGIDAt(Vec2(pos.x, pos.y - i)))
			return i - 1;
	}
	return range;
}
int Bombdestroy::bomb_down(int x, int y, int range)
{
	Vec2 pos = turn_to_tile(x, y);
	for (int i = 0; i <= range; ++i)
	{
		if (pos.y + i > 12)
			return i - 1;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x, pos.y + i))
			|| a_box->getTileGIDAt(Vec2(pos.x, pos.y + i))
			|| a_movebox->getTileGIDAt(Vec2(pos.x, pos.y + i)))
			return i - 1;
	}
	return range;
}
int Bombdestroy::bomb_left(int x, int y, int range)
{
	Vec2 pos = turn_to_tile(x, y);
	for (int i = 0; i <= range; ++i)
	{
		if (pos.x - i <0)
			return i - 1;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x - i, pos.y))
			|| a_box->getTileGIDAt(Vec2(pos.x - i, pos.y))
			|| a_movebox->getTileGIDAt(Vec2(pos.x - i, pos.y)))
			return i - 1;
	}
	return range;
}
int Bombdestroy::bomb_right(int x, int y, int range)
{
	Vec2 pos = turn_to_tile(x, y);
	for (int i = 0; i <= range; ++i)
	{
		if (pos.x + i > 14)
			return i - 1;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x + i, pos.y))
			|| a_box->getTileGIDAt(Vec2(pos.x + i, pos.y))
			|| a_movebox->getTileGIDAt(Vec2(pos.x + i, pos.y)))
			return i - 1;
	}
	return range;
}
void Bombdestroy::shan(int x, int y, int range)
{
	Vec2 pos = turn_to_tile(x, y);
	//ио╥╫у╗╩ы
	for (int i = 0; i <= range; ++i)
	{
		if (pos.y - i < 0)
			break;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x, pos.y - i)))
			break;
		if (a_box->getTileGIDAt(Vec2(pos.x, pos.y - i)))
		{
			Sprite* a_box_shan = a_box->getTileAt(Vec2(pos.x, pos.y - i));
			//иак╦
			blink(a_box_shan);
			if (pos.y - i - 1 >= 0)
			{
				Sprite* b_box_shan = b_box->getTileAt(Vec2(pos.x, pos.y - i - 1));
				//иак╦
				blink(b_box_shan);
			}
			break;
		}
		if (a_movebox->getTileGIDAt(Vec2(pos.x, pos.y - i)))
		{
			Sprite* a_movebox_shan = a_movebox->getTileAt(Vec2(pos.x, pos.y - i));
			//иак╦
			blink(a_movebox_shan);
			if (pos.y - i - 1 >= 0)
			{
				Sprite* b_movebox_shan = b_movebox->getTileAt(Vec2(pos.x, pos.y - i - 1));
				//иак╦
				blink(b_movebox_shan);
			}
			break;
		}
		if (a_grass->getTileGIDAt(Vec2(pos.x, pos.y - i)))
		{
			Sprite* a_grass_shan = a_grass->getTileAt(Vec2(pos.x, pos.y - i));
			//иак╦
			blink(a_grass_shan);
			if (pos.y - i - 1 >= 0)
			{
				Sprite* b_grass_shan = b_grass->getTileAt(Vec2(pos.x, pos.y - i - 1));
				//иак╦
				blink(b_grass_shan);
			}
			if (i != 0)
				break;
		}
	}
	//об╥╫у╗╩ы
	for (int i = 0; i <= range; ++i)
	{
		if (pos.y + i >12)
			break;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x, pos.y + i)))
			break;
		if (a_box->getTileGIDAt(Vec2(pos.x, pos.y + i)))
		{
			Sprite* a_box_shan = a_box->getTileAt(Vec2(pos.x, pos.y + i));
			//иак╦
			blink(a_box_shan);
			if (pos.y + i - 1 >= 0)
			{
				Sprite* b_box_shan = b_box->getTileAt(Vec2(pos.x, pos.y + i - 1));
				//иак╦
				blink(b_box_shan);
			}
			break;
		}
		if (a_movebox->getTileGIDAt(Vec2(pos.x, pos.y + i)))
		{
			Sprite* a_movebox_shan = a_movebox->getTileAt(Vec2(pos.x, pos.y + i));
			//иак╦
			blink(a_movebox_shan);
			if (pos.y + i - 1 >= 0)
			{
				Sprite* b_movebox_shan = b_movebox->getTileAt(Vec2(pos.x, pos.y + i - 1));
				//иак╦
				blink(b_movebox_shan);
			}
			break;
		}
		if (a_grass->getTileGIDAt(Vec2(pos.x, pos.y + i)))
		{
			Sprite* a_grass_shan = a_grass->getTileAt(Vec2(pos.x, pos.y + i));
			//иак╦
			blink(a_grass_shan);
			if (pos.y + i - 1 >= 0)
			{
				Sprite* b_grass_shan = b_grass->getTileAt(Vec2(pos.x, pos.y + i - 1));
				//иак╦
				blink(b_grass_shan);
			}
			if (i != 0)
				break;
		}
	}
	//вС╥╫у╗╩ы
	for (int i = 0; i <= range; ++i)
	{
		if (pos.x - i < 0)
			break;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x - i, pos.y)))
			break;
		if (a_box->getTileGIDAt(Vec2(pos.x - i, pos.y)))
		{
			Sprite* a_box_shan = a_box->getTileAt(Vec2(pos.x - i, pos.y));
			//иак╦
			blink(a_box_shan);
			if (pos.y - 1 >= 0)
			{
				Sprite* b_box_shan = b_box->getTileAt(Vec2(pos.x - i, pos.y - 1));
				//иак╦
				blink(b_box_shan);
			}
			break;
		}
		if (a_movebox->getTileGIDAt(Vec2(pos.x - i, pos.y)))
		{
			Sprite* a_movebox_shan = a_movebox->getTileAt(Vec2(pos.x - i, pos.y));
			//иак╦
			blink(a_movebox_shan);
			if (pos.y - 1 >= 0)
			{
				Sprite* b_movebox_shan = b_movebox->getTileAt(Vec2(pos.x - i, pos.y - 1));
				//иак╦
				blink(b_movebox_shan);
			}
			break;
		}
		if (a_grass->getTileGIDAt(Vec2(pos.x - i, pos.y)))
		{
			Sprite* a_grass_shan = a_grass->getTileAt(Vec2(pos.x - i, pos.y));
			//иак╦
			blink(a_grass_shan);
			if (pos.y - 1 >= 0)
			{
				Sprite* b_grass_shan = b_grass->getTileAt(Vec2(pos.x - i, pos.y - 1));
				//иак╦
				blink(b_grass_shan);
			}
			if (i != 0)
				break;
		}
	}
	//ср╥╫у╗╩ы
	for (int i = 0; i <= range; ++i)
	{
		if (pos.x + i >14)
			break;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x + i, pos.y)))
			break;
		if (a_box->getTileGIDAt(Vec2(pos.x + i, pos.y)))
		{
			Sprite* a_box_shan = a_box->getTileAt(Vec2(pos.x + i, pos.y));
			//иак╦
			blink(a_box_shan);
			if (pos.y - 1 >= 0)
			{
				Sprite* b_box_shan = b_box->getTileAt(Vec2(pos.x + i, pos.y - 1));
				//иак╦
				blink(b_box_shan);
			}
			break;
		}
		if (a_movebox->getTileGIDAt(Vec2(pos.x + i, pos.y)))
		{
			Sprite* a_movebox_shan = a_movebox->getTileAt(Vec2(pos.x + i, pos.y));
			//иак╦
			blink(a_movebox_shan);
			if (pos.y - 1 >= 0)
			{
				Sprite* b_movebox_shan = b_movebox->getTileAt(Vec2(pos.x + i, pos.y - 1));
				//иак╦
				blink(b_movebox_shan);
			}
			break;
		}
		if (a_grass->getTileGIDAt(Vec2(pos.x + i, pos.y)))
		{
			Sprite* a_grass_shan = a_grass->getTileAt(Vec2(pos.x + i, pos.y));
			//иак╦
			blink(a_grass_shan);
			if (pos.y - 1 >= 0)
			{
				Sprite* b_grass_shan = b_grass->getTileAt(Vec2(pos.x + i, pos.y - 1));
				//иак╦
				blink(b_grass_shan);				
			}
			if (i != 0)
				break;
		}
	}
}
void Bombdestroy::bombdestroy(int x, int y, int range)
{
	Vec2 pos = turn_to_tile(x, y);
	//ио╥╫у╗╩ы
	for (int i = 0; i <= range; ++i)
	{
		if (pos.y - i < 0)
			break;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x, pos.y - i)))
			break;
		if (a_box->getTileGIDAt(Vec2(pos.x, pos.y - i)))
		{
			a_box->removeTileAt(Vec2(pos.x, pos.y - i));
			if (pos.y - i - 1 >= 0)
			{
				b_box->removeTileAt(Vec2(pos.x, pos.y - i - 1));
			}
			meta->removeTileAt(Vec2(pos.x, pos.y - i));
			break;
		}
		if (a_movebox->getTileGIDAt(Vec2(pos.x, pos.y - i)))
		{
			a_movebox->removeTileAt(Vec2(pos.x, pos.y - i));
			if (pos.y - i - 1 >= 0)
			{
				b_movebox->removeTileAt(Vec2(pos.x, pos.y - i - 1));
			}
			meta->removeTileAt(Vec2(pos.x, pos.y - i));
			break;
		}
		if (a_grass->getTileGIDAt(Vec2(pos.x, pos.y - i)))
		{
			a_grass->removeTileAt(Vec2(pos.x, pos.y - i));
			if (pos.y - i - 1 >= 0)
			{
				b_grass->removeTileAt(Vec2(pos.x, pos.y - i - 1));
			}
			if (i != 0)
				break;
		}
	}
	//об╥╫у╗╩ы
	for (int i = 0; i <= range; ++i)
	{
		if (pos.y + i >12)
			break;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x, pos.y + i)))
			break;
		if (a_box->getTileGIDAt(Vec2(pos.x, pos.y + i)))
		{
			a_box->removeTileAt(Vec2(pos.x, pos.y + i));
			if (pos.y + i - 1 >= 0)
			{
				b_box->removeTileAt(Vec2(pos.x, pos.y + i - 1));
			}
			meta->removeTileAt(Vec2(pos.x, pos.y + i));
			break;
		}
		if (a_movebox->getTileGIDAt(Vec2(pos.x, pos.y + i)))
		{
			a_movebox->removeTileAt(Vec2(pos.x, pos.y + i));
			if (pos.y + i - 1 >= 0)
			{
				b_movebox->removeTileAt(Vec2(pos.x, pos.y + i - 1));
			}
			meta->removeTileAt(Vec2(pos.x, pos.y + i));
			break;
		}
		if (a_grass->getTileGIDAt(Vec2(pos.x, pos.y + i)))
		{
			a_grass->removeTileAt(Vec2(pos.x, pos.y + i));
			if (pos.y + i - 1 >= 0)
			{
				b_grass->removeTileAt(Vec2(pos.x, pos.y + i - 1));
			}
			if (i != 0)
				break;
		}
	}
	//вС╥╫у╗╩ы
	for (int i = 0; i <= range; ++i)
	{
		if (pos.x - i < 0)
			break;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x - i, pos.y)))
			break;
		if (a_box->getTileGIDAt(Vec2(pos.x - i, pos.y)))
		{
			a_box->removeTileAt(Vec2(pos.x - i, pos.y));
			if (pos.y - 1 >= 0)
			{
				b_box->removeTileAt(Vec2(pos.x - i, pos.y - 1));
			}
			meta->removeTileAt(Vec2(pos.x - i, pos.y));
			break;
		}
		if (a_movebox->getTileGIDAt(Vec2(pos.x - i, pos.y)))
		{
			a_movebox->removeTileAt(Vec2(pos.x - i, pos.y));
			if (pos.y - 1 >= 0)
			{
				b_movebox->removeTileAt(Vec2(pos.x - i, pos.y - 1));
			}
			meta->removeTileAt(Vec2(pos.x - i, pos.y));
			break;
		}
		if (a_grass->getTileGIDAt(Vec2(pos.x - i, pos.y)))
		{
			a_grass->removeTileAt(Vec2(pos.x - i, pos.y));
			if (pos.y - 1 >= 0)
			{
				b_grass->removeTileAt(Vec2(pos.x - i, pos.y - 1));
			}
			if (i != 0)
				break;
		}
	}
	//ср╥╫у╗╩ы
	for (int i = 0; i <= range; ++i)
	{
		if (pos.x + i >14)
			break;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x + i, pos.y)))
			break;
		if (a_box->getTileGIDAt(Vec2(pos.x + i, pos.y)))
		{
			a_box->removeTileAt(Vec2(pos.x + i, pos.y));
			if (pos.y - 1 >= 0)
			{
				b_box->removeTileAt(Vec2(pos.x + i, pos.y - 1));
			}
			meta->removeTileAt(Vec2(pos.x + i, pos.y));
			break;
		}
		if (a_movebox->getTileGIDAt(Vec2(pos.x + i, pos.y)))
		{
			a_movebox->removeTileAt(Vec2(pos.x + i, pos.y));
			if (pos.y - 1 >= 0)
			{
				b_movebox->removeTileAt(Vec2(pos.x + i, pos.y - 1));
			}
			meta->removeTileAt(Vec2(pos.x + i, pos.y));
			break;
		}
		if (a_grass->getTileGIDAt(Vec2(pos.x + i, pos.y)))
		{
			a_grass->removeTileAt(Vec2(pos.x + i, pos.y));
			if (pos.y - 1 >= 0)
			{
				b_grass->removeTileAt(Vec2(pos.x + i, pos.y - 1));
			}
			if (i != 0)
				break;
		}
	}
}
void Bombdestroy::zhahui(int x, int y, int range)
{
	shan(x, y, range);
	auto delayTime = DelayTime::create(3.0 / 5.0);
	no_use->runAction(Sequence::create(delayTime, CCCallFunc::create(CC_CALLBACK_0(Bombdestroy::bombdestroy,this,x,y,range)),NULL));
}
Vec2 Bombdestroy::turn_to_tile(int x, int y)
{
	return Vec2(x / 40, 12 - y / 40);
}
void Bombdestroy::blink(Sprite* sprite)
{
	sprite->runAction(Blink::create(3.0 / 5.0, 10));
}