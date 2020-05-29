#include "stdafx.h"
#include "monster.h"
#define MONSTER_SPEED_STR 2

int monster::s_AniCount = 0;

monster::~monster()
{
}
bool monster::init(int startX, int startY, std::string _name)
{
	m_monster = UTIL::IRectMake(startX * WIDTH + OFFSETX, startY * HEIGHT + OFFSETY, WIDTH, HEIGHT);

	monsterGensetting(_name);

	m_monster_PosX = startX;
	m_monster_PosY = startY;

	prvPos = { m_monster_PosX, m_monster_PosY };

	CAMERAMANAGER->rectInCamera(m_outmonster, m_monster, isCanprint);

	is_monster_arrow_6 = true;

	m_AniNameMap["monster_arrow_1"] = "monster_arrow_1" + std::to_string(s_AniCount);
	m_AniNameMap["monster_arrow_5"] = "monster_arrow_5" + std::to_string(s_AniCount);
	m_AniNameMap["monster_arrow_7"] = "monster_arrow_7" + std::to_string(s_AniCount);
	m_AniNameMap["monster_arrow_10"] = "monster_arrow_10" + std::to_string(s_AniCount);

	m_AniNameMap["monster_move_1"] = "monster_move_1" + std::to_string(s_AniCount);
	m_AniNameMap["monster_move_5"] = "monster_move_5" + std::to_string(s_AniCount);
	m_AniNameMap["monster_move_7"] = "monster_move_7" + std::to_string(s_AniCount);
	m_AniNameMap["monster_move_10"] = "monster_move_10" + std::to_string(s_AniCount);

	m_AniNameMap["monster_damage_1"] = "monster_damage_1" + std::to_string(s_AniCount);
	m_AniNameMap["monster_damage_5"] = "monster_damage_5" + std::to_string(s_AniCount);
	m_AniNameMap["monster_damage_7"] = "monster_damage_7" + std::to_string(s_AniCount);
	m_AniNameMap["monster_damage_10"] = "monster_damage_10" + std::to_string(s_AniCount);

	m_AniNameMap["monster_attack_1"] = "monster_attack_1" + std::to_string(s_AniCount);
	m_AniNameMap["monster_attack_5"] = "monster_attack_5" + std::to_string(s_AniCount);
	m_AniNameMap["monster_attack_7"] = "monster_attack_7" + std::to_string(s_AniCount);
	m_AniNameMap["monster_attack_10"] = "monster_attack_10" + std::to_string(s_AniCount);

	m_AniNameMap["monster_die"] = "monster_die" + std::to_string(s_AniCount);

	ani_monster_arrow_1 = ANIMANAGER->findAnimation(m_AniNameMap["monster_arrow_1"]);
	ani_monster_arrow_5 = ANIMANAGER->findAnimation(m_AniNameMap["monster_arrow_5"]);
	ani_monster_arrow_7 = ANIMANAGER->findAnimation(m_AniNameMap["monster_arrow_7"]);
	ani_monster_arrow_10 = ANIMANAGER->findAnimation(m_AniNameMap["monster_arrow_10"]);

	ani_monster_move_1 = ANIMANAGER->findAnimation(m_AniNameMap["monster_move_1"]);
	ani_monster_move_5 = ANIMANAGER->findAnimation(m_AniNameMap["monster_move_5"]);
	ani_monster_move_7 = ANIMANAGER->findAnimation(m_AniNameMap["monster_move_7"]);
	ani_monster_move_10 = ANIMANAGER->findAnimation(m_AniNameMap["monster_move_10"]);

	ani_monster_damage_img_1 = ANIMANAGER->findAnimation(m_AniNameMap["monster_damage_1"]);
	ani_monster_damage_img_5 = ANIMANAGER->findAnimation(m_AniNameMap["monster_damage_5"]);
	ani_monster_damage_img_7 = ANIMANAGER->findAnimation(m_AniNameMap["monster_damage_7"]);
	ani_monster_damage_img_10 = ANIMANAGER->findAnimation(m_AniNameMap["monster_damage_10"]);

	ani_monster_attack_img_1 = ANIMANAGER->findAnimation(m_AniNameMap["monster_attack_1"]);
	ani_monster_attack_img_5 = ANIMANAGER->findAnimation(m_AniNameMap["monster_attack_5"]);
	ani_monster_attack_img_7 = ANIMANAGER->findAnimation(m_AniNameMap["monster_attack_7"]);
	ani_monster_attack_img_10 = ANIMANAGER->findAnimation(m_AniNameMap["monster_attack_10"]);

	ani_monster_die = ANIMANAGER->findAnimation(m_AniNameMap["monster_die"]);

	m_target = IMAGEMANAGER->findImage("target");

	move_delay = rand() % 1000 + 500;

	s_AniCount++;

	return true;
}
void monster::release()
{
}
void monster::update(float _deltaTime)
{
	CAMERAMANAGER->rectInCamera(m_outmonster, m_monster, isCanprint);
	CAMERAMANAGER->update();
	monsterAnihandle();

	if (isLive)
	{
		movesetting();
		if (isMonsterBattle)
		{
			monster_mini_Hp_gaze = UTIL::IRectMake(m_outmonster.left + 6, m_outmonster.bottom, 50, 5);
			monster_mini_curHp_gaze = UTIL::IRectMake(m_outmonster.left + 6, m_outmonster.bottom, 50 * m_Hp / m_MaxHp, 5);
		}
		if (isTargeted)
		{
			monster_target = UTIL::IRectMake(m_outmonster.left + 20, m_outmonster.top - 15, 10, 10);
		}

		if (m_Hp <= 0)
		{
			isLive = false;
		}
	}
	else if (!isLive)
	{
		if (monsterDieAlpha == 255)
		{
			SOUNDMANAGER->stopChannel(Channel::eChannelporing_die);
			SOUNDMANAGER->playSound("poring_die", Channel::eChannelporing_die);
		}
		if (monsterDieAlpha > 0)
			monsterDieAlpha -= 3;

		if (monsterDieAlpha <= 0)
		{
			isEraseMonster = true;
		}

	}

	if (!isMonsterDamage && !isMonsterBattle && !isMove)
	{
		is_monster_arrow_1 = false;
		is_monster_arrow_3 = false;
		is_monster_arrow_5 = false;
		is_monster_arrow_6 = true;
		is_monster_arrow_7 = false;
		is_monster_arrow_9 = false;
		is_monster_arrow_10 = false;
		is_monster_arrow_12 = false;

		is_monster_move_1 = false;
		is_monster_move_3 = false;
		is_monster_move_5 = false;
		is_monster_move_6 = false;
		is_monster_move_7 = false;
		is_monster_move_9 = false;
		is_monster_move_10 = false;
		is_monster_move_12 = false;

		is_monster_damage_1 = false;
		is_monster_damage_5 = false;
		is_monster_damage_7 = false;
		is_monster_damage_10 = false;

		is_monster_attack_1 = false;
		is_monster_attack_5 = false;
		is_monster_attack_7 = false;
		is_monster_attack_10 = false;

	}
}
void monster::render(HDC hdc)
{
	if (isLive)
	{
		m_shadow->alphaRender(hdc, m_outmonster.left + 1 + MONSTER_IMAGE_OFFSETX, m_outmonster.bottom - 50, 70);

		if (is_monster_arrow_1 || is_monster_arrow_12)
		{
			m_monster_arrow_img_1->aniRender(hdc, m_outmonster.left + MONSTER_IMAGE_OFFSETX, m_outmonster.top, ani_monster_arrow_1);
		}
		else if (is_monster_arrow_5 || is_monster_arrow_3)
		{
			m_monster_arrow_img_5->aniRender(hdc, m_outmonster.left + MONSTER_IMAGE_OFFSETX, m_outmonster.top, ani_monster_arrow_5);
		}
		else if (is_monster_arrow_7 || is_monster_arrow_6)
		{
			m_monster_arrow_img_7->aniRender(hdc, m_outmonster.left + MONSTER_IMAGE_OFFSETX, m_outmonster.top, ani_monster_arrow_7);
		}
		else if (is_monster_arrow_10 || is_monster_arrow_9)
		{
			m_monster_arrow_img_10->aniRender(hdc, m_outmonster.left + MONSTER_IMAGE_OFFSETX, m_outmonster.top, ani_monster_arrow_10);
		}
		else if (is_monster_move_1 || is_monster_move_12)
		{
			m_monster_move_img_1->aniRender(hdc, m_outmonster.left + MONSTER_IMAGE_OFFSETX, m_outmonster.top, ani_monster_move_1);
		}
		else if (is_monster_move_5 || is_monster_move_3)
		{
			m_monster_move_img_5->aniRender(hdc, m_outmonster.left + MONSTER_IMAGE_OFFSETX, m_outmonster.top, ani_monster_move_5);
		}
		else if (is_monster_move_7 || is_monster_move_6)
		{
			m_monster_move_img_7->aniRender(hdc, m_outmonster.left + MONSTER_IMAGE_OFFSETX, m_outmonster.top, ani_monster_move_7);
		}
		else if (is_monster_move_10 || is_monster_move_9)
		{
			m_monster_move_img_10->aniRender(hdc, m_outmonster.left + MONSTER_IMAGE_OFFSETX, m_outmonster.top, ani_monster_move_10);
		}
		else if (is_monster_damage_1)
		{
			m_monster_damage_img_1->aniRender(hdc, m_outmonster.left + MONSTER_IMAGE_OFFSETX, m_outmonster.top, ani_monster_damage_img_1);
		}
		else if (is_monster_damage_5)
		{
			m_monster_damage_img_5->aniRender(hdc, m_outmonster.left + MONSTER_IMAGE_OFFSETX, m_outmonster.top, ani_monster_damage_img_5);
		}
		else if (is_monster_damage_7)
		{
			m_monster_damage_img_7->aniRender(hdc, m_outmonster.left + MONSTER_IMAGE_OFFSETX, m_outmonster.top, ani_monster_damage_img_7);
		}
		else if (is_monster_damage_10)
		{
			m_monster_damage_img_10->aniRender(hdc, m_outmonster.left + MONSTER_IMAGE_OFFSETX, m_outmonster.top, ani_monster_damage_img_10);
		}
		else if (is_monster_attack_1)
		{
			m_monster_attack_img_1->aniRender(hdc, m_outmonster.left + MONSTER_IMAGE_OFFSETX, m_outmonster.top - 15, ani_monster_attack_img_1);
		}
		else if (is_monster_attack_5)
		{
			m_monster_attack_img_5->aniRender(hdc, m_outmonster.left + MONSTER_IMAGE_OFFSETX, m_outmonster.top - 3, ani_monster_attack_img_5);
		}
		else if (is_monster_attack_7)
		{
			m_monster_attack_img_7->aniRender(hdc, m_outmonster.left - 19 + MONSTER_IMAGE_OFFSETX, m_outmonster.top - 6, ani_monster_attack_img_7);
		}
		else if (is_monster_attack_10)
		{
			m_monster_attack_img_10->aniRender(hdc, m_outmonster.left - 19 + MONSTER_IMAGE_OFFSETX, m_outmonster.top - 12, ani_monster_attack_img_10);
		}

		std::string m_monster_hp = std::to_string(m_Hp);
		//UTIL::PrintText(hdc, "HP: ", "", m_outmonster.left, m_outmonster.bottom + 5, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		//UTIL::PrintText(hdc, m_monster_hp.c_str(), "", m_outmonster.left + 25, m_outmonster.bottom + 5, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));

		if (isShowName)
		{
			UTIL::PrintText(hdc, m_name.c_str(), "", 700, m_outmonster.left + 15, m_outmonster.bottom + 6, 24, RGB(255, 0, 0), true, RGB(0, 0, 0));
		}

		if (isMonsterBattle)
		{
			UTIL::DrawColorRect(hdc, monster_mini_Hp_gaze, RGB(66, 66, 66), false);
			UTIL::DrawColorRect(hdc, monster_mini_curHp_gaze, RGB(16, 239, 33), false);
		}
		if (isTargeted)
		{
			m_target->render(hdc, monster_target.left, monster_target.top);
		}
	}

	else if (!isLive)
	{
		m_monster_die_img->alphaRender(hdc, m_outmonster.left - 20 + MONSTER_IMAGE_OFFSETX, m_outmonster.top - 15, monsterDieAlpha);
	}
}
void monster::afterRender(HDC hdc)
{

}
void monster::debugRender(HDC hdc)
{
	UTIL::DrawColorRect(hdc, m_outmonster, RGB(255, 0, 0), false);
	UTIL::DrawColorRect(hdc, monster_target, RGB(0, 255, 0), false);
}

