#include "stdafx.h"
#include "IntroScene.h"
bool IntroScene::init()
{
	BG_img = IMAGEMANAGER->findImage("main_bg");
	Create_player_off_img = IMAGEMANAGER->findImage("create_player_off");
	Create_player_on_img = IMAGEMANAGER->findImage("create_player_on");
	cursor_base = IMAGEMANAGER->findImage("cursor_base");
	info_img = IMAGEMANAGER->findImage("main_info");
	reset_btn_img = IMAGEMANAGER->findImage("reset_Btn");
	create_btn_img = IMAGEMANAGER->findImage("create_Btn");
	ANIMANAGER->addAnimation("cursor_base", "cursor_base", 0, 6, 10, false, true);
	ani_cursor_base = ANIMANAGER->findAnimation("cursor_base");
	stat_add_img = IMAGEMANAGER->findImage("ui_stat_add");

	black_bg = IMAGEMANAGER->findImage("black_bg");

	player_body_base = IMAGEMANAGER->findImage("player_base");
	player_head_base = IMAGEMANAGER->findImage("player_head_base");

	is_player_arrow_6 = true;

	int player_arrow_1[] = { 0 };
	int player_arrow_3[] = { 1 };
	int player_arrow_5[] = { 2 };
	int player_arrow_6[] = { 3 };
	int player_arrow_7[] = { 4 };
	int player_arrow_9[] = { 5 };
	int player_arrow_10[] = { 6 };
	int player_arrow_12[] = { 7 };

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

	return true;
};
void IntroScene::update(float _deltaTime)
{


	if (isCreatPlayer == false && ishavePlayer == false)
	{
		ChoosePlayer_rect = UTIL::IRectMake(400, 350, 241, 295);
		if (UTIL::isPointRectCollision(m_ptMouse, ChoosePlayer_rect) && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
		{
			isCreatPlayer = true;
		}
	}

	if (isGameStart)
	{
		startalpha+=2;

		if (startalpha >= 255)
		{

			SKILL->intro_str = stat_str;
			SKILL->intro_agi = stat_agi;
			SKILL->intro_vit = stat_vit;
			SKILL->intro_int = stat_int;
			SKILL->intro_dex = stat_dex;
			SKILL->intro_luk = stat_luk;
			SKILL->intro_point = stat_point * 2;
			SOUNDMANAGER->stopChannel(Channel::eChannelBgm);
			SCENEMANAGER->changeScene("Sample");

		}
	}

	if (isCreatPlayer == true && ishavePlayer == true)
	{
		ChoosePlayer_rect = UTIL::IRectMake(400, 350, 241, 295);
		m_outPlayer = UTIL::IRectMake(495, 525, 60, 60);
		
	

		isTypingName = false;
		if (UTIL::isPointRectCollision(m_ptMouse, ChoosePlayer_rect) && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
		{
			isGameStart = true;
		}
	}

	if (isCreatPlayer == true && ishavePlayer == false)
	{
		Player_rect = UTIL::IRectMake(300, 350, 255, 312);
		m_outPlayer = UTIL::IRectMake(395, 525, 60, 60);
		info_rect = UTIL::IRectMake(600, 350, 172, 312);
		reset_rect = UTIL::IRectMake(info_rect.left + 28, info_rect.top + 291, 30, 12);
		create_player_rect = UTIL::IRectMake(703, 670, 68, 20);

		name_rect = UTIL::IRectMake(316, 616, 220, 30);
		if (UTIL::isPointRectCollision(m_ptMouse, name_rect))
		{
			if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
			{
				isTypingName = true;
			}
		}

		if (isTypingName == true)
		{
			curtime += 0.1f;

			if (curtime < 0.8)
			{
				underbar = "";
			}
			else if (curtime > 0.8 && curtime <1.6)
			{
				underbar = "_";
			}
			else if (curtime > 1.6)
			{
				curtime = 0;
			}

			if (KEYMANAGER->isOnceKeyDown(GAME_SPACE))
			{
				name_vec.push_back(" ");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_A))
			{
				name_vec.push_back("A");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_B))
			{
				name_vec.push_back("B");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_C))
			{
				name_vec.push_back("C");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_D))
			{
				name_vec.push_back("D");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_E))
			{
				name_vec.push_back("E");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_F))
			{
				name_vec.push_back("F");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_G))
			{
				name_vec.push_back("G");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_H))
			{
				name_vec.push_back("H");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_I))
			{
				name_vec.push_back("I");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_J))
			{
				name_vec.push_back("J");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_K))
			{
				name_vec.push_back("K");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_L))
			{
				name_vec.push_back("L");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_M))
			{
				name_vec.push_back("M");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_N))
			{
				name_vec.push_back("N");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_O))
			{
				name_vec.push_back("O");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_P))
			{
				name_vec.push_back("P");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_Q))
			{
				name_vec.push_back("Q");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_R))
			{
				name_vec.push_back("R");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_S))
			{
				name_vec.push_back("S");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_T))
			{
				name_vec.push_back("T");
			}if (KEYMANAGER->isOnceKeyDown(GAME_U))
			{
				name_vec.push_back("U");
			}if (KEYMANAGER->isOnceKeyDown(GAME_V))
			{
				name_vec.push_back("V");
			}if (KEYMANAGER->isOnceKeyDown(GAME_W))
			{
				name_vec.push_back("W");
			}if (KEYMANAGER->isOnceKeyDown(GAME_X))
			{
				name_vec.push_back("X");
			}if (KEYMANAGER->isOnceKeyDown(GAME_Y))
			{
				name_vec.push_back("Y");
			}if (KEYMANAGER->isOnceKeyDown(GAME_Z))
			{
				name_vec.push_back("Z");
			}
			if (KEYMANAGER->isOnceKeyDown(GAME_BACK))
			{
				if (name_vec.size() > 0)name_vec.pop_back();

			}
		}



		player_Arrow_count++;

		if (player_Arrow_count == 40)
		{
			is_player_arrow_1 = false;
			is_player_arrow_3 = false;
			is_player_arrow_5 = false;
			is_player_arrow_6 = true;
			is_player_arrow_7 = false;
			is_player_arrow_9 = false;
			is_player_arrow_10 = false;
			is_player_arrow_12 = false;
		}
		else if (player_Arrow_count == 80)
		{
			is_player_arrow_1 = false;
			is_player_arrow_3 = false;
			is_player_arrow_5 = false;
			is_player_arrow_6 = false;
			is_player_arrow_7 = true;
			is_player_arrow_9 = false;
			is_player_arrow_10 = false;
			is_player_arrow_12 = false;
		}
		else if (player_Arrow_count == 120)
		{
			is_player_arrow_1 = false;
			is_player_arrow_3 = false;
			is_player_arrow_5 = false;
			is_player_arrow_6 = false;
			is_player_arrow_7 = false;
			is_player_arrow_9 = true;
			is_player_arrow_10 = false;
			is_player_arrow_12 = false;
		}
		else if (player_Arrow_count == 160)
		{
			is_player_arrow_1 = false;
			is_player_arrow_3 = false;
			is_player_arrow_5 = false;
			is_player_arrow_6 = false;
			is_player_arrow_7 = false;
			is_player_arrow_9 = false;
			is_player_arrow_10 = true;
			is_player_arrow_12 = false;
		}
		else if (player_Arrow_count == 200)
		{
			is_player_arrow_1 = false;
			is_player_arrow_3 = false;
			is_player_arrow_5 = false;
			is_player_arrow_6 = false;
			is_player_arrow_7 = false;
			is_player_arrow_9 = false;
			is_player_arrow_10 = false;
			is_player_arrow_12 = true;
		}
		else if (player_Arrow_count == 240)
		{
			is_player_arrow_1 = true;
			is_player_arrow_3 = false;
			is_player_arrow_5 = false;
			is_player_arrow_6 = false;
			is_player_arrow_7 = false;
			is_player_arrow_9 = false;
			is_player_arrow_10 = false;
			is_player_arrow_12 = false;
		}
		else if (player_Arrow_count == 280)
		{
			is_player_arrow_1 = false;
			is_player_arrow_3 = true;
			is_player_arrow_5 = false;
			is_player_arrow_6 = false;
			is_player_arrow_7 = false;
			is_player_arrow_9 = false;
			is_player_arrow_10 = false;
			is_player_arrow_12 = false;
		}
		else if (player_Arrow_count == 320)
		{
			is_player_arrow_1 = false;
			is_player_arrow_3 = false;
			is_player_arrow_5 = true;
			is_player_arrow_6 = false;
			is_player_arrow_7 = false;
			is_player_arrow_9 = false;
			is_player_arrow_10 = false;
			is_player_arrow_12 = false;
			player_Arrow_count = 0;
		}



		if (UTIL::isPointRectCollision(m_ptMouse, reset_rect) && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
		{
			stat_str = 1;
			stat_agi = 1;
			stat_vit = 1;
			stat_int = 1;
			stat_dex = 1;
			stat_luk = 1;
			stat_point = 10;
		}

		if (UTIL::isPointRectCollision(m_ptMouse, create_player_rect) && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
		{
			is_player_arrow_1 = false;
			is_player_arrow_3 = false;
			is_player_arrow_5 = false;
			is_player_arrow_6 = true;
			is_player_arrow_7 = false;
			is_player_arrow_9 = false;
			is_player_arrow_10 = false;
			is_player_arrow_12 = false;
			
			for (auto name_itr = name_vec.begin(); name_itr != name_vec.end(); name_itr++)
			{
				SKILL->player_name += name_itr->c_str();
			}
			
			ishavePlayer = true;



		}


		if (stat_point >= stat_str_need_point)
		{
			isStatAddStr = true;
			stat_add_str_btn_rect = UTIL::IRectMake(info_rect.left + 80, info_rect.top + 191, 11, 11);
			if (UTIL::isPointRectCollision(m_ptMouse, stat_add_str_btn_rect))
			{
				if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
				{
					stat_str += 1;
					stat_point -= stat_str_need_point;
				}

			}
		}
		else isStatAddStr = false;
		if (stat_point >= stat_agi_need_point)
		{
			isStatAddAgi = true;
			stat_add_agi_btn_rect = UTIL::IRectMake(info_rect.left + 80, info_rect.top + 208, 11, 11);
			if (UTIL::isPointRectCollision(m_ptMouse, stat_add_agi_btn_rect))
			{
				if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
				{
					stat_agi += 1;
					stat_point -= stat_agi_need_point;
				}
			}
		}
		else isStatAddAgi = false;
		if (stat_point >= stat_vit_need_point)
		{
			isStatAddVit = true;
			stat_add_vit_btn_rect = UTIL::IRectMake(info_rect.left + 80, info_rect.top + 225, 11, 11);
			if (UTIL::isPointRectCollision(m_ptMouse, stat_add_vit_btn_rect))
			{
				if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
				{
					stat_vit += 1;
					stat_point -= stat_vit_need_point;
				}


			}

		}
		else isStatAddVit = false;
		if (stat_point >= stat_int_need_point)
		{
			isStatAddInt = true;
			stat_add_int_btn_rect = UTIL::IRectMake(info_rect.left + 80, info_rect.top + 242, 11, 11);
			if (UTIL::isPointRectCollision(m_ptMouse, stat_add_int_btn_rect))
			{
				if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
				{
					stat_int += 1;
					stat_point -= stat_int_need_point;
				}

			}
		}
		else isStatAddInt = false;
		if (stat_point >= stat_dex_need_point)
		{
			isStatAddDex = true;
			stat_add_dex_btn_rect = UTIL::IRectMake(info_rect.left + 80, info_rect.top + 259, 11, 11);
			if (UTIL::isPointRectCollision(m_ptMouse, stat_add_dex_btn_rect))
			{
				if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
				{
					stat_dex += 1;
					stat_point -= stat_dex_need_point;
				}

			}
		}
		else isStatAddDex = false;
		if (stat_point >= stat_luk_need_point)
		{
			isStatAddLuk = true;
			stat_add_luk_btn_rect = UTIL::IRectMake(info_rect.left + 80, info_rect.top + 276, 11, 11);
			if (UTIL::isPointRectCollision(m_ptMouse, stat_add_luk_btn_rect))
			{
				if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
				{
					stat_luk += 1;
					stat_point -= stat_luk_need_point;
				}

			}
		}
		else isStatAddLuk = false;


	}


	//stat
	stat_Maxhp = 50 + 10 + stat_vit * 5;
	stat_Maxsp = 50 + 5 + stat_int * 8;


	//player

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
};

