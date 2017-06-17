#include "collidable.h"
USING_NS_CC;

//Åö×²¼ì²â
bool Collidable::collidable_up(int x, int y, int speed)
{
	if (y + speed >= 480)
		return true;
	int _x = x / 40;
	int _y = 12 - (y + speed) / 40 - 1;
	int _r = x % 40;
	//»ñÈ¡GID
	int tileGid1 = meta->getTileGIDAt(Vec2(_x, _y));
	//Åö×²¼ì²â
	if (_x == 14)
	{
		if (tileGid1 == 4)
			return true;
		else
			return false;
	}
	else
	{
		int tileGid2 = meta->getTileGIDAt(Vec2(_x + 1, _y));
		if ((tileGid1 == 4 && _r<10) || (tileGid2 == 4 && _r>30) || (tileGid1 == 4 && tileGid2 == 4))
		{
			return true;
		}
	}
	return false;
}
bool Collidable::col_move_up_left(int x, int y, int speed)
{
	int _x = x / 40;
	int _y = 12 - (y + speed) / 40 - 1;
	int _r = x % 40;
	//»ñÈ¡GID
	int tileGid1 = meta->getTileGIDAt(Vec2(_x, _y));
	//Åö×²¼ì²â
	if (_x == 14)
	{
		return false;
	}
	else
	{
		int tileGid2 = meta->getTileGIDAt(Vec2(_x + 1, _y));
		if (tileGid2 == 4 && tileGid1 != 4 && _r <= 30 && _r >= 5)
		{
			return true;
		}
	}
	return false;
}
bool Collidable::col_move_up_right(int x, int y, int speed)
{
	int _x = x / 40;
	int _y = 12 - (y + speed) / 40 - 1;
	int _r = x % 40;
	//»ñÈ¡GID
	int tileGid1 = meta->getTileGIDAt(Vec2(_x, _y));
	//Åö×²¼ì²â
	if (_x == 14)
	{
		return false;
	}
	else
	{
		int tileGid2 = meta->getTileGIDAt(Vec2(_x + 1, _y));
		if (tileGid1 == 4 && tileGid2 != 4 && _r >= 10 && _r <= 35)
		{
			return true;
		}
	}
	return false;
}
bool Collidable::collidable_down(int x, int y, int speed)
{
	if (y - speed <= 0)
		return true;
	int _x = x / 40;
	int _y = 12 - (y - speed) / 40;
	int _r = x % 40;
	//»ñÈ¡GID
	int tileGid1 = meta->getTileGIDAt(Vec2(_x, _y));
	//Åö×²¼ì²â
	if (_x == 14)
	{
		if (tileGid1 == 4)
			return true;
		else
			return false;
	}
	else
	{
		int tileGid2 = meta->getTileGIDAt(Vec2(_x + 1, _y));
		if ((tileGid1 == 4 && _r<10) || (tileGid2 == 4 && _r>30) || (tileGid1 == 4 && tileGid2 == 4))
		{
			return true;
		}
	}
	return false;
}
bool Collidable::col_move_down_left(int x, int y, int speed)
{
	int _x = x / 40;
	int _y = 12 - (y - speed) / 40;
	int _r = x % 40;
	//»ñÈ¡GID
	int tileGid1 = meta->getTileGIDAt(Vec2(_x, _y));
	//Åö×²¼ì²â
	if (_x == 14)
	{
		return false;
	}
	else
	{
		int tileGid2 = meta->getTileGIDAt(Vec2(_x + 1, _y));
		if (tileGid2 == 4 && tileGid1 != 4 && _r <= 30 && _r >= 5)
		{
			return true;
		}
	}
	return false;
}
bool Collidable::col_move_down_right(int x, int y, int speed)
{
	int _x = x / 40;
	int _y = 12 - (y - speed) / 40;
	int _r = x % 40;
	//»ñÈ¡GID
	int tileGid1 = meta->getTileGIDAt(Vec2(_x, _y));
	//Åö×²¼ì²â
	if (_x == 14)
	{
		return false;
	}
	else
	{
		int tileGid2 = meta->getTileGIDAt(Vec2(_x + 1, _y));
		if (tileGid1 == 4 && tileGid2 != 4 && _r >= 10 && _r <= 35)
		{
			return true;
		}
	}
	return false;
}
bool Collidable::collidable_left(int x, int y, int speed)
{
	if (x - speed <= 0)
		return true;
	int _x = (x - speed) / 40;
	int _y = 12 - y / 40;
	int _r = y % 40;
	//»ñÈ¡GID
	int tileGid1 = meta->getTileGIDAt(Vec2(_x, _y));
	//Åö×²¼ì²â
	if (_y == 0)
	{
		if (tileGid1 == 4)
			return true;
		else
			return false;
	}
	else
	{
		int tileGid2 = meta->getTileGIDAt(Vec2(_x, _y - 1));
		if ((tileGid1 == 4 && _r<10) || (tileGid2 == 4 && _r>30) || (tileGid1 == 4 && tileGid2 == 4))
		{
			return true;
		}
	}
	return false;
}
bool Collidable::col_move_left_up(int x, int y, int speed)
{
	int _x = (x - speed) / 40;
	int _y = 12 - y / 40;
	int _r = y % 40;
	//»ñÈ¡GID
	int tileGid1 = meta->getTileGIDAt(Vec2(_x, _y));
	//Åö×²¼ì²â
	if (_y == 0)
	{
		return false;
	}
	else
	{
		int tileGid2 = meta->getTileGIDAt(Vec2(_x, _y - 1));
		if (tileGid1 == 4 && tileGid2 != 4 && _r >= 10 && _r <= 35)
		{
			return true;
		}
	}
	return false;
}
bool Collidable::col_move_left_down(int x, int y, int speed)
{
	int _x = (x - speed) / 40;
	int _y = 12 - y / 40;
	int _r = y % 40;
	//»ñÈ¡GID
	int tileGid1 = meta->getTileGIDAt(Vec2(_x, _y));
	//Åö×²¼ì²â
	if (_y == 0)
	{
		return false;
	}
	else
	{
		int tileGid2 = meta->getTileGIDAt(Vec2(_x, _y - 1));
		if (tileGid2 == 4 && tileGid1 != 4 && _r <= 30 && _r >= 5)
		{
			return true;
		}
	}
	return false;
}
bool Collidable::collidable_right(int x, int y, int speed)
{
	if (x + speed >= 560)
		return true;
	int _x = (x + speed) / 40 + 1;
	int _y = 12 - y / 40;
	int _r = y % 40;
	//»ñÈ¡GID
	int tileGid1 = meta->getTileGIDAt(Vec2(_x, _y));
	//Åö×²¼ì²â
	if (_y == 0)
	{
		if (tileGid1 == 4)
			return true;
		else
			return false;
	}
	else
	{
		int tileGid2 = meta->getTileGIDAt(Vec2(_x, _y - 1));
		if ((tileGid1 == 4 && _r<10) || (tileGid2 == 4 && _r>30) || (tileGid1 == 4 && tileGid2 == 4))
		{
			return true;
		}
	}
	return false;
}
bool Collidable::col_move_right_up(int x, int y, int speed)
{
	int _x = (x + speed) / 40 + 1;
	int _y = 12 - y / 40;
	int _r = y % 40;
	//»ñÈ¡GID
	int tileGid1 = meta->getTileGIDAt(Vec2(_x, _y));
	//Åö×²¼ì²â
	if (_y == 0)
	{
		return false;
	}
	else
	{
		int tileGid2 = meta->getTileGIDAt(Vec2(_x, _y - 1));
		if (tileGid1 == 4 && tileGid2 != 4 && _r >= 10 && _r <= 35)
		{
			return true;
		}
	}
	return false;
}
bool Collidable::col_move_right_down(int x, int y, int speed)
{
	int _x = (x + speed) / 40 + 1;
	int _y = 12 - y / 40;
	int _r = y % 40;
	//»ñÈ¡GID
	int tileGid1 = meta->getTileGIDAt(Vec2(_x, _y));
	//Åö×²¼ì²â
	if (_y == 0)
	{
		return false;
	}
	else
	{
		int tileGid2 = meta->getTileGIDAt(Vec2(_x, _y - 1));
		if (tileGid2 == 4 && tileGid1 != 4 && _r <= 30 && _r >= 5)
		{
			return true;
		}
	}
	return false;
}