void monster::monsterAnihandle()
{
	if (isLive)
	{
		if (is_monster_arrow_1 || is_monster_arrow_12)
		{
			ANIMANAGER->resume(m_AniNameMap["monster_arrow_1"]);
		}
		else if (!is_monster_arrow_1 || !is_monster_arrow_12)
		{
			ANIMANAGER->pause(m_AniNameMap["monster_arrow_1"]);
		}
		if (is_monster_arrow_5 || is_monster_arrow_3)
		{
			ANIMANAGER->resume(m_AniNameMap["monster_arrow_5"]);
		}
		else if (!is_monster_arrow_5 || !is_monster_arrow_3)
		{
			ANIMANAGER->pause(m_AniNameMap["monster_arrow_5"]);
		}
		if (is_monster_arrow_7 || is_monster_arrow_6)
		{
			ANIMANAGER->resume(m_AniNameMap["monster_arrow_7"]);
		}
		else if (!is_monster_arrow_7 || !is_monster_arrow_6)
		{
			ANIMANAGER->pause(m_AniNameMap["monster_arrow_7"]);
		}
		if (is_monster_arrow_10 || is_monster_arrow_9)
		{
			ANIMANAGER->resume(m_AniNameMap["monster_arrow_10"]);
		}
		else if (!is_monster_arrow_10 || !is_monster_arrow_9)
		{
			ANIMANAGER->pause(m_AniNameMap["monster_arrow_10"]);
		}

		if (is_monster_move_1 || is_monster_move_12)
		{
			ANIMANAGER->resume(m_AniNameMap["monster_move_1"]);
		}
		else if (!is_monster_move_1 || !is_monster_move_12)
		{
			ANIMANAGER->pause(m_AniNameMap["monster_move_1"]);
		}
		if (is_monster_move_5 || is_monster_move_3)
		{
			ANIMANAGER->resume(m_AniNameMap["monster_move_5"]);
		}
		else if (!is_monster_move_5 || !is_monster_move_3)
		{
			ANIMANAGER->pause(m_AniNameMap["monster_move_5"]);
		}
		if (is_monster_move_7 || is_monster_move_6)
		{
			ANIMANAGER->resume(m_AniNameMap["monster_move_7"]);
		}
		else if (!is_monster_move_7 || !is_monster_move_6)
		{
			ANIMANAGER->pause(m_AniNameMap["monster_move_7"]);
		}
		if (is_monster_move_10 || is_monster_move_9)
		{
			ANIMANAGER->resume(m_AniNameMap["monster_move_10"]);
		}
		else if (!is_monster_move_10 || !is_monster_move_9)
		{
			ANIMANAGER->pause(m_AniNameMap["monster_move_10"]);
		}
		if (is_monster_damage_1)
		{
			if (isMonsterDamageAni)
				ANIMANAGER->start(m_AniNameMap["monster_damage_1"]);
		}
		else if (!is_monster_damage_1)
		{
			ANIMANAGER->stop(m_AniNameMap["monster_damage_1"]);
		}
		if (is_monster_damage_5)
		{
			if (isMonsterDamageAni)
				ANIMANAGER->start(m_AniNameMap["monster_damage_5"]);
		}
		else if (!is_monster_damage_5)
		{
			ANIMANAGER->stop(m_AniNameMap["monster_damage_5"]);
		}
		if (is_monster_damage_7)
		{
			if (isMonsterDamageAni)
				ANIMANAGER->start(m_AniNameMap["monster_damage_7"]);
		}
		else if (!is_monster_damage_7)
		{
			ANIMANAGER->stop(m_AniNameMap["monster_damage_7"]);
		}
		if (is_monster_damage_10)
		{
			if (isMonsterDamageAni)
				ANIMANAGER->start(m_AniNameMap["monster_damage_10"]);
		}
		else if (!is_monster_damage_10)
		{
			ANIMANAGER->stop(m_AniNameMap["monster_damage_10"]);
		}


		if (is_monster_attack_1)
		{
			if (isMonsterAttackAni)
				ANIMANAGER->start(m_AniNameMap["monster_attack_1"]);
		}
		else if (!is_monster_attack_1)
		{
			ANIMANAGER->stop(m_AniNameMap["monster_attack_1"]);
		}
		if (is_monster_attack_5)
		{
			if (isMonsterAttackAni)
				ANIMANAGER->start(m_AniNameMap["monster_attack_5"]);
		}
		else if (!is_monster_attack_5)
		{
			ANIMANAGER->stop(m_AniNameMap["monster_attack_5"]);
		}
		if (is_monster_attack_7)
		{
			if (isMonsterAttackAni)
				ANIMANAGER->start(m_AniNameMap["monster_attack_7"]);
		}
		else if (!is_monster_attack_7)
		{
			ANIMANAGER->stop(m_AniNameMap["monster_attack_7"]);
		}
		if (is_monster_attack_10)
		{
			if (isMonsterAttackAni)
				ANIMANAGER->start(m_AniNameMap["monster_attack_10"]);
		}
		else if (!is_monster_attack_10)
		{
			ANIMANAGER->stop(m_AniNameMap["monster_attack_10"]);
		}
	}

	else if (!isLive)
	{
		ANIMANAGER->resume(m_AniNameMap["monster_die"]);

	}
}

