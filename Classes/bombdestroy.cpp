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
	//�Ϸ�ը��
	for (int i = 0; i <= range; ++i)
	{
		if (pos.y - i < 0)
			break;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x, pos.y - i)))
			break;
		if (a_box->getTileGIDAt(Vec2(pos.x, pos.y - i)))
		{
			Sprite* a_box_shan = a_box->getTileAt(Vec2(pos.x, pos.y - i));
			//��˸
			blink(a_box_shan);
			if (pos.y - i - 1 >= 0)
			{
				Sprite* b_box_shan = b_box->getTileAt(Vec2(pos.x, pos.y - i - 1));
				//��˸
				blink(b_box_shan);
			}
			break;
		}
		if (a_movebox->getTileGIDAt(Vec2(pos.x, pos.y - i)))
		{
			Sprite* a_movebox_shan = a_movebox->getTileAt(Vec2(pos.x, pos.y - i));
			//��˸
			blink(a_movebox_shan);
			if (pos.y - i - 1 >= 0)
			{
				Sprite* b_movebox_shan = b_movebox->getTileAt(Vec2(pos.x, pos.y - i - 1));
				//��˸
				blink(b_movebox_shan);
			}
			break;
		}
		if (a_grass->getTileGIDAt(Vec2(pos.x, pos.y - i)))
		{
			Sprite* a_grass_shan = a_grass->getTileAt(Vec2(pos.x, pos.y - i));
			//��˸
			blink(a_grass_shan);
			if (pos.y - i - 1 >= 0)
			{
				Sprite* b_grass_shan = b_grass->getTileAt(Vec2(pos.x, pos.y - i - 1));
				//��˸
				blink(b_grass_shan);
			}
			if (i != 0)
				break;
		}
	}
	//�·�ը��
	for (int i = 0; i <= range; ++i)
	{
		if (pos.y + i >12)
			break;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x, pos.y + i)))
			break;
		if (a_box->getTileGIDAt(Vec2(pos.x, pos.y + i)))
		{
			Sprite* a_box_shan = a_box->getTileAt(Vec2(pos.x, pos.y + i));
			//��˸
			blink(a_box_shan);
			if (pos.y + i - 1 >= 0)
			{
				Sprite* b_box_shan = b_box->getTileAt(Vec2(pos.x, pos.y + i - 1));
				//��˸
				blink(b_box_shan);
			}
			break;
		}
		if (a_movebox->getTileGIDAt(Vec2(pos.x, pos.y + i)))
		{
			Sprite* a_movebox_shan = a_movebox->getTileAt(Vec2(pos.x, pos.y + i));
			//��˸
			blink(a_movebox_shan);
			if (pos.y + i - 1 >= 0)
			{
				Sprite* b_movebox_shan = b_movebox->getTileAt(Vec2(pos.x, pos.y + i - 1));
				//��˸
				blink(b_movebox_shan);
			}
			break;
		}
		if (a_grass->getTileGIDAt(Vec2(pos.x, pos.y + i)))
		{
			Sprite* a_grass_shan = a_grass->getTileAt(Vec2(pos.x, pos.y + i));
			//��˸
			blink(a_grass_shan);
			if (pos.y + i - 1 >= 0)
			{
				Sprite* b_grass_shan = b_grass->getTileAt(Vec2(pos.x, pos.y + i - 1));
				//��˸
				blink(b_grass_shan);
			}
			if (i != 0)
				break;
		}
	}
	//��ը��
	for (int i = 0; i <= range; ++i)
	{
		if (pos.x - i < 0)
			break;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x - i, pos.y)))
			break;
		if (a_box->getTileGIDAt(Vec2(pos.x - i, pos.y)))
		{
			Sprite* a_box_shan = a_box->getTileAt(Vec2(pos.x - i, pos.y));
			//��˸
			blink(a_box_shan);
			if (pos.y - 1 >= 0)
			{
				Sprite* b_box_shan = b_box->getTileAt(Vec2(pos.x - i, pos.y - 1));
				//��˸
				blink(b_box_shan);
			}
			break;
		}
		if (a_movebox->getTileGIDAt(Vec2(pos.x - i, pos.y)))
		{
			Sprite* a_movebox_shan = a_movebox->getTileAt(Vec2(pos.x - i, pos.y));
			//��˸
			blink(a_movebox_shan);
			if (pos.y - 1 >= 0)
			{
				Sprite* b_movebox_shan = b_movebox->getTileAt(Vec2(pos.x - i, pos.y - 1));
				//��˸
				blink(b_movebox_shan);
			}
			break;
		}
		if (a_grass->getTileGIDAt(Vec2(pos.x - i, pos.y)))
		{
			Sprite* a_grass_shan = a_grass->getTileAt(Vec2(pos.x - i, pos.y));
			//��˸
			blink(a_grass_shan);
			if (pos.y - 1 >= 0)
			{
				Sprite* b_grass_shan = b_grass->getTileAt(Vec2(pos.x - i, pos.y - 1));
				//��˸
				blink(b_grass_shan);
			}
			if (i != 0)
				break;
		}
	}
	//�ҷ�ը��
	for (int i = 0; i <= range; ++i)
	{
		if (pos.x + i >14)
			break;
		if (a_undestroy->getTileGIDAt(Vec2(pos.x + i, pos.y)))
			break;
		if (a_box->getTileGIDAt(Vec2(pos.x + i, pos.y)))
		{
			Sprite* a_box_shan = a_box->getTileAt(Vec2(pos.x + i, pos.y));
			//��˸
			blink(a_box_shan);
			if (pos.y - 1 >= 0)
			{
				Sprite* b_box_shan = b_box->getTileAt(Vec2(pos.x + i, pos.y - 1));
				//��˸
				blink(b_box_shan);
			}
			break;
		}
		if (a_movebox->getTileGIDAt(Vec2(pos.x + i, pos.y)))
		{
			Sprite* a_movebox_shan = a_movebox->getTileAt(Vec2(pos.x + i, pos.y));
			//��˸
			blink(a_movebox_shan);
			if (pos.y - 1 >= 0)
			{
				Sprite* b_movebox_shan = b_movebox->getTileAt(Vec2(pos.x + i, pos.y - 1));
				//��˸
				blink(b_movebox_shan);
			}
			break;
		}
		if (a_grass->getTileGIDAt(Vec2(pos.x + i, pos.y)))
		{
			Sprite* a_grass_shan = a_grass->getTileAt(Vec2(pos.x + i, pos.y));
			//��˸
			blink(a_grass_shan);
			if (pos.y - 1 >= 0)
			{
				Sprite* b_grass_shan = b_grass->getTileAt(Vec2(pos.x + i, pos.y - 1));
				//��˸
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
	//����ը��
	//������ͼ
	for (int m = 0; m < 15; ++m)
	{
		for (int n = 0; n < 13; ++n)
		{
			for (int i = -range; i <= range; ++i)
			{
				//����ը��
				if (pos.x == m&&pos.y + i == n)
				{
					if (prop[m][n] == 1)
					{
						shoes[m][n].remove_shoes(map);
						prop[m][n] = 0;
					}
					if (prop[m][n] == 2)
					{
						bubble[m][n].remove_bubble(map);
						prop[m][n] = 0;
					}
					if (prop[m][n] == 3)
					{
						medicine[m][n].remove_medicine(map);
						prop[m][n] = 0;
					}
					if (prop[m][n] == 4)
					{
						tortoise[m][n].remove_tortoise(map);
						prop[m][n] = 0;
					}
				}
				//����ը��
				if (pos.x+i==m&&pos.y==n)
				{
					if (prop[m][n] == 1)
					{
						shoes[m][n].remove_shoes(map);
						prop[m][n] = 0;
					}
					if (prop[m][n] == 2)
					{
						bubble[m][n].remove_bubble(map);
						prop[m][n] = 0;
					}
					if (prop[m][n] == 3)
					{
						medicine[m][n].remove_medicine(map);
						prop[m][n] = 0;
					}
					if (prop[m][n] == 4)
					{
						tortoise[m][n].remove_tortoise(map);
						prop[m][n] = 0;
					}
				}
			}
		}
	}
	//�ϰ���ը��
	//�Ϸ�ը��
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
			medicine[(int)(pos.x)][(int)(pos.y - i)].medicineInit(pos.x * 40, 480 - (pos.y - i) * 40, map);
			prop[(int)(pos.x)][(int)(pos.y - i)] = 3;
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
			shoes[(int)(pos.x)][(int)(pos.y - i)].shoesInit(pos.x * 40, 480 - (pos.y - i) * 40, map);
			prop[(int)(pos.x)][(int)(pos.y - i)] = 1;
			if (i != 0)
				break;
		}
	}
	//�·�ը��
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
			bubble[(int)(pos.x)][(int)(pos.y + i)].bubbleInit(pos.x * 40, 480 - (pos.y + i) * 40, map);
			prop[(int)(pos.x)][(int)(pos.y + i)] = 2;
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
			shoes[(int)(pos.x)][(int)(pos.y + i)].shoesInit(pos.x * 40, 480 - (pos.y + i) * 40, map);
			prop[(int)(pos.x)][(int)(pos.y + i)] = 1;
			if (i != 0)
				break;
		}
	}
	//��ը��
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
			bubble[(int)(pos.x - i)][(int)(pos.y)].bubbleInit((pos.x - i) * 40, 480 - pos.y * 40, map);
			prop[(int)(pos.x - i)][(int)(pos.y)] = 2;
			break;
		}
		if (a_grass->getTileGIDAt(Vec2(pos.x - i, pos.y)))
		{
			a_grass->removeTileAt(Vec2(pos.x - i, pos.y));
			if (pos.y - 1 >= 0)
			{
				b_grass->removeTileAt(Vec2(pos.x - i, pos.y - 1));
			}
			tortoise[(int)(pos.x - i)][(int)(pos.y)].tortoiseInit((pos.x - i) * 40, 480 - pos.y * 40, map);
			prop[(int)(pos.x - i)][(int)(pos.y)] = 4;
			if (i != 0)
				break;
		}
	}
	//�ҷ�ը��
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
			medicine[(int)(pos.x + i)][(int)(pos.y)].medicineInit((pos.x + i) * 40, 480 - pos.y * 40, map);
			prop[(int)(pos.x + i)][(int)(pos.y)] = 3;
			break;
		}
		if (a_grass->getTileGIDAt(Vec2(pos.x + i, pos.y)))
		{
			a_grass->removeTileAt(Vec2(pos.x + i, pos.y));
			if (pos.y - 1 >= 0)
			{
				b_grass->removeTileAt(Vec2(pos.x + i, pos.y - 1));
			}
			tortoise[(int)(pos.x + i)][(int)(pos.y)].tortoiseInit((pos.x + i) * 40, 480 - pos.y * 40, map);
			prop[(int)(pos.x + i)][(int)(pos.y)] = 4;
			if (i != 0)
				break;
		}
	}
}
void Bombdestroy::zhahui(int x, int y, int range)
{
	shan(x, y, range);
	auto zhahui_delayTime = DelayTime::create(3.0 / 5.0);
	no_use->runAction(Sequence::create(zhahui_delayTime, CCCallFunc::create(CC_CALLBACK_0(Bombdestroy::bombdestroy,this,x,y,range)),NULL));
}
Vec2 Bombdestroy::turn_to_tile(int x, int y)
{
	return Vec2(x / 40, 12 - y / 40);
}
void Bombdestroy::blink(Sprite* sprite)
{
	sprite->runAction(Blink::create(3.0 / 5.0, 10));
}