void IntroScene::release()
{

};
void IntroScene::render(HDC hdc)
{
	BG_img->render(hdc, 0, 0);
	if (isCreatPlayer == false && ishavePlayer == false)
	{
		Create_player_off_img->render(hdc, ChoosePlayer_rect.left, ChoosePlayer_rect.top);
	}
	else if (isCreatPlayer == true && ishavePlayer == true)
	{
		Create_player_on_img->render(hdc, ChoosePlayer_rect.left, ChoosePlayer_rect.top);
		
		UTIL::PrintText(hdc, SKILL->player_name.c_str(), "", 700, ChoosePlayer_rect.centerX - SKILL->player_name.size() *5, ChoosePlayer_rect.bottom-27, 25, RGB(0, 0, 0), true, RGB(0, 0, 0));
	}
	else if (isCreatPlayer == true && ishavePlayer == false)
	{
		Create_player_on_img->render(hdc, Player_rect.left, Player_rect.top);
		info_img->render(hdc, info_rect.left, info_rect.top);
		reset_btn_img->render(hdc, reset_rect.left, reset_rect.top);
		create_btn_img->render(hdc, create_player_rect.left, create_player_rect.top);

		UTIL::DrawColorRect(hdc, name_rect, RGB(255, 255, 255));

		UTIL::PrintText(hdc, "리셋", "", reset_rect.left + 12, reset_rect.top + 3, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));

		UTIL::PrintText(hdc, "프론테라 마을입구", "", info_rect.left + 60, info_rect.top + 90, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "Novice", "", info_rect.left + 60, info_rect.top + 107, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "1", "", info_rect.left + 60, info_rect.top + 124, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "0", "", info_rect.left + 60, info_rect.top + 141, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		std::string curHP = std::to_string(stat_Maxhp);
		UTIL::PrintText(hdc, curHP.c_str(), "", info_rect.left + 60, info_rect.top + 157, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		std::string curSP = std::to_string(stat_Maxsp);
		UTIL::PrintText(hdc, curSP.c_str(), "", info_rect.left + 60, info_rect.top + 174, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		std::string curSTR = std::to_string(stat_str);
		UTIL::PrintText(hdc, curSTR.c_str(), "", info_rect.left + 60, info_rect.top + 191, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		std::string curAGI = std::to_string(stat_agi);
		UTIL::PrintText(hdc, curAGI.c_str(), "", info_rect.left + 60, info_rect.top + 208, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		std::string curVIT = std::to_string(stat_vit);
		UTIL::PrintText(hdc, curVIT.c_str(), "", info_rect.left + 60, info_rect.top + 225, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		std::string curINT = std::to_string(stat_int);
		UTIL::PrintText(hdc, curINT.c_str(), "", info_rect.left + 60, info_rect.top + 242, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		std::string curDEX = std::to_string(stat_dex);
		UTIL::PrintText(hdc, curDEX.c_str(), "", info_rect.left + 60, info_rect.top + 259, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));
		std::string curLUK = std::to_string(stat_luk);
		UTIL::PrintText(hdc, curLUK.c_str(), "", info_rect.left + 60, info_rect.top + 276, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));

		if (isStatAddStr) stat_add_img->render(hdc, stat_add_str_btn_rect.left, stat_add_str_btn_rect.top);
		if (isStatAddAgi) stat_add_img->render(hdc, stat_add_agi_btn_rect.left, stat_add_agi_btn_rect.top);
		if (isStatAddVit) stat_add_img->render(hdc, stat_add_vit_btn_rect.left, stat_add_vit_btn_rect.top);
		if (isStatAddInt) stat_add_img->render(hdc, stat_add_int_btn_rect.left, stat_add_int_btn_rect.top);
		if (isStatAddDex) stat_add_img->render(hdc, stat_add_dex_btn_rect.left, stat_add_dex_btn_rect.top);
		if (isStatAddLuk) stat_add_img->render(hdc, stat_add_luk_btn_rect.left, stat_add_luk_btn_rect.top);

		std::string curstat = "남은 포인트: " + std::to_string(stat_point);
		UTIL::PrintText(hdc, curstat.c_str(), "", info_rect.left + 80, info_rect.top + 294, 11, RGB(0, 0, 0), true, RGB(0, 0, 0));


	}

	//이름입력 표시

	i = 0;
	if (isTypingName)
	{
		if (name_vec.size() == 0)
		{
			UTIL::PrintText(hdc, underbar.c_str(), "", 700, name_rect.left + 10, name_rect.top, 25, RGB(0, 0, 0), true, RGB(0, 0, 0));
		}

		for (auto name_itr = name_vec.begin(); name_itr != name_vec.end(); name_itr++)
		{
			UTIL::PrintText(hdc, name_itr->c_str(), "", 700, name_rect.left + 5 + i * 14, name_rect.top, 25, RGB(0, 0, 0), true, RGB(0, 0, 0));

			i++;
		}

		UTIL::PrintText(hdc, underbar.c_str(), "", 700, name_rect.left + 5 + i * 14, name_rect.top, 25, RGB(0, 0, 0), true, RGB(0, 0, 0));
	}

	if ((isCreatPlayer == true && ishavePlayer == true)|| (isCreatPlayer == true && ishavePlayer == false))
	{
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
	}
	if(isGameStart)
	black_bg->alphaRender(hdc,0, 0, startalpha);


	/*else
	{
		Create_player_on_img->render(hdc, ChoosePlayer_rect.left, ChoosePlayer_rect.top);
	}*/
	ANIMANAGER->resume("cursor_base");
};
void IntroScene::afterRender(HDC hdc)
{
	cursor_base->aniRender(hdc, m_ptMouse.x, m_ptMouse.y, ani_cursor_base);


};
void IntroScene::debugRender(HDC hdc)
{

};