void monster::movesetting()
{

	POINT m_monster_Pos = { m_monster_PosX, m_monster_PosY };

	for (auto& tile : *m_Tiles)
	{
		if (tile.getTileIndex() == m_monster_Pos)
		{
			if (isLive)
				tile.setisMonster(true);

			else if (!isLive)
				tile.setisMonster(false);
		}

		if (prvPos != m_monster_Pos)
		{
			if (tile.getTileIndex() == prvPos)
			{
				tile.setisMonster(false);
				prvPos = m_monster_Pos;
			}
		}


	}


	/////////////////////////////////////////////////////////////////////

	POINT monsterTile = getTileindex();

	move_delay_cnt++;
	if (isMonsterDamage == false && isMoveSolo == false && isMonsterBattle == false && (move_delay_cnt > move_delay))
	{
		int x = rand() % m_monster_PosX + 4;
		int y = rand() % m_monster_PosY + 4;

		Monster_Coordinate A(m_monster_PosX, m_monster_PosY);
		Monster_Coordinate B(x, y);
		isMove = true;
		m_FindPath = m_Astar.FindPath(A, B);

		isMoveSolo = true;
		move_delay_cnt = 0;
	}

	if (isMonsterDamage)
	{
		isMoveSolo = true;
		isMonsterBattleFind = true;
	}

	if (isMonsterBattleFind && !isMove)
	{
		for (int y = monsterTile.y - 3; y <= monsterTile.y + 3; y++)
		{
			for (int x = monsterTile.x - 3; x <= monsterTile.x + 3; x++)
			{
				if ((*m_Tiles)[x + y * m_TileColEA].getisPlayer() == true)
				{
					Monster_Coordinate A(m_monster_PosX, m_monster_PosY);
					Monster_Coordinate B(x, y);
					isMove = true;
					m_FindPath = m_Astar.FindPath(A, B);
				}
			}
		}
	}

	//길 이동
	if (isMove)
	{
		auto i = m_FindPath.begin();

		POINT FindPoint = { ((*i)->x), ((*i)->y) };
		POINT MonsterIndex = getTileindex();


		if (m_FindPath.size() <= 2 && MonsterIndex == FindPoint)
		{
			m_FindPath.clear();
			isMove = false;
			isMoveSolo = false;
		}
		else if (m_FindPath.size() > 2 && MonsterIndex == FindPoint)
		{
			m_FindPath.pop_front();
		}

		else if (MonsterIndex != FindPoint)
		{
			FindPoint = { ((*i)->x), ((*i)->y) };


			//좌방향 이동
			if (FindPoint.x < MonsterIndex.x && FindPoint.y == MonsterIndex.y)
			{
				is_monster_move_12 = false;
				is_monster_move_1 = false;
				is_monster_move_3 = false;
				is_monster_move_5 = false;
				is_monster_move_6 = false;
				is_monster_move_7 = false;
				is_monster_move_9 = true;
				is_monster_move_10 = false;
				is_monster_move_12 = false;
				is_monster_arrow_1 = false;
				is_monster_arrow_3 = false;
				is_monster_arrow_5 = false;
				is_monster_arrow_6 = false;
				is_monster_arrow_7 = false;
				is_monster_arrow_9 = false;
				is_monster_arrow_10 = false;
				is_monster_arrow_12 = false;
				m_monster.moveLeft(MONSTER_SPEED_STR);
				monsterArrow = 9;
			}
			///우방향 이동
			else if (FindPoint.x > MonsterIndex.x && FindPoint.y == MonsterIndex.y)
			{
				is_monster_move_12 = false;
				is_monster_move_1 = false;
				is_monster_move_3 = true;
				is_monster_move_5 = false;
				is_monster_move_6 = false;
				is_monster_move_7 = false;
				is_monster_move_9 = false;
				is_monster_move_10 = false;
				is_monster_move_12 = false;
				is_monster_arrow_1 = false;
				is_monster_arrow_3 = false;
				is_monster_arrow_5 = false;
				is_monster_arrow_6 = false;
				is_monster_arrow_7 = false;
				is_monster_arrow_9 = false;
				is_monster_arrow_10 = false;
				is_monster_arrow_12 = false;
				m_monster.moveRight(MONSTER_SPEED_STR);
				monsterArrow = 3;

			}
			//상방향 이동
			else if (FindPoint.x == MonsterIndex.x && FindPoint.y < MonsterIndex.y)
			{
				is_monster_move_12 = false;
				is_monster_move_1 = false;
				is_monster_move_3 = false;
				is_monster_move_5 = false;
				is_monster_move_6 = false;
				is_monster_move_7 = false;
				is_monster_move_9 = false;
				is_monster_move_10 = false;
				is_monster_move_12 = true;
				is_monster_arrow_1 = false;
				is_monster_arrow_3 = false;
				is_monster_arrow_5 = false;
				is_monster_arrow_6 = false;
				is_monster_arrow_7 = false;
				is_monster_arrow_9 = false;
				is_monster_arrow_10 = false;
				is_monster_arrow_12 = false;
				m_monster.moveUp(MONSTER_SPEED_STR);
				monsterArrow = 12;

			}
			//하방향 이동
			else if (FindPoint.x == MonsterIndex.x && FindPoint.y > MonsterIndex.y)
			{
				is_monster_move_12 = false;
				is_monster_move_1 = false;
				is_monster_move_3 = false;
				is_monster_move_5 = false;
				is_monster_move_6 = true;
				is_monster_move_7 = false;
				is_monster_move_9 = false;
				is_monster_move_10 = false;
				is_monster_move_12 = false;
				is_monster_arrow_1 = false;
				is_monster_arrow_3 = false;
				is_monster_arrow_5 = false;
				is_monster_arrow_6 = false;
				is_monster_arrow_7 = false;
				is_monster_arrow_9 = false;
				is_monster_arrow_10 = false;
				is_monster_arrow_12 = false;
				m_monster.moveDown(MONSTER_SPEED_STR);
				monsterArrow = 6;

			}
			//좌상방향 이동
			else if (FindPoint.x < MonsterIndex.x && FindPoint.y < MonsterIndex.y)
			{
				is_monster_move_12 = false;
				is_monster_move_1 = false;
				is_monster_move_3 = false;
				is_monster_move_5 = false;
				is_monster_move_6 = false;
				is_monster_move_7 = false;
				is_monster_move_9 = false;
				is_monster_move_10 = true;
				is_monster_move_12 = false;
				is_monster_arrow_1 = false;
				is_monster_arrow_3 = false;
				is_monster_arrow_5 = false;
				is_monster_arrow_6 = false;
				is_monster_arrow_7 = false;
				is_monster_arrow_9 = false;
				is_monster_arrow_10 = false;
				is_monster_arrow_12 = false;
				m_monster.moveLeft(MONSTER_SPEED_STR);
				m_monster.moveUp(MONSTER_SPEED_STR);
				monsterArrow = 10;

			}
			//좌하방향 이동
			else if (FindPoint.x < MonsterIndex.x && FindPoint.y > MonsterIndex.y)
			{
				is_monster_move_12 = false;
				is_monster_move_1 = false;
				is_monster_move_3 = false;
				is_monster_move_5 = false;
				is_monster_move_6 = false;
				is_monster_move_7 = true;
				is_monster_move_9 = false;
				is_monster_move_10 = false;
				is_monster_move_12 = false;
				is_monster_arrow_1 = false;
				is_monster_arrow_3 = false;
				is_monster_arrow_5 = false;
				is_monster_arrow_6 = false;
				is_monster_arrow_7 = false;
				is_monster_arrow_9 = false;
				is_monster_arrow_10 = false;
				is_monster_arrow_12 = false;
				m_monster.moveLeft(MONSTER_SPEED_STR);
				m_monster.moveDown(MONSTER_SPEED_STR);
				monsterArrow = 7;

			}
			//우상방향 이동
			else if (FindPoint.x > MonsterIndex.x && FindPoint.y < MonsterIndex.y)
			{
				is_monster_move_12 = false;
				is_monster_move_1 = true;
				is_monster_move_3 = false;
				is_monster_move_5 = false;
				is_monster_move_6 = false;
				is_monster_move_7 = false;
				is_monster_move_9 = false;
				is_monster_move_10 = false;
				is_monster_move_12 = false;
				is_monster_arrow_1 = false;
				is_monster_arrow_3 = false;
				is_monster_arrow_5 = false;
				is_monster_arrow_6 = false;
				is_monster_arrow_7 = false;
				is_monster_arrow_9 = false;
				is_monster_arrow_10 = false;
				is_monster_arrow_12 = false;
				m_monster.moveRight(MONSTER_SPEED_STR);
				m_monster.moveUp(MONSTER_SPEED_STR);
				monsterArrow = 1;

			}
			//우하방향 이동
			else if (FindPoint.x > MonsterIndex.x && FindPoint.y > MonsterIndex.y)
			{
				is_monster_move_12 = false;
				is_monster_move_1 = false;
				is_monster_move_3 = false;
				is_monster_move_5 = true;
				is_monster_move_6 = false;
				is_monster_move_7 = false;
				is_monster_move_9 = false;
				is_monster_move_10 = false;
				is_monster_move_12 = false;
				is_monster_arrow_1 = false;
				is_monster_arrow_3 = false;
				is_monster_arrow_5 = false;
				is_monster_arrow_6 = false;
				is_monster_arrow_7 = false;
				is_monster_arrow_9 = false;
				is_monster_arrow_10 = false;
				is_monster_arrow_12 = false;
				m_monster.moveRight(MONSTER_SPEED_STR);
				m_monster.moveDown(MONSTER_SPEED_STR);
				monsterArrow = 5;

			}
		}
	}

	for (int i = 0; i < (*m_Tiles).size(); ++i) {
		if (UTIL::isPointPointCollision({ (*m_Tiles)[i].getabsTile().centerX,  (*m_Tiles)[i].getabsTile().centerY }, { m_monster.centerX,m_monster.centerY }))
		{
			m_monster_PosX = (*m_Tiles)[i].m_BlockPositionX;
			m_monster_PosY = (*m_Tiles)[i].m_BlockPositionY;
			//isDest = m_Tiles[i].isDest; ->플레이어 앞으로 도착했을때로 추후 수정
			break;
		}
	}


	if (!isMove && !isMonsterDamage)
	{
		switch (monsterArrow)
		{
		case 1:
			is_monster_move_12 = false;
			is_monster_move_1 = false;
			is_monster_move_3 = false;
			is_monster_move_5 = false;
			is_monster_move_6 = false;
			is_monster_move_7 = false;
			is_monster_move_9 = false;
			is_monster_move_10 = false;
			is_monster_move_12 = false;
			is_monster_arrow_1 = true;
			is_monster_arrow_3 = false;
			is_monster_arrow_5 = false;
			is_monster_arrow_6 = false;
			is_monster_arrow_7 = false;
			is_monster_arrow_9 = false;
			is_monster_arrow_10 = false;
			is_monster_arrow_12 = false;
			break;
		case 3:
			is_monster_move_12 = false;
			is_monster_move_1 = false;
			is_monster_move_3 = false;
			is_monster_move_5 = false;
			is_monster_move_6 = false;
			is_monster_move_7 = false;
			is_monster_move_9 = false;
			is_monster_move_10 = false;
			is_monster_move_12 = false;
			is_monster_arrow_1 = false;
			is_monster_arrow_3 = true;
			is_monster_arrow_5 = false;
			is_monster_arrow_6 = false;
			is_monster_arrow_7 = false;
			is_monster_arrow_9 = false;
			is_monster_arrow_10 = false;
			is_monster_arrow_12 = false;
			break;
		case 5:
			is_monster_move_12 = false;
			is_monster_move_1 = false;
			is_monster_move_3 = false;
			is_monster_move_5 = false;
			is_monster_move_6 = false;
			is_monster_move_7 = false;
			is_monster_move_9 = false;
			is_monster_move_10 = false;
			is_monster_move_12 = false;
			is_monster_arrow_1 = false;
			is_monster_arrow_3 = false;
			is_monster_arrow_5 = true;
			is_monster_arrow_6 = false;
			is_monster_arrow_7 = false;
			is_monster_arrow_9 = false;
			is_monster_arrow_10 = false;
			is_monster_arrow_12 = false;
			break;
		case 6:
			is_monster_move_12 = false;
			is_monster_move_1 = false;
			is_monster_move_3 = false;
			is_monster_move_5 = false;
			is_monster_move_6 = false;
			is_monster_move_7 = false;
			is_monster_move_9 = false;
			is_monster_move_10 = false;
			is_monster_move_12 = false;
			is_monster_arrow_1 = false;
			is_monster_arrow_3 = false;
			is_monster_arrow_5 = false;
			is_monster_arrow_6 = true;
			is_monster_arrow_7 = false;
			is_monster_arrow_9 = false;
			is_monster_arrow_10 = false;
			is_monster_arrow_12 = false;
			break;
		case 7:
			is_monster_move_12 = false;
			is_monster_move_1 = false;
			is_monster_move_3 = false;
			is_monster_move_5 = false;
			is_monster_move_6 = false;
			is_monster_move_7 = false;
			is_monster_move_9 = false;
			is_monster_move_10 = false;
			is_monster_move_12 = false;
			is_monster_arrow_1 = false;
			is_monster_arrow_3 = false;
			is_monster_arrow_5 = false;
			is_monster_arrow_6 = false;
			is_monster_arrow_7 = true;
			is_monster_arrow_9 = false;
			is_monster_arrow_10 = false;
			is_monster_arrow_12 = false;
			break;
		case 9:
			is_monster_move_12 = false;
			is_monster_move_1 = false;
			is_monster_move_3 = false;
			is_monster_move_5 = false;
			is_monster_move_6 = false;
			is_monster_move_7 = false;
			is_monster_move_9 = false;
			is_monster_move_10 = false;
			is_monster_move_12 = false;
			is_monster_arrow_1 = false;
			is_monster_arrow_3 = false;
			is_monster_arrow_5 = false;
			is_monster_arrow_6 = false;
			is_monster_arrow_7 = false;
			is_monster_arrow_9 = true;
			is_monster_arrow_10 = false;
			is_monster_arrow_12 = false;
			break;
		case 10:
			is_monster_move_12 = false;
			is_monster_move_1 = false;
			is_monster_move_3 = false;
			is_monster_move_5 = false;
			is_monster_move_6 = false;
			is_monster_move_7 = false;
			is_monster_move_9 = false;
			is_monster_move_10 = false;
			is_monster_move_12 = false;
			is_monster_arrow_1 = false;
			is_monster_arrow_3 = false;
			is_monster_arrow_5 = false;
			is_monster_arrow_6 = false;
			is_monster_arrow_7 = false;
			is_monster_arrow_9 = false;
			is_monster_arrow_10 = true;
			is_monster_arrow_12 = false;
			break;
		case 12:
			is_monster_move_12 = false;
			is_monster_move_1 = false;
			is_monster_move_3 = false;
			is_monster_move_5 = false;
			is_monster_move_6 = false;
			is_monster_move_7 = false;
			is_monster_move_9 = false;
			is_monster_move_10 = false;
			is_monster_move_12 = false;
			is_monster_arrow_1 = false;
			is_monster_arrow_3 = false;
			is_monster_arrow_5 = false;
			is_monster_arrow_6 = false;
			is_monster_arrow_7 = false;
			is_monster_arrow_9 = false;
			is_monster_arrow_10 = false;
			is_monster_arrow_12 = true;
			break;
		}
	}
}

