#include "stdafx.h"
#include "Tile.h"

bool tile::init(POINT _TileXY, TileType _type,bool _isPlayer, bool _isMonster,bool _isNpc, bool _isDest, bool _isRoot, int _BlockPositionX, int _BlockPositionY)
{
	m_Type = _type;

	isPlayer = _isPlayer;
	isMonster = _isMonster;
	isNpc = _isNpc;
	isDest = _isDest;
	isRoot = _isRoot;

	m_BlockPositionX = _BlockPositionX;
	m_BlockPositionY = _BlockPositionY;

	m_absTile.left = _BlockPositionX * WIDTH + OFFSETX;
	m_absTile.right = _BlockPositionX * WIDTH + WIDTH + OFFSETX;
	m_absTile.top = _BlockPositionY * HEIGHT + OFFSETY;
	m_absTile.bottom = _BlockPositionY * HEIGHT + HEIGHT + OFFSETY;

	TileNumber = _TileXY;

	pron_bot_01 = IMAGEMANAGER->findImage("pron_bot_01");
	prt_wall01 = IMAGEMANAGER->findImage("prt_wall01");
	prt_wall02 = IMAGEMANAGER->findImage("prt_wall02");

	return true;
}

bool tile::init(POINT _TileXY, TileType _type, bool _isDest, bool _isRoot, POINT _BlockPosition)
{
	m_Type = _type;

	isDest = _isDest;
	isRoot = _isRoot;

	m_BlockPositionX = _BlockPosition.x;
	m_BlockPositionY = _BlockPosition.y;

	m_absTile.left = m_BlockPositionX * WIDTH + OFFSETX;
	m_absTile.right = m_BlockPositionX * WIDTH + WIDTH + OFFSETX;
	m_absTile.top = m_BlockPositionY * HEIGHT + OFFSETY;
	m_absTile.bottom = m_BlockPositionY * HEIGHT + HEIGHT + OFFSETY;

	TileNumber = _TileXY;

	return true;
}

void tile::release()
{
}

void tile::update(float _deltaTime)
{
	CAMERAMANAGER->rectInCamera(m_outputTile, m_absTile, isCanprint);

}

void tile::render(HDC hdc)
{
	switch (m_Type)
	{
	case TileType::road:
		if (m_BlockPositionX % 4 == 0 && m_BlockPositionY % 4 == 0)
		{
			pron_bot_01->render(hdc, m_outputTile.left, m_outputTile.top);
		}
		break;
	case TileType::wall:
		if ((m_BlockPositionX == 12 && m_BlockPositionY == 0))
		{
			prt_wall02->render(hdc, m_outputTile.left, m_outputTile.top);
		}
		else if(m_BlockPositionX %4 == 0 && m_BlockPositionY % 4 == 0)
		{
			prt_wall01->render(hdc, m_outputTile.left, m_outputTile.top);
		}
		break;
	case TileType::dest:
		UTIL::DrawColorRect(hdc, m_outputTile, RGB(255, 30, 30), false);
		break;
	}
}

void tile::afterRender(HDC hdc)
{

}

void tile::debugRender(HDC hdc)
{
	if (isCanprint == false)
		return;

	if (!isDest)
	{
		if (!isRoot)
		{
			switch (m_Type)
			{
			case TileType::road:
				UTIL::DrawColorRect(hdc, m_outputTile, RGB(100, 255, 255), false);
				break;
			case TileType::wall:
				UTIL::DrawColorRect(hdc, m_outputTile, RGB(124, 139, 200), false);
				break;
			case TileType::dest:
				UTIL::DrawColorRect(hdc, m_outputTile, RGB(255, 30, 30), false);
				break;
			}
		}
		else if (isRoot)
		{
			switch (m_Type)
			{
			case TileType::road:
				UTIL::DrawColorRect(hdc, m_outputTile, RGB(255, 80, 80), false);
				break;
			case TileType::wall:
				UTIL::DrawColorRect(hdc, m_outputTile, RGB(124, 139, 200), false);
				break;
			case TileType::dest:
				UTIL::DrawColorRect(hdc, m_outputTile, RGB(255, 30, 30), false);
				break;
			}
		}
	}
	else if (isDest)
	{
		switch (m_Type)
		{
		case TileType::road:
			UTIL::DrawColorRect(hdc, m_outputTile, RGB(255, 30, 30), false);
			break;
		case TileType::wall:
			UTIL::DrawColorRect(hdc, m_outputTile, RGB(124, 139, 200), false);
			break;
		case TileType::dest:
			UTIL::DrawColorRect(hdc, m_outputTile, RGB(255, 30, 30), false);
			break;
		}
	}

	char str[100];
	sprintf_s(str, "%d %d", TileNumber.x, TileNumber.y);

	UTIL::PrintText(hdc, str, "돋움", m_outputTile.left + 2, m_outputTile.top + 2, 10, RGB(0, 0, 0), true, RGB(0, 0, 0));
}

void tile::setisRoot(bool _isRoot)
{

	isRoot = _isRoot;

}

void tile::setisDest(bool _isDest)
{
	isDest = _isDest;
}

void tile::setisPlayer(bool _isPlayer)
{
	isPlayer = _isPlayer;
}

void tile::setisMonster(bool _isMonster)
{
	isMonster = _isMonster;
}

void tile::setisNpc(bool _isNpc)
{
	isNpc = _isNpc;
}

POINT tile::getTileIndex()
{
	return { m_BlockPositionX, m_BlockPositionY };
}

POINT tile::getTileNumber()
{

	if (UTIL::isPointRectCollision(m_ptMouse, m_outputTile))
	{
		return { m_BlockPositionX, m_BlockPositionY };
	}
	return NOT_POINT_TILE;


}

UTIL::IRECT tile::getoutTile()
{
	return m_outputTile;
}

UTIL::IRECT tile::getabsTile()
{
	return m_absTile;
}
