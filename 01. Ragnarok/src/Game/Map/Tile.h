#pragma once
#include"Game/GameTypes.h"
#include"Common/SystemManagers.h"
enum class TileType
{
	road,
	wall,
	dest,
	outrange
};

class tile
{
public:
	tile() {}
	~tile() {}

	bool init(POINT _TileXY, TileType _type, bool _isPlayer,bool _isMonster,bool _isNpc, bool _isDest,bool _isRoot, int _BlockPositionX, int _BlockPositionY);
	bool init(POINT _TileXY, TileType _type, bool _isDest,bool _isRoot, POINT _BlockPosition);

	void release();

public:
	void update(float _deltaTime);
	void render(HDC hdc);
	void afterRender(HDC hdc);
	void debugRender(HDC hdc);

	void setisRoot(bool _isRoot);
	void setisDest(bool _isDest);
	void setisPlayer(bool _isPlayer);
	void setisMonster(bool _isMonster);
	void setisNpc(bool _isNpc);

	bool getisPlayer() { return isPlayer; }
	bool getisMonster() { return isMonster; }
	bool getisNpc() { return isNpc; }
	POINT getTileIndex();
	POINT getTileNumber();

	UTIL::IRECT getoutTile();
	UTIL::IRECT getabsTile();


	int m_BlockPositionX;
	int m_BlockPositionY;
	bool isPlayer = false;
	bool isMonster = false;
	bool isNpc = false;
	bool isDest = false;
	bool isRoot = false;
	bool isCanprint = false;
	TileType m_Type;

	Image* pron_bot_01;
	Image* prt_wall01;
	Image* prt_wall02;

private:

	UTIL::IRECT m_absTile;
	UTIL::IRECT m_outputTile;

	POINT TileNumber;



};