POINT monster::getTileindex()
{
	{
		return { m_monster_PosX,m_monster_PosY };
	}
}

void monster::monsterGensetting(std::string _name)
{
	if (_name == "포링")
	{
		m_name = "포링";

		m_level = 1;
		m_Hp = 300;
		m_MaxHp = m_Hp;
		m_atk = 20;
		m_matk = 20;
		m_def = 1;
		m_mdef = 1;
		m_feel = 2;
		m_aspd = 100;
		m_base_exp = 50;
		m_job_exp = 35;
		m_have_item_1 = ITEM->Item_collect("젤로피", 1);
		m_have_item_2 = ITEM->Item_collect("빨간포션", 1);


		m_monster_arrow_img_1 = IMAGEMANAGER->findImage("poring_1");
		m_monster_arrow_img_5 = IMAGEMANAGER->findImage("poring_5");
		m_monster_arrow_img_7 = IMAGEMANAGER->findImage("poring_7");
		m_monster_arrow_img_10 = IMAGEMANAGER->findImage("poring_10");
		ANIMANAGER->addAnimation("monster_arrow_1" + std::to_string(s_AniCount), "poring_1", 0, 3, 10, false, true);
		ANIMANAGER->addAnimation("monster_arrow_5" + std::to_string(s_AniCount), "poring_5", 0, 3, 10, false, true);
		ANIMANAGER->addAnimation("monster_arrow_7" + std::to_string(s_AniCount), "poring_7", 0, 3, 10, false, true);
		ANIMANAGER->addAnimation("monster_arrow_10" + std::to_string(s_AniCount), "poring_10", 0, 3, 10, false, true);

		m_monster_move_img_1 = IMAGEMANAGER->findImage("poring_move_1");
		m_monster_move_img_5 = IMAGEMANAGER->findImage("poring_move_5");
		m_monster_move_img_7 = IMAGEMANAGER->findImage("poring_move_7");
		m_monster_move_img_10 = IMAGEMANAGER->findImage("poring_move_10");

		ANIMANAGER->addAnimation("monster_move_1" + std::to_string(s_AniCount), "poring_move_1", 0, 9, 10, false, true);
		ANIMANAGER->addAnimation("monster_move_5" + std::to_string(s_AniCount), "poring_move_5", 0, 9, 10, false, true);
		ANIMANAGER->addAnimation("monster_move_7" + std::to_string(s_AniCount), "poring_move_7", 0, 9, 10, false, true);
		ANIMANAGER->addAnimation("monster_move_10" + std::to_string(s_AniCount), "poring_move_10", 0, 9, 10, false, true);

		m_monster_damage_img_1 = IMAGEMANAGER->findImage("poring_damage_1");
		m_monster_damage_img_5 = IMAGEMANAGER->findImage("poring_damage_5");
		m_monster_damage_img_7 = IMAGEMANAGER->findImage("poring_damage_7");
		m_monster_damage_img_10 = IMAGEMANAGER->findImage("poring_damage_10");

		ANIMANAGER->addAnimation("monster_damage_1" + std::to_string(s_AniCount), "poring_damage_1", 0, 4, 10, false, false);
		ANIMANAGER->addAnimation("monster_damage_5" + std::to_string(s_AniCount), "poring_damage_5", 0, 4, 10, false, false);
		ANIMANAGER->addAnimation("monster_damage_7" + std::to_string(s_AniCount), "poring_damage_7", 0, 4, 10, false, false);
		ANIMANAGER->addAnimation("monster_damage_10" + std::to_string(s_AniCount), "poring_damage_10", 0, 4, 10, false, false);

		m_monster_attack_img_1 = IMAGEMANAGER->findImage("poring_attack_1");
		m_monster_attack_img_5 = IMAGEMANAGER->findImage("poring_attack_5");
		m_monster_attack_img_7 = IMAGEMANAGER->findImage("poring_attack_7");
		m_monster_attack_img_10 = IMAGEMANAGER->findImage("poring_attack_10");

		ANIMANAGER->addAnimation("monster_attack_1" + std::to_string(s_AniCount), "poring_attack_1", 0, 27, 27, false, false);
		ANIMANAGER->addAnimation("monster_attack_5" + std::to_string(s_AniCount), "poring_attack_5", 0, 27, 27, false, false);
		ANIMANAGER->addAnimation("monster_attack_7" + std::to_string(s_AniCount), "poring_attack_7", 0, 27, 27, false, false);
		ANIMANAGER->addAnimation("monster_attack_10" + std::to_string(s_AniCount), "poring_attack_10", 0, 27, 27, false, false);

		m_monster_die_img = IMAGEMANAGER->findImage("poring_die");
		ANIMANAGER->addAnimation("monster_die" + std::to_string(s_AniCount), "poring_die", 0, 0, 20, false, false);

		m_shadow = IMAGEMANAGER->findImage("shadow_base_poring");
	}

}

