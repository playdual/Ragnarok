#pragma once
#include "Game/GameObject/Object.h"
#include "Game/Map/Tile.h"

class npc

{

public:
	npc() = default;
	npc(std::vector<tile>& tiles)
		:m_Tiles(tiles)
	{
	}

	~npc();
	bool init(int startX, int startY);
	void release();
public:
	void update(float _deltaTime);
	void render(HDC hdc);
	void afterRender(HDC hdc);
	void debugRender(HDC hdc);
	void settilenpc(POINT _XY);

	UTIL::IRECT getnpcRect() { return m_outnpc; }
	UTIL::IRECT getnpcRealRect() { return m_npc; }

	POINT getTileindex();

private:
	std::vector<tile>& m_Tiles; // 타일을 참조하고 있다(by pointer)


public:
	POINT prvPos;
	static int s_AniCount;
	Item_struct	m_have_item_1;
	Item_struct	m_have_item_2;
	bool isShowName = false;
	bool isTargeted = false;
	bool isCanprint = true;
	bool isDest = false;
	bool isMove = false;
	bool isMoveComplete = false;
	bool isnpcDamage = false;
	bool isnpcDamageAni = false;
	bool isnpcAttack = false;
	bool isnpcAttackAni = false;
	bool isnpcBattle = false;
	bool isnpcBattleFind = false;
	bool isErasenpc = false;




	bool isLive = true;
	int m_npc_PosX;
	int m_npc_PosY;

	int npcDieAlpha = 255;
	int npcDieFrameX = 0;
	int dieCount = 0;
	int dieIndex;

	UTIL::IRECT m_npc;
	UTIL::IRECT m_outnpc;

	UTIL::IRECT npc_target;

	Image* m_target;
	Image* m_shadow;

	Image* zondagirl_img;
	Animation* ani_zondagirl;

	std::string m_name;



};



