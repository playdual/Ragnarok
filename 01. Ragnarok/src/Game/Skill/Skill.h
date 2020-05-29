#pragma once
#include "SystemManager/ImageManager.h"
struct skill_struct
{

	std::string skill_name;
	bool skill_isActive;
	UTIL::IRECT skill_icon_rect;
	UTIL::IRECT skill_point_plus_rect;
	UTIL::IRECT skill_des_rect;
	Image* skill_icon_image;
	Image* skill_point_plus_image;
	Image* skill_des_image;
	int skill_curLevel;
	int skill_maxLevel;
	int skill_sp;
	int skill_effect;


	std::string skill_des;

};


class Skill
{
public:
	void init();
	void release();
	void update();

	void user_Skill(std::string _jobName);

	std::vector<skill_struct> player_skill;

	int intro_str;
	int intro_agi;
	int intro_vit;
	int intro_int;
	int intro_dex;
	int intro_luk;
	int intro_point;

	std::string player_name;

private:
	DECLARE_SINGLE(Skill)
};

#define SKILL Skill::GetInst()