void monster::monsterDamagesetting(bool _isMonsterDamage, int playerArrow)
{
	isMonsterDamage = _isMonsterDamage;

	if (isMonsterDamage == true)
	{
		is_monster_arrow_1 = false;
		is_monster_arrow_3 = false;
		is_monster_arrow_5 = false;
		is_monster_arrow_6 = false;
		is_monster_arrow_7 = false;
		is_monster_arrow_9 = false;
		is_monster_arrow_10 = false;
		is_monster_arrow_12 = false;

		is_monster_move_1 = false;
		is_monster_move_3 = false;
		is_monster_move_5 = false;
		is_monster_move_6 = false;
		is_monster_move_7 = false;
		is_monster_move_9 = false;
		is_monster_move_10 = false;
		is_monster_move_12 = false;

		is_monster_attack_1 = false;
		is_monster_attack_5 = false;
		is_monster_attack_7 = false;
		is_monster_attack_10 = false;

		switch (playerArrow)
		{
		case 1:
			monsterArrow = 7;
			is_monster_damage_1 = false;
			is_monster_damage_5 = false;
			is_monster_damage_7 = true;
			is_monster_damage_10 = false;
			break;
		case 3:
			monsterArrow = 9;
			is_monster_damage_1 = false;
			is_monster_damage_5 = false;
			is_monster_damage_7 = false;
			is_monster_damage_10 = true;
			break;
		case 5:
			monsterArrow = 10;
			is_monster_damage_1 = false;
			is_monster_damage_5 = false;
			is_monster_damage_7 = false;
			is_monster_damage_10 = true;
			break;
		case 6:
			monsterArrow = 12;
			is_monster_damage_1 = false;
			is_monster_damage_5 = false;
			is_monster_damage_7 = false;
			is_monster_damage_10 = true;
			break;
		case 7:
			monsterArrow = 1;
			is_monster_damage_1 = true;
			is_monster_damage_5 = false;
			is_monster_damage_7 = false;
			is_monster_damage_10 = false;
			break;
		case 9:
			monsterArrow = 3;
			is_monster_damage_1 = false;
			is_monster_damage_5 = true;
			is_monster_damage_7 = false;
			is_monster_damage_10 = false;
			break;
		case 10:
			monsterArrow = 5;
			is_monster_damage_1 = false;
			is_monster_damage_5 = true;
			is_monster_damage_7 = false;
			is_monster_damage_10 = false;
			break;
		case 12:
			monsterArrow = 6;
			is_monster_damage_1 = false;
			is_monster_damage_5 = false;
			is_monster_damage_7 = true;
			is_monster_damage_10 = false;
			break;
		}
	}



}

