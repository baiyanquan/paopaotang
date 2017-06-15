#include "bombdestroy.h"
USING_NS_CC;

int Bombdestroy::bomb_up(int x, int y,int range)
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
			||a_box->getTileGIDAt(Vec2(pos.x, pos.y + i))
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
		if (a_undestroy->getTileGIDAt(Vec2(pos.x-i, pos.y ))
			||a_box->getTileGIDAt(Vec2(pos.x - i, pos.y)) 
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
		if (a_undestroy->getTileGIDAt(Vec2(pos.x+i, pos.y))
			|| a_box->getTileGIDAt(Vec2(pos.x+i, pos.y))
			|| a_movebox->getTileGIDAt(Vec2(pos.x+i, pos.y)))
			return i - 1;
	}
	return range;
}
void Bombdestroy::bombdestroy(int x, int y, int range)
{
	Vec2 pos = turn_to_tile(x, y);
	//ÉÏ·½Õ¨»Ù
	for (int i = 0; i <= range; ++i)
	{
		if (pos.y - i < 0)
			break;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x, pos.y - i)))
			break;
		if (a_box->getTileGIDAt(Vec2(pos.x, pos.y - i)))
		{
			meta->removeTileAt(Vec2(pos.x, pos.y - i));
			a_box->removeTileAt(Vec2(pos.x, pos.y - i));
			if (pos.y - i - 1 >= 0)
				b_box->removeTileAt(Vec2(pos.x, pos.y - i - 1));
			break;
		}
		if (a_movebox->getTileGIDAt(Vec2(pos.x, pos.y - i)))
		{
			meta->removeTileAt(Vec2(pos.x, pos.y - i));
			a_movebox->removeTileAt(Vec2(pos.x, pos.y - i));
			if (pos.y - i - 1 >= 0)
				b_movebox->removeTileAt(Vec2(pos.x, pos.y - i - 1));
			break;
		}
		if (a_grass->getTileGIDAt(Vec2(pos.x, pos.y - i)))
		{
			a_grass->removeTileAt(Vec2(pos.x, pos.y - i));
			if (pos.y - i - 1 >= 0)
				b_grass->removeTileAt(Vec2(pos.x, pos.y - i - 1));
			if (i!=0)
				break;
		}
	}
	//ÏÂ·½Õ¨»Ù
	for (int i = 0; i <= range; ++i)
	{
		if (pos.y + i >12)
			break;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x, pos.y + i)))
			break;
		if (a_box->getTileGIDAt(Vec2(pos.x, pos.y + i)))
		{
			meta->removeTileAt(Vec2(pos.x, pos.y + i));
			a_box->removeTileAt(Vec2(pos.x, pos.y + i));
			if (pos.y + i - 1 >= 0)
				b_box->removeTileAt(Vec2(pos.x, pos.y + i - 1));
			break;
		}
		if (a_movebox->getTileGIDAt(Vec2(pos.x, pos.y + i)))
		{
			meta->removeTileAt(Vec2(pos.x, pos.y + i));
			a_movebox->removeTileAt(Vec2(pos.x, pos.y + i));
			if (pos.y + i - 1 >= 0)
				b_movebox->removeTileAt(Vec2(pos.x, pos.y + i - 1));
			break;
		}
		if (a_grass->getTileGIDAt(Vec2(pos.x, pos.y + i)))
		{
			a_grass->removeTileAt(Vec2(pos.x, pos.y + i));
			if (pos.y + i - 1 >= 0)
				b_grass->removeTileAt(Vec2(pos.x, pos.y + i - 1));
			if (i != 0)
				break;
		}
	}
	//×ó·½Õ¨»Ù
	for (int i = 0; i <= range; ++i)
	{
		if (pos.x - i < 0)
			break;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x-i, pos.y)))
			break;
		if (a_box->getTileGIDAt(Vec2(pos.x-i, pos.y)))
		{
			meta->removeTileAt(Vec2(pos.x-i, pos.y));
			a_box->removeTileAt(Vec2(pos.x-i, pos.y));
			if (pos.y - 1 >= 0)
				b_box->removeTileAt(Vec2(pos.x-i, pos.y - 1));
			break;
		}
		if (a_movebox->getTileGIDAt(Vec2(pos.x-i, pos.y)))
		{
			meta->removeTileAt(Vec2(pos.x-i, pos.y));
			a_movebox->removeTileAt(Vec2(pos.x-i, pos.y));
			if (pos.y  - 1 >= 0)
				b_movebox->removeTileAt(Vec2(pos.x-i, pos.y  - 1));
			break;
		}
		if (a_grass->getTileGIDAt(Vec2(pos.x-i, pos.y )))
		{
			a_grass->removeTileAt(Vec2(pos.x-i, pos.y ));
			if (pos.y  - 1 >= 0)
				b_grass->removeTileAt(Vec2(pos.x-i, pos.y  - 1));
			if (i != 0)
				break;
		}
	}
	//ÓÒ·½Õ¨»Ù
	for (int i = 0; i <= range; ++i)
	{
		if (pos.x + i >14)
			break;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x + i, pos.y)))
			break;
		if (a_box->getTileGIDAt(Vec2(pos.x + i, pos.y)))
		{
			meta->removeTileAt(Vec2(pos.x + i, pos.y));
			a_box->removeTileAt(Vec2(pos.x + i, pos.y));
			if (pos.y - 1 >= 0)
				b_box->removeTileAt(Vec2(pos.x + i, pos.y - 1));
			break;
		}
		if (a_movebox->getTileGIDAt(Vec2(pos.x + i, pos.y)))
		{
			meta->removeTileAt(Vec2(pos.x + i, pos.y));
			a_movebox->removeTileAt(Vec2(pos.x + i, pos.y));
			if (pos.y - 1 >= 0)
				b_movebox->removeTileAt(Vec2(pos.x + i, pos.y - 1));
			break;
		}
		if (a_grass->getTileGIDAt(Vec2(pos.x + i, pos.y)))
		{
			a_grass->removeTileAt(Vec2(pos.x + i, pos.y));
			if (pos.y - 1 >= 0)
				b_grass->removeTileAt(Vec2(pos.x + i, pos.y - 1));
			if (i != 0)
				break;
		}
	}
}
Vec2 Bombdestroy::turn_to_tile(int x, int y)
{
	return Vec2(x / 40, 12 - y / 40);
}