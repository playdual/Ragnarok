#include "stdafx.h"
#include "Game/Skill/Skill.h"
DEFINITION_SINGLE(Skill)


Skill::Skill() {}
Skill::~Skill() {}

void Skill::init()
{
}

void Skill::release()
{
}

void Skill::update()
{
}

void Skill::user_Skill(std::string _jobName)
{
	if (_jobName == "Novice")
	{
		skill_struct Novice_emergencyheal;

		Novice_emergencyheal.skill_name = "응급치료";
		Novice_emergencyheal.skill_isActive = true;
		Novice_emergencyheal.skill_icon_rect;
		Novice_emergencyheal.skill_point_plus_rect;
		Novice_emergencyheal.skill_des_rect;
		Novice_emergencyheal.skill_curLevel = 0;
		Novice_emergencyheal.skill_maxLevel = 1;
		Novice_emergencyheal.skill_icon_image = IMAGEMANAGER->findImage("Novice_emergencyheal");
		Novice_emergencyheal.skill_point_plus_image = IMAGEMANAGER->findImage("plus_btn");
		Novice_emergencyheal.skill_des_image = IMAGEMANAGER->findImage("skill_des_ui");
		Novice_emergencyheal.skill_sp = 5;
		Novice_emergencyheal.skill_effect = 15;
		Novice_emergencyheal.skill_des = "소량의 SP를 사용해 체력을 긴급히 회복한다.";

		player_skill.push_back(Novice_emergencyheal);

		skill_struct Novice_basefunction;

		Novice_basefunction.skill_name = "기본기능";
		Novice_basefunction.skill_isActive = false;
		Novice_basefunction.skill_icon_rect;
		Novice_basefunction.skill_point_plus_rect;
		Novice_basefunction.skill_des_rect;
		Novice_basefunction.skill_curLevel = 0;
		Novice_basefunction.skill_maxLevel = 9;
		Novice_basefunction.skill_icon_image = IMAGEMANAGER->findImage("Novice_basefunction");
		Novice_basefunction.skill_point_plus_image = IMAGEMANAGER->findImage("plus_btn");
		Novice_basefunction.skill_des_image = IMAGEMANAGER->findImage("skill_des_ui");
		Novice_basefunction.skill_sp = 0;
		Novice_basefunction.skill_effect = 5;
		Novice_basefunction.skill_des = "기본에 충실하자.";

		player_skill.push_back(Novice_basefunction);
	}
}