void monster::monsterAttacksetting(bool _isPlayerBattle, int playerArrow)
{
	if (isMonsterDamage)
	{
		isMonsterBattleFind = true;
	}

	if (isMonsterBattleFind && !isMove)
	{
		isMonsterBattle = true;
	}

	if (isMonsterBattle && !isMove)
	{
		monster_attack_count++;

		if (!isMonsterAttack && monster_attack_count >= 150)
		{
			isMonsterAttack = true;
			isMonsterAttackAni = true;
			monster_attack_count = 0;
		}

		if (isMonsterAttack)
		{
			monster_attack_delay++;

			if (monster_attack_delay >= 2)
			{
				isMonsterAttackAni = false;
			}

			if (monster_attack_delay >= 65)
			{
				isMonsterAttack = false;
				monster_attack_delay = 0;
			}

		}

		if (isMonsterAttack && !isMonsterDamage)
		{
			is_monster_arrow_1 = false;
			is_monster_arrow_3 = false;
			is_monster_arrow_5 = false;
			is_monster_arrow_6 = false;
			is_monster_arrow_7 = false;
			is_monster_arrow_9 = false;
			is_monster_arrow_10 = false;
			is_monster_arrow_12 = false;

			is_monster_move_1 = false;
			is_monster_move_3 = false;
			is_monster_move_5 = false;
			is_monster_move_6 = false;
			is_monster_move_7 = false;
			is_monster_move_9 = false;
			is_monster_move_10 = false;
			is_monster_move_12 = false;

			is_monster_damage_1 = false;
			is_monster_damage_5 = false;
			is_monster_damage_7 = false;
			is_monster_damage_10 = false;


			POINT monsterTile = getTileindex();

			for (int y = monsterTile.y - 1; y <= monsterTile.y + 1; y++)
			{
				for (int x = monsterTile.x - 1; x <= monsterTile.x + 1; x++)
				{
					if ((*m_Tiles)[x + y * m_TileColEA].getisPlayer() == true)
					{
						if (monsterTile.x < x && monsterTile.y > y)
						{
							monsterArrow = 1;
						}
						else if (monsterTile.x < x && monsterTile.y == y)
						{
							monsterArrow = 3;
						}
						else if (monsterTile.x < x && monsterTile.y < y)
						{
							monsterArrow = 5;
						}
						else if (monsterTile.x == x && monsterTile.y < y)
						{
							monsterArrow = 6;
						}
						else if (monsterTile.x > x && monsterTile.y < y)
						{
							monsterArrow = 7;
						}
						else if (monsterTile.x > x && monsterTile.y == y)
						{
							monsterArrow = 9;
						}
						else if (monsterTile.x > x && monsterTile.y > y)
						{
							monsterArrow = 10;
						}
						else if (monsterTile.x == x && monsterTile.y > y)
						{
							monsterArrow = 12;
						}

					}
				}
			}
			switch (monsterArrow)
			{
			case 1:
				is_monster_attack_1 = true;
				is_monster_attack_5 = false;
				is_monster_attack_7 = false;
				is_monster_attack_10 = false;
				break;
			case 3:
				is_monster_attack_1 = false;
				is_monster_attack_5 = true;
				is_monster_attack_7 = false;
				is_monster_attack_10 = false;
				break;
			case 5:
				is_monster_attack_1 = false;
				is_monster_attack_5 = true;
				is_monster_attack_7 = false;
				is_monster_attack_10 = false;
				break;
			case 6:
				is_monster_attack_1 = false;
				is_monster_attack_5 = false;
				is_monster_attack_7 = true;
				is_monster_attack_10 = false;

				break;
			case 7:
				is_monster_attack_1 = false;
				is_monster_attack_5 = false;
				is_monster_attack_7 = true;
				is_monster_attack_10 = false;
				break;
			case 9:
				is_monster_attack_1 = false;
				is_monster_attack_5 = false;
				is_monster_attack_7 = false;
				is_monster_attack_10 = true;
				break;
			case 10:
				is_monster_attack_1 = false;
				is_monster_attack_5 = false;
				is_monster_attack_7 = false;
				is_monster_attack_10 = true;
				break;
			case 12:
				is_monster_attack_1 = false;
				is_monster_attack_5 = false;
				is_monster_attack_7 = false;
				is_monster_attack_10 = true;
				break;
			}
		}
	}
}


