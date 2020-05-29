#pragma once
#include "Game/GameScene/IntroScene.h"
#include "Game/GameObject/player.h"
#include "Game/GameObject/monster.h"
#include "Game/GameObject/Npc.h"
#include "Game/Map/Tile.h"

struct damagePiece
{
	bool isWhiteDmg = true;
	Image* damage_white_img = nullptr;
	Image* damage_red_img = nullptr;
	UTIL::IRECT damage_rect_out;
	UTIL::IRECT damage_rect_real;
	int DisplayX = 0;
	int DisplayY = 0;
	float gravity = 0;
};

struct DamageBundle
{
	std::vector<damagePiece> pieces;
	int displayCount;
	int alpha = 255;
	void alphaRender(HDC hdc)
	{
		for (int i = 0; i < pieces.size(); ++i)
		{
			if (pieces[i].isWhiteDmg == true)
				pieces[i].damage_white_img->alphaRender(hdc, pieces[i].damage_rect_out.left, pieces[i].damage_rect_out.top, alpha);
		
			else if(pieces[i].isWhiteDmg == false)
				pieces[i].damage_red_img->alphaRender(hdc, pieces[i].damage_rect_out.left, pieces[i].damage_rect_out.top, alpha);
		}
	}
};



class SampleScene :
	public Scene
{

public:
	SampleScene()
		: player(m_tiles), npc_m(m_tiles)
	{
		
	}
	virtual	~SampleScene() {}


public:
	bool init() override;
	void release() override;

public:
	void update(float _deltaTime) override;
	void render(HDC hdc) override;
	void afterRender(HDC hdc) override;
	void debugRender(HDC hdc) override;
	TileType getTileType(POINT _XY);
	std::vector<tile>& getTiles() { return m_tiles; }

	character player;
	npc npc_m;

	tile tempTile;


private:
	//npc
	int NpcChatNum = 0;

	bool quest = false;
	bool isClearMonster = false;

	int start_alpha = 255;
	Image* black_bg;
	Image* black_bg_quest;

	int poring_die = 0;

	Image* npc_base;
	Image* npc_gugjung;
	Image* npc_smile;

	Image* npc_bg;
	Image* npc_ok;
	Image* npc_next;

	UTIL::IRECT npc_bg_rect;
	UTIL::IRECT npc_ok_rect;
	UTIL::IRECT npc_next_rect;

	//
	bool isStartGame = false;
	float openTime = 0;
	std::vector<tile> m_tiles;

	UTIL::IRECT npc_rect;
	UTIL::IRECT player_rect;

	int camera_tempX = 0;
	int camera_tempY = 0;


	int prevMemoryX;
	int prevMemoryY;
	
	const int nMonster = 2;

	std::vector<DamageBundle> damage_vector;
	std::vector<damagePiece> damage_vector_original;
	std::vector<monster> monster_vector;

	std::vector<DamageBundle> Monster_damage_vector;
	std::vector<damagePiece> Monster_damage_vector_original;

	bool damage_player_to_monster = false;
	bool damage_monster_to_player = false;
	bool isgetitem = false;

	POINT Playertileindex;

	TileType PrevtileType;
	Item_struct getitem;
	
	float curTime;
	Image* getItem_img;
};


