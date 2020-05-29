#include "stdafx.h"
#include "player.h"

/////////////////////////////////////////////////////////
///// Character /////////////////////////////////////////
/////////////////////////////////////////////////////////
bool character::init(int startX, int startY)
{
	uiSetting();

	job = "Novice";

	player_name = SKILL->player_name;
	SKILL->user_Skill(job);

	stat_str = SKILL->intro_str;
	stat_agi = SKILL->intro_agi;
	stat_vit = SKILL->intro_vit;
	stat_int = SKILL->intro_int;
	stat_dex = SKILL->intro_dex;
	stat_luk = SKILL->intro_luk;
	stat_point = SKILL->intro_point;

	m_playerPosX = startX;
	m_playerPosY = startY;
	m_player = UTIL::IRectMake(startX * WIDTH + OFFSETX, startY * HEIGHT + OFFSETY, WIDTH, HEIGHT);

	m_outPlayer;// = UTIL::IRectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, WIDTH, HEIGHT);

	chat_rect = UTIL::IRectMake(0, WINSIZEY - 100, 467, 100);

	//CAMERAMANAGER->setCameraFocus(&m_player.centerX, &m_player.centerY, WINSIZEX / 2, WINSIZEY / 2);
	CAMERAMANAGER->update();

	dest_tile = IMAGEMANAGER->findImage("dest_tile");


	playerImgSetting();
	return true;
}

void character::release()
{
}

void character::update(float _deltaTime)
{
	itemsettiong();

	if (isStartGame == false)
	{

		CAMERAMANAGER->rectInCamera(m_outPlayer, m_player, isCanprint);
	}
	else if (isStartGame == true)
	{
		m_outPlayer = UTIL::IRectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, WIDTH, HEIGHT);
		//CAMERAMANAGER->setCameraFocus(&m_player.centerX, &m_player.centerY, WINSIZEX / 2, WINSIZEY / 2);
	}


	//마우스 포인터의 현재 타일인덱스
	DestcurTileIndex = NOT_POINT_TILE;
	for (auto& tile : m_Tiles)
	{
		tile.update(_deltaTime);

		if (DestcurTileIndex == NOT_POINT_TILE)
			DestcurTileIndex = tile.getTileNumber();
	}

	if (ismemoryMoveIndex)memoryDestCurTileindex = DestcurTileIndex;



	//chat
	if (is_chat == false && KEYMANAGER->isOnceKeyDown(GAME_ENTER))
	{
		is_chat = true;
	}
	if (is_chat == true && KEYMANAGER->isOnceKeyDown(GAME_ENTER))
	{

		if (chat_input.size() != 0)
		{
			if (chat_2.size() != 0)
			{
				chat_3.clear();
				chat_3 = chat_2;
			}
			if (chat_1.size() != 0)
			{
				chat_2.clear();
				chat_2 = chat_1;
			}

			chat_1.clear();
			for (auto chat_itr = chat_input.begin(); chat_itr != chat_input.end(); chat_itr++)
			{
				chat_1 += chat_itr->c_str();
			}
			chat_input.clear();

		}
		chatcnt = 0;
		is_chat = false;
	}

	chatcnt++;


	if (is_chat == true)
	{

		curtime += 0.1f;

		if (curtime < 0.8)
		{
			underbar = "";
		}
		else if (curtime > 0.8 && curtime < 1.6)
		{
			underbar = "_";
		}
		else if (curtime > 1.6)
		{
			curtime = 0;
		}

		if (KEYMANAGER->isOnceKeyDown(GAME_SPACE))
		{
			chat_input.push_back(" ");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_A))
		{
			chat_input.push_back("A");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_B))
		{
			chat_input.push_back("B");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_C))
		{
			chat_input.push_back("C");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_D))
		{
			chat_input.push_back("D");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_E))
		{
			chat_input.push_back("E");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_F))
		{
			chat_input.push_back("F");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_G))
		{
			chat_input.push_back("G");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_H))
		{
			chat_input.push_back("H");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_I))
		{
			chat_input.push_back("I");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_J))
		{
			chat_input.push_back("J");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_K))
		{
			chat_input.push_back("K");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_L))
		{
			chat_input.push_back("L");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_M))
		{
			chat_input.push_back("M");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_N))
		{
			chat_input.push_back("N");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_O))
		{
			chat_input.push_back("O");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_P))
		{
			chat_input.push_back("P");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_Q))
		{
			chat_input.push_back("Q");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_R))
		{
			chat_input.push_back("R");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_S))
		{
			chat_input.push_back("S");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_T))
		{
			chat_input.push_back("T");
		}if (KEYMANAGER->isOnceKeyDown(GAME_U))
		{
			chat_input.push_back("U");
		}if (KEYMANAGER->isOnceKeyDown(GAME_V))
		{
			chat_input.push_back("V");
		}if (KEYMANAGER->isOnceKeyDown(GAME_W))
		{
			chat_input.push_back("W");
		}if (KEYMANAGER->isOnceKeyDown(GAME_X))
		{
			chat_input.push_back("X");
		}if (KEYMANAGER->isOnceKeyDown(GAME_Y))
		{
			chat_input.push_back("Y");
		}if (KEYMANAGER->isOnceKeyDown(GAME_Z))
		{
			chat_input.push_back("Z");
		}
		if (KEYMANAGER->isOnceKeyDown(GAME_BACK))
		{
			if (chat_input.size() > 0)chat_input.pop_back();

		}
	}




	//cheat_1
	if (KEYMANAGER->isOnceKeyDown(P1_RIGHT))
	{
		stat_base_curExp += 10;
		stat_job_curExp += 7;
	}
	if (KEYMANAGER->isOnceKeyDown(P1_LEFT))
	{
		stat_Curhp -= 10;
	}

	//cheat_2
	if (chat_1 == "HELP ME" && cheat_temp == 0)
	{
		ischeat = true;
		stat_base_level = 99;
		stat_str = 99;
		stat_vit = 30;
		stat_agi = 99;
		stat_int = 30;
		stat_Curhp = 99999;
		stat_Cursp = 99999;

		cheat_temp = 1;
	}
	if (chat_1 == "INCLUDE SUNWOO" && cheat ==1)
	{
		ischeat = true;
		cheat = 2;
	}


	if (ischeat == true)
	{
		cheatcnt++;
		if (cheatcnt > 300)
		{
			ischeat = false;
			cheatcnt = 0;
		}
	}


	//ui
	if (isStat || isSkill || isItem || isDie)
	{
		if (UTIL::isPointRectCollision(m_ptMouse, stat_ui_rect) || UTIL::isPointRectCollision(m_ptMouse, item_ui_rect)
			|| UTIL::isPointRectCollision(m_ptMouse, skill_ui_rect) || UTIL::isPointRectCollision(m_ptMouse, quickslot_ui_rect) || UTIL::isPointRectCollision(m_ptMouse, quickslot_1_ui_rect)
			|| UTIL::isPointRectCollision(m_ptMouse, quickslot_2_ui_rect) || UTIL::isPointRectCollision(m_ptMouse, die_ui_rect))
		{
			isUi = true;
			isbase = true;
		}
		else if (!(UTIL::isPointRectCollision(m_ptMouse, stat_ui_rect) && UTIL::isPointRectCollision(m_ptMouse, item_ui_rect)
			&& UTIL::isPointRectCollision(m_ptMouse, skill_ui_rect) && UTIL::isPointRectCollision(m_ptMouse, quickslot_ui_rect) && UTIL::isPointRectCollision(m_ptMouse, quickslot_1_ui_rect)
			&& UTIL::isPointRectCollision(m_ptMouse, quickslot_2_ui_rect) && UTIL::isPointRectCollision(m_ptMouse, die_ui_rect)))
		{
			isUi = false;
			isbase = false;
		}
	}


	if (UTIL::isPointRectCollision(m_ptMouse, base_ui_rect) || UTIL::isPointRectCollision(m_ptMouse, quickslot_ui_rect)
		|| UTIL::isPointRectCollision(m_ptMouse, quickslot_1_ui_rect) || UTIL::isPointRectCollision(m_ptMouse, quickslot_2_ui_rect))
	{
		isbase = true;
	}
	else if (isItem && UTIL::isPointRectCollision(m_ptMouse, item_ui_rect))
	{
		isbase = true;
	}
	else if (isDie && UTIL::isPointRectCollision(m_ptMouse, die_ui_rect))
	{
		isbase = true;
	}
	else
	{
		isbase = false;
	}

	statSetting();

	Hp_Sp_mini_bar_setting();


	if (!isDie)
	{
		moveSetting(_deltaTime);
		battleSetting();
	}



	playerAnihandle();
	CAMERAMANAGER->update();

}

void character::render(HDC hdc)
{
	for (auto& tile : m_Tiles)
	{
		if (tile.getTileIndex() == DestcurTileIndex)
		{
			TileType tileType = getTileType(DestcurTileIndex);
			if (tileType != TileType::wall)
				dest_tile->alphaRender(hdc, tile.getoutTile().left, tile.getoutTile().top, 150);
		}
	}

	player_shadow->alphaRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.bottom - 24 + PLAYER_IMAGE_OFFSETY, 70);

	if (isLevelup)
	{
		wing_img->aniRender(hdc, m_outPlayer.left - 124 + 30 -7 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 120 + PLAYER_IMAGE_OFFSETY, ani_wing);
		wing_wing_img->aniRender(hdc, m_outPlayer.left - 124 + 30 -5 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 120 + PLAYER_IMAGE_OFFSETY, ani_wing_wing);
	}

	if (is_player_arrow_1)
	{
		player_body_base->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_arrow_1);
		player_head_base->aniRender(hdc, m_outPlayer.left + 4 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 18 + PLAYER_IMAGE_OFFSETY, ani_player_head_arrow_1);
	}
	else if (is_player_arrow_3)
	{
		player_body_base->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_arrow_3);
		player_head_base->aniRender(hdc, m_outPlayer.left + 6 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 18 + PLAYER_IMAGE_OFFSETY, ani_player_head_arrow_3);
	}
	else if (is_player_arrow_5)
	{
		player_body_base->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_arrow_5);
		player_head_base->aniRender(hdc, m_outPlayer.left + 6 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 18 + PLAYER_IMAGE_OFFSETY, ani_player_head_arrow_5);
	}
	else if (is_player_arrow_6)
	{
		player_body_base->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_arrow_6);
		player_head_base->aniRender(hdc, m_outPlayer.left + 6 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 17 + PLAYER_IMAGE_OFFSETY, ani_player_head_arrow_6);
	}
	else if (is_player_arrow_7)
	{
		player_body_base->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_arrow_7);
		player_head_base->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 18 + PLAYER_IMAGE_OFFSETY, ani_player_head_arrow_7);
	}
	else if (is_player_arrow_9)
	{
		player_body_base->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_arrow_9);
		player_head_base->aniRender(hdc, m_outPlayer.left + 6 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 18 + PLAYER_IMAGE_OFFSETY, ani_player_head_arrow_9);
	}
	else if (is_player_arrow_10)
	{
		player_body_base->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_arrow_10);
		player_head_base->aniRender(hdc, m_outPlayer.left + 9 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 18 + PLAYER_IMAGE_OFFSETY, ani_player_head_arrow_10);
	}
	else if (is_player_arrow_12)
	{
		player_body_base->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_arrow_12);
		player_head_base->aniRender(hdc, m_outPlayer.left + 3 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 18 + PLAYER_IMAGE_OFFSETY, ani_player_head_arrow_12);
	}
	else if (is_player_move_1)
	{
		player_move_1->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_move_1);
		player_head_move_1->aniRender(hdc, m_outPlayer.left + 8 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 19 + PLAYER_IMAGE_OFFSETY, ani_player_head_move_1);
	}
	else if (is_player_move_3)
	{
		player_move_3->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_move_3);
		player_head_move_3->aniRender(hdc, m_outPlayer.left + 9 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 22 + PLAYER_IMAGE_OFFSETY, ani_player_head_move_3);
	}
	else if (is_player_move_5)
	{
		player_move_5->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_move_5);
		player_head_move_5->aniRender(hdc, m_outPlayer.left + 8 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 21 + PLAYER_IMAGE_OFFSETY, ani_player_head_move_5);
	}
	else if (is_player_move_6)
	{
		player_move_6->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_move_6);
		player_head_move_6->aniRender(hdc, m_outPlayer.left + 4 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 19 + PLAYER_IMAGE_OFFSETY, ani_player_head_move_6);
	}
	else if (is_player_move_7)
	{
		player_move_7->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_move_7);
		player_head_move_7->aniRender(hdc, m_outPlayer.left + 7 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 20 + PLAYER_IMAGE_OFFSETY, ani_player_head_move_7);
	}
	else if (is_player_move_9)
	{
		player_move_9->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_move_9);
		player_head_move_9->aniRender(hdc, m_outPlayer.left + 12 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 21 + PLAYER_IMAGE_OFFSETY, ani_player_head_move_9);
	}
	else if (is_player_move_10)
	{
		player_move_10->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_move_10);
		player_head_move_10->aniRender(hdc, m_outPlayer.left + 9 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 20 + PLAYER_IMAGE_OFFSETY, ani_player_head_move_10);
	}
	else if (is_player_move_12)
	{
		player_move_12->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_move_12);
		player_head_move_12->aniRender(hdc, m_outPlayer.left + 3 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 21 + PLAYER_IMAGE_OFFSETY, ani_player_head_move_12);
	}
	else if (is_player_attackwait_1)
	{
		player_attackwait_1->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_attackwait_1);
		player_head_attackwait_1->aniRender(hdc, m_outPlayer.left + 3 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 10 + PLAYER_IMAGE_OFFSETY, ani_player_head_attackwait_1);
		weapon_wait_1->aniRender(hdc, m_outPlayer.left + 12 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + 32 + PLAYER_IMAGE_OFFSETY, ani_weapon_wait_1);
	}
	else if (is_player_attackwait_5)
	{
		player_head_attackwait_5->aniRender(hdc, m_outPlayer.left + 15 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 13 + PLAYER_IMAGE_OFFSETY, ani_player_head_attackwait_5);
		weapon_wait_5->aniRender(hdc, m_outPlayer.left - 5 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + 28 + PLAYER_IMAGE_OFFSETY, ani_weapon_wait_5);
		player_attackwait_5->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_attackwait_5);
	}
	else if (is_player_attackwait_7)
	{
		player_head_attackwait_7->aniRender(hdc, m_outPlayer.left + 8 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 12 + PLAYER_IMAGE_OFFSETY, ani_player_head_attackwait_7);
		weapon_wait_7->aniRender(hdc, m_outPlayer.left + 30 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + 30 + PLAYER_IMAGE_OFFSETY, ani_weapon_wait_7);
		player_attackwait_7->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_attackwait_7);
	}
	else if (is_player_attackwait_10)
	{
		player_attackwait_10->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_attackwait_10);
		player_head_attackwait_10->aniRender(hdc, m_outPlayer.left + 8 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 10 + PLAYER_IMAGE_OFFSETY, ani_player_head_attackwait_10);
		weapon_wait_10->aniRender(hdc, m_outPlayer.left - 2 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + 32 + PLAYER_IMAGE_OFFSETY, ani_weapon_wait_10);
	}
	else if (is_player_attack_1)
	{
		player_attack_1->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + PLAYER_IMAGE_OFFSETY, ani_player_attack_1);
		player_head_attack_1->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 13 + PLAYER_IMAGE_OFFSETY, ani_player_head_attack_1);
		weapon_attack_1->aniRender(hdc, m_outPlayer.left + 12 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + 13 + PLAYER_IMAGE_OFFSETY, ani_weapon_attack_1);

	}
	else if (is_player_attack_5)
	{
		player_head_attack_5->aniRender(hdc, m_outPlayer.left + 13 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 7 + PLAYER_IMAGE_OFFSETY, ani_player_head_attack_5);
		weapon_attack_5->aniRender(hdc, m_outPlayer.left - 8 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + 32 + PLAYER_IMAGE_OFFSETY, ani_weapon_attack_5);
		player_attack_5->aniRender(hdc, m_outPlayer.left - 3 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + 10 + PLAYER_IMAGE_OFFSETY, ani_player_attack_5);

	}
	else if (is_player_attack_7)
	{
		player_head_attack_7->aniRender(hdc, m_outPlayer.left - 17 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 7 + PLAYER_IMAGE_OFFSETY, ani_player_head_attack_7);
		weapon_attack_7->aniRender(hdc, m_outPlayer.left - 26 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + 30 + PLAYER_IMAGE_OFFSETY, ani_weapon_attack_7);
		player_attack_7->aniRender(hdc, m_outPlayer.left - 3 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + 8 + PLAYER_IMAGE_OFFSETY, ani_player_attack_7);

	}
	else if (is_player_attack_10)
	{
		player_attack_10->aniRender(hdc, m_outPlayer.left - 10 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + 3 + PLAYER_IMAGE_OFFSETY, ani_player_attack_10);
		player_head_attack_10->aniRender(hdc, m_outPlayer.left - 13 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 7 + PLAYER_IMAGE_OFFSETY, ani_player_head_attack_10);
		weapon_attack_10->aniRender(hdc, m_outPlayer.left - 29 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + 16 + PLAYER_IMAGE_OFFSETY, ani_weapon_attack_10);

	}
	else if (is_player_damaged_1)
	{

		player_damaged_1->aniRender(hdc, m_outPlayer.left - 5 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + 6 + PLAYER_IMAGE_OFFSETY, ani_player_damaged_1);
		player_head_damaged_1->aniRender(hdc, m_outPlayer.left + 5 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 15 + PLAYER_IMAGE_OFFSETY, ani_player_head_damaged_1);

	}
	else if (is_player_damaged_5)
	{
		player_damaged_5->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + 3 + PLAYER_IMAGE_OFFSETY, ani_player_damaged_5);
		player_head_damaged_5->aniRender(hdc, m_outPlayer.left + 5 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 17 + PLAYER_IMAGE_OFFSETY, ani_player_head_damaged_5);

	}
	else if (is_player_damaged_7)
	{
		player_damaged_7->aniRender(hdc, m_outPlayer.left + 5 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + 3 + PLAYER_IMAGE_OFFSETY, ani_player_damaged_7);
		player_head_damaged_7->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 18 + PLAYER_IMAGE_OFFSETY, ani_player_head_damaged_7);
	}
	else if (is_player_damaged_10)
	{
		player_damaged_10->aniRender(hdc, m_outPlayer.left - 10 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + 3 + PLAYER_IMAGE_OFFSETY, ani_player_damaged_10);
		player_head_damaged_10->aniRender(hdc, m_outPlayer.left + PLAYER_IMAGE_OFFSETX, m_outPlayer.top - 20 + PLAYER_IMAGE_OFFSETY, ani_player_head_damaged_10);
	}
	else if (isDie)
	{
		player_die->render(hdc, m_outPlayer.left - 10 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + 20 + PLAYER_IMAGE_OFFSETY);
		player_head_die->render(hdc, m_outPlayer.left + 20 + PLAYER_IMAGE_OFFSETX, m_outPlayer.top + 12 + PLAYER_IMAGE_OFFSETY);
	}


}