/////////////////////////////////////////////////////////
///// Astar::Node ///////////////////////////////////////
/////////////////////////////////////////////////////////
Monster_Astar::Monster_Node::Monster_Node(int _x, int _y, Monster_Astar::Monster_Node* _pParent, Monster_Coordinate _DestPoint)
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

Monster_Astar::Monster_Node::~Monster_Node()
{
}

bool Monster_Astar::Monster_Node::init()
{
	return S_OK;
}

void Monster_Astar::Monster_Node::update(float _deltaTime)
{
}

void Monster_Astar::Monster_Node::release()
{
}

void Monster_Astar::Monster_Node::render(HDC hdc)
{
}

void Monster_Astar::Monster_Node::afterRender(HDC hdc)
{
}

void Monster_Astar::Monster_Node::debugRender(HDC hdc)
{
}

/////////////////////////////////////////////////////////
///// Astar /////////////////////////////////////////////
/////////////////////////////////////////////////////////


Monster_Astar::~Monster_Astar()
{ // path 동적할당 해제
	iter = path.begin();
	for (; iter != path.end(); iter++)
	{
		delete* iter;
	}
}

std::list<Monster_Coordinate*> Monster_Astar::FindPath(Monster_Coordinate StartPoint, Monster_Coordinate EndPoint)
{
	// (상,우,하,좌) 4방향 시계방향 탐색 후 결과에 따라 (우상,우하,좌하,좌상) 탐색.	
	std::list<Monster_Node*> OpenNode; // 열린노드
	std::list<Monster_Node*> CloseNode; // 닫힌노드
	Monster_Node* SNode; // 선택된 노드
	std::list<Monster_Coordinate*> path;

	OpenNode.push_back(new Monster_Node(StartPoint.x, StartPoint.y, NULL, EndPoint)); // 시작지점을 열린노드에 추가

	std::list<Monster_Node*>::iterator iter;

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
			path.push_back(new Monster_Coordinate(SNode->point.x, SNode->point.y));
		}	path.push_back(new Monster_Coordinate(SNode->point.x, SNode->point.y)); // 부모가 NULL인 경우의 path까지 저장(출발 지점)

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

