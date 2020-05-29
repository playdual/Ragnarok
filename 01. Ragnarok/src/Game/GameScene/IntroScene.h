#pragma once
#include "Scene.h"
class IntroScene :
	public Scene
{

public:
	IntroScene()
	{}
	virtual	~IntroScene() {}


public:
	bool init() override;
	void release() override;

public:
	void update(float _deltaTime) override;
	void render(HDC hdc) override;
	void afterRender(HDC hdc) override;
	void debugRender(HDC hdc) override;


public:
	std::vector<std::string > name_vec;

	Image* BG_img;
	Image* Create_player_off_img;
	Image* Create_player_on_img;
	Image* cursor_base;
	Image* info_img;

	Image* stat_add_img;
	Image* reset_btn_img;
	Image* create_btn_img;

	Animation* ani_cursor_base;
	int i = 0;
	bool isTypingName = false;
	bool isCreatPlayer = false;
	bool isResetStat = false;
	bool ishavePlayer = false;
	bool isGameStart = false;

	UTIL::IRECT name_rect;

	UTIL::IRECT ChoosePlayer_rect;
	UTIL::IRECT Player_rect;
	UTIL::IRECT info_rect;
	UTIL::IRECT reset_rect;
	UTIL::IRECT create_player_rect;

	UTIL::IRECT stat_add_str_btn_rect;
	UTIL::IRECT stat_add_agi_btn_rect;
	UTIL::IRECT stat_add_vit_btn_rect;
	UTIL::IRECT stat_add_int_btn_rect;
	UTIL::IRECT stat_add_dex_btn_rect;
	UTIL::IRECT stat_add_luk_btn_rect;

	int stat_str = 1;
	int stat_agi = 1;
	int stat_vit = 1;
	int stat_int = 1;
	int stat_dex = 1;
	int stat_luk = 1;

	int stat_str_need_point = 1;
	int stat_agi_need_point = 1;
	int stat_vit_need_point = 1;
	int stat_int_need_point = 1;
	int stat_dex_need_point = 1;
	int stat_luk_need_point = 1;


	bool isStatAddStr = false;
	bool isStatAddAgi = false;
	bool isStatAddVit = false;
	bool isStatAddInt = false;
	bool isStatAddDex = false;
	bool isStatAddLuk = false;

	int stat_Maxhp;
	int stat_Maxsp;

	int stat_base_curExp = 0;
	int stat_job_curExp = 0;

	int stat_point = 10;


	int player_Arrow_count = 0;
	//player

	Image* player_body_base;
	Image* player_head_base;

	UTIL::IRECT m_outPlayer;

	Animation* ani_player_arrow_1;
	Animation* ani_player_arrow_3;
	Animation* ani_player_arrow_5;
	Animation* ani_player_arrow_6;
	Animation* ani_player_arrow_7;
	Animation* ani_player_arrow_9;
	Animation* ani_player_arrow_10;
	Animation* ani_player_arrow_12;

	Animation* ani_player_head_arrow_1;
	Animation* ani_player_head_arrow_3;
	Animation* ani_player_head_arrow_5;
	Animation* ani_player_head_arrow_6;
	Animation* ani_player_head_arrow_7;
	Animation* ani_player_head_arrow_9;
	Animation* ani_player_head_arrow_10;
	Animation* ani_player_head_arrow_12;

	bool is_player_arrow_1 = false;
	bool is_player_arrow_3 = false;
	bool is_player_arrow_5 = false;
	bool is_player_arrow_6 = false;
	bool is_player_arrow_7 = false;
	bool is_player_arrow_9 = false;
	bool is_player_arrow_10 = false;
	bool is_player_arrow_12 = false;

	std::string underbar;
	std::string name_temp;

	Image* black_bg;

	int startalpha = 0;

	float curtime = 0;
};