void character::afterRender(HDC hdc)
{
	base_ui_img->render(hdc, base_ui_rect.left, base_ui_rect.top);
	ui_minicircle_off_img->render(hdc, base_ui_rect.left + 3, base_ui_rect.top + 2);
	if (!isStat_btn)stat_ui_btn_off_img->render(hdc, stat_ui_btn_rect.left, stat_ui_btn_rect.top);
	else stat_ui_btn_on_img->render(hdc, stat_ui_btn_rect.left, stat_ui_btn_rect.top);
	if (!isSkill_btn)skill_ui_btn_off_img->render(hdc, skill_ui_btn_rect.left, skill_ui_btn_rect.top);
	else skill_ui_btn_on_img->render(hdc, skill_ui_btn_rect.left, skill_ui_btn_rect.top);

	if (!isItem_btn)item_ui_btn_off_img->render(hdc, item_ui_btn_rect.left, item_ui_btn_rect.top);
	else item_ui_btn_on_img->render(hdc, item_ui_btn_rect.left, item_ui_btn_rect.top);

	if (ischeat == true && cheatcnt % 2 == 0)
	{
		UTIL::PrintText(hdc, "Cheat Correct !!", "", 700, WINSIZEX / 2 - 150, 200, 46, RGB(255, 0, 0), true, RGB(0, 0, 0));
	}

	quickslot_ui_img->render(hdc, quickslot_ui_rect.left, quickslot_ui_rect.top);
	quickslot_item_ui_img->render(hdc, quickslot_item_ui_rect.left, quickslot_item_ui_rect.top);

	chat_bg->alphaRender(hdc, 0, chat_rect.top, chat_alpha);


	int temp = 0;
	if (is_chat == true)
	{
		chat_on->render(hdc, 0, WINSIZEY - 22);


		if (chat_input.size() == 0)
		{
			UTIL::PrintText(hdc, underbar.c_str(), "", chat_rect.left + 5, WINSIZEY - 16, 12, RGB(0, 0, 0), true, RGB(0, 0, 0));
		}

		for (auto chat_itr = chat_input.begin(); chat_itr != chat_input.end(); chat_itr++)
		{
			UTIL::PrintText(hdc, chat_itr->c_str(), "", chat_rect.left + 5 + temp * 9, WINSIZEY - 16, 12, RGB(0, 0, 0), true, RGB(0, 0, 0));

			temp++;
		}

		UTIL::PrintText(hdc, underbar.c_str(), "", chat_rect.left + 5 + temp * 9, WINSIZEY - 16, 12, RGB(0, 0, 0), true, RGB(0, 0, 0));

	}
	if (chatcnt < 150)
	{
		std::string chat_1_temp = player_name + ": " + chat_1;
		UTIL::PrintText(hdc, chat_1_temp.c_str(), "", m_outPlayer.centerX + 50 - ((chat_1_temp.size() + 2 + player_name.size()) / 2 * 11), m_outPlayer.top - 70, 13, RGB(100, 255, 100), false, RGB(120, 120, 120));
	}


	if (chat_1.size() != 0)
	{
		std::string chat_1_temp = player_name + ": " + chat_1;
		UTIL::PrintText(hdc, chat_1_temp.c_str(), "", chat_rect.left + 5, WINSIZEY - 45, 14, RGB(100, 255, 100), true, RGB(0, 0, 0));
	}
	if (chat_2.size() != 0)
	{
		std::string chat_2_temp = player_name + ": " + chat_2;
		UTIL::PrintText(hdc, chat_2_temp.c_str(), "", chat_rect.left + 5, WINSIZEY - 65, 14, RGB(100, 255, 100), true, RGB(0, 0, 0));
	}
	if (chat_3.size() != 0)
	{
		std::string chat_3_temp = player_name + ": " + chat_3;
		UTIL::PrintText(hdc, chat_3_temp.c_str(), "", chat_rect.left + 5, WINSIZEY - 85, 14, RGB(100, 255, 100), true, RGB(0, 0, 0));
	}
	//Hp, Sp mini Bar
	UTIL::DrawColorRect(hdc, stat_mini_Hp_gaze, RGB(66, 66, 66), false);
	UTIL::DrawColorRect(hdc, stat_mini_Hp_Cur_gaze, RGB(16, 239, 33), false);
	UTIL::DrawColorRect(hdc, stat_mini_Sp_gaze, RGB(66, 66, 66), false);
	UTIL::DrawColorRect(hdc, stat_mini_Sp_Cur_gaze, RGB(24, 99, 222), false);

	UTIL::PrintText(hdc, "기본정보", "", base_ui_rect.left + 17, base_ui_rect.top + 2, 12, RGB(0, 0, 0), true, RGB(0, 0, 0));
	UTIL::PrintText(hdc, player_name.c_str(), "", base_ui_rect.left + 5, base_ui_rect.top + 23, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
	UTIL::PrintText(hdc, job.c_str(), "", base_ui_rect.left + 5, base_ui_rect.top + 41, 12, RGB(0, 0, 0), true, RGB(0, 0, 0));

	UTIL::PrintText(hdc, "HP", "", base_ui_rect.left + 90, base_ui_rect.top + 21, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
	UTIL::PrintText(hdc, "SP", "", base_ui_rect.left + 90, base_ui_rect.top + 41, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));

	//Weight
	std::string m_stat_Cur_Weight = std::to_string(stat_Curweight);
	std::string m_stat_Max_Weight = std::to_string(stat_Maxweight);
	UTIL::PrintText(hdc, "Weight :", "", base_ui_rect.left + 15, base_ui_rect.top + 103, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
	UTIL::PrintText(hdc, m_stat_Cur_Weight.c_str(), "", base_ui_rect.left + 65, base_ui_rect.top + 103, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
	UTIL::PrintText(hdc, " / ", "", base_ui_rect.left + 85, base_ui_rect.top + 103, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
	UTIL::PrintText(hdc, m_stat_Max_Weight.c_str(), "", base_ui_rect.left + 95, base_ui_rect.top + 103, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));

	//Money (zeny)
	std::string m_have_Zeny = std::to_string(have_zeny);
	UTIL::PrintText(hdc, "Zeny :", "", base_ui_rect.left + 125, base_ui_rect.top + 103, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
	UTIL::PrintText(hdc, m_have_Zeny.c_str(), "", base_ui_rect.left + 163, base_ui_rect.top + 103, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));


	//Base stat

	//Hp, Sp bar
	gaze_mid->render(hdc, stat_Hp_gaze.left - 2, stat_Hp_gaze.top, 0, 0, 77 * stat_Curhp / stat_Maxhp, 8);
	gaze_left->render(hdc, stat_Hp_gaze.left - 5, stat_Hp_gaze.top);
	gaze_right->render(hdc, stat_Hp_gaze.right - 2, stat_Hp_gaze.top);

	gaze_mid->render(hdc, stat_Sp_gaze.left - 2, stat_Sp_gaze.top, 0, 0, 77 * stat_Cursp / stat_Maxsp, 8);
	gaze_left->render(hdc, stat_Sp_gaze.left - 5, stat_Sp_gaze.top);
	gaze_right->render(hdc, stat_Sp_gaze.right - 2, stat_Sp_gaze.top);

	std::string m_stat_MaxHp = std::to_string(stat_Maxhp);
	std::string m_stat_CurHp = std::to_string(stat_Curhp);
	std::string m_stat_MaxSp = std::to_string(stat_Maxsp);
	std::string m_stat_CurSp = std::to_string(stat_Cursp);
	UTIL::PrintText(hdc, m_stat_CurHp.c_str(), "", base_ui_rect.left + 135, base_ui_rect.top + 32, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
	UTIL::PrintText(hdc, " / ", "", base_ui_rect.left + 150, base_ui_rect.top + 32, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
	UTIL::PrintText(hdc, m_stat_MaxHp.c_str(), "", base_ui_rect.left + 165, base_ui_rect.top + 32, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
	std::string m_stat_hpPer = std::to_string(100 * stat_Curhp / stat_Maxhp);
	UTIL::PrintText(hdc, m_stat_hpPer.c_str(), "", base_ui_rect.left + 141, base_ui_rect.top + 22, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
	UTIL::PrintText(hdc, "%", "", base_ui_rect.left + 162, base_ui_rect.top + 22, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));

	UTIL::PrintText(hdc, m_stat_CurSp.c_str(), "", base_ui_rect.left + 135, base_ui_rect.top + 52, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
	UTIL::PrintText(hdc, " / ", "", base_ui_rect.left + 150, base_ui_rect.top + 52, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
	UTIL::PrintText(hdc, m_stat_MaxSp.c_str(), "", base_ui_rect.left + 165, base_ui_rect.top + 52, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));

	std::string m_stat_spPer = std::to_string(100 * stat_Cursp / stat_Maxsp);
	UTIL::PrintText(hdc, m_stat_spPer.c_str(), "", base_ui_rect.left + 141, base_ui_rect.top + 42, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
	UTIL::PrintText(hdc, "%", "", base_ui_rect.left + 162, base_ui_rect.top + 42, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));

	std::string m_stat_Base_level = std::to_string(stat_base_level);
	UTIL::PrintText(hdc, "Base Lv. ", "", base_ui_rect.left + 15, base_ui_rect.top + 74, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
	UTIL::PrintText(hdc, m_stat_Base_level.c_str(), "", base_ui_rect.left + 65, base_ui_rect.top + 74, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
	std::string m_stat_Job_level = std::to_string(stat_job_level);
	UTIL::PrintText(hdc, "Job   Lv. ", "", base_ui_rect.left + 15, base_ui_rect.top + 85, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
	UTIL::PrintText(hdc, m_stat_Job_level.c_str(), "", base_ui_rect.left + 65, base_ui_rect.top + 85, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));


	//Exp Bar
	UTIL::DrawColorRect(hdc, stat_base_Exp_rect, RGB(255, 255, 255), false);
	UTIL::DrawColorRect(hdc, stat_base_Cur_Exp_rect, RGB(122, 143, 210), false);
	UTIL::DrawColorRect(hdc, stat_job_Exp_rect, RGB(255, 255, 255), false);
	UTIL::DrawColorRect(hdc, stat_job_Cur_Exp_rect, RGB(122, 143, 210), false);

	if (UTIL::isPointRectCollision(m_ptMouse, stat_base_Exp_rect))
	{
		int base_exp_per;
		base_exp_per = 100 * stat_base_curExp / stat_base_MaxExp;
		std::string m_base_exp_per = std::to_string(base_exp_per) + "%";
		UTIL::PrintText(hdc, m_base_exp_per.c_str(), "", m_ptMouse.x - 50, m_ptMouse.y, 15, RGB(0, 0, 0), false, RGB(200, 200, 200));
	}
	else if (UTIL::isPointRectCollision(m_ptMouse, stat_job_Exp_rect))
	{
		int job_exp_per;
		job_exp_per = 100 * stat_job_curExp / stat_job_MaxExp;
		std::string m_job_exp_per = std::to_string(job_exp_per) + "%";
		UTIL::PrintText(hdc, m_job_exp_per.c_str(), "", m_ptMouse.x - 50, m_ptMouse.y, 15, RGB(0, 0, 0), false, RGB(200, 200, 200));
	}

	//Status
	if (isStat)
	{
		stat_ui_img->alphaRender(hdc, stat_ui_rect.left, stat_ui_rect.top + 17, stat_alpha);
		ui_bar_img->alphaRender(hdc, stat_ui_bar_rect.left, stat_ui_bar_rect.top, stat_alpha);
		ui_bar_cancle_img->alphaRender(hdc, stat_ui_bar_cancle_rect.left, stat_ui_bar_cancle_rect.top - 2, stat_alpha);
		ui_minicircle_off_img->alphaRender(hdc, stat_ui_rect.left + 3, stat_ui_rect.top + 2, stat_alpha);

		UTIL::PrintText(hdc, "스테이터스", "", stat_ui_rect.left + 20, stat_ui_rect.top + 3, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));

		std::string m_stat_str = std::to_string(stat_str);
		std::string m_stat_agi = std::to_string(stat_agi);
		std::string m_stat_vit = std::to_string(stat_vit);
		std::string m_stat_int = std::to_string(stat_int);
		std::string m_stat_dex = std::to_string(stat_dex);
		std::string m_stat_luk = std::to_string(stat_luk);
		UTIL::PrintText(hdc, m_stat_str.c_str(), "", stat_ui_rect.left + 38, stat_ui_rect.top + 24, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_agi.c_str(), "", stat_ui_rect.left + 38, stat_ui_rect.top + 40, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_vit.c_str(), "", stat_ui_rect.left + 38, stat_ui_rect.top + 56, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_int.c_str(), "", stat_ui_rect.left + 38, stat_ui_rect.top + 72, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_dex.c_str(), "", stat_ui_rect.left + 38, stat_ui_rect.top + 88, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_luk.c_str(), "", stat_ui_rect.left + 38, stat_ui_rect.top + 104, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));

		std::string m_stat_need_str = std::to_string(stat_str_need_point);
		std::string m_stat_need_agi = std::to_string(stat_agi_need_point);
		std::string m_stat_need_vit = std::to_string(stat_vit_need_point);
		std::string m_stat_need_int = std::to_string(stat_int_need_point);
		std::string m_stat_need_dex = std::to_string(stat_dex_need_point);
		std::string m_stat_need_luk = std::to_string(stat_luk_need_point);

		UTIL::PrintText(hdc, m_stat_need_str.c_str(), "", stat_ui_rect.left + 95, stat_ui_rect.top + 24, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_need_agi.c_str(), "", stat_ui_rect.left + 95, stat_ui_rect.top + 40, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_need_vit.c_str(), "", stat_ui_rect.left + 95, stat_ui_rect.top + 56, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_need_int.c_str(), "", stat_ui_rect.left + 95, stat_ui_rect.top + 72, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_need_dex.c_str(), "", stat_ui_rect.left + 95, stat_ui_rect.top + 88, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_need_luk.c_str(), "", stat_ui_rect.left + 95, stat_ui_rect.top + 104, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));

		std::string m_stat_point = std::to_string(stat_point);
		UTIL::PrintText(hdc, m_stat_point.c_str(), "", stat_ui_rect.left + 249, stat_ui_rect.top + 87, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));

		std::string m_stat_atk_left = std::to_string(stat_str * 3);
		std::string m_stat_atk_right = std::to_string(equip_atk);
		std::string m_stat_matk_left = std::to_string(stat_int * 2);
		std::string m_stat_matk_right = std::to_string(equip_matk);
		std::string m_stat_def_left = std::to_string(stat_vit * 2);
		std::string m_stat_def_right = std::to_string(equip_def);
		std::string m_stat_mdef_left = std::to_string(stat_int * 2);
		std::string m_stat_mdef_right = std::to_string(equip_mdef);
		std::string m_stat_hit = std::to_string(stat_hit);
		std::string m_stat_feel = std::to_string(stat_feel);
		std::string m_stat_cri = std::to_string(stat_cri);
		std::string m_stat_aspd = std::to_string(stat_aspd);

		UTIL::PrintText(hdc, m_stat_atk_left.c_str(), "", stat_ui_rect.left + 150, stat_ui_rect.top + 24, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "+", "", stat_ui_rect.left + 170, stat_ui_rect.top + 24, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_atk_right.c_str(), "", stat_ui_rect.left + 180, stat_ui_rect.top + 24, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_matk_left.c_str(), "", stat_ui_rect.left + 150, stat_ui_rect.top + 40, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "+", "", stat_ui_rect.left + 170, stat_ui_rect.top + 40, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_matk_right.c_str(), "", stat_ui_rect.left + 180, stat_ui_rect.top + 40, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_def_left.c_str(), "", stat_ui_rect.left + 230, stat_ui_rect.top + 24, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "+", "", stat_ui_rect.left + 250, stat_ui_rect.top + 24, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_def_right.c_str(), "", stat_ui_rect.left + 260, stat_ui_rect.top + 24, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_mdef_left.c_str(), "", stat_ui_rect.left + 230, stat_ui_rect.top + 40, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "+", "", stat_ui_rect.left + 250, stat_ui_rect.top + 40, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_mdef_right.c_str(), "", stat_ui_rect.left + 260, stat_ui_rect.top + 40, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_hit.c_str(), "", stat_ui_rect.left + 180, stat_ui_rect.top + 56, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_cri.c_str(), "", stat_ui_rect.left + 180, stat_ui_rect.top + 72, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_feel.c_str(), "", stat_ui_rect.left + 249, stat_ui_rect.top + 56, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, m_stat_aspd.c_str(), "", stat_ui_rect.left + 249, stat_ui_rect.top + 72, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));

		if (isStatAddStr) stat_add_img->alphaRender(hdc, stat_add_str_btn_rect.left, stat_add_str_btn_rect.top, stat_alpha);
		if (isStatAddAgi) stat_add_img->alphaRender(hdc, stat_add_agi_btn_rect.left, stat_add_agi_btn_rect.top, stat_alpha);
		if (isStatAddVit) stat_add_img->alphaRender(hdc, stat_add_vit_btn_rect.left, stat_add_vit_btn_rect.top, stat_alpha);
		if (isStatAddInt) stat_add_img->alphaRender(hdc, stat_add_int_btn_rect.left, stat_add_int_btn_rect.top, stat_alpha);
		if (isStatAddDex) stat_add_img->alphaRender(hdc, stat_add_dex_btn_rect.left, stat_add_dex_btn_rect.top, stat_alpha);
		if (isStatAddLuk) stat_add_img->alphaRender(hdc, stat_add_luk_btn_rect.left, stat_add_luk_btn_rect.top, stat_alpha);
	}
	if (isDie && Rescu_alpha <= 0)
	{
		die_ui_img->alphaRender(hdc, die_ui_rect.left, die_ui_rect.top + 17, die_alpha);
		ui_bar_img->alphaRender(hdc, die_ui_bar_rect.left, die_ui_bar_rect.top, die_alpha);

		ui_minicircle_off_img->alphaRender(hdc, die_ui_rect.left + 3, die_ui_rect.top + 2, die_alpha);

		choose_Bar->alphaRender(hdc, die_ui_bar_recure_rect.left, die_ui_bar_recure_rect.top, die_alpha);

		UTIL::PrintText(hdc, "캐릭터가 죽었습니다.", "", die_ui_rect.left + 20, die_ui_rect.top + 3, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "다시 부활하기", "", die_ui_bar_recure_rect.left + 60, die_ui_bar_recure_rect.top + 3, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
	}

	if (isRescu)
	{
		black_bg_->alphaRender(hdc, 0, 0, Rescu_alpha);
	}




	if (isSkill)
	{
		skill_ui_img->alphaRender(hdc, skill_ui_rect.left, skill_ui_rect.top + 17, skill_alpha);
		ui_bar_img->alphaRender(hdc, skill_ui_bar_rect.left, skill_ui_bar_rect.top, skill_alpha);
		ui_bar_cancle_img->alphaRender(hdc, skill_ui_bar_cancle_rect.left, skill_ui_bar_cancle_rect.top - 2, skill_alpha);
		ui_minicircle_off_img->alphaRender(hdc, skill_ui_rect.left + 3, skill_ui_rect.top + 2, skill_alpha);

		UTIL::PrintText(hdc, "스킬목록", "", skill_ui_rect.left + 20, skill_ui_rect.top + 3, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));

		int i = 0;
		for (auto& Skill_player = SKILL->player_skill.begin(); Skill_player != SKILL->player_skill.end(); ++Skill_player)
		{

			Skill_player->skill_icon_rect = UTIL::IRectMake(skill_ui_rect.left + 30 + 70 * i, skill_ui_rect.top + 30, 30, 30);
			Skill_player->skill_icon_image->render(hdc, skill_ui_rect.left + 30 + 70 * i, skill_ui_rect.top + 30);
			UTIL::PrintText(hdc, Skill_player->skill_name.c_str(), "", skill_ui_rect.left + 23 + 70 * i, skill_ui_rect.top + 70, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));


			std::string Skill_curLevel = std::to_string(Skill_player->skill_curLevel) + " /";
			UTIL::PrintText(hdc, Skill_curLevel.c_str(), "", skill_ui_rect.left + 35 + 70 * i, skill_ui_rect.top + 82, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));

			std::string Skill_maxLevel = std::to_string(Skill_player->skill_maxLevel);
			UTIL::PrintText(hdc, Skill_maxLevel.c_str(), "", skill_ui_rect.left + 50 + 70 * i, skill_ui_rect.top + 82, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));

			//스킬포인트 투자
			if (skill_point > 0 && Skill_player->skill_curLevel < Skill_player->skill_maxLevel)
			{
				Skill_player->skill_point_plus_rect = UTIL::IRectMake(skill_ui_rect.left + 60 + 70 * i, skill_ui_rect.top + 82, 10, 10);
				Skill_player->skill_point_plus_image->render(hdc, Skill_player->skill_point_plus_rect.left, Skill_player->skill_point_plus_rect.top);

				if (UTIL::isPointRectCollision(m_ptMouse, Skill_player->skill_point_plus_rect) && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
				{
					isAddcursor = true;
					Skill_player->skill_curLevel += 1;
					skill_point -= 1;

					if (Skill_player->skill_name == "기본기능")
					{
						equip_atk += Skill_player->skill_effect;
					}
				}

				else if (KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
				{
					isAddcursor = false;
				}
			}

			i++;
		}

		std::string Skill_point = "스킬포인트 : " + std::to_string(skill_point);
		UTIL::PrintText(hdc, Skill_point.c_str(), "", skill_ui_rect.left + 175, skill_ui_rect.top + 195, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));


		for (auto& Skill_player = SKILL->player_skill.begin(); Skill_player != SKILL->player_skill.end(); ++Skill_player)
		{
			//스킬설명 && 드래그
			if (UTIL::isPointRectCollision(m_ptMouse, Skill_player->skill_icon_rect))
			{
				if (is_skill_icon_move == false)
				{
					Skill_player->skill_des_rect = UTIL::IRectMake(m_ptMouse.x - 10, m_ptMouse.y + 30, 300, 120);
					Skill_player->skill_des_image->render(hdc, Skill_player->skill_des_rect.left, Skill_player->skill_des_rect.top);
					UTIL::PrintText(hdc, Skill_player->skill_des.c_str(), "", Skill_player->skill_des_rect.left + 9, Skill_player->skill_des_rect.top + 11, 12, RGB(0, 0, 0), true, RGB(0, 0, 0));

					if (Skill_player->skill_isActive == true)
					{
						UTIL::PrintText(hdc, "스킬유형 : 액티브", "", Skill_player->skill_des_rect.left + 9, Skill_player->skill_des_rect.top + 30, 12, RGB(0, 0, 0), true, RGB(0, 0, 0));

						std::string recover_hp = "HP 회복량 : " + std::to_string(Skill_player->skill_effect);
						UTIL::PrintText(hdc, recover_hp.c_str(), "", Skill_player->skill_des_rect.left + 9, Skill_player->skill_des_rect.top + 49, 12, RGB(0, 0, 0), true, RGB(0, 0, 0));

						std::string use_sp = "SP 소모량 : " + std::to_string(Skill_player->skill_sp);
						UTIL::PrintText(hdc, use_sp.c_str(), "", Skill_player->skill_des_rect.left + 9, Skill_player->skill_des_rect.top + 68, 12, RGB(0, 0, 0), true, RGB(0, 0, 0));

					}
					else if (Skill_player->skill_isActive == false)
					{
						UTIL::PrintText(hdc, "스킬유형 : 패시브", "", Skill_player->skill_des_rect.left + 9, Skill_player->skill_des_rect.top + 30, 12, RGB(0, 0, 0), true, RGB(0, 0, 0));
						std::string effect = "스킬 레벨당 공격력 증가 + : " + std::to_string(Skill_player->skill_effect);
						UTIL::PrintText(hdc, effect.c_str(), "", Skill_player->skill_des_rect.left + 9, Skill_player->skill_des_rect.top + 49, 12, RGB(0, 0, 0), true, RGB(0, 0, 0));

					}
				}

				if (Skill_player->skill_curLevel > 0 && Skill_player->skill_isActive == true && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
				{
					is_skill_icon_move = true;
					move_icon.push_back(*Skill_player);
				}
			}


			if (is_skill_icon_move && move_icon.size() != 0)
			{

				if (move_icon.size() == 0)continue;

				move_icon.begin()->skill_icon_image->alphaRender(hdc, m_ptMouse.x - 5, m_ptMouse.y - 5, 120);

				if (UTIL::isPointRectCollision(m_ptMouse, quickslot_1_ui_rect) && KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
				{
					quickslot.clear();

					is_skill_icon_move = false;
					quickslot.push_back(*move_icon.begin());
					move_icon.clear();
				}
				else if (UTIL::isPointRectCollision(m_ptMouse, quickslot_2_ui_rect) && KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
				{
					quickslot2.clear();

					is_skill_icon_move = false;
					quickslot2.push_back(*move_icon.begin());
					move_icon.clear();
				}
				else if (KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
				{
					is_skill_icon_move = false;
					move_icon.clear();
				}
			}

		}
	}




	if (isItem)
	{
		Item_ui_img->alphaRender(hdc, item_ui_rect.left, item_ui_rect.top + 17, item_alpha);
		ui_bar_img->alphaRender(hdc, item_ui_bar_rect.left, item_ui_bar_rect.top, item_alpha);
		ui_bar_cancle_img->alphaRender(hdc, item_ui_bar_cancle_rect.left, item_ui_bar_cancle_rect.top - 2, item_alpha);
		ui_minicircle_off_img->alphaRender(hdc, item_ui_rect.left + 3, item_ui_rect.top + 2, item_alpha);

		UTIL::PrintText(hdc, "아이템목록", "", item_ui_rect.left + 20, item_ui_rect.top + 3, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));


		if (is_item_usetab == true)
		{
			Item_ui_potiontab_img->alphaRender(hdc, item_ui_rect.left, item_ui_rect.top + 17, item_alpha);
			int number = 0;
			for (auto& item_usetab_itr = item_use_vector.begin(); item_usetab_itr != item_use_vector.end(); ++item_usetab_itr)
			{
				item_usetab_itr->Item_icon_rect = UTIL::IRectMake(item_ui_rect.left + 39 + 40 * number, item_ui_rect.top + 28, 30, 30);
				item_shadow_img->render(hdc, item_usetab_itr->Item_icon_rect.left - 7, item_usetab_itr->Item_icon_rect.top - 3);
				item_usetab_itr->Item_icon_image->render(hdc, item_usetab_itr->Item_icon_rect.left, item_usetab_itr->Item_icon_rect.top);
				std::string item_ea = std::to_string(item_usetab_itr->Item_ea);
				UTIL::PrintText(hdc, item_ea.c_str(), "", item_usetab_itr->Item_icon_rect.right - 10, item_usetab_itr->Item_icon_rect.bottom - 17, 10, RGB(0, 0, 0), true, RGB(0, 0, 0));
				number++;
			}

			for (auto& item_usetab_itr = item_use_vector.begin(); item_usetab_itr != item_use_vector.end(); ++item_usetab_itr)
			{
				if (UTIL::isPointRectCollision(m_ptMouse, item_usetab_itr->Item_icon_rect))
				{
					if (is_item_icon_move == false)
					{
						std::string item_name_ea = item_usetab_itr->Item_name + " " + std::to_string(item_usetab_itr->Item_ea) + "개";
						UTIL::PrintText(hdc, item_name_ea.c_str(), "", m_ptMouse.x - 5, m_ptMouse.y - 15, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
						if (KEYMANAGER->isOnceKeyDown(GAME_RMOUSE))
						{
							isIteminfoView = true;
							if (item_info_vector.size() != 0)item_info_vector.clear();
							item_info_vector.push_back(*item_usetab_itr);
						}
					}

					//아이템 드래그
					if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
					{
						is_item_icon_move = true;
						move_item_icon.push_back(*item_usetab_itr);
					}
				}

				if (is_item_icon_move && move_item_icon.size() != 0)
				{

					if (move_item_icon.size() == 0)continue;

					move_item_icon.begin()->Item_icon_image->alphaRender(hdc, m_ptMouse.x - 5, m_ptMouse.y - 5, 120);

					if (UTIL::isPointRectCollision(m_ptMouse, quickslot_item_1_ui_rect) && KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
					{
						quickslot_item_1.clear();

						is_item_icon_move = false;
						quickslot_item_1.push_back(*move_item_icon.begin());
						move_item_icon.clear();
					}
					else if (UTIL::isPointRectCollision(m_ptMouse, quickslot_item_2_ui_rect) && KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
					{
						quickslot_item_2.clear();

						is_item_icon_move = false;
						quickslot_item_2.push_back(*move_item_icon.begin());
						move_item_icon.clear();
					}
					else if (KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
					{
						is_item_icon_move = false;
						move_item_icon.clear();
					}
				}
			}
		}
		else if (is_item_equiptab == true)
		{
			Item_ui_equiptab_img->alphaRender(hdc, item_ui_rect.left, item_ui_rect.top + 17, item_alpha);
			int number = 0;
			for (auto& item_equiptab_itr = item_equip_vector.begin(); item_equiptab_itr != item_equip_vector.end(); ++item_equiptab_itr)
			{
				item_equiptab_itr->Item_icon_rect = UTIL::IRectMake(item_ui_rect.left + 39 + 40 * number, item_ui_rect.top + 28, 30, 30);
				item_shadow_img->render(hdc, item_equiptab_itr->Item_icon_rect.left - 7, item_equiptab_itr->Item_icon_rect.top - 3);
				item_equiptab_itr->Item_icon_image->render(hdc, item_equiptab_itr->Item_icon_rect.left, item_equiptab_itr->Item_icon_rect.top);
				std::string item_ea = std::to_string(item_equiptab_itr->Item_ea);
				UTIL::PrintText(hdc, item_ea.c_str(), "", item_equiptab_itr->Item_icon_rect.right - 10, item_equiptab_itr->Item_icon_rect.bottom - 17, 10, RGB(0, 0, 0), true, RGB(0, 0, 0));

				number++;
			}

			for (auto& item_equiptab_itr = item_use_vector.begin(); item_equiptab_itr != item_use_vector.end(); ++item_equiptab_itr)
			{
				if (UTIL::isPointRectCollision(m_ptMouse, item_equiptab_itr->Item_icon_rect))
				{
					std::string item_name_ea = item_equiptab_itr->Item_name + " " + std::to_string(item_equiptab_itr->Item_ea) + "개";
					UTIL::PrintText(hdc, item_name_ea.c_str(), "", m_ptMouse.x - 5, m_ptMouse.y - 15, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
					if (KEYMANAGER->isOnceKeyDown(GAME_RMOUSE))
					{
						isIteminfoView = true;
						if (item_info_vector.size() != 0)item_info_vector.clear();
						item_info_vector.push_back(*item_equiptab_itr);
					}
				}
			}
		}
		else if (is_item_kindtab == true)
		{
			Item_ui_kindtab_img->alphaRender(hdc, item_ui_rect.left, item_ui_rect.top + 17, item_alpha);
			int number = 0;
			for (auto& item_kindtab_itr = item_kind_vector.begin(); item_kindtab_itr != item_kind_vector.end(); ++item_kindtab_itr)
			{
				item_kindtab_itr->Item_icon_rect = UTIL::IRectMake(item_ui_rect.left + 39 + 40 * number, item_ui_rect.top + 28, 30, 30);
				item_shadow_img->render(hdc, item_kindtab_itr->Item_icon_rect.left - 7, item_kindtab_itr->Item_icon_rect.top - 3);
				item_kindtab_itr->Item_icon_image->render(hdc, item_kindtab_itr->Item_icon_rect.left, item_kindtab_itr->Item_icon_rect.top);
				std::string item_ea = std::to_string(item_kindtab_itr->Item_ea);
				UTIL::PrintText(hdc, item_ea.c_str(), "", item_kindtab_itr->Item_icon_rect.right - 10, item_kindtab_itr->Item_icon_rect.bottom - 17, 10, RGB(0, 0, 0), true, RGB(0, 0, 0));
				number++;
			}

			for (auto& item_kindtab_itr = item_kind_vector.begin(); item_kindtab_itr != item_kind_vector.end(); ++item_kindtab_itr)
			{
				if (UTIL::isPointRectCollision(m_ptMouse, item_kindtab_itr->Item_icon_rect))
				{
					std::string item_name_ea = item_kindtab_itr->Item_name + " " + std::to_string(item_kindtab_itr->Item_ea) + "개";
					UTIL::PrintText(hdc, item_name_ea.c_str(), "", m_ptMouse.x - 5, m_ptMouse.y - 15, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
					if (KEYMANAGER->isOnceKeyDown(GAME_RMOUSE))
					{
						isIteminfoView = true;
						if (item_info_vector.size() != 0)item_info_vector.clear();
						item_info_vector.push_back(*item_kindtab_itr);
					}
				}
			}

		}

		if (isIteminfoView == true)
		{
			item_info_vector.begin()->Item_des_rect = UTIL::IRectMake(item_info_vector.begin()->Item_icon_rect.left + 10, item_info_vector.begin()->Item_icon_rect.bottom + 10, 300, 130);
			item_info_vector.begin()->Item_des_image->render(hdc, item_info_vector.begin()->Item_des_rect.left, item_info_vector.begin()->Item_des_rect.top);
			item_info_vector.begin()->Item_des_mini_image->render(hdc, item_info_vector.begin()->Item_des_rect.left + 5, item_info_vector.begin()->Item_des_rect.top + 5);

			item_info_cancle_rect = UTIL::IRectMake(item_info_vector.begin()->Item_des_rect.right - 15, item_info_vector.begin()->Item_des_rect.top + 3, 11, 11);
			item_info_bar_cancle_img->render(hdc, item_info_cancle_rect.left, item_info_cancle_rect.top);

			UTIL::PrintText(hdc, item_info_vector.begin()->Item_name.c_str(), "", item_info_vector.begin()->Item_des_rect.left + 80, item_info_vector.begin()->Item_des_rect.top + 10, 16, RGB(0, 0, 0), true, RGB(0, 0, 0));
			UTIL::PrintText(hdc, item_info_vector.begin()->Item_des.c_str(), "", item_info_vector.begin()->Item_des_rect.left + 80, item_info_vector.begin()->Item_des_rect.top + 50, 14, RGB(0, 0, 0), true, RGB(0, 0, 0));

			std::string item_kind = "분류: " + item_info_vector.begin()->Item_type;
			UTIL::PrintText(hdc, item_kind.c_str(), "", item_info_vector.begin()->Item_des_rect.left + 140, item_info_vector.begin()->Item_des_rect.top + 110, 12, RGB(0, 0, 0), true, RGB(0, 0, 0));

			std::string item_weight = "무게: " + std::to_string(item_info_vector.begin()->Item_weight);
			UTIL::PrintText(hdc, item_weight.c_str(), "", item_info_vector.begin()->Item_des_rect.left + 240, item_info_vector.begin()->Item_des_rect.top + 110, 12, RGB(0, 0, 0), true, RGB(0, 0, 0));

			if (UTIL::isPointRectCollision(m_ptMouse, item_info_cancle_rect) && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
			{
				isIteminfoView = false;
			}
		}

	}

	//아이템 퀵슬롯_1 (3번키)
	for (auto itemslot_itr = quickslot_item_1.begin(); itemslot_itr != quickslot_item_1.end();)
	{
		if (quickslot_item_1.size() == 0)continue;

		itemslot_itr->Item_icon_image->render(hdc, quickslot_item_1_ui_rect.left + 3, quickslot_item_1_ui_rect.top);

		if (UTIL::isPointRectCollision(m_ptMouse, quickslot_item_1_ui_rect))
		{
			std::string quickslot_item_1 = "3. " + itemslot_itr->Item_name + " " + std::to_string(itemslot_itr->Item_ea) + "개";
			UTIL::PrintText(hdc, quickslot_item_1.c_str(), "", m_ptMouse.x + 10, m_ptMouse.y + 30, 14, RGB(0, 0, 0), false, RGB(150, 150, 150));
		}


		for (auto item_delete_iter = item_use_vector.begin(); item_delete_iter != item_use_vector.end();)
		{
			if (item_delete_iter->Item_name == itemslot_itr->Item_name)
			{
				std::string quickslot_item_1_ea = std::to_string(item_delete_iter->Item_ea);
				UTIL::PrintText(hdc, quickslot_item_1_ea.c_str(), "", quickslot_item_1_ui_rect.right - 10, quickslot_item_1_ui_rect.bottom - 10, 11, RGB(0, 0, 0), true, RGB(150, 150, 150));

				if (KEYMANAGER->isOnceKeyDown(GAME_3) && itemslot_itr->Item_type == "소비" && !is_chat)
				{
					SOUNDMANAGER->stopChannel(Channel::eChannelheal);
					SOUNDMANAGER->playSound("heal", Channel::eChannelheal);
					//itemslot_itr->Item_ea -= 1;
					item_delete_iter->Item_ea -= 1;
					stat_Curweight -= itemslot_itr->Item_weight;


					if (itemslot_itr->Item_effect_type == "HP")
						stat_Curhp += itemslot_itr->Item_effect;

					else if (itemslot_itr->Item_effect_type == "SP")
						stat_Cursp += itemslot_itr->Item_effect;


					if (item_delete_iter->Item_ea <= 0)
					{
						itemslot_itr = quickslot_item_1.erase(itemslot_itr);
						item_delete_iter = item_use_vector.erase(item_delete_iter);

					}

					break;
				}


			}
			++item_delete_iter;
		}
		if (quickslot_item_1.size() == 0)continue;
		else itemslot_itr++;
	}

	//아이템 퀵슬롯_2 (4번키)
	for (auto itemslot_itr = quickslot_item_2.begin(); itemslot_itr != quickslot_item_2.end();)
	{
		if (quickslot_item_2.size() == 0)continue;

		itemslot_itr->Item_icon_image->render(hdc, quickslot_item_2_ui_rect.left + 3, quickslot_item_2_ui_rect.top);

		if (UTIL::isPointRectCollision(m_ptMouse, quickslot_item_2_ui_rect))
		{
			std::string quickslot_item_2 = "4. " + itemslot_itr->Item_name + " " + std::to_string(itemslot_itr->Item_ea) + "개";
			UTIL::PrintText(hdc, quickslot_item_2.c_str(), "", m_ptMouse.x + 10, m_ptMouse.y + 30, 14, RGB(0, 0, 0), false, RGB(150, 150, 150));
		}


		for (auto item_delete_iter = item_use_vector.begin(); item_delete_iter != item_use_vector.end();)
		{
			if (item_delete_iter->Item_name == itemslot_itr->Item_name)
			{
				std::string quickslot_item_2_ea = std::to_string(item_delete_iter->Item_ea);
				UTIL::PrintText(hdc, quickslot_item_2_ea.c_str(), "", quickslot_item_2_ui_rect.right - 10, quickslot_item_2_ui_rect.bottom - 10, 11, RGB(0, 0, 0), true, RGB(150, 150, 150));

				if (KEYMANAGER->isOnceKeyDown(GAME_4) && itemslot_itr->Item_type == "소비" && !is_chat)
				{
					SOUNDMANAGER->stopChannel(Channel::eChannelheal);
					SOUNDMANAGER->playSound("heal", Channel::eChannelheal);
					//itemslot_itr->Item_ea -= 1;
					item_delete_iter->Item_ea -= 1;
					stat_Curweight -= itemslot_itr->Item_weight;


					if (itemslot_itr->Item_effect_type == "HP")
						stat_Curhp += itemslot_itr->Item_effect;

					else if (itemslot_itr->Item_effect_type == "SP")
						stat_Cursp += itemslot_itr->Item_effect;


					if (item_delete_iter->Item_ea <= 0)
					{
						itemslot_itr = quickslot_item_2.erase(itemslot_itr);
						item_delete_iter = item_use_vector.erase(item_delete_iter);

					}

					break;
				}


			}
			++item_delete_iter;
		}
		if (quickslot_item_2.size() == 0)continue;
		else itemslot_itr++;
	}

	///////////




	//스킬 퀵슬롯
	for (auto& quickslot_itr = quickslot.begin(); quickslot_itr != quickslot.end(); ++quickslot_itr)
	{
		if (quickslot.size() == 0)continue;

		quickslot_itr->skill_icon_image->render(hdc, quickslot_1_ui_rect.left, quickslot_1_ui_rect.top);

		if (UTIL::isPointRectCollision(m_ptMouse, quickslot_1_ui_rect))
		{
			std::string quickslot_1 = "1. " + quickslot_itr->skill_name;
			UTIL::PrintText(hdc, quickslot_1.c_str(), "", m_ptMouse.x + 10, m_ptMouse.y + 30, 14, RGB(0, 0, 0), false, RGB(150, 150, 150));
		}

		if (KEYMANAGER->isOnceKeyDown(GAME_1) && quickslot_itr->skill_isActive == true && !is_chat)
		{
			SOUNDMANAGER->stopChannel(Channel::eChannelheal);
			SOUNDMANAGER->playSound("heal", Channel::eChannelheal);
			stat_Curhp += quickslot_itr->skill_effect;
			stat_Cursp -= quickslot_itr->skill_sp;

			isUseQuickSlot_1 = true;

		}

		if (isUseQuickSlot_1)
		{
			QuickSlot_1_count++;
			std::string quickslot_1 = quickslot_itr->skill_name + "!!";
			UTIL::PrintText(hdc, quickslot_1.c_str(), "", 700, m_outPlayer.left, m_outPlayer.top - 70, 19, RGB(0, 0, 0), true, RGB(100, 230, 100));
			isBattle = true;
			if (QuickSlot_1_count > 50)
			{
				isUseQuickSlot_1 = false;
				QuickSlot_1_count = 0;
				isBattle = false;
			}
		}

	}


	for (auto& quickslot2_itr = quickslot2.begin(); quickslot2_itr != quickslot2.end(); ++quickslot2_itr)
	{
		if (quickslot2.size() == 0)continue;
		quickslot2_itr->skill_icon_image->render(hdc, quickslot_2_ui_rect.left, quickslot_2_ui_rect.top);

		if (UTIL::isPointRectCollision(m_ptMouse, quickslot_2_ui_rect))
		{
			std::string quickslot_2 = "2. " + quickslot2_itr->skill_name;
			UTIL::PrintText(hdc, quickslot_2.c_str(), "", m_ptMouse.x + 10, m_ptMouse.y + 30, 14, RGB(0, 0, 0), false, RGB(150, 150, 150));
		}

		if (KEYMANAGER->isOnceKeyDown(GAME_2) && quickslot2_itr->skill_isActive == true && !is_chat)
		{
			SOUNDMANAGER->stopChannel(Channel::eChannelheal);
			SOUNDMANAGER->playSound("heal", Channel::eChannelheal);
			stat_Curhp += quickslot2_itr->skill_effect;
			stat_Cursp -= quickslot2_itr->skill_sp;
			isUseQuickSlot_2 = true;


		}

		if (isUseQuickSlot_2)
		{
			QuickSlot_2_count++;
			std::string quickslot_2 = quickslot2_itr->skill_name + "!!";
			UTIL::PrintText(hdc, quickslot_2.c_str(), "", 700, m_outPlayer.left, m_outPlayer.top - 70, 19, RGB(0, 0, 0), true, RGB(230, 230, 230));
			isBattle = true;
			if (QuickSlot_2_count > 100)
			{
				isUseQuickSlot_2 = false;
				QuickSlot_2_count = 0;
				isBattle = false;
			}
		}


	}

	if (!isAddcursor && !isAddcursor_select && !isAttackcursor && !npc_cursor)
	{
		cursor_base->aniRender(hdc, m_ptMouse.x, m_ptMouse.y, ani_cursor_base);
	}
	else if (isAddcursor && !isAddcursor_select && !npc_cursor)
	{
		cursor_add->render(hdc, m_ptMouse.x, m_ptMouse.y);
	}
	else if (isAttackcursor && !npc_cursor)
	{
		cursor_attack->render(hdc, m_ptMouse.x, m_ptMouse.y);
	}
	else if (isAddcursor_select && !npc_cursor)
	{
		cursor_add_select->render(hdc, m_ptMouse.x, m_ptMouse.y);
	}
	else if (npc_cursor)
	{
		npc_cursor_img->aniRender(hdc, m_ptMouse.x, m_ptMouse.y, ani_cursor_npc);
	}

}
void character::debugRender(HDC hdc)
{
	if (m_FindPath.size())
	{
		m_Astar.PrintPath(m_FindPath);
	}

	UTIL::DrawColorRect(hdc, m_outPlayer, RGB(0, 255, 0));
	char str[30];
	sprintf_s(str, "%d %d, %d %d", DestcurTileIndex.x, DestcurTileIndex.y, m_ptMouse.x, m_ptMouse.y);

	if (isSkill)
	{
		UTIL::DrawColorRect(hdc, skill_ui_rect, RGB(255, 255, 255), false);
		UTIL::DrawColorRect(hdc, skill_ui_bar_rect, RGB(0, 0, 255), false);
		UTIL::DrawColorRect(hdc, skill_ui_bar_cancle_rect, RGB(255, 0, 0), false);
	}
	UTIL::PrintText(hdc, str, "명조", m_ptMouse.x, m_ptMouse.y + 20, 20, RGB(0, 0, 0), false, RGB(255, 255, 255));

	UTIL::DrawColorRect(hdc, base_ui_rect, RGB(255, 255, 255), true);

	UTIL::DrawColorRect(hdc, stat_ui_btn_rect, RGB(0, 0, 255), false);
	UTIL::DrawColorRect(hdc, skill_ui_btn_rect, RGB(0, 0, 255), false);
	UTIL::DrawColorRect(hdc, item_ui_btn_rect, RGB(0, 0, 255), false);
	if (isStat)
	{
		UTIL::DrawColorRect(hdc, stat_ui_rect, RGB(255, 255, 255), true);
		UTIL::DrawColorRect(hdc, stat_ui_bar_rect, RGB(0, 0, 255), true);
		UTIL::DrawColorRect(hdc, stat_ui_bar_cancle_rect, RGB(255, 0, 0), true);
	}

	if (isItem)
	{
		UTIL::DrawColorRect(hdc, item_ui_rect, RGB(255, 255, 255), true);
		UTIL::DrawColorRect(hdc, item_ui_bar_rect, RGB(0, 0, 255), true);
		UTIL::DrawColorRect(hdc, item_ui_bar_cancle_rect, RGB(255, 0, 0), true);
		UTIL::DrawColorRect(hdc, item_use_rect, RGB(255, 0, 0), true);
		UTIL::DrawColorRect(hdc, item_equip_rect, RGB(255, 0, 0), true);
		UTIL::DrawColorRect(hdc, item_kind_rect, RGB(255, 0, 0), true);

	}

	UTIL::DrawColorRect(hdc, stat_Hp_gaze, RGB(255, 0, 0), false);
	UTIL::DrawColorRect(hdc, stat_Sp_gaze, RGB(0, 0, 255), false);

	cursor_base->aniRender(hdc, m_ptMouse.x, m_ptMouse.y, ani_cursor_base);

	UTIL::DrawColorRect(hdc, quickslot_ui_rect, RGB(100, 100, 100));
	UTIL::DrawColorRect(hdc, quickslot_1_ui_rect, RGB(100, 250, 100));
	UTIL::DrawColorRect(hdc, quickslot_2_ui_rect, RGB(100, 250, 100));

	UTIL::DrawColorRect(hdc, quickslot_item_ui_rect, RGB(100, 100, 100));
	UTIL::DrawColorRect(hdc, quickslot_item_1_ui_rect, RGB(100, 250, 100));
	UTIL::DrawColorRect(hdc, quickslot_item_2_ui_rect, RGB(100, 250, 100));
}

POINT character::getMemoryTileIndex()
{
	if (memoryDestCurTileindex.x >= 0 && memoryDestCurTileindex.x <= m_TileColEA && memoryDestCurTileindex.y >= 0 && memoryDestCurTileindex.y <= m_TileRowEA)
	{
		return memoryDestCurTileindex;
	}
}

POINT character::getPlayerTileIndex()
{
	return { m_playerPosX,m_playerPosY };
}

bool character::getisMonster(POINT _XY)
{
	return m_Tiles[_XY.x + _XY.y * m_TileColEA].getisMonster();
}

bool character::getPlayerisTileDest()
{
	//플레이어 렉트의 현재 타일의 Dest 값을 반환(bool 값)
	return isDest;
}

void character::itemsettiong()
{

	for (auto item_collection_itr = item_collection.begin(); item_collection_itr != item_collection.end(); )
	{
		if (item_collection_itr->Item_type == "소비")
		{
			bool isHaveItem = false;
			for (auto item_usetab_iter = item_use_vector.begin(); item_usetab_iter != item_use_vector.end();)
			{
				if (item_collection_itr->Item_name == item_usetab_iter->Item_name)
				{
					item_usetab_iter->Item_ea += item_collection_itr->Item_ea;
					stat_Curweight += (item_collection_itr->Item_ea * item_collection_itr->Item_weight);
					item_collection_itr = item_collection.erase(item_collection_itr);
					isHaveItem = true;
					break;
				}
				else ++item_usetab_iter;

			}
			if (isHaveItem == true)continue;

			item_use_vector.push_back(*item_collection_itr);
			stat_Curweight += (item_collection_itr->Item_ea * item_collection_itr->Item_weight);
			item_collection_itr = item_collection.erase(item_collection_itr);
		}
		else if (item_collection_itr->Item_type == "장비")
		{
			item_equip_vector.push_back(*item_collection_itr);
			item_collection_itr = item_collection.erase(item_collection_itr);
		}
		else if (item_collection_itr->Item_type == "기타")
		{
			bool isHaveItem = false;
			for (auto item_kindtab_iter = item_kind_vector.begin(); item_kindtab_iter != item_kind_vector.end();)
			{

				if (item_collection_itr->Item_name == item_kindtab_iter->Item_name)
				{
					item_kindtab_iter->Item_ea += item_collection_itr->Item_ea;
					stat_Curweight += (item_collection_itr->Item_ea * item_collection_itr->Item_weight);
					item_collection_itr = item_collection.erase(item_collection_itr);
					isHaveItem = true;
					break;
				}
				else ++item_kindtab_iter;

			}
			if (isHaveItem == true)continue;

			item_kind_vector.push_back(*item_collection_itr);
			stat_Curweight += (item_collection_itr->Item_ea * item_collection_itr->Item_weight);
			item_collection_itr = item_collection.erase(item_collection_itr);

		}
	}

}

void character::moveSetting(float _deltaTime)
{
	TileType tileType = getTileType(DestcurTileIndex);



	for (auto& tile : m_Tiles)
	{
		if (tile.getTileIndex() == getPlayerTileIndex())
		{
			m_Tiles[tile.getTileIndex().x + tile.getTileIndex().y * m_TileColEA].setisPlayer(true);
		}
		else
		{
			m_Tiles[tile.getTileIndex().x + tile.getTileIndex().y * m_TileColEA].setisPlayer(false);
		}
	}


	if (isUi == false && isbase == false && isStartGame)
	{

		if (isMoveComplete && moveOk&& isNpcchat==false && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
		{
			if (tileType == TileType::outrange || tileType == TileType::wall || getisNpc(DestcurTileIndex) || moveOk == false)
			{
				for (auto& tile : m_Tiles)
				{
					tile.setisRoot(false);
				}
				isDest = true;
			}
			else
			{
				ismemoryMoveIndex = true;
				isMove = false;
			}
		}
		else if (!isMoveComplete && moveOk && isNpcchat == false && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
		{
			if (tileType == TileType::outrange || tileType == TileType::wall || getisNpc(DestcurTileIndex) || moveOk == false)
			{
				isMoveComplete = true;
			}
			else
			{
				for (auto& tile : m_Tiles)
				{

					tile.setisRoot(false);

				}

				ismemoryMoveIndex = true;
			}
		}

		if (isNpcchat == false && KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
		{
			if (isMoveComplete)
			{
				for (auto& tile : m_Tiles)
				{
					tile.setisRoot(false);
				}
				if (tileType != TileType::outrange)
				{
					if (m_Tiles[DestcurTileIndex.x + DestcurTileIndex.y * m_TileColEA].getisMonster() == false)
					{
						isBattle = false;
					}
				}

				if (tileType == TileType::outrange || tileType == TileType::wall || getisNpc(DestcurTileIndex) || moveOk == false)
				{
					m_FindPath.clear();
					ismemoryMoveIndex = false;
					isMove = false;
					isDest = true;
				}
				else if (getisMonster(DestcurTileIndex))
				{
					ismemoryMoveIndex = false;
					isMove = true;
					isMovetoMonster = true;

					isTargetMonster = true;

					Coordinate A(m_playerPosX, m_playerPosY);
					Coordinate B(toMonsterIndex.x, toMonsterIndex.y);

					m_FindPath = m_Astar.FindPath(A, B);

				}
				else if (memoryDestCurTileindex != getPlayerTileIndex())
				{
					ismemoryMoveIndex = false;
					isMove = true;

					Coordinate A(m_playerPosX, m_playerPosY);
					Coordinate B(memoryDestCurTileindex.x, memoryDestCurTileindex.y);

					m_FindPath = m_Astar.FindPath(A, B);
				}
			}
			else if (!isMoveComplete)
			{
				if (UTIL::isPointRectCollision(m_ptMouse, TargetMonster))
				{
					isMovetoMonster = true;
				}
				isMove = true;
				isMovetemp = true;
			}
		}

		if (isMovetemp)
		{
			if (isMovetoMonster && isMoveComplete)
			{
				isMove = true;
				ismemoryMoveIndex = false;

				Coordinate A(m_playerPosX, m_playerPosY);
				Coordinate B(toMonsterIndex.x, toMonsterIndex.y);

				m_FindPath = m_Astar.FindPath(A, B);

				isMovetemp = false;
			}
			else if (!isMovetoMonster && isMoveComplete && (memoryDestCurTileindex != getPlayerTileIndex()))
			{
				isMove = true;
				ismemoryMoveIndex = false;

				Coordinate A(m_playerPosX, m_playerPosY);
				Coordinate B(memoryDestCurTileindex.x, memoryDestCurTileindex.y);

				m_FindPath = m_Astar.FindPath(A, B);

				isMovetemp = false;
			}
		}
	}

	if (!isMove && isMoveComplete && !isBattle)
	{
		switch (playerArrow)
		{
		case 1:
			is_player_move_12 = false;
			is_player_move_1 = false;
			is_player_move_3 = false;
			is_player_move_5 = false;
			is_player_move_6 = false;
			is_player_move_7 = false;
			is_player_move_9 = false;
			is_player_move_10 = false;
			is_player_move_12 = false;
			is_player_arrow_1 = true;
			is_player_arrow_3 = false;
			is_player_arrow_5 = false;
			is_player_arrow_6 = false;
			is_player_arrow_7 = false;
			is_player_arrow_9 = false;
			is_player_arrow_10 = false;
			is_player_arrow_12 = false;
			break;
		case 3:
			is_player_move_12 = false;
			is_player_move_1 = false;
			is_player_move_3 = false;
			is_player_move_5 = false;
			is_player_move_6 = false;
			is_player_move_7 = false;
			is_player_move_9 = false;
			is_player_move_10 = false;
			is_player_move_12 = false;
			is_player_arrow_1 = false;
			is_player_arrow_3 = true;
			is_player_arrow_5 = false;
			is_player_arrow_6 = false;
			is_player_arrow_7 = false;
			is_player_arrow_9 = false;
			is_player_arrow_10 = false;
			is_player_arrow_12 = false;
			break;
		case 5:
			is_player_move_12 = false;
			is_player_move_1 = false;
			is_player_move_3 = false;
			is_player_move_5 = false;
			is_player_move_6 = false;
			is_player_move_7 = false;
			is_player_move_9 = false;
			is_player_move_10 = false;
			is_player_move_12 = false;
			is_player_arrow_1 = false;
			is_player_arrow_3 = false;
			is_player_arrow_5 = true;
			is_player_arrow_6 = false;
			is_player_arrow_7 = false;
			is_player_arrow_9 = false;
			is_player_arrow_10 = false;
			is_player_arrow_12 = false;
			break;
		case 6:
			is_player_move_12 = false;
			is_player_move_1 = false;
			is_player_move_3 = false;
			is_player_move_5 = false;
			is_player_move_6 = false;
			is_player_move_7 = false;
			is_player_move_9 = false;
			is_player_move_10 = false;
			is_player_move_12 = false;
			is_player_arrow_1 = false;
			is_player_arrow_3 = false;
			is_player_arrow_5 = false;
			is_player_arrow_6 = true;
			is_player_arrow_7 = false;
			is_player_arrow_9 = false;
			is_player_arrow_10 = false;
			is_player_arrow_12 = false;
			break;
		case 7:
			is_player_move_12 = false;
			is_player_move_1 = false;
			is_player_move_3 = false;
			is_player_move_5 = false;
			is_player_move_6 = false;
			is_player_move_7 = false;
			is_player_move_9 = false;
			is_player_move_10 = false;
			is_player_move_12 = false;
			is_player_arrow_1 = false;
			is_player_arrow_3 = false;
			is_player_arrow_5 = false;
			is_player_arrow_6 = false;
			is_player_arrow_7 = true;
			is_player_arrow_9 = false;
			is_player_arrow_10 = false;
			is_player_arrow_12 = false;
			break;
		case 9:
			is_player_move_12 = false;
			is_player_move_1 = false;
			is_player_move_3 = false;
			is_player_move_5 = false;
			is_player_move_6 = false;
			is_player_move_7 = false;
			is_player_move_9 = false;
			is_player_move_10 = false;
			is_player_move_12 = false;
			is_player_arrow_1 = false;
			is_player_arrow_3 = false;
			is_player_arrow_5 = false;
			is_player_arrow_6 = false;
			is_player_arrow_7 = false;
			is_player_arrow_9 = true;
			is_player_arrow_10 = false;
			is_player_arrow_12 = false;
			break;
		case 10:
			is_player_move_12 = false;
			is_player_move_1 = false;
			is_player_move_3 = false;
			is_player_move_5 = false;
			is_player_move_6 = false;
			is_player_move_7 = false;
			is_player_move_9 = false;
			is_player_move_10 = false;
			is_player_move_12 = false;
			is_player_arrow_1 = false;
			is_player_arrow_3 = false;
			is_player_arrow_5 = false;
			is_player_arrow_6 = false;
			is_player_arrow_7 = false;
			is_player_arrow_9 = false;
			is_player_arrow_10 = true;
			is_player_arrow_12 = false;
			break;
		case 12:
			is_player_move_12 = false;
			is_player_move_1 = false;
			is_player_move_3 = false;
			is_player_move_5 = false;
			is_player_move_6 = false;
			is_player_move_7 = false;
			is_player_move_9 = false;
			is_player_move_10 = false;
			is_player_move_12 = false;
			is_player_arrow_1 = false;
			is_player_arrow_3 = false;
			is_player_arrow_5 = false;
			is_player_arrow_6 = false;
			is_player_arrow_7 = false;
			is_player_arrow_9 = false;
			is_player_arrow_10 = false;
			is_player_arrow_12 = true;
			break;
		}
	}
	if (isDamaged && !isAttackAni)
	{

		if (isDamaged)
		{
			isDamagedAni = true;

			if (m_playerPosX < toMonsterIndex.x && m_playerPosY > toMonsterIndex.y)playerArrow = 1;
			if (m_playerPosX < toMonsterIndex.x && m_playerPosY == toMonsterIndex.y)playerArrow = 3;
			if (m_playerPosX < toMonsterIndex.x && m_playerPosY < toMonsterIndex.y)playerArrow = 5;
			if (m_playerPosX == toMonsterIndex.x && m_playerPosY < toMonsterIndex.y)playerArrow = 6;
			if (m_playerPosX > toMonsterIndex.x && m_playerPosY < toMonsterIndex.y) playerArrow = 7;
			if (m_playerPosX > toMonsterIndex.x && m_playerPosY == toMonsterIndex.y)playerArrow = 9;
			if (m_playerPosX > toMonsterIndex.x && m_playerPosY > toMonsterIndex.y)playerArrow = 10;
			if (m_playerPosX == toMonsterIndex.x && m_playerPosY > toMonsterIndex.y)playerArrow = 12;

			if (isDamagedAni)
			{
				Damaged_count++;
			}
			if (Damaged_count >= 3)
			{
				isDamagedAni = false;
				isDamaged = false;
				Damaged_count = 0;
			}

			if (isDamagedAni)
			{
				is_player_move_12 = false;
				is_player_move_1 = false;
				is_player_move_3 = false;
				is_player_move_5 = false;
				is_player_move_6 = false;
				is_player_move_7 = false;
				is_player_move_9 = false;
				is_player_move_10 = false;
				is_player_move_12 = false;
				is_player_arrow_1 = false;
				is_player_arrow_3 = false;
				is_player_arrow_5 = false;
				is_player_arrow_6 = false;
				is_player_arrow_7 = false;
				is_player_arrow_9 = false;
				is_player_arrow_10 = false;
				is_player_arrow_12 = false;
				is_player_attackwait_1 = false;
				is_player_attackwait_5 = false;
				is_player_attackwait_7 = false;
				is_player_attackwait_10 = false;
				switch (playerArrow)
				{
				case 1:
					is_player_damaged_1 = true;
					is_player_damaged_5 = false;
					is_player_damaged_7 = false;
					is_player_damaged_10 = false;
					break;
				case 3:
					is_player_damaged_1 = false;
					is_player_damaged_5 = true;
					is_player_damaged_7 = false;
					is_player_damaged_10 = false;
					break;
				case 5:
					is_player_damaged_1 = false;
					is_player_damaged_5 = true;
					is_player_damaged_7 = false;
					is_player_damaged_10 = false;
					break;
				case 6:
					is_player_damaged_1 = false;
					is_player_damaged_5 = false;
					is_player_damaged_7 = true;
					is_player_damaged_10 = false;
					break;
				case 7:
					is_player_damaged_1 = false;
					is_player_damaged_5 = false;
					is_player_damaged_7 = true;
					is_player_damaged_10 = false;
					break;
				case 9:
					is_player_damaged_1 = false;
					is_player_damaged_5 = false;
					is_player_damaged_7 = true;
					is_player_damaged_10 = false;
					break;
				case 10:
					is_player_damaged_1 = false;
					is_player_damaged_5 = false;
					is_player_damaged_7 = false;
					is_player_damaged_10 = true;
					break;
				case 12:
					is_player_damaged_1 = false;
					is_player_damaged_5 = false;
					is_player_damaged_7 = false;
					is_player_damaged_10 = true;
					break;
				}
			}
		}

	}


	//길 이동
	if (isMove)
	{
		auto i = m_FindPath.begin();

		POINT FindPoint = { ((*i)->x), ((*i)->y) };
		POINT PlayerIndex = getPlayerTileIndex();

		if (PlayerIndex == FindPoint)
		{
			if (m_FindPath.size() > 2)
			{
				isBattle = false;
			}

			if (isMovetoMonster && m_FindPath.size() <= 2)
			{
				m_FindPath.clear();
				isMove = false;
				isMovetoMonster = false;
				isMoveComplete = true;
				isBattle = true;
			}

			else
			{
				m_Tiles[FindPoint.x + FindPoint.y * m_TileColEA].setisRoot(false);
				isMoveComplete = true;

				m_FindPath.pop_front();

				if (m_FindPath.size() <= 0)
				{
					isMove = false;
				}

			}
		}

		else if (PlayerIndex != FindPoint)
		{
			isMoveComplete = false;
			FindPoint = { ((*i)->x), ((*i)->y) };

			//좌방향 이동
			if (FindPoint.x < PlayerIndex.x && FindPoint.y == PlayerIndex.y)
			{

				is_player_move_12 = false;
				is_player_move_1 = false;
				is_player_move_3 = false;
				is_player_move_5 = false;
				is_player_move_6 = false;
				is_player_move_7 = false;
				is_player_move_10 = false;
				is_player_move_12 = false;
				is_player_arrow_1 = false;
				is_player_arrow_3 = false;
				is_player_arrow_5 = false;
				is_player_arrow_6 = false;
				is_player_arrow_7 = false;
				is_player_arrow_9 = false;
				is_player_arrow_10 = false;
				is_player_arrow_12 = false;
				is_player_move_9 = true;

				m_player.moveLeft(5 * cheat);
				playerArrow = 9;
			}
			///우방향 이동
			else if (FindPoint.x > PlayerIndex.x && FindPoint.y == PlayerIndex.y)
			{
				is_player_move_12 = false;
				is_player_move_1 = false;
				is_player_move_3 = true;
				is_player_move_5 = false;
				is_player_move_6 = false;
				is_player_move_7 = false;
				is_player_move_9 = false;
				is_player_move_10 = false;
				is_player_move_12 = false;
				is_player_arrow_1 = false;
				is_player_arrow_3 = false;
				is_player_arrow_5 = false;
				is_player_arrow_6 = false;
				is_player_arrow_7 = false;
				is_player_arrow_9 = false;
				is_player_arrow_10 = false;
				is_player_arrow_12 = false;
				m_player.moveRight(5 * cheat);
				playerArrow = 3;

			}
			//상방향 이동
			else if (FindPoint.x == PlayerIndex.x && FindPoint.y < PlayerIndex.y)
			{
				is_player_move_1 = false;
				is_player_move_3 = false;
				is_player_move_5 = false;
				is_player_move_6 = false;
				is_player_move_7 = false;
				is_player_move_9 = false;
				is_player_move_10 = false;
				is_player_move_12 = false;
				is_player_move_12 = true;
				is_player_arrow_1 = false;
				is_player_arrow_3 = false;
				is_player_arrow_5 = false;
				is_player_arrow_6 = false;
				is_player_arrow_7 = false;
				is_player_arrow_9 = false;
				is_player_arrow_10 = false;
				is_player_arrow_12 = false;
				m_player.moveUp(5 * cheat);
				playerArrow = 12;

			}
			//하방향 이동
			else if (FindPoint.x == PlayerIndex.x && FindPoint.y > PlayerIndex.y)
			{
				is_player_move_12 = false;
				is_player_move_1 = false;
				is_player_move_3 = false;
				is_player_move_5 = false;
				is_player_move_6 = true;
				is_player_move_7 = false;
				is_player_move_9 = false;
				is_player_move_10 = false;
				is_player_move_12 = false;
				is_player_arrow_1 = false;
				is_player_arrow_3 = false;
				is_player_arrow_5 = false;
				is_player_arrow_6 = false;
				is_player_arrow_7 = false;
				is_player_arrow_9 = false;
				is_player_arrow_10 = false;
				is_player_arrow_12 = false;
				m_player.moveDown(5 * cheat);
				playerArrow = 6;

			}
			//좌상방향 이동
			else if (FindPoint.x < PlayerIndex.x && FindPoint.y < PlayerIndex.y)
			{
				is_player_move_12 = false;
				is_player_move_1 = false;
				is_player_move_3 = false;
				is_player_move_5 = false;
				is_player_move_6 = false;
				is_player_move_7 = false;
				is_player_move_9 = false;
				is_player_move_10 = true;
				is_player_move_12 = false;
				is_player_arrow_1 = false;
				is_player_arrow_3 = false;
				is_player_arrow_5 = false;
				is_player_arrow_6 = false;
				is_player_arrow_7 = false;
				is_player_arrow_9 = false;
				is_player_arrow_10 = false;
				is_player_arrow_12 = false;
				m_player.moveLeft(3 * cheat);
				m_player.moveUp(3 * cheat);
				playerArrow = 10;

			}
			//좌하방향 이동
			else if (FindPoint.x < PlayerIndex.x && FindPoint.y > PlayerIndex.y)
			{
				is_player_move_12 = false;
				is_player_move_1 = false;
				is_player_move_3 = false;
				is_player_move_5 = false;
				is_player_move_6 = false;
				is_player_move_7 = true;
				is_player_move_9 = false;
				is_player_move_10 = false;
				is_player_move_12 = false;
				is_player_arrow_1 = false;
				is_player_arrow_3 = false;
				is_player_arrow_5 = false;
				is_player_arrow_6 = false;
				is_player_arrow_7 = false;
				is_player_arrow_9 = false;
				is_player_arrow_10 = false;
				is_player_arrow_12 = false;
				m_player.moveLeft(3 * cheat);
				m_player.moveDown(3 * cheat);
				playerArrow = 7;

			}
			//우상방향 이동
			else if (FindPoint.x > PlayerIndex.x && FindPoint.y < PlayerIndex.y)
			{
				is_player_move_12 = false;
				is_player_move_1 = true;
				is_player_move_3 = false;
				is_player_move_5 = false;
				is_player_move_6 = false;
				is_player_move_7 = false;
				is_player_move_9 = false;
				is_player_move_10 = false;
				is_player_move_12 = false;
				is_player_arrow_1 = false;
				is_player_arrow_3 = false;
				is_player_arrow_5 = false;
				is_player_arrow_6 = false;
				is_player_arrow_7 = false;
				is_player_arrow_9 = false;
				is_player_arrow_10 = false;
				is_player_arrow_12 = false;
				m_player.moveRight(3 * cheat);
				m_player.moveUp(3 * cheat);
				playerArrow = 1;

			}
			//우하방향 이동
			else if (FindPoint.x > PlayerIndex.x && FindPoint.y > PlayerIndex.y)
			{
				is_player_move_12 = false;
				is_player_move_1 = false;
				is_player_move_3 = false;
				is_player_move_5 = true;
				is_player_move_6 = false;
				is_player_move_7 = false;
				is_player_move_9 = false;
				is_player_move_10 = false;
				is_player_move_12 = false;
				is_player_arrow_1 = false;
				is_player_arrow_3 = false;
				is_player_arrow_5 = false;
				is_player_arrow_6 = false;
				is_player_arrow_7 = false;
				is_player_arrow_9 = false;
				is_player_arrow_10 = false;
				is_player_arrow_12 = false;
				m_player.moveRight(3 * cheat);
				m_player.moveDown(3 * cheat);
				playerArrow = 5;

			}
		}
	}


	if (isBattle)
	{
		is_player_move_12 = false;
		is_player_move_1 = false;
		is_player_move_3 = false;
		is_player_move_5 = false;
		is_player_move_6 = false;
		is_player_move_7 = false;
		is_player_move_9 = false;
		is_player_move_10 = false;
		is_player_move_12 = false;
		is_player_arrow_1 = false;
		is_player_arrow_3 = false;
		is_player_arrow_5 = false;
		is_player_arrow_6 = false;
		is_player_arrow_7 = false;
		is_player_arrow_9 = false;
		is_player_arrow_10 = false;
		is_player_arrow_12 = false;

		if (!isAttack)
		{
			is_player_attack_1 = false;
			is_player_attack_5 = false;
			is_player_attack_7 = false;
			is_player_attack_10 = false;

			switch (playerArrow)
			{
			case 1:
				is_player_attackwait_1 = true;
				is_player_attackwait_5 = false;
				is_player_attackwait_7 = false;
				is_player_attackwait_10 = false;

				break;
			case 3:
				is_player_attackwait_1 = false;
				is_player_attackwait_5 = true;
				is_player_attackwait_7 = false;
				is_player_attackwait_10 = false;
				break;
			case 5:
				is_player_attackwait_1 = false;
				is_player_attackwait_5 = true;
				is_player_attackwait_7 = false;
				is_player_attackwait_10 = false;
				break;
			case 6:
				is_player_attackwait_1 = false;
				is_player_attackwait_5 = true;
				is_player_attackwait_7 = false;
				is_player_attackwait_10 = false;
				break;
			case 7:
				is_player_attackwait_1 = false;
				is_player_attackwait_5 = false;
				is_player_attackwait_7 = true;
				is_player_attackwait_10 = false;
				break;
			case 9:
				is_player_attackwait_1 = false;
				is_player_attackwait_5 = false;
				is_player_attackwait_7 = true;
				is_player_attackwait_10 = false;
				break;
			case 10:
				is_player_attackwait_1 = false;
				is_player_attackwait_5 = false;
				is_player_attackwait_7 = false;
				is_player_attackwait_10 = true;
				break;
			case 12:
				is_player_attackwait_1 = false;
				is_player_attackwait_5 = false;
				is_player_attackwait_7 = false;
				is_player_attackwait_10 = true;
				break;
			}
		}

		else if (isAttack)
		{
			is_player_attackwait_1 = false;
			is_player_attackwait_5 = false;
			is_player_attackwait_7 = false;
			is_player_attackwait_10 = false;

			switch (playerArrow)
			{
			case 1:
				is_player_attack_1 = true;
				is_player_attack_5 = false;
				is_player_attack_7 = false;
				is_player_attack_10 = false;

				break;
			case 3:
				is_player_attack_1 = false;
				is_player_attack_5 = true;
				is_player_attack_7 = false;
				is_player_attack_10 = false;
				break;
			case 5:
				is_player_attack_1 = false;
				is_player_attack_5 = true;
				is_player_attack_7 = false;
				is_player_attack_10 = false;
				break;
			case 6:
				is_player_attack_1 = false;
				is_player_attack_5 = true;
				is_player_attack_7 = false;
				is_player_attack_10 = false;
				break;
			case 7:
				is_player_attack_1 = false;
				is_player_attack_5 = false;
				is_player_attack_7 = true;
				is_player_attack_10 = false;
				break;
			case 9:
				is_player_attack_1 = false;
				is_player_attack_5 = false;
				is_player_attack_7 = true;
				is_player_attack_10 = false;
				break;
			case 10:
				is_player_attack_1 = false;
				is_player_attack_5 = false;
				is_player_attack_7 = false;
				is_player_attack_10 = true;
				break;
			case 12:
				is_player_attack_1 = false;
				is_player_attack_5 = false;
				is_player_attack_7 = false;
				is_player_attack_10 = true;
				break;
			}
		}
	}
	if (!isBattle)
	{
		is_player_attackwait_1 = false;
		is_player_attackwait_5 = false;
		is_player_attackwait_7 = false;
		is_player_attackwait_10 = false;
		is_player_attack_1 = false;
		is_player_attack_5 = false;
		is_player_attack_7 = false;
		is_player_attack_10 = false;
	}


	if (isDest)
	{
		for (auto& tile : m_Tiles)
		{
			tile.setisRoot(false);
			tile.setisDest(false);
		}
		isMove = false;
	}


	for (int i = 0; i < m_Tiles.size(); ++i) {
		if (UTIL::isPointPointCollision({ m_Tiles[i].getabsTile().centerX,  m_Tiles[i].getabsTile().centerY }, { m_player.centerX,m_player.centerY }))
		{
			m_playerPosX = m_Tiles[i].m_BlockPositionX;
			m_playerPosY = m_Tiles[i].m_BlockPositionY;
			isDest = m_Tiles[i].isDest;
			break;
		}
	}
}

void character::Hp_Sp_mini_bar_setting()
{
	stat_mini_Hp_gaze = UTIL::IRectMake(m_outPlayer.left + 6, m_outPlayer.bottom, 50, 5);
	stat_mini_Hp_Cur_gaze = UTIL::IRectMake(m_outPlayer.left + 6, m_outPlayer.bottom, 50 * stat_Curhp / stat_Maxhp, 5);
	stat_mini_Sp_gaze = UTIL::IRectMake(m_outPlayer.left + 6, m_outPlayer.bottom + 5, 50, 5);
	stat_mini_Sp_Cur_gaze = UTIL::IRectMake(m_outPlayer.left + 6, m_outPlayer.bottom + 5, 50 * stat_Cursp / stat_Maxsp, 5);
}

void character::statSetting()
{
	stat_Hp_gaze = UTIL::IRectMake(base_ui_rect.left + 115, base_ui_rect.top + 22, 77 * stat_Curhp / stat_Maxhp, 8);
	stat_Sp_gaze = UTIL::IRectMake(base_ui_rect.left + 115, base_ui_rect.top + 43, 77 * stat_Cursp / stat_Maxsp, 8);
	//skill
	if (UTIL::isPointRectCollision(m_ptMouse, skill_ui_btn_rect))
	{
		isAddcursor = true;
		isSkill_btn = true;

	}
	else if (UTIL::isPointRectCollision(m_ptMouse, item_ui_btn_rect))
	{
		isAddcursor = true;
		isItem_btn = true;
	}
	else if (UTIL::isPointRectCollision(m_ptMouse, stat_ui_btn_rect))
	{
		isAddcursor = true;
		isStat_btn = true;
	}
	else
	{
		isAddcursor = false;
		isStat_btn = false;
		isSkill_btn = false;
		isItem_btn = false;
	}
	if (isSkill == false)
	{
		is_skill_icon_move = false;
	}

	if (isItem == false && KEYMANAGER->isOnceKeyDown(GAME_INVEN) && !is_chat)
	{
		isItem = true;
	}
	if (isItem_btn == true && isItem == false && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
	{
		isAddcursor_select = true;
		isItem = true;
	}
	if (isItem_btn == true && KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
	{
		isAddcursor_select = false;
	}
	if ((isItem == true && KEYMANAGER->isOnceKeyDown(GAME_INVEN) && !is_chat) || (UTIL::isPointRectCollision(m_ptMouse, item_ui_bar_cancle_rect) && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE)))
	{
		isAddcursor = false;
		isAddcursor_select = false;
		isItem_fix = false;
		isItem_first = true;
		isItem = false;
		is_item_icon_move = false;
		isIteminfoView = false;
		isUi = false;
	}
	if (isItem_btn == true && isItem == true && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
	{
		isAddcursor_select = true;
		isItem_fix = false;
		isItem_first = true;
		isItem = false;
		is_item_icon_move = false;
		isIteminfoView = false;
		isUi = false;
	}


	//item
	if (isItem)
	{
		if (isItem_first && !isItem_fix)
		{
			item_ui_rect = UTIL::IRectMake(item_memory_x, item_memory_y, 280, 200);
			item_ui_bar_rect = UTIL::IRectMake(item_ui_rect.left, item_ui_rect.top, 280, 17);
			item_ui_bar_cancle_rect = UTIL::IRectMake(item_ui_rect.left + 263, item_ui_rect.top + 4, 11, 11);
			item_use_rect = UTIL::IRectMake(item_ui_rect.left, item_ui_rect.top + 17, 20, 27);
			item_equip_rect = UTIL::IRectMake(item_ui_rect.left, item_ui_rect.top + 44, 20, 27);
			item_kind_rect = UTIL::IRectMake(item_ui_rect.left, item_ui_rect.top + 71, 20, 27);
		}


		if (UTIL::isPointRectCollision(m_ptMouse, item_ui_bar_rect) && !is_item_icon_move)
		{
			if (KEYMANAGER->isStayKeyDown(GAME_LMOUSE))
			{
				isItem_fix = false;
				isItem_first = false;
			}
		}
		if (!isItem_first && !isItem_fix && !is_item_icon_move)
		{
			item_alpha = 125;

			item_ui_rect = UTIL::IRectMake(m_ptMouse.x - 100, m_ptMouse.y - 10, 280, 200);
			item_ui_bar_rect = UTIL::IRectMake(item_ui_rect.left, item_ui_rect.top, 280, 17);
			item_ui_bar_cancle_rect = UTIL::IRectMake(item_ui_rect.left + 263, item_ui_rect.top + 4, 11, 11);
			item_use_rect = UTIL::IRectMake(item_ui_rect.left, item_ui_rect.top + 17, 20, 27);
			item_equip_rect = UTIL::IRectMake(item_ui_rect.left, item_ui_rect.top + 44, 20, 27);
			item_kind_rect = UTIL::IRectMake(item_ui_rect.left, item_ui_rect.top + 71, 20, 27);
			if (KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
			{
				isItem_fix = true;
				item_alpha = 255;
				item_memory_x = m_ptMouse.x - 100;
				item_memory_y = m_ptMouse.y - 10;
			}
		}
		if (isUi)
		{
			if (KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
			{
				isAddcursor_select = false;
			}
		}

		if (UTIL::isPointRectCollision(m_ptMouse, item_use_rect) && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
		{
			is_item_usetab = true;
			is_item_equiptab = false;
			is_item_kindtab = false;
		}
		else if (UTIL::isPointRectCollision(m_ptMouse, item_equip_rect) && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
		{
			is_item_usetab = false;
			is_item_equiptab = true;
			is_item_kindtab = false;
		}
		else if (UTIL::isPointRectCollision(m_ptMouse, item_kind_rect) && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
		{
			is_item_usetab = false;
			is_item_equiptab = false;
			is_item_kindtab = true;
		}



	}
	//


	if (isSkill == false && KEYMANAGER->isOnceKeyDown(GAME_SKILL) && !is_chat)
	{
		isSkill = true;
	}
	if (isSkill_btn == true && isSkill == false && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
	{
		isAddcursor_select = true;
		isSkill = true;
	}
	if (isSkill_btn == true && KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
	{
		isAddcursor_select = false;
	}
	if ((isSkill == true && KEYMANAGER->isOnceKeyDown(GAME_SKILL) && !is_chat) || (UTIL::isPointRectCollision(m_ptMouse, skill_ui_bar_cancle_rect) && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE)))
	{
		isAddcursor = false;
		isAddcursor_select = false;
		isSkill_fix = false;
		isSkill_first = true;
		isSkill = false;
		isUi = false;
	}
	if (isSkill_btn == true && isSkill == true && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
	{
		isAddcursor_select = true;
		isSkill_fix = false;
		isSkill_first = true;
		isSkill = false;
		isUi = false;
	}



	//stat
	if (isStat == false && KEYMANAGER->isOnceKeyDown(GAME_STAT) && !is_chat)
	{
		isStat = true;
		stat_alpha = 255;
	}
	if (isStat_btn == true && isStat == false && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
	{
		isAddcursor_select = true;
		isStat = true;
		stat_alpha = 255;
	}
	if (isStat_btn == true && KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
	{
		isAddcursor_select = false;
	}
	if ((isStat == true && KEYMANAGER->isOnceKeyDown(GAME_STAT) && !is_chat) || (UTIL::isPointRectCollision(m_ptMouse, stat_ui_bar_cancle_rect) && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE)))
	{
		isAddcursor = false;
		isAddcursor_select = false;
		isStat_fix = false;
		isStat_first = true;
		isStat = false;
		isUi = false;
		stat_alpha = 255;
	}
	if (isStat_btn == true && isStat == true && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
	{
		isAddcursor_select = true;
		isStat_fix = false;
		isStat_first = true;
		isStat = false;
		isUi = false;
		stat_alpha = 255;
	}

	if (isSkill)
	{
		if (isSkill_first && !isSkill_fix)
		{
			skill_ui_rect = UTIL::IRectMake(skill_memory_x, skill_memory_y, 280, 200);
			skill_ui_bar_rect = UTIL::IRectMake(skill_ui_rect.left, skill_ui_rect.top, 280, 17);
			skill_ui_bar_cancle_rect = UTIL::IRectMake(skill_ui_rect.left + 263, skill_ui_rect.top + 4, 11, 11);
		}


		if (UTIL::isPointRectCollision(m_ptMouse, skill_ui_bar_rect) && !is_skill_icon_move)
		{
			if (KEYMANAGER->isStayKeyDown(GAME_LMOUSE))
			{
				isSkill_fix = false;
				isSkill_first = false;
			}
		}
		if (!isSkill_first && !isSkill_fix)
		{
			skill_alpha = 125;

			skill_ui_rect = UTIL::IRectMake(m_ptMouse.x - 100, m_ptMouse.y - 10, 280, 200);
			skill_ui_bar_rect = UTIL::IRectMake(skill_ui_rect.left, skill_ui_rect.top, 280, 17);
			skill_ui_bar_cancle_rect = UTIL::IRectMake(skill_ui_rect.left + 263, skill_ui_rect.top + 4, 11, 11);

			if (KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
			{
				isSkill_fix = true;
				skill_alpha = 255;
				skill_memory_x = m_ptMouse.x - 100;
				skill_memory_y = m_ptMouse.y - 10;
			}
		}
		if (isUi)
		{
			if (KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
			{
				isAddcursor_select = false;
			}
		}
	}

	if (isRescu == true)
	{
		moveOk = false;

		if (isDie == true && Rescu_alpha <= 255)
		{
			Rescu_alpha += 2;
		}

		if (Rescu_alpha >= 255)
		{
			stat_Curhp = 9999;
			isDie = false;
		}

		if (isDie == false)
		{
			Rescu_alpha -= 2;

			if (Rescu_alpha <= 0)
			{
				m_playerPosX = 2;
				m_playerPosY = 3;

				stat_Curhp = 9999;
				moveOk = true;
				isUi = false;
				isBattle = false;
				isAttack = false;
				isMove = false;
				isRescu = false;
		
				
			}
		}
	}


	if (isDie)
	{
		if (isdie_first && !isdie_fix)
		{
			die_ui_rect = UTIL::IRectMake(die_memory_x, die_memory_y, 280, 200);
			die_ui_bar_rect = UTIL::IRectMake(die_ui_rect.left, die_ui_rect.top, 280, 17);
			die_ui_bar_cancle_rect = UTIL::IRectMake(die_ui_rect.left + 263, die_ui_rect.top + 4, 11, 11);

			die_ui_bar_recure_rect = UTIL::IRectMake(die_ui_rect.left + 40, die_ui_rect.top + 30, 200, 20);
		}

		if (UTIL::isPointRectCollision(m_ptMouse, die_ui_bar_recure_rect))
		{
			if (KEYMANAGER->isStayKeyDown(GAME_LMOUSE))
			{
				isRescu = true;
			}
		}




		if (UTIL::isPointRectCollision(m_ptMouse, die_ui_bar_rect))
		{
			if (KEYMANAGER->isStayKeyDown(GAME_LMOUSE))
			{
				isdie_fix = false;
				isdie_first = false;
			}
		}
		if (!isdie_first && !isdie_fix)
		{
			die_alpha = 125;

			die_ui_rect = UTIL::IRectMake(m_ptMouse.x - 100, m_ptMouse.y - 10, 280, 200);
			die_ui_bar_rect = UTIL::IRectMake(die_ui_rect.left, die_ui_rect.top, 280, 17);
			die_ui_bar_cancle_rect = UTIL::IRectMake(die_ui_rect.left + 263, die_ui_rect.top + 4, 11, 11);

			die_ui_bar_recure_rect = UTIL::IRectMake(die_ui_rect.left + 40, die_ui_rect.top + 30, 200, 20);
			if (KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
			{
				isdie_fix = true;
				die_alpha = 255;
				die_memory_x = m_ptMouse.x - 100;
				die_memory_y = m_ptMouse.y - 10;
			}
		}
		if (isUi)
		{
			if (KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
			{
				isAddcursor_select = false;
			}
		}
	}


	if (isStat)
	{
		if (isStat_first && !isStat_fix)
		{
			stat_ui_rect = UTIL::IRectMake(stat_memory_x, stat_memory_y, 280, 120);
			stat_ui_bar_rect = UTIL::IRectMake(stat_ui_rect.left, stat_ui_rect.top, 280, 17);
			stat_ui_bar_cancle_rect = UTIL::IRectMake(stat_ui_rect.left + 263, stat_ui_rect.top + 4, 11, 11);
		}


		if (UTIL::isPointRectCollision(m_ptMouse, stat_ui_bar_rect))
		{
			if (KEYMANAGER->isStayKeyDown(GAME_LMOUSE))
			{
				isStat_fix = false;
				isStat_first = false;
			}
		}
		if (!isStat_first && !isStat_fix)
		{
			stat_alpha = 125;

			stat_ui_rect = UTIL::IRectMake(m_ptMouse.x - 100, m_ptMouse.y - 10, 280, 120);
			stat_ui_bar_rect = UTIL::IRectMake(stat_ui_rect.left, stat_ui_rect.top, 280, 17);
			stat_ui_bar_cancle_rect = UTIL::IRectMake(stat_ui_rect.left + 263, stat_ui_rect.top + 4, 11, 11);

			if (KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
			{
				isStat_fix = true;
				stat_alpha = 255;
				stat_memory_x = m_ptMouse.x - 100;
				stat_memory_y = m_ptMouse.y - 10;
			}
		}
		if (isUi)
		{
			if (KEYMANAGER->isOnceKeyUp(GAME_LMOUSE))
			{
				isAddcursor_select = false;
			}
		}
		if (stat_point >= stat_str_need_point)
		{
			isStatAddStr = true;
			stat_add_str_btn_rect = UTIL::IRectMake(stat_ui_rect.left + 80, stat_ui_rect.top + 24, 11, 11);
			if (UTIL::isPointRectCollision(m_ptMouse, stat_add_str_btn_rect))
			{
				if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
				{
					isAddcursor_select = true;
					stat_str += 1;
					stat_point -= stat_str_need_point;
				}

			}
		}
		else isStatAddStr = false;
		if (stat_point >= stat_agi_need_point)
		{
			isStatAddAgi = true;
			stat_add_agi_btn_rect = UTIL::IRectMake(stat_ui_rect.left + 80, stat_ui_rect.top + 40, 11, 11);
			if (UTIL::isPointRectCollision(m_ptMouse, stat_add_agi_btn_rect))
			{
				if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
				{
					isAddcursor_select = true;
					stat_agi += 1;
					stat_point -= stat_agi_need_point;
				}
			}
		}
		else isStatAddAgi = false;
		if (stat_point >= stat_vit_need_point)
		{
			isStatAddVit = true;
			stat_add_vit_btn_rect = UTIL::IRectMake(stat_ui_rect.left + 80, stat_ui_rect.top + 56, 11, 11);
			if (UTIL::isPointRectCollision(m_ptMouse, stat_add_vit_btn_rect))
			{
				if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
				{
					isAddcursor_select = true;
					stat_vit += 1;
					stat_point -= stat_vit_need_point;
				}


			}

		}
		else isStatAddVit = false;
		if (stat_point >= stat_int_need_point)
		{
			isStatAddInt = true;
			stat_add_int_btn_rect = UTIL::IRectMake(stat_ui_rect.left + 80, stat_ui_rect.top + 72, 11, 11);
			if (UTIL::isPointRectCollision(m_ptMouse, stat_add_int_btn_rect))
			{
				if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
				{
					isAddcursor_select = true;
					stat_int += 1;
					stat_point -= stat_int_need_point;
				}

			}
		}
		else isStatAddInt = false;
		if (stat_point >= stat_dex_need_point)
		{
			isStatAddDex = true;
			stat_add_dex_btn_rect = UTIL::IRectMake(stat_ui_rect.left + 80, stat_ui_rect.top + 88, 11, 11);
			if (UTIL::isPointRectCollision(m_ptMouse, stat_add_dex_btn_rect))
			{
				if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
				{
					isAddcursor_select = true;
					stat_dex += 1;
					stat_point -= stat_dex_need_point;
				}

			}
		}
		else isStatAddDex = false;
		if (stat_point >= stat_luk_need_point)
		{
			isStatAddLuk = true;
			stat_add_luk_btn_rect = UTIL::IRectMake(stat_ui_rect.left + 80, stat_ui_rect.top + 104, 11, 11);
			if (UTIL::isPointRectCollision(m_ptMouse, stat_add_luk_btn_rect))
			{
				if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
				{
					isAddcursor_select = true;
					stat_luk += 1;
					stat_point -= stat_luk_need_point;
				}

			}
		}
		else isStatAddLuk = false;
		if ((UTIL::isPointRectCollision(m_ptMouse, stat_add_str_btn_rect)) || (UTIL::isPointRectCollision(m_ptMouse, stat_add_agi_btn_rect)) || (UTIL::isPointRectCollision(m_ptMouse, stat_add_vit_btn_rect)) || (UTIL::isPointRectCollision(m_ptMouse, stat_add_int_btn_rect)) || (UTIL::isPointRectCollision(m_ptMouse, stat_add_dex_btn_rect)) || (UTIL::isPointRectCollision(m_ptMouse, stat_add_luk_btn_rect)))
		{
			isAddcursor = true;
		}
		else isAddcursor = false;
	}


	//Exp setting
	stat_base_Cur_Exp_rect = UTIL::IRectMake(85, 77, 100 * stat_base_curExp / stat_base_MaxExp, 6);
	stat_job_Cur_Exp_rect = UTIL::IRectMake(85, 86, 100 * stat_job_curExp / stat_job_MaxExp, 6);

	if (stat_base_curExp >= stat_base_MaxExp)
	{
		isLevelup = true;

		stat_base_curExp -= stat_base_MaxExp;
		stat_base_level += 1;

		stat_point += stat_base_level * 1.5;

		stat_Curhp = stat_Maxhp * 1.2;
		stat_Cursp = stat_Maxsp * 1.2;
	}
	if (stat_job_curExp >= stat_job_MaxExp)
	{
		stat_job_curExp -= stat_job_MaxExp;

		stat_job_level += 1;
		stat_job_curExp = 0;
		skill_point += 1;


	}

	if (isLevelup == true)
	{
	
		levelup_cnt++;
		if (levelup_cnt == 2)
		{
			SOUNDMANAGER->playSound("levelup", Channel::eChannellevelup);
			iswing = true;
		}
		if (levelup_cnt == 4)
		{
			iswing = false;
		}
		if (levelup_cnt > 140)
		{
			SOUNDMANAGER->stopChannel(Channel::eChannellevelup);
			isLevelup = false;
			levelup_cnt = 0;
		}
	}

	//stat need point
	if (stat_str < 10)stat_str_need_point = 2;
	else if (stat_str >= 10 && stat_str < 20)stat_str_need_point = 3;
	else if (stat_str >= 20 && stat_str < 30)stat_str_need_point = 4;
	else if (stat_str >= 30 && stat_str < 40)stat_str_need_point = 5;
	else stat_str_need_point = 6;

	if (stat_agi < 10)stat_agi_need_point = 2;
	else if (stat_agi >= 10 && stat_agi < 20)stat_agi_need_point = 3;
	else if (stat_agi >= 20 && stat_agi < 30)stat_agi_need_point = 4;
	else if (stat_agi >= 30 && stat_agi < 40)stat_agi_need_point = 5;
	else stat_agi_need_point = 6;
	if (stat_vit < 10)stat_vit_need_point = 2;
	else if (stat_vit >= 10 && stat_vit < 20)stat_vit_need_point = 3;
	else if (stat_vit >= 20 && stat_vit < 30)stat_vit_need_point = 4;
	else if (stat_vit >= 30 && stat_vit < 40)stat_vit_need_point = 5;
	else stat_vit_need_point = 6;
	if (stat_int < 10)stat_int_need_point = 2;
	else if (stat_int >= 10 && stat_int < 20)stat_int_need_point = 3;
	else if (stat_int >= 20 && stat_int < 30)stat_int_need_point = 4;
	else if (stat_int >= 30 && stat_int < 40)stat_int_need_point = 5;
	else stat_int_need_point = 6;
	if (stat_dex < 10)stat_dex_need_point = 2;
	else if (stat_dex >= 10 && stat_dex < 20)stat_dex_need_point = 3;
	else if (stat_dex >= 20 && stat_dex < 30)stat_dex_need_point = 4;
	else if (stat_dex >= 30 && stat_dex < 40)stat_dex_need_point = 5;
	else stat_dex_need_point = 6;
	if (stat_luk < 10)stat_luk_need_point = 2;
	else if (stat_luk >= 10 && stat_luk < 20)stat_luk_need_point = 3;
	else if (stat_luk >= 20 && stat_luk < 30)stat_luk_need_point = 4;
	else if (stat_luk >= 30 && stat_luk < 40)stat_luk_need_point = 5;
	else stat_luk_need_point = 6;
	//

	//status 
	stat_base_MaxExp = 50 + stat_base_level * 15;
	stat_job_MaxExp = 10 + stat_job_level * 10;

	stat_Maxhp = 50 + stat_base_level * 5 + stat_vit * 5;
	stat_Maxsp = 50 + stat_base_level * 5 + stat_int * 8;

	if (stat_Curhp >= stat_Maxhp)
	{
		stat_Curhp = stat_Maxhp;
	}
	if (stat_Cursp >= stat_Maxsp)
	{
		stat_Cursp = stat_Maxsp;
	}
	if (stat_Curhp <= 0)
	{
		stat_Curhp = 0;
		isDie = true;
		if (isDie)
		{
			is_player_arrow_1 = false;
			is_player_arrow_3 = false;
			is_player_arrow_5 = false;
			is_player_arrow_6 = false;
			is_player_arrow_7 = false;
			is_player_arrow_9 = false;
			is_player_arrow_10 = false;
			is_player_arrow_12 = false;

			is_player_move_1 = false;
			is_player_move_3 = false;
			is_player_move_5 = false;
			is_player_move_6 = false;
			is_player_move_7 = false;
			is_player_move_9 = false;
			is_player_move_10 = false;
			is_player_move_12 = false;

			is_player_attack_1 = false;
			is_player_attack_5 = false;
			is_player_attack_7 = false;
			is_player_attack_10 = false;

			is_player_attackwait_1 = false;
			is_player_attackwait_5 = false;
			is_player_attackwait_7 = false;
			is_player_attackwait_10 = false;

			isDamaged = false;
			is_player_damaged_1 = false;
			is_player_damaged_5 = false;
			is_player_damaged_7 = false;
			is_player_damaged_10 = false;
		}
	}

	if (stat_Cursp <= 0)stat_Cursp = 0;


	stat_Maxweight = 500 + stat_str * 10;

	stat_atk = stat_str * 3 + equip_atk;
	stat_matk = stat_int * 3 + equip_matk;
	stat_def = stat_vit * 1 + equip_def;
	stat_mdef = stat_int * 1 + equip_mdef;
	stat_hit = stat_dex * 1 + equip_hit;
	stat_cri = stat_luk * 1 + equip_cri;
	stat_feel = stat_agi * 1 + equip_feel;
	stat_aspd = 100 + stat_agi / 2 + equip_aspd;

	aspd_Maxcount = 180 - stat_aspd;

	//end of stat setting
}
void character::uiSetting()
{

	//ui
	base_ui_rect = UTIL::IRectMake(0, 0, 280, 120);
	stat_ui_btn_rect = UTIL::IRectMake(207, 22, 30, 20);
	skill_ui_btn_rect = UTIL::IRectMake(242, 22, 30, 20);
	item_ui_btn_rect = UTIL::IRectMake(207, 48, 30, 20);
	choose_Bar = IMAGEMANAGER->findImage("choose_bar");
	chat_bg = IMAGEMANAGER->findImage("chat_bg");
	chat_on = IMAGEMANAGER->findImage("chat_on");
	npc_cursor_img = IMAGEMANAGER->findImage("npc_cursor");
	base_ui_img = IMAGEMANAGER->findImage("base_ui");
	ui_minicircle_off_img = IMAGEMANAGER->findImage("ui_minicircle_off");
	ui_minicircle_on_img = IMAGEMANAGER->findImage("ui_minicircle_on");
	stat_ui_img = IMAGEMANAGER->findImage("stat_ui");
	skill_ui_img = IMAGEMANAGER->findImage("skill_ui");
	die_ui_img = IMAGEMANAGER->findImage("die_ui");
	black_bg_ = IMAGEMANAGER->findImage("black_bg");

	ui_bar_img = IMAGEMANAGER->findImage("ui_bar");

	ui_bar_cancle_img = IMAGEMANAGER->findImage("ui_bar_cancle");
	stat_ui_btn_on_img = IMAGEMANAGER->findImage("stat_btn_on_ui");
	stat_ui_btn_off_img = IMAGEMANAGER->findImage("stat_btn_off_ui");
	stat_add_img = IMAGEMANAGER->findImage("ui_stat_add");
	skill_ui_btn_on_img = IMAGEMANAGER->findImage("skill_btn_on_ui");
	skill_ui_btn_off_img = IMAGEMANAGER->findImage("skill_btn_off_ui");
	skill_no_img = IMAGEMANAGER->findImage("skill_no_ui");

	item_ui_btn_on_img = IMAGEMANAGER->findImage("item_btn_on_ui");
	item_ui_btn_off_img = IMAGEMANAGER->findImage("item_btn_off_ui");
	Item_ui_potiontab_img = IMAGEMANAGER->findImage("tab_use");
	Item_ui_equiptab_img = IMAGEMANAGER->findImage("tab_equip");
	Item_ui_kindtab_img = IMAGEMANAGER->findImage("tab_kind");
	Item_ui_img = IMAGEMANAGER->findImage("item_ui");
	item_info_bar_cancle_img = IMAGEMANAGER->findImage("ui_info_bar_cancle");
	item_info_bar_img = IMAGEMANAGER->findImage("ui_info_bar");
	item_shadow_img = IMAGEMANAGER->findImage("item_shadow");

	quickslot_ui_rect = UTIL::IRectMake(281, 0, 77, 34);
	quickslot_1_ui_rect = UTIL::IRectMake(285, 4, 25, 25);
	quickslot_2_ui_rect = UTIL::IRectMake(315, 4, 25, 25);

	quickslot_item_ui_rect = UTIL::IRectMake(281, 35, 77, 34);
	quickslot_item_1_ui_rect = UTIL::IRectMake(285, 39, 25, 25);
	quickslot_item_2_ui_rect = UTIL::IRectMake(315, 39, 25, 25);

	quickslot_ui_img = IMAGEMANAGER->findImage("quickslot");
	quickslot_item_ui_img = IMAGEMANAGER->findImage("quickslot");

	player_shadow = IMAGEMANAGER->findImage("shadow_base");

	cursor_add = IMAGEMANAGER->findImage("cursor_add");
	cursor_add_select = IMAGEMANAGER->findImage("cursor_add_select");
	cursor_base = IMAGEMANAGER->findImage("cursor_base");
	cursor_attack = IMAGEMANAGER->findImage("cursor_attack");


	ANIMANAGER->addAnimation("cursor_base", "cursor_base", 0, 6, 10, false, true);
	ani_cursor_base = ANIMANAGER->findAnimation("cursor_base");

	ANIMANAGER->addAnimation("npc_cursor", "npc_cursor", 0, 8, 10, false, true);
	ani_cursor_npc = ANIMANAGER->findAnimation("npc_cursor");

	gaze_left = IMAGEMANAGER->findImage("ui_gaze_left");
	gaze_mid = IMAGEMANAGER->findImage("ui_gaze_mid");
	gaze_right = IMAGEMANAGER->findImage("ui_gaze_right");

	stat_base_Exp_rect = UTIL::IRectMake(85, 77, 100, 6);
	stat_job_Exp_rect = UTIL::IRectMake(85, 86, 100, 6);
	stat_base_Cur_Exp_rect = UTIL::IRectMake(85, 77, 0, 6);
	stat_job_Cur_Exp_rect = UTIL::IRectMake(85, 86, 0, 6);

	//stat init
	stat_point = 100;
	stat_str = 1;
	stat_agi = 1;
	stat_vit = 1;
	stat_int = 1;
	stat_dex = 1;
	stat_luk = 1;
	stat_Curhp = 65;
	stat_Cursp = 63;

	skill_point = 0;
	have_zeny = 10000;

	//
}

void character::playerImgSetting()
{
	wing_img = IMAGEMANAGER->findImage("wing");
	wing_wing_img = IMAGEMANAGER->findImage("wing_wing");

	player_body_base = IMAGEMANAGER->findImage("player_base");
	player_move_1 = IMAGEMANAGER->findImage("player_move_1");
	player_move_3 = IMAGEMANAGER->findImage("player_move_3");
	player_move_5 = IMAGEMANAGER->findImage("player_move_5");
	player_move_6 = IMAGEMANAGER->findImage("player_move_6");
	player_move_7 = IMAGEMANAGER->findImage("player_move_7");
	player_move_9 = IMAGEMANAGER->findImage("player_move_9");
	player_move_10 = IMAGEMANAGER->findImage("player_move_10");
	player_move_12 = IMAGEMANAGER->findImage("player_move_12");

	player_head_base = IMAGEMANAGER->findImage("player_head_base");
	player_head_move_1 = IMAGEMANAGER->findImage("player_head_move_1");
	player_head_move_3 = IMAGEMANAGER->findImage("player_head_move_3");
	player_head_move_5 = IMAGEMANAGER->findImage("player_head_move_5");
	player_head_move_6 = IMAGEMANAGER->findImage("player_head_move_6");
	player_head_move_7 = IMAGEMANAGER->findImage("player_head_move_7");
	player_head_move_9 = IMAGEMANAGER->findImage("player_head_move_9");
	player_head_move_10 = IMAGEMANAGER->findImage("player_head_move_10");
	player_head_move_12 = IMAGEMANAGER->findImage("player_head_move_12");

	player_head_damaged_1 = IMAGEMANAGER->findImage("player_head_damaged_1");
	player_head_damaged_5 = IMAGEMANAGER->findImage("player_head_damaged_5");
	player_head_damaged_7 = IMAGEMANAGER->findImage("player_head_damaged_7");
	player_head_damaged_10 = IMAGEMANAGER->findImage("player_head_damaged_10");

	player_attack_1 = IMAGEMANAGER->findImage("player_attack_1");
	player_attack_5 = IMAGEMANAGER->findImage("player_attack_5");
	player_attack_7 = IMAGEMANAGER->findImage("player_attack_7");
	player_attack_10 = IMAGEMANAGER->findImage("player_attack_10");
	player_attackwait_1 = IMAGEMANAGER->findImage("player_attackwait_1");
	player_attackwait_5 = IMAGEMANAGER->findImage("player_attackwait_5");
	player_attackwait_7 = IMAGEMANAGER->findImage("player_attackwait_7");
	player_attackwait_10 = IMAGEMANAGER->findImage("player_attackwait_10");

	player_damaged_1 = IMAGEMANAGER->findImage("player_damaged_1");
	player_damaged_5 = IMAGEMANAGER->findImage("player_damaged_5");
	player_damaged_7 = IMAGEMANAGER->findImage("player_damaged_7");
	player_damaged_10 = IMAGEMANAGER->findImage("player_damaged_10");

	player_die = IMAGEMANAGER->findImage("player_die");

	player_head_attack_1 = IMAGEMANAGER->findImage("player_head_attack_1");
	player_head_attack_5 = IMAGEMANAGER->findImage("player_head_attack_5");
	player_head_attack_7 = IMAGEMANAGER->findImage("player_head_attack_7");
	player_head_attack_10 = IMAGEMANAGER->findImage("player_head_attack_10");
	player_head_attackwait_1 = IMAGEMANAGER->findImage("player_head_attackwait_1");
	player_head_attackwait_5 = IMAGEMANAGER->findImage("player_head_attackwait_5");
	player_head_attackwait_7 = IMAGEMANAGER->findImage("player_head_attackwait_7");
	player_head_attackwait_10 = IMAGEMANAGER->findImage("player_head_attackwait_10");

	player_head_die = IMAGEMANAGER->findImage("player_head_die");

	weapon_wait_1 = IMAGEMANAGER->findImage("weapon_dangum_wait_1");
	weapon_wait_5 = IMAGEMANAGER->findImage("weapon_dangum_wait_5");
	weapon_wait_7 = IMAGEMANAGER->findImage("weapon_dangum_wait_7");
	weapon_wait_10 = IMAGEMANAGER->findImage("weapon_dangum_wait_10");

	weapon_attack_1 = IMAGEMANAGER->findImage("weapon_dangum_attack_1");
	weapon_attack_5 = IMAGEMANAGER->findImage("weapon_dangum_attack_5");
	weapon_attack_7 = IMAGEMANAGER->findImage("weapon_dangum_attack_7");
	weapon_attack_10 = IMAGEMANAGER->findImage("weapon_dangum_attack_10");

	playerArrow = 6;

	int player_arrow_1[] = { 0 };
	int player_arrow_3[] = { 1 };
	int player_arrow_5[] = { 2 };
	int player_arrow_6[] = { 3 };
	int player_arrow_7[] = { 4 };
	int player_arrow_9[] = { 5 };
	int player_arrow_10[] = { 6 };
	int player_arrow_12[] = { 7 };

	ANIMANAGER->addAnimation("wing", "wing", 0, 27, 10, false, false);
	ANIMANAGER->addAnimation("wing_wing", "wing_wing", 0, 25, 10, false, false);

	ANIMANAGER->addAnimation("player_arrow_1", "player_base", player_arrow_1, 1, 1, true);
	ANIMANAGER->addAnimation("player_arrow_3", "player_base", player_arrow_3, 1, 1, true);
	ANIMANAGER->addAnimation("player_arrow_5", "player_base", player_arrow_5, 1, 1, true);
	ANIMANAGER->addAnimation("player_arrow_6", "player_base", player_arrow_6, 1, 1, true);
	ANIMANAGER->addAnimation("player_arrow_7", "player_base", player_arrow_7, 1, 1, true);
	ANIMANAGER->addAnimation("player_arrow_9", "player_base", player_arrow_9, 1, 1, true);
	ANIMANAGER->addAnimation("player_arrow_10", "player_base", player_arrow_10, 1, 1, true);
	ANIMANAGER->addAnimation("player_arrow_12", "player_base", player_arrow_12, 1, 1, true);

	ANIMANAGER->addAnimation("player_head_arrow_1", "player_head_base", player_arrow_1, 1, 1, true);
	ANIMANAGER->addAnimation("player_head_arrow_3", "player_head_base", player_arrow_3, 1, 1, true);
	ANIMANAGER->addAnimation("player_head_arrow_5", "player_head_base", player_arrow_5, 1, 1, true);
	ANIMANAGER->addAnimation("player_head_arrow_6", "player_head_base", player_arrow_6, 1, 1, true);
	ANIMANAGER->addAnimation("player_head_arrow_7", "player_head_base", player_arrow_7, 1, 1, true);
	ANIMANAGER->addAnimation("player_head_arrow_9", "player_head_base", player_arrow_9, 1, 1, true);
	ANIMANAGER->addAnimation("player_head_arrow_10", "player_head_base", player_arrow_10, 1, 1, true);
	ANIMANAGER->addAnimation("player_head_arrow_12", "player_head_base", player_arrow_12, 1, 1, true);


	ANIMANAGER->addAnimation("player_move_1", "player_move_1", 0, 7, 10, false, true);
	ANIMANAGER->addAnimation("player_move_3", "player_move_3", 0, 7, 10, false, true);
	ANIMANAGER->addAnimation("player_move_5", "player_move_5", 0, 7, 10, false, true);
	ANIMANAGER->addAnimation("player_move_6", "player_move_6", 0, 7, 10, false, true);
	ANIMANAGER->addAnimation("player_move_7", "player_move_7", 0, 7, 10, false, true);
	ANIMANAGER->addAnimation("player_move_9", "player_move_9", 0, 7, 10, false, true);
	ANIMANAGER->addAnimation("player_move_10", "player_move_10", 0, 7, 10, false, true);
	ANIMANAGER->addAnimation("player_move_12", "player_move_12", 0, 7, 10, false, true);

	ANIMANAGER->addAnimation("player_head_move_1", "player_head_move_1", 0, 7, 10, false, true);
	ANIMANAGER->addAnimation("player_head_move_3", "player_head_move_3", 0, 7, 10, false, true);
	ANIMANAGER->addAnimation("player_head_move_5", "player_head_move_5", 0, 7, 10, false, true);
	ANIMANAGER->addAnimation("player_head_move_6", "player_head_move_6", 0, 7, 10, false, true);
	ANIMANAGER->addAnimation("player_head_move_7", "player_head_move_7", 0, 7, 10, false, true);
	ANIMANAGER->addAnimation("player_head_move_9", "player_head_move_9", 0, 7, 10, false, true);
	ANIMANAGER->addAnimation("player_head_move_10", "player_head_move_10", 0, 7, 10, false, true);
	ANIMANAGER->addAnimation("player_head_move_12", "player_head_move_12", 0, 7, 10, false, true);

	ANIMANAGER->addAnimation("player_attack_1", "player_attack_1", 0, 8, 10, false, false);
	ANIMANAGER->addAnimation("player_attack_5", "player_attack_5", 0, 8, 10, false, false);
	ANIMANAGER->addAnimation("player_attack_7", "player_attack_7", 0, 8, 10, false, false);
	ANIMANAGER->addAnimation("player_attack_10", "player_attack_10", 0, 8, 10, false, false);
	ANIMANAGER->addAnimation("player_attackwait_1", "player_attackwait_1", 0, 5, 10, false, true);
	ANIMANAGER->addAnimation("player_attackwait_5", "player_attackwait_5", 0, 5, 10, false, true);
	ANIMANAGER->addAnimation("player_attackwait_7", "player_attackwait_7", 0, 5, 10, false, true);
	ANIMANAGER->addAnimation("player_attackwait_10", "player_attackwait_10", 0, 5, 10, false, true);

	ANIMANAGER->addAnimation("player_damaged_1", "player_damaged_1", 0, 2, 3, false, false);
	ANIMANAGER->addAnimation("player_damaged_5", "player_damaged_5", 0, 2, 3, false, false);
	ANIMANAGER->addAnimation("player_damaged_7", "player_damaged_7", 0, 2, 3, false, false);
	ANIMANAGER->addAnimation("player_damaged_10", "player_damaged_10", 0, 2, 3, false, false);

	ANIMANAGER->addAnimation("player_die", "player_die", 0, 0, false, false);

	ANIMANAGER->addAnimation("player_head_attack_1", "player_head_attack_1", 0, 8, 10, false, false);
	ANIMANAGER->addAnimation("player_head_attack_5", "player_head_attack_5", 0, 8, 10, false, false);
	ANIMANAGER->addAnimation("player_head_attack_7", "player_head_attack_7", 0, 8, 10, false, false);
	ANIMANAGER->addAnimation("player_head_attack_10", "player_head_attack_10", 0, 8, 10, false, false);
	ANIMANAGER->addAnimation("player_head_attackwait_1", "player_head_attackwait_1", 0, 5, 10, false, true);
	ANIMANAGER->addAnimation("player_head_attackwait_5", "player_head_attackwait_5", 0, 5, 10, false, true);
	ANIMANAGER->addAnimation("player_head_attackwait_7", "player_head_attackwait_7", 0, 5, 10, false, true);
	ANIMANAGER->addAnimation("player_head_attackwait_10", "player_head_attackwait_10", 0, 5, 10, false, true);

	ANIMANAGER->addAnimation("player_head_damaged_1", "player_head_damaged_1", 0, 2, 3, false, false);
	ANIMANAGER->addAnimation("player_head_damaged_5", "player_head_damaged_5", 0, 2, 3, false, false);
	ANIMANAGER->addAnimation("player_head_damaged_7", "player_head_damaged_7", 0, 2, 3, false, false);
	ANIMANAGER->addAnimation("player_head_damaged_10", "player_head_damaged_10", 0, 2, 3, false, false);

	ANIMANAGER->addAnimation("player_head_die", "player_head_die", 0, 0, false, false);



	ANIMANAGER->addAnimation("weapon_wait_1", "weapon_dangum_wait_1", 0, 5, 10, false, true);
	ANIMANAGER->addAnimation("weapon_wait_5", "weapon_dangum_wait_5", 0, 5, 10, false, true);
	ANIMANAGER->addAnimation("weapon_wait_7", "weapon_dangum_wait_7", 0, 5, 10, false, true);
	ANIMANAGER->addAnimation("weapon_wait_10", "weapon_dangum_wait_10", 0, 5, 10, false, true);

	ANIMANAGER->addAnimation("weapon_attack_1", "weapon_dangum_attack_1", 0, 8, 10, false, false);
	ANIMANAGER->addAnimation("weapon_attack_5", "weapon_dangum_attack_5", 0, 8, 10, false, false);
	ANIMANAGER->addAnimation("weapon_attack_7", "weapon_dangum_attack_7", 0, 8, 10, false, false);
	ANIMANAGER->addAnimation("weapon_attack_10", "weapon_dangum_attack_10", 0, 8, 10, false, false);

	ani_wing = ANIMANAGER->findAnimation("wing");
	ani_wing_wing = ANIMANAGER->findAnimation("wing_wing");
	ani_player_attack_1 = ANIMANAGER->findAnimation("player_attack_1");
	ani_player_attack_5 = ANIMANAGER->findAnimation("player_attack_5");
	ani_player_attack_7 = ANIMANAGER->findAnimation("player_attack_7");
	ani_player_attack_10 = ANIMANAGER->findAnimation("player_attack_10");
	ani_player_attackwait_1 = ANIMANAGER->findAnimation("player_attackwait_1");
	ani_player_attackwait_5 = ANIMANAGER->findAnimation("player_attackwait_5");
	ani_player_attackwait_7 = ANIMANAGER->findAnimation("player_attackwait_7");
	ani_player_attackwait_10 = ANIMANAGER->findAnimation("player_attackwait_10");
	ani_player_damaged_1 = ANIMANAGER->findAnimation("player_damaged_1");
	ani_player_damaged_5 = ANIMANAGER->findAnimation("player_damaged_5");
	ani_player_damaged_7 = ANIMANAGER->findAnimation("player_damaged_7");
	ani_player_damaged_10 = ANIMANAGER->findAnimation("player_damaged_10");

	ani_player_head_attack_1 = ANIMANAGER->findAnimation("player_head_attack_1");
	ani_player_head_attack_5 = ANIMANAGER->findAnimation("player_head_attack_5");
	ani_player_head_attack_7 = ANIMANAGER->findAnimation("player_head_attack_7");
	ani_player_head_attack_10 = ANIMANAGER->findAnimation("player_head_attack_10");
	ani_player_head_attackwait_1 = ANIMANAGER->findAnimation("player_head_attackwait_1");
	ani_player_head_attackwait_5 = ANIMANAGER->findAnimation("player_head_attackwait_5");
	ani_player_head_attackwait_7 = ANIMANAGER->findAnimation("player_head_attackwait_7");
	ani_player_head_attackwait_10 = ANIMANAGER->findAnimation("player_head_attackwait_10");
	ani_player_head_damaged_1 = ANIMANAGER->findAnimation("player_head_damaged_1");
	ani_player_head_damaged_5 = ANIMANAGER->findAnimation("player_head_damaged_5");
	ani_player_head_damaged_7 = ANIMANAGER->findAnimation("player_head_damaged_7");
	ani_player_head_damaged_10 = ANIMANAGER->findAnimation("player_head_damaged_10");

	ani_player_arrow_1 = ANIMANAGER->findAnimation("player_arrow_1");
	ani_player_arrow_3 = ANIMANAGER->findAnimation("player_arrow_3");
	ani_player_arrow_5 = ANIMANAGER->findAnimation("player_arrow_5");
	ani_player_arrow_6 = ANIMANAGER->findAnimation("player_arrow_6");
	ani_player_arrow_7 = ANIMANAGER->findAnimation("player_arrow_7");
	ani_player_arrow_9 = ANIMANAGER->findAnimation("player_arrow_9");
	ani_player_arrow_10 = ANIMANAGER->findAnimation("player_arrow_10");
	ani_player_arrow_12 = ANIMANAGER->findAnimation("player_arrow_12");

	ani_player_head_arrow_1 = ANIMANAGER->findAnimation("player_head_arrow_1");
	ani_player_head_arrow_3 = ANIMANAGER->findAnimation("player_head_arrow_3");
	ani_player_head_arrow_5 = ANIMANAGER->findAnimation("player_head_arrow_5");
	ani_player_head_arrow_6 = ANIMANAGER->findAnimation("player_head_arrow_6");
	ani_player_head_arrow_7 = ANIMANAGER->findAnimation("player_head_arrow_7");
	ani_player_head_arrow_9 = ANIMANAGER->findAnimation("player_head_arrow_9");
	ani_player_head_arrow_10 = ANIMANAGER->findAnimation("player_head_arrow_10");
	ani_player_head_arrow_12 = ANIMANAGER->findAnimation("player_head_arrow_12");

	ani_player_move_1 = ANIMANAGER->findAnimation("player_move_1");
	ani_player_move_3 = ANIMANAGER->findAnimation("player_move_3");
	ani_player_move_5 = ANIMANAGER->findAnimation("player_move_5");
	ani_player_move_6 = ANIMANAGER->findAnimation("player_move_6");
	ani_player_move_7 = ANIMANAGER->findAnimation("player_move_7");
	ani_player_move_9 = ANIMANAGER->findAnimation("player_move_9");
	ani_player_move_10 = ANIMANAGER->findAnimation("player_move_10");
	ani_player_move_12 = ANIMANAGER->findAnimation("player_move_12");

	ani_player_head_move_1 = ANIMANAGER->findAnimation("player_head_move_1");
	ani_player_head_move_3 = ANIMANAGER->findAnimation("player_head_move_3");
	ani_player_head_move_5 = ANIMANAGER->findAnimation("player_head_move_5");
	ani_player_head_move_6 = ANIMANAGER->findAnimation("player_head_move_6");
	ani_player_head_move_7 = ANIMANAGER->findAnimation("player_head_move_7");
	ani_player_head_move_9 = ANIMANAGER->findAnimation("player_head_move_9");
	ani_player_head_move_10 = ANIMANAGER->findAnimation("player_head_move_10");
	ani_player_head_move_12 = ANIMANAGER->findAnimation("player_head_move_12");

	ani_weapon_wait_1 = ANIMANAGER->findAnimation("weapon_wait_1");
	ani_weapon_wait_5 = ANIMANAGER->findAnimation("weapon_wait_5");
	ani_weapon_wait_7 = ANIMANAGER->findAnimation("weapon_wait_7");
	ani_weapon_wait_10 = ANIMANAGER->findAnimation("weapon_wait_10");

	ani_weapon_attack_1 = ANIMANAGER->findAnimation("weapon_attack_1");
	ani_weapon_attack_5 = ANIMANAGER->findAnimation("weapon_attack_5");
	ani_weapon_attack_7 = ANIMANAGER->findAnimation("weapon_attack_7");
	ani_weapon_attack_10 = ANIMANAGER->findAnimation("weapon_attack_10");

}

void character::battleSetting()
{
	if (isBattle)
	{

		if (m_playerPosX < toMonsterIndex.x && m_playerPosY > toMonsterIndex.y)playerArrow = 1;
		if (m_playerPosX < toMonsterIndex.x && m_playerPosY == toMonsterIndex.y)playerArrow = 3;
		if (m_playerPosX < toMonsterIndex.x && m_playerPosY < toMonsterIndex.y)playerArrow = 5;
		if (m_playerPosX == toMonsterIndex.x && m_playerPosY < toMonsterIndex.y)playerArrow = 6;
		if (m_playerPosX > toMonsterIndex.x && m_playerPosY < toMonsterIndex.y) playerArrow = 7;
		if (m_playerPosX > toMonsterIndex.x && m_playerPosY == toMonsterIndex.y)playerArrow = 9;
		if (m_playerPosX > toMonsterIndex.x && m_playerPosY > toMonsterIndex.y)playerArrow = 10;
		if (m_playerPosX == toMonsterIndex.x && m_playerPosY > toMonsterIndex.y)playerArrow = 12;

		if (!isAttack && aspd_count < aspd_Maxcount)aspd_count++;
		if (!isAttack && aspd_count >= aspd_Maxcount)
		{
			isAttackAni = true;
			isAttack = true;
			aspd_count = 0;
		}
		if (isAttack)
		{

			attack_delay_count++;

			if (attack_delay_count >= 3)isAttackAni = false;

			if (attack_delay_count >= attack_delay)
			{
				isAttack = false;
				attack_delay_count = 0;
			}
		}
	}
	if (!isBattle)
	{
		aspd_count = 0;
		isAttackAni = false;
		isAttack = false;
		attack_delay_count = 0;
	}


}

TileType character::getTileType(POINT _XY)
{

	if (0 <= _XY.x && _XY.x <= m_TileColEA && 0 <= _XY.y && _XY.y <= m_TileRowEA)
	{
		return m_Tiles[_XY.x + _XY.y * m_TileColEA].m_Type;
	}
	else
	{
		return TileType::outrange;
	}

}

bool character::getisNpc(POINT _XY)
{

	if (0 <= _XY.x && _XY.x <= m_TileColEA && 0 <= _XY.y && _XY.y <= m_TileRowEA)
	{
		return m_Tiles[_XY.x + _XY.y * m_TileColEA].isNpc;
	}
	else
	{
		return false;
	}

}

void character::playerAnihandle()
{
	ANIMANAGER->resume("cursor_base");
	ANIMANAGER->resume("npc_cursor");

	if (is_player_arrow_1)
	{
		ANIMANAGER->resume("player_arrow_1");
		ANIMANAGER->resume("player_head_arrow_1");
	}
	else if (!is_player_arrow_1)
	{
		ANIMANAGER->pause("player_arrow_1");
		ANIMANAGER->pause("player_head_arrow_1");
	}
	if (is_player_arrow_3)
	{
		ANIMANAGER->resume("player_arrow_3");
		ANIMANAGER->resume("player_head_arrow_3");
	}
	else if (!is_player_arrow_3)
	{
		ANIMANAGER->pause("player_arrow_3");
		ANIMANAGER->pause("player_head_arrow_3");
	}
	if (is_player_arrow_5)
	{
		ANIMANAGER->resume("player_arrow_5");
		ANIMANAGER->resume("player_head_arrow_5");
	}
	else if (!is_player_arrow_5)
	{
		ANIMANAGER->pause("player_arrow_5");
		ANIMANAGER->pause("player_head_arrow_5");
	}
	if (is_player_arrow_6)
	{
		ANIMANAGER->resume("player_arrow_6");
		ANIMANAGER->resume("player_head_arrow_6");
	}
	else if (!is_player_arrow_6)
	{
		ANIMANAGER->pause("player_arrow_6");
		ANIMANAGER->pause("player_head_arrow_6");
	}
	if (is_player_arrow_7)
	{
		ANIMANAGER->resume("player_arrow_7");
		ANIMANAGER->resume("player_head_arrow_7");
	}
	else if (!is_player_arrow_7)
	{
		ANIMANAGER->pause("player_arrow_7");
		ANIMANAGER->pause("player_head_arrow_7");
	}
	if (is_player_arrow_9)
	{
		ANIMANAGER->resume("player_arrow_9");
		ANIMANAGER->resume("player_head_arrow_9");
	}
	else if (!is_player_arrow_9)
	{
		ANIMANAGER->pause("player_arrow_9");
		ANIMANAGER->pause("player_head_arrow_9");
	}
	if (is_player_arrow_10)
	{
		ANIMANAGER->resume("player_arrow_10");
		ANIMANAGER->resume("player_head_arrow_10");
	}
	else if (!is_player_arrow_10)
	{
		ANIMANAGER->pause("player_arrow_10");
		ANIMANAGER->pause("player_head_arrow_10");
	}
	if (is_player_arrow_12)
	{
		ANIMANAGER->resume("player_arrow_12");
		ANIMANAGER->resume("player_head_arrow_12");
	}
	else if (!is_player_arrow_12)
	{
		ANIMANAGER->pause("player_arrow_12");
		ANIMANAGER->pause("player_head_arrow_12");
	}

	if (is_player_move_1)
	{
		ANIMANAGER->resume("player_move_1");
		ANIMANAGER->resume("player_head_move_1");
	}
	else if (!is_player_move_1)
	{
		ANIMANAGER->pause("player_move_1");
		ANIMANAGER->pause("player_head_move_1");
	}
	if (is_player_move_3)
	{
		ANIMANAGER->resume("player_move_3");
		ANIMANAGER->resume("player_head_move_3");
	}
	else if (!is_player_move_3)
	{
		ANIMANAGER->pause("player_move_3");
		ANIMANAGER->pause("player_head_move_3");
	}
	if (is_player_move_5)
	{
		ANIMANAGER->resume("player_move_5");
		ANIMANAGER->resume("player_head_move_5");
	}
	else if (!is_player_move_5)
	{
		ANIMANAGER->pause("player_move_5");
		ANIMANAGER->pause("player_head_move_5");
	}
	if (is_player_move_6)
	{
		ANIMANAGER->resume("player_move_6");
		ANIMANAGER->resume("player_head_move_6");
	}
	else if (!is_player_move_6)
	{
		ANIMANAGER->pause("player_move_6");
		ANIMANAGER->pause("player_head_move_6");
	}
	if (is_player_move_7)
	{
		ANIMANAGER->resume("player_move_7");
		ANIMANAGER->resume("player_head_move_7");
	}
	else if (!is_player_move_7)
	{
		ANIMANAGER->pause("player_move_7");
		ANIMANAGER->pause("player_head_move_7");
	}
	if (is_player_move_9)
	{
		ANIMANAGER->resume("player_move_9");
		ANIMANAGER->resume("player_head_move_9");
	}
	else if (!is_player_move_9)
	{
		ANIMANAGER->pause("player_move_9");
		ANIMANAGER->pause("player_head_move_9");
	}
	if (is_player_move_10)
	{
		ANIMANAGER->resume("player_move_10");
		ANIMANAGER->resume("player_head_move_10");
	}
	else if (!is_player_move_10)
	{
		ANIMANAGER->pause("player_move_10");
		ANIMANAGER->pause("player_head_move_10");
	}
	if (is_player_move_12)
	{
		ANIMANAGER->resume("player_move_12");
		ANIMANAGER->resume("player_head_move_12");
	}
	else if (!is_player_move_12)
	{
		ANIMANAGER->pause("player_move_12");
		ANIMANAGER->pause("player_head_move_12");
	}

	if (is_player_attackwait_1)
	{
		ANIMANAGER->resume("player_attackwait_1");
		ANIMANAGER->resume("player_head_attackwait_1");
		ANIMANAGER->resume("weapon_wait_1");
	}
	else if (!is_player_attackwait_1)
	{
		ANIMANAGER->pause("player_attackwait_1");
		ANIMANAGER->pause("player_head_attackwait_1");
		ANIMANAGER->pause("weapon_wait_1");
	}
	if (is_player_attackwait_5)
	{
		ANIMANAGER->resume("player_attackwait_5");
		ANIMANAGER->resume("player_head_attackwait_5");
		ANIMANAGER->resume("weapon_wait_5");
	}
	else if (!is_player_attackwait_5)
	{
		ANIMANAGER->pause("player_attackwait_5");
		ANIMANAGER->pause("player_head_attackwait_5");
		ANIMANAGER->pause("weapon_wait_5");

	}
	if (is_player_attackwait_7)
	{
		ANIMANAGER->resume("player_attackwait_7");
		ANIMANAGER->resume("player_head_attackwait_7");
		ANIMANAGER->resume("weapon_wait_7");

	}
	else if (!is_player_attackwait_7)
	{
		ANIMANAGER->pause("player_attackwait_7");
		ANIMANAGER->pause("player_head_attackwait_7");
		ANIMANAGER->pause("weapon_wait_7");

	}
	if (is_player_attackwait_10)
	{
		ANIMANAGER->resume("player_attackwait_10");
		ANIMANAGER->resume("player_head_attackwait_10");
		ANIMANAGER->resume("weapon_wait_10");

	}
	else if (!is_player_attackwait_10)
	{
		ANIMANAGER->pause("player_attackwait_10");
		ANIMANAGER->pause("player_head_attackwait_10");
		ANIMANAGER->pause("weapon_wait_10");

	}
	if (is_player_attack_1)
	{
		if (isAttackAni)
		{
			ANIMANAGER->start("player_attack_1");
			ANIMANAGER->start("player_head_attack_1");
			ANIMANAGER->start("weapon_attack_1");
		}
	}
	else if (!is_player_attack_1)
	{
		ANIMANAGER->stop("player_attack_1");
		ANIMANAGER->stop("player_head_attack_1");
		ANIMANAGER->stop("weapon_attack_1");
	}
	if (is_player_attack_5)
	{
		if (isAttackAni)
		{
			ANIMANAGER->start("player_attack_5");
			ANIMANAGER->start("player_head_attack_5");
			ANIMANAGER->start("weapon_attack_5");
		}
	}
	else if (!is_player_attack_5)
	{
		ANIMANAGER->stop("player_attack_5");
		ANIMANAGER->stop("player_head_attack_5");
		ANIMANAGER->stop("weapon_attack_5");
	}
	if (is_player_attack_7)
	{
		if (isAttackAni)
		{
			ANIMANAGER->start("player_attack_7");
			ANIMANAGER->start("player_head_attack_7");
			ANIMANAGER->start("weapon_attack_7");
		}
	}
	else if (!is_player_attack_7)
	{
		ANIMANAGER->stop("player_attack_7");
		ANIMANAGER->stop("player_head_attack_7");
		ANIMANAGER->stop("weapon_attack_7");
	}
	if (is_player_attack_10)
	{
		if (isAttackAni)
		{
			ANIMANAGER->start("player_attack_10");
			ANIMANAGER->start("player_head_attack_10");
			ANIMANAGER->start("weapon_attack_10");
		}
	}
	else if (!is_player_attack_10)
	{
		ANIMANAGER->stop("player_attack_10");
		ANIMANAGER->stop("player_head_attack_10");
		ANIMANAGER->stop("weapon_attack_10");
	}

	if (is_player_damaged_1)
	{
		if (isDamagedAni)
		{
			ANIMANAGER->start("player_damaged_1");
			ANIMANAGER->start("player_head_damaged_1");
		}
	}
	else if (!is_player_damaged_1)
	{
		ANIMANAGER->stop("player_damaged_1");
		ANIMANAGER->stop("player_head_damaged_1");
	}
	if (is_player_damaged_5)
	{
		if (isDamagedAni)
		{
			ANIMANAGER->start("player_damaged_5");
			ANIMANAGER->start("player_head_damaged_5");
		}
	}
	else if (!is_player_damaged_5)
	{
		ANIMANAGER->stop("player_damaged_5");
		ANIMANAGER->stop("player_head_damaged_5");
	}
	if (is_player_damaged_7)
	{
		if (isDamagedAni)
		{
			ANIMANAGER->start("player_damaged_7");
			ANIMANAGER->start("player_head_damaged_7");
		}
	}
	else if (!is_player_damaged_7)
	{
		ANIMANAGER->stop("player_damaged_7");
		ANIMANAGER->stop("player_head_damaged_7");
	}
	if (is_player_damaged_10)
	{
		if (isDamagedAni)
		{
			ANIMANAGER->start("player_damaged_10");
			ANIMANAGER->start("player_head_damaged_10");
		}
	}
	else if (!is_player_damaged_10)
	{
		ANIMANAGER->stop("player_damaged_10");
		ANIMANAGER->stop("player_head_damaged_10");
	}
	if (isLevelup)
	{
		if (iswing)
		{
			ANIMANAGER->start("wing");
			ANIMANAGER->start("wing_wing");
		}
	}
	else if (!isLevelup)
	{
		ANIMANAGER->stop("wing");
		ANIMANAGER->stop("wing_wing");
	}


}

void character::setfocusCamera(UTIL::IRECT realRect)
{
	CAMERAMANAGER->setCameraFocus(&realRect.centerX, &realRect.centerY, WINSIZEX / 2, WINSIZEY / 2);

}


/////////////////////////////////////////////////////////
///// Astar::Node ///////////////////////////////////////
/////////////////////////////////////////////////////////
Astar::Node::Node(int _x, int _y, Astar::Node* _pParent, Coordinate _DestPoint)
{
	point.x = _x;
	point.y = _y;
	pParent = _pParent;
	DestPoint = _DestPoint;

	if (pParent == NULL)
	{
		G = 0;
	}
	else if (
		(pParent->point.x == point.x - 1 && pParent->point.y == point.y) || // 부모가 '상'방향에 있거나
		(pParent->point.x == point.x + 1 && pParent->point.y == point.y) || // 부모가 '하'방향에 있거나
		(pParent->point.x == point.x && pParent->point.y == point.y - 1) || // 부모가 '좌'방향에 있거나
		(pParent->point.x == point.x && pParent->point.y == point.y + 1)) // 부모가 '우'방향에 있으면		
	{
		G = pParent->G + 50;
	}
	else if ( // 대각선 방향인 경우
		(pParent->point.x == point.x - 1 && pParent->point.y == point.y - 1) || // 부모가 '좌상'방향에 있거나
		(pParent->point.x == point.x - 1 && pParent->point.y == point.y + 1) || // 부모가 '우상'방향에 있거나
		(pParent->point.x == point.x + 1 && pParent->point.y == point.y - 1) || // 부모가 '좌하'방향에 있거나
		(pParent->point.x == point.x + 1 && pParent->point.y == point.y + 1)) // 부모가 '우하'방향에 있으면
	{
		G = pParent->G + 70;
	}
	else {

	}
	H = (abs(DestPoint.x - point.x) + abs(DestPoint.y - point.y)) * 50;

	F = G + H;
}

Astar::Node::~Node()
{
}

bool Astar::Node::init()
{
	return S_OK;
}

void Astar::Node::update(float _deltaTime)
{
}

void Astar::Node::release()
{
}

void Astar::Node::render(HDC hdc)
{
}

void Astar::Node::afterRender(HDC hdc)
{
}

void Astar::Node::debugRender(HDC hdc)
{
}

/////////////////////////////////////////////////////////
///// Astar /////////////////////////////////////////////
/////////////////////////////////////////////////////////


Astar::~Astar()
{ // path 동적할당 해제
	iter = path.begin();
	for (; iter != path.end(); iter++)
	{
		delete* iter;
	}
}

std::list<Coordinate*> Astar::FindPath(Coordinate StartPoint, Coordinate EndPoint)
{
	// (상,우,하,좌) 4방향 시계방향 탐색 후 결과에 따라 (우상,우하,좌하,좌상) 탐색.	
	std::list<Node*> OpenNode; // 열린노드
	std::list<Node*> CloseNode; // 닫힌노드
	Node* SNode; // 선택된 노드
	std::list<Coordinate*> path;

	OpenNode.push_back(new Node(StartPoint.x, StartPoint.y, NULL, EndPoint)); // 시작지점을 열린노드에 추가

	std::list<Node*>::iterator iter;

	// 열린 노드가 비거나(열린노드의 시작==끝) 목적지에 도착(열린노드에서 값이 발견)한 경우 끝내야함
	// 즉 조건은 반대로 '열린 노드에 내용이 있거나 목적지를 못 찾은 경우' 반복
	while ((OpenNode.end() != OpenNode.begin()) && (OpenNode.end() == FindCoordNode(EndPoint.x, EndPoint.y, &OpenNode)))
	{
		iter = FindNextNode(&OpenNode); // 열린노드 중 F값이 제일 작은 노드의 주소를 찾아서 iter 에 저장
		SNode = *iter; // 열린노드 중 F값이 제일 작은 노드를 SNode에 저장

		// 선택된 SNode 주변의 8방향 노드 탐색, 값이 수정될 수 있는 것은 열린 노드 뿐이므로 열린 노드는 주소를 전달.
		ExploreNode(SNode, &OpenNode, &CloseNode, EndPoint);

		CloseNode.push_back(SNode); // 현재 탐색한 노드를 닫힌 노드에 추가
		OpenNode.erase(iter); // 닫힌 노드에 추가한 노드를 열린 노드에서 제거
	}

	if ((OpenNode.end() != OpenNode.begin())) // 길을 찾은 경우
	{
		iter = FindCoordNode(EndPoint.x, EndPoint.y, &OpenNode); // 목적지의 노드를 찾아서 iter에 저장
		for (SNode = *iter; SNode->pParent != NULL; SNode = SNode->pParent)  // 부모가 NULL일 때까지 path에 경로 저장
		{
			path.push_back(new Coordinate(SNode->point.x, SNode->point.y));
		}	path.push_back(new Coordinate(SNode->point.x, SNode->point.y)); // 부모가 NULL인 경우의 path까지 저장(출발 지점)

		path.reverse(); // 목적지점으부터 역순으로 입력했으므로 다시 역순으로 뒤집어 출발지점이 첫 번째가 되도록 함.

						// 길을 찾은 경우 동적할당 해제
		iter = OpenNode.begin();
		for (; iter != OpenNode.end(); iter++)
		{
			delete* iter; // 열린 노드 동적할당 해제
		}
		iter = CloseNode.begin();
		for (; iter != CloseNode.end(); iter++)
		{
			delete* iter; // 닫힌 노드 동적할당 해제
		}

		return path; // 길을 찾은 경우 리턴
	}

	// 길을 찾지 못한 경우 동적할당 해제
	iter = CloseNode.begin();
	for (; iter != CloseNode.end(); iter++)
	{
		delete* iter; // 닫힌 노드 동적할당 해제
	}
	path.clear();
	return path; // 길을 찾지 못한 경우 리턴

}

std::list<Astar::Node*>::iterator Astar::FindNextNode(std::list<Astar::Node*>* pOpenNode)
{
	std::list<Node*>::iterator iter = (*pOpenNode).begin();

	int minValue = 2000000000; // 현재 제일 작은 값을 저장
	int order = 0; // 제일 작은 값이 몇 번째인지

	for (int i = 1; iter != (*pOpenNode).end(); i++, iter++)
	{
		if ((*iter)->F <= minValue) // F값이 작거나 같은 경우를 발견하면(이렇게 구현 시 F값이 같은 경우 최근에 추가된 것이 우선)
		{
			minValue = (*iter)->F;
			order = i;
		}
	}

	iter = (*pOpenNode).begin();
	for (int i = 1; i < order; i++)
	{
		iter++;
	}

	return iter;
}

std::list<Astar::Node*>::iterator Astar::FindCoordNode(int _x, int _y, std::list<Astar::Node*>* NodeList)
{
	std::list<Astar::Node*>::iterator iter = NodeList->begin();

	for (int i = 1; iter != NodeList->end(); i++, iter++)
	{
		if ((*iter)->point.x == _x && (*iter)->point.y == _y)
		{
			return iter;
		}
	}

	return NodeList->end();
}

void Astar::ExploreNode(Astar::Node* SNode, std::list<Astar::Node*>* OpenNode, std::list<Astar::Node*>* CloseNode, Coordinate EndPoint)
{
	bool up = true, right = true, down = true, left = true; // 이 결과에 따라 대각선 방향 탐색 여부를 결정. true == 장애물 있음, false == 없음
	std::list<Node*>::iterator iter;
	POINT point;

	// '상' 방향 탐색
	point.x = SNode->point.x;	point.y = SNode->point.y - 1;
	if (SNode->point.y > 0 && getNodeTiletype({ point.x, point.y }) != TileType::wall) // '상' 방향에 맵이 존재하고 장애물이 없을 경우
	{
		// 장애물이 없는 경우에 해당하므로 장애물 false 세팅
		up = false;

		// 이미 열린 노드에 있는 경우
		if (OpenNode->end() != FindCoordNode(point.x, point.y, OpenNode))
		{
			iter = FindCoordNode(point.x, point.y, OpenNode);
			if ((*iter)->G > (SNode->G + 50)) // 원래 부모를 통해서 갔을 때의 비용보다 현재 노드를 통해서 갔을 때 비용이 더 낮아질 경우 
			{
				(*iter)->pParent = SNode; // 현재 노드를 부모로 바꿈
			}
		}

		// 닫힌 노드에 있는 경우
		else if (CloseNode->end() != FindCoordNode(point.x, point.y, CloseNode))
		{
		}

		// 상방향에 장애물이 없고 열린 노드 및 닫힌 노드에 추가되어있지 않은 경우
		// 상방향 노드를 열린 노드에 추가, 부모는 현재 탐색 노드로 지정.
		else
		{
			OpenNode->push_back(new Node(point.x, point.y, SNode, EndPoint));
		}
	}
	// '우' 방향 탐색
	point.x = SNode->point.x + 1;	point.y = SNode->point.y;
	if (SNode->point.x < (m_TileColEA - 1) && getNodeTiletype({ point.x, point.y }) != TileType::wall) // '우' 방향에 맵이 존재하고 장애물이 없을 경우
	{
		// 장애물이 없는 경우에 해당하므로 장애물 false 세팅
		right = false;

		// 이미 열린 노드에 있는 경우
		if (OpenNode->end() != FindCoordNode(point.x, point.y, OpenNode))
		{
			iter = FindCoordNode(point.x, point.y, OpenNode);
			if ((*iter)->G > (SNode->G + 50)) // 원래 부모를 통해서 갔을 때의 비용보다 현재 노드를 통해서 갔을 때 비용이 더 낮아질 경우 
			{
				(*iter)->pParent = SNode; // 현재 노드를 부모로 바꿈
			}
		}

		// 닫힌 노드에 있는 경우
		else if (CloseNode->end() != FindCoordNode(point.x, point.y, CloseNode))
		{
		}

		// 상방향에 장애물이 없고 열린 노드 및 닫힌 노드에 추가되어있지 않은 경우
		// 상방향 노드를 열린 노드에 추가, 부모는 현재 탐색 노드로 지정.
		else
		{
			OpenNode->push_back(new Node(point.x, point.y, SNode, EndPoint));
		}
	}
	// '하' 방향 탐색
	point.x = SNode->point.x;	point.y = SNode->point.y + 1;
	if (SNode->point.y < (m_TileRowEA - 1) && getNodeTiletype({ point.x, point.y }) != TileType::wall) // '하' 방향에 맵이 존재하고 장애물이 없을 경우
	{
		// 장애물이 없는 경우에 해당하므로 장애물 false 세팅
		down = false;

		// 이미 열린 노드에 있는 경우
		if (OpenNode->end() != FindCoordNode(point.x, point.y, OpenNode))
		{
			iter = FindCoordNode(point.x, point.y, OpenNode);
			if ((*iter)->G > (SNode->G + 50)) // 원래 부모를 통해서 갔을 때의 비용보다 현재 노드를 통해서 갔을 때 비용이 더 낮아질 경우 
			{
				(*iter)->pParent = SNode; // 현재 노드를 부모로 바꿈
			}
		}

		// 닫힌 노드에 있는 경우
		else if (CloseNode->end() != FindCoordNode(point.x, point.y, CloseNode))
		{
		}

		// 상방향에 장애물이 없고 열린 노드 및 닫힌 노드에 추가되어있지 않은 경우
		// 상방향 노드를 열린 노드에 추가, 부모는 현재 탐색 노드로 지정.
		else
		{
			OpenNode->push_back(new Node(point.x, point.y, SNode, EndPoint));
		}
	}
	// '좌' 방향 탐색
	point.x = SNode->point.x - 1;	point.y = SNode->point.y;
	if (SNode->point.x > 0 && getNodeTiletype({ point.x, point.y }) != TileType::wall) // '좌' 방향에 맵이 존재하고 장애물이 없을 경우
	{
		// 장애물이 없는 경우에 해당하므로 장애물 false 세팅
		left = false;

		// 이미 열린 노드에 있는 경우
		if (OpenNode->end() != FindCoordNode(point.x, point.y, OpenNode))
		{
			iter = FindCoordNode(point.x, point.y, OpenNode);
			if ((*iter)->G > (SNode->G + 50)) // 원래 부모를 통해서 갔을 때의 비용보다 현재 노드를 통해서 갔을 때 비용이 더 낮아질 경우 
			{
				(*iter)->pParent = SNode; // 현재 노드를 부모로 바꿈
			}
		}

		// 닫힌 노드에 있는 경우
		else if (CloseNode->end() != FindCoordNode(point.x, point.y, CloseNode))
		{
		}

		// 상방향에 장애물이 없고 열린 노드 및 닫힌 노드에 추가되어있지 않은 경우
		// 상방향 노드를 열린 노드에 추가, 부모는 현재 탐색 노드로 지정.
		else
		{
			OpenNode->push_back(new Node(point.x, point.y, SNode, EndPoint));
		}
	}


	// '우상' 방향 탐색
	point.x = SNode->point.x + 1;	point.y = SNode->point.y - 1;
	if (SNode->point.x < (m_TileColEA - 1) && SNode->point.y > 0 && getNodeTiletype({ point.x, point.y }) != TileType::wall &&
		up == false && right == false) // '우상' 방향에 맵이 존재하고 장애물이 없으며, 우방향과 상방향에도 장애물이 없을 경우
	{
		// 이미 열린 노드에 있는 경우
		if (OpenNode->end() != FindCoordNode(point.x, point.y, OpenNode))
		{
			iter = FindCoordNode(point.x, point.y, OpenNode);
			if ((*iter)->G > (SNode->G + 70)) // 원래 부모를 통해서 갔을 때의 비용보다 현재 노드를 통해서 갔을 때 비용이 더 낮아질 경우 
			{
				(*iter)->pParent = SNode; // 현재 노드를 부모로 바꿈
			}
		}

		// 닫힌 노드에 있는 경우
		else if (CloseNode->end() != FindCoordNode(point.x, point.y, CloseNode))
		{
		}

		// 상방향에 장애물이 없고 열린 노드 및 닫힌 노드에 추가되어있지 않은 경우
		// 상방향 노드를 열린 노드에 추가, 부모는 현재 탐색 노드로 지정.
		else
		{
			OpenNode->push_back(new Node(point.x, point.y, SNode, EndPoint));
		}
	}

	// '우하' 방향 탐색
	point.x = SNode->point.x + 1;	point.y = SNode->point.y + 1;
	if (SNode->point.x < (m_TileColEA - 1) && SNode->point.y < (m_TileRowEA - 1) &&
		getNodeTiletype({ point.x, point.y }) != TileType::wall && right == false && down == false)
		// '우하' 방향에 맵이 존재하고 장애물이 없으며, 우방향과 하방향에도 장애물이 없을 경우
	{
		// 이미 열린 노드에 있는 경우
		if (OpenNode->end() != FindCoordNode(point.x, point.y, OpenNode))
		{
			iter = FindCoordNode(point.x, point.y, OpenNode);
			if ((*iter)->G > (SNode->G + 70)) // 원래 부모를 통해서 갔을 때의 비용보다 현재 노드를 통해서 갔을 때 비용이 더 낮아질 경우 
			{
				(*iter)->pParent = SNode; // 현재 노드를 부모로 바꿈
			}
		}

		// 닫힌 노드에 있는 경우
		else if (CloseNode->end() != FindCoordNode(point.x, point.y, CloseNode))
		{
		}

		// 상방향에 장애물이 없고 열린 노드 및 닫힌 노드에 추가되어있지 않은 경우
		// 상방향 노드를 열린 노드에 추가, 부모는 현재 탐색 노드로 지정.
		else
		{
			OpenNode->push_back(new Node(point.x, point.y, SNode, EndPoint));
		}
	}
	// '좌하' 방향 탐색
	point.x = SNode->point.x - 1;	point.y = SNode->point.y + 1;
	if (SNode->point.x > 0 && SNode->point.y < (m_TileRowEA - 1) && getNodeTiletype({ point.x, point.y }) != TileType::wall &&
		left == false && down == false) // '좌하' 방향에 맵이 존재하고 장애물이 없으며, 좌방향과 하방향에도 장애물이 없을 경우
	{
		// 이미 열린 노드에 있는 경우
		if (OpenNode->end() != FindCoordNode(point.x, point.y, OpenNode))
		{
			iter = FindCoordNode(point.x, point.y, OpenNode);
			if ((*iter)->G > (SNode->G + 70)) // 원래 부모를 통해서 갔을 때의 비용보다 현재 노드를 통해서 갔을 때 비용이 더 낮아질 경우 
			{
				(*iter)->pParent = SNode; // 현재 노드를 부모로 바꿈
			}
		}

		// 닫힌 노드에 있는 경우
		else if (CloseNode->end() != FindCoordNode(point.x, point.y, CloseNode))
		{
		}

		// 상방향에 장애물이 없고 열린 노드 및 닫힌 노드에 추가되어있지 않은 경우
		// 상방향 노드를 열린 노드에 추가, 부모는 현재 탐색 노드로 지정.
		else
		{
			OpenNode->push_back(new Node(point.x, point.y, SNode, EndPoint));
		}
	}
	// '좌상' 방향 탐색
	point.x = SNode->point.x - 1;	point.y = SNode->point.y - 1;
	if (SNode->point.x > 0 && SNode->point.y > 0 && getNodeTiletype({ point.x, point.y }) != TileType::wall &&
		left == false && up == false) // '좌상' 방향에 맵이 존재하고 장애물이 없으며, 좌방향과 상방향에도 장애물이 없을 경우
	{
		// 이미 열린 노드에 있는 경우
		if (OpenNode->end() != FindCoordNode(point.x, point.y, OpenNode))
		{
			iter = FindCoordNode(point.x, point.y, OpenNode);
			if ((*iter)->G > (SNode->G + 70)) // 원래 부모를 통해서 갔을 때의 비용보다 현재 노드를 통해서 갔을 때 비용이 더 낮아질 경우 
			{
				(*iter)->pParent = SNode; // 현재 노드를 부모로 바꿈
			}
		}

		// 닫힌 노드에 있는 경우
		else if (CloseNode->end() != FindCoordNode(point.x, point.y, CloseNode))
		{
		}

		// 상방향에 장애물이 없고 열린 노드 및 닫힌 노드에 추가되어있지 않은 경우
		// 상방향 노드를 열린 노드에 추가, 부모는 현재 탐색 노드로 지정.
		else
		{
			OpenNode->push_back(new Node(point.x, point.y, SNode, EndPoint));
		}
	}


}


Coordinate Astar::GetPos(int order)
{
	Coordinate pos;
	for (int i = 1; i < order; i++)
	{
		iter++;
	}
	pos.x = (*iter)->x;
	pos.y = (*iter)->y;
	iter = path.begin();
	return pos;
}

void Astar::PrintNavi()
{
	for (int i = 0; iter != path.end(); iter++)
	{
		//cout << (*iter)->x << (*iter)->y << endl;
	}
	iter = path.begin(); // iter 값 원래대로 돌려주기
}

void Astar::PrintPath()
{

	for (auto i = 0; iter != path.end(); iter++) // 맵에서 경로에 해당하는 곳 표시
	{
		POINT tempPoint = { ((*iter)->x),((*iter)->y) };

		for (auto& tile : m_Tiles)
		{
			if (tile.getTileIndex() == tempPoint)
			{
				tile.setisRoot(true);
			}
		}
	}
	iter = path.begin(); // iter 값 원래대로 돌려주기
}

void Astar::PrintPath(std::list<Coordinate*> _path)
{
	iter = _path.begin();
	for (auto i = 0; iter != _path.end(); iter++) // 맵에서 경로에 해당하는 곳 표시
	{
		POINT tempPoint = { ((*iter)->x),((*iter)->y) };

		for (auto& tile : m_Tiles)
		{
			if (tile.getTileIndex() == tempPoint)
			{
				tile.setisRoot(true);
			}
		}
	}
}

TileType Astar::getNodeTiletype(POINT _XY)
{
	if (0 <= _XY.x && _XY.x < m_TileColEA && 0 <= _XY.y && _XY.y < m_TileRowEA)
	{
		return m_Tiles[_XY.x + _XY.y * (m_TileColEA)].m_Type;
	}
	else
	{
		return TileType::outrange;
	}
}