std::list<Monster_Astar::Monster_Node*>::iterator Monster_Astar::FindNextNode(std::list<Monster_Astar::Monster_Node*>* pOpenNode)
{
	std::list<Monster_Node*>::iterator iter = (*pOpenNode).begin();

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

std::list<Monster_Astar::Monster_Node*>::iterator Monster_Astar::FindCoordNode(int _x, int _y, std::list<Monster_Astar::Monster_Node*>* NodeList)
{
	std::list<Monster_Astar::Monster_Node*>::iterator iter = NodeList->begin();

	for (int i = 1; iter != NodeList->end(); i++, iter++)
	{
		if ((*iter)->point.x == _x && (*iter)->point.y == _y)
		{
			return iter;
		}
	}

	return NodeList->end();
}

void Monster_Astar::ExploreNode(Monster_Astar::Monster_Node* SNode, std::list<Monster_Astar::Monster_Node*>* OpenNode, std::list<Monster_Astar::Monster_Node*>* CloseNode, Monster_Coordinate EndPoint)
{
	bool up = true, right = true, down = true, left = true; // 이 결과에 따라 대각선 방향 탐색 여부를 결정. true == 장애물 있음, false == 없음
	std::list<Monster_Node*>::iterator iter;
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
			OpenNode->push_back(new Monster_Node(point.x, point.y, SNode, EndPoint));
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
			OpenNode->push_back(new Monster_Node(point.x, point.y, SNode, EndPoint));
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
			OpenNode->push_back(new Monster_Node(point.x, point.y, SNode, EndPoint));
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
			OpenNode->push_back(new Monster_Node(point.x, point.y, SNode, EndPoint));
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
			OpenNode->push_back(new Monster_Node(point.x, point.y, SNode, EndPoint));
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
			OpenNode->push_back(new Monster_Node(point.x, point.y, SNode, EndPoint));
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
			OpenNode->push_back(new Monster_Node(point.x, point.y, SNode, EndPoint));
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
			OpenNode->push_back(new Monster_Node(point.x, point.y, SNode, EndPoint));
		}
	}


}


Monster_Coordinate Monster_Astar::GetPos(int order)
{
	Monster_Coordinate pos;
	for (int i = 1; i < order; i++)
	{
		iter++;
	}
	pos.x = (*iter)->x;
	pos.y = (*iter)->y;
	iter = path.begin();
	return pos;
}

void Monster_Astar::PrintNavi()
{
	for (int i = 0; iter != path.end(); iter++)
	{
		//cout << (*iter)->x << (*iter)->y << endl;
	}
	iter = path.begin(); // iter 값 원래대로 돌려주기
}

void Monster_Astar::PrintPath()
{

	for (auto i = 0; iter != path.end(); iter++) // 맵에서 경로에 해당하는 곳 표시
	{
		POINT tempPoint = { ((*iter)->x),((*iter)->y) };

		for (auto& tile : *m_Tiles)
		{
			if (tile.getTileIndex() == tempPoint)
			{
				tile.setisRoot(true);
			}
		}
	}
	iter = path.begin(); // iter 값 원래대로 돌려주기
}

void Monster_Astar::PrintPath(std::list<Monster_Coordinate*> _path)
{
	iter = _path.begin();
	for (auto i = 0; iter != _path.end(); iter++) // 맵에서 경로에 해당하는 곳 표시
	{
		POINT tempPoint = { ((*iter)->x),((*iter)->y) };

		for (auto& tile : *m_Tiles)
		{
			if (tile.getTileIndex() == tempPoint)
			{
				tile.setisRoot(true);
			}
		}
	}
}

TileType Monster_Astar::getNodeTiletype(POINT _XY)
{
	if (0 <= _XY.x && _XY.x < m_TileColEA && 0 <= _XY.y && _XY.y < m_TileRowEA)
	{
		return (*m_Tiles)[_XY.x + _XY.y * (m_TileColEA)].m_Type;
	}
	else
	{
		return TileType::outrange;
	}
}
