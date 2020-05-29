#include "stdafx.h"
#include "SampleScene.h"


bool SampleScene::init()
{
	SOUNDMANAGER->playSound("pron", Channel::eChannelBgm);

	CAMERAMANAGER->setCameraFocus(&player.m_player.centerX, &player.m_player.centerY, WINSIZEX / 2, WINSIZEY / 2);
	black_bg = IMAGEMANAGER->findImage("black_bg");
	black_bg_quest = IMAGEMANAGER->findImage("black_bg_quest");
	npc_base = IMAGEMANAGER->findImage("npc_base");
	npc_gugjung = IMAGEMANAGER->findImage("npc_gugjung");
	npc_smile = IMAGEMANAGER->findImage("npc_smile");
	npc_bg = IMAGEMANAGER->findImage("npc_bg");
	npc_next = IMAGEMANAGER->findImage("npc_next");
	npc_ok = IMAGEMANAGER->findImage("npc_ok");

	for (int i = 0; i < 10; ++i)
	{
		damagePiece whitetemp;
		std::string imageName = "damage" + std::to_string(i);
		whitetemp.damage_white_img = IMAGEMANAGER->findImage(imageName);
		damage_vector_original.push_back(whitetemp);

		damagePiece redtemp;
		std::string imageNameRed = "Reddamage" + std::to_string(i);
		redtemp.damage_red_img = IMAGEMANAGER->findImage(imageNameRed);
		Monster_damage_vector_original.push_back(redtemp);
	}

	for (int y = 0; y < m_TileRowEA; ++y)
	{
		for (int x = 0; x < m_TileColEA; ++x)
		{
			tile temp;

			if (y >= 0 && y <= 3)
			{
				temp.init({ x, y }, TileType::wall, false, false, false, false, false, x, y);
			}
			else
			{
				temp.init({ x, y }, TileType::road, false, false, false, false, false, x, y);
			}
			m_tiles.push_back(temp);
		}
	}

	getItem_img = IMAGEMANAGER->findImage("item_get");


	player.init(1, 6);
	npc_m.init(16, 5);



	int monster_position_x[11] = { 15, 19,20, 8, 11, 20, 24, 2, 5,8 , 21 };
	int monster_position_y[11] = { 17, 25, 20, 24, 16, 19, 22,15,20,21,22 };

	for (int i = 0; i < 11; ++i)
	{
		monster _monster(&m_tiles);
		_monster.init(monster_position_x[i], monster_position_y[i], "포링");
		monster_vector.push_back(_monster);
	}

	return true;
}

void SampleScene::update(float _deltaTime)
{
	npc_m.update(_deltaTime);
	player.update(_deltaTime);
	for (auto& Monster : monster_vector)
	{
		if (monster_vector.size() == 0)
			continue;
		Monster.update(_deltaTime);
	}



	if (isStartGame == false)
	{
		start_alpha -= 2;

		openTime += _deltaTime;
		if (start_alpha <= 0)
		{
			if (player.m_player.centerX > npc_m.m_npc.centerX)
			{
				if (player.m_player.centerX + camera_tempX >= npc_m.m_npc.centerX)
				{
					camera_tempX -= 2;

				}
			}
			else if (player.m_player.centerX < npc_m.m_npc.centerX)
			{
				if (player.m_player.centerX + camera_tempX <= npc_m.m_npc.centerX)
				{
					camera_tempX += 2;

				}
			}

			if (player.m_player.centerY > npc_m.m_npc.centerY)
			{
				if (player.m_player.centerY + camera_tempY > npc_m.m_npc.centerY)
				{
					camera_tempY -= 2;

				}
			}
			else if (player.m_player.centerY < npc_m.m_npc.centerY)
			{
				if (player.m_player.centerY + camera_tempY < npc_m.m_npc.centerY)
				{
					camera_tempY += 2;

				}
			}
		}
		//	player.m_outPlayer = UTIL::IRectMakeCenter(WINSIZEX / 2+ camera_tempX, WINSIZEY / 2+ camera_tempY, WIDTH, HEIGHT);
		CAMERAMANAGER->setCameraFocus(&player.m_player.centerX, &player.m_player.centerY, WINSIZEX / 2, WINSIZEY / 2);
		CAMERAMANAGER->m_cameraOffX = camera_tempX;
		CAMERAMANAGER->m_cameraOffY = camera_tempY;


	}

	if ((player.m_player.centerX + camera_tempX >= npc_m.m_npc.centerX) && NpcChatNum == 0)
	{
		NpcChatNum = 1;
	}

	if (NpcChatNum == 1)
	{
		npc_bg_rect = UTIL::IRectMake(300, 300, 277, 178);
		npc_ok_rect = UTIL::IRectMake(npc_bg_rect.right - 50, npc_bg_rect.bottom - 25, 42, 20);


		if (UTIL::isPointRectCollision(m_ptMouse, npc_ok_rect) && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
		{
			NpcChatNum = 2;
			isStartGame = true;

		}
	}

	if (isStartGame == true && NpcChatNum == 2)
	{

		if (player.m_player.centerX < npc_m.m_npc.centerX + camera_tempX)
		{
			camera_tempX -= 2;
		}
		if (player.m_player.centerY > npc_m.m_npc.centerY + camera_tempY)
		{
			camera_tempY += 2;
		}
		CAMERAMANAGER->setCameraFocus(&player.m_player.centerX, &player.m_player.centerY, WINSIZEX / 2, WINSIZEY / 2);
		CAMERAMANAGER->m_cameraOffX = camera_tempX;
		CAMERAMANAGER->m_cameraOffY = camera_tempY;

		if ((player.m_player.centerX + camera_tempX <= player.m_player.centerX))
		{
			CAMERAMANAGER->m_cameraOffX = 0;
			CAMERAMANAGER->m_cameraOffY = 0;
			CAMERAMANAGER->setCameraFocus(&player.m_player.centerX, &player.m_player.centerY, WINSIZEX / 2, WINSIZEY / 2);
			NpcChatNum = 3;
			player.isStartGame = true;
		}

	}
	if (NpcChatNum >= 4 && NpcChatNum < 7)
	{
		npc_bg_rect = UTIL::IRectMake(300, 300, 277, 178);

		if (NpcChatNum < 6)
		{
			npc_next_rect = UTIL::IRectMake(npc_bg_rect.right - 50, npc_bg_rect.bottom - 25, 42, 20);
		}

		if (NpcChatNum == 6)
		{
			npc_ok_rect = UTIL::IRectMake(npc_bg_rect.right - 50, npc_bg_rect.bottom - 25, 42, 20);
		}


		if (NpcChatNum == 4 && UTIL::isPointRectCollision(m_ptMouse, npc_next_rect))
		{
			if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
				NpcChatNum = 5;
		}
		if (NpcChatNum == 5 && UTIL::isPointRectCollision(m_ptMouse, npc_next_rect))
		{
			if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
			{
				player.item_collection.push_back(ITEM->Item_collect("빨간포션", 5));
				player.item_collection.push_back(ITEM->Item_collect("파란포션", 5));
				isgetitem = true;
				curTime = TIMEMANAGER->getWorldTime();
				getitem = ITEM->Item_collect("빨간포션", 5);
				NpcChatNum = 6;
			}
		}
		if (NpcChatNum == 6 && UTIL::isPointRectCollision(m_ptMouse, npc_next_rect))
		{
			if (KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
			{
				NpcChatNum = 7;
				quest = true;
				player.moveOk = true;
			}
		}
	}
	if (NpcChatNum == 7 && player.moveOk == false)
	{
		npc_bg_rect = UTIL::IRectMake(300, 300, 277, 178);
		npc_ok_rect = UTIL::IRectMake(npc_bg_rect.right - 50, npc_bg_rect.bottom - 25, 42, 20);


		if (UTIL::isPointRectCollision(m_ptMouse, npc_ok_rect) && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
		{
			player.moveOk = true;

		}
	}

	if (NpcChatNum == 7)
	{
		if (poring_die >= 10)
		{
			isClearMonster = true;
			NpcChatNum = 8;
		}
	}

	if (NpcChatNum == 8)
	{
		npc_bg_rect = UTIL::IRectMake(300, 300, 277, 178);
		npc_ok_rect = UTIL::IRectMake(npc_bg_rect.right - 50, npc_bg_rect.bottom - 25, 42, 20);

		if (UTIL::isPointRectCollision(m_ptMouse, npc_ok_rect) && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
		{
			player.moveOk = true;
		}
	}


	//도착지 타일지정

	for (auto& Monster = monster_vector.begin(); Monster != monster_vector.end(); ++Monster)
	{
		if (monster_vector.size() == 0)
			continue;
		if (Monster->getTileindex() == player.getMemoryTileIndex())
		{
			player.settoMonsterIndex(Monster->getTileindex());

		}


		if (player.getisUi() == false)
		{
			//npc 대화하기
			if (UTIL::isPointRectCollision(m_ptMouse, npc_m.getnpcRect()))
			{
				player.isNpcchat = true;
				player.npc_cursor = true;
				npc_m.isShowName = true;

				if (NpcChatNum < 4 && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
				{
					NpcChatNum = 4;
					player.moveOk = false;
				}

				if (NpcChatNum == 7 && isClearMonster == false && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
				{
					player.moveOk = false;
				}


				if (NpcChatNum == 8 && KEYMANAGER->isOnceKeyDown(GAME_LMOUSE))
				{
					player.moveOk = false;
				}
			}
			else {
				player.isNpcchat = false;
				player.npc_cursor = false;
				npc_m.isShowName = false;
			}
			//몬스터 마우스커서 충돌시 마우스커서를 칼모양으로 변경
			for (auto& Monsters = monster_vector.begin(); Monsters != monster_vector.end(); )
			{
				if (UTIL::isPointRectCollision(m_ptMouse, Monsters->getMonsterRect()))
				{
					player.setisAttackCursor(true);
					Monsters->setisShowMonsterName(true);

					break;
				}
				else
				{
					Monsters->setisShowMonsterName(false);
					player.setisAttackCursor(false);
					++Monsters;
				}
			}
		}
		//몬스터 타겟이미지 설정
		for (auto& Monsters = monster_vector.begin(); Monsters != monster_vector.end(); )
		{
			if (player.getTargetMonster() && Monsters->getTileindex() == player.getMemoryTileIndex())
			{
				Monsters->isTargeted = true;
				break;
			}
			else if(player.isDie == true)
			{
				Monsters->isTargeted = false;
				Monsters++;
			}
			else
			{
				Monsters->isTargeted = false;
				Monsters++;
			}

		}
		if (UTIL::isPointRectCollision(m_ptMouse, Monster->getMonsterRect()))
		{

			player.setTargetMonsterRect(Monster->getMonsterRect());

		}
		for (auto& tile = m_tiles.begin(); tile != m_tiles.end(); ++tile)
		{
			if (tile->getTileNumber() == player.getMemoryTileIndex() && player.getisMove())
			{
				Playertileindex = player.getMemoryTileIndex();
				TileType tileType = getTileType(Playertileindex);

				if (tileType == TileType::outrange
					|| tileType == TileType::wall
					)
				{
					break;
				}
				else
				{
					tile->init(Playertileindex, getTileType(Playertileindex), false, false, false, true, false, Playertileindex.x, Playertileindex.y);
					prevMemoryX = Playertileindex.x;
					prevMemoryY = Playertileindex.y;
					PrevtileType = getTileType(Playertileindex);

					break;
				}
			}

			if (tile->m_BlockPositionX == prevMemoryX && tile->m_BlockPositionY == prevMemoryY
				&& player.getisMove() == false)
			{
				tile->init({ prevMemoryX, prevMemoryY }, PrevtileType, false, false, false, false, false,
					prevMemoryX, prevMemoryY);

				break;
			}
		}
	}


	for (auto Monster = monster_vector.begin(); Monster != monster_vector.end(); )
	{
		if (monster_vector.size() == 0)
			continue;
		if (Monster->getTileindex() == player.getPlayerToMonsterindex())
		{
			if (player.getisAttackCount() == 30)
			{
				damage_player_to_monster = true;
				Monster->monsterDamagesetting(true, player.getPlayerArrow());
				Monster->setMonsterDamageAni(true);
			}
			else if (player.getisAttackCount() == 31)
			{
				SOUNDMANAGER->stopChannel(Channel::eChannelattack);
				SOUNDMANAGER->playSound("attack", Channel::eChannelattack);
				Monster->setMonsterDamageAni(false);
				damage_player_to_monster = false;
			}
			else
			{
				damage_player_to_monster = false;
			}

			if (player.getisAttack() == false)
			{
				Monster->monsterDamagesetting(false, player.getPlayerArrow());
			}
		}
		Monster++;
	}


	for (auto Monster = monster_vector.begin(); Monster != monster_vector.end(); )
	{
		if (monster_vector.size() == 0)
			continue;
		if (player.getisDie() == true)
		{
			Monster->isMonsterBattle = false;
			Monster->isMonsterBattleFind = false;
			Monster->isMonsterDamage = false;
		}


		if (Monster->isMonsterBattleFind == true)
		{
			Monster->monsterAttacksetting(player.getisBattle(), player.getPlayerArrow());

			if (Monster->monster_attack_delay == 30)
			{
				damage_monster_to_player = true;

				DamageBundle m_dbundle;
				damagePiece m_p;
				if (damage_monster_to_player && player.getisDie() == false)
				{
					int monster_damagevalue_orign = Monster->m_atk - player.getStatDef();
					int monster_damagevalue = Monster->m_atk - player.getStatDef();

					int i = 0;

					while (monster_damagevalue)
					{
						m_p.isWhiteDmg = false;
						int index = monster_damagevalue % 10;
						m_p = Monster_damage_vector_original[index];

						//TODO : Set display position
						m_p.damage_rect_real = UTIL::IRectMake(player.getPlayerRect().centerX - 20 * i, player.getPlayerRect().centerY - 30, 30, 30);

						//TOTO end
						m_dbundle.pieces.push_back(m_p);
						monster_damagevalue /= 10;
						++i;
					}
					Monster_damage_vector.push_back(m_dbundle);
					SOUNDMANAGER->stopChannel(Channel::eChanneldamaged);
					SOUNDMANAGER->playSound("player_damaged", Channel::eChanneldamaged);
					player.setHp(monster_damagevalue_orign);

				}
				damage_monster_to_player = false;
				player.setisDamaged(true);

			}
			else if (Monster->monster_attack_delay == 65)
			{
				player.setisDamaged(false);
			}
			else
			{
				damage_monster_to_player = false;
			}
		}



		if (Monster->getTileindex() == player.getPlayerToMonsterindex())
		{
			if (Monster->getisEraseMonster())
			{
	

				srand(time(NULL));
				int getItemRandom = rand() % 10;
				if (getItemRandom < 3)
				{
					player.item_collection.push_back(Monster->m_have_item_1);
					isgetitem = true;
					curTime = TIMEMANAGER->getWorldTime();
					getitem = Monster->m_have_item_1;
				}
				else if (7 > getItemRandom && getItemRandom > 3)
				{
					player.item_collection.push_back(Monster->m_have_item_2);
					isgetitem = true;
					curTime = TIMEMANAGER->getWorldTime();
					getitem = Monster->m_have_item_2;
				}

				poring_die += 1;
				player.setBaseExp(Monster->getBaseExp());
				player.setJobExp(Monster->getJobExp());
				Monster = monster_vector.erase(Monster);
				player.setisBattle(false);
				player.setisDamaged(false);
				continue;
			}


			DamageBundle dbundle;
			damagePiece p;
			if (damage_player_to_monster)
			{
				int damagevalue_orign = player.getPlayerAtk() - Monster->getMonsterDef();
				int damagevalue = player.getPlayerAtk() - Monster->getMonsterDef();

				int i = 0;

				while (damagevalue)
				{
					p.isWhiteDmg = true;
					int index = damagevalue % 10;
					p = damage_vector_original[index];

					//TODO : Set display position
					p.damage_rect_real = UTIL::IRectMake(Monster->getMonsterRealRect().centerX - 20 * i, Monster->getMonsterRealRect().centerY - 30, 30, 30);

					//TOTO end
					dbundle.pieces.push_back(p);
					damagevalue /= 10;
					++i;
				}
				damage_vector.push_back(dbundle);

	
				Monster->setMonsterHp(damagevalue_orign);
			}


		}
		Monster++;
	}

	if (isgetitem)
	{
		if (TIMEMANAGER->getWorldTime() > curTime + 3)
		{
			isgetitem = false;
		}
	}

	//플레이어 to 몬스터 대미지 포물선 공식 
	for (auto iter = damage_vector.begin(); iter != damage_vector.end(); )
	{
		bool isEnd = false;
		for (auto iterer = iter->pieces.begin(); iterer != iter->pieces.end(); ++iterer)
		{
			bool isCanprint = true;
			iterer->gravity += 0.07;
			iterer->damage_rect_real.left += cosf(0.9) * 4;
			iterer->damage_rect_real.right += cosf(0.9) * 4;
			iterer->damage_rect_real.top += -sinf(0.9) * 4 + iterer->gravity;
			iterer->damage_rect_real.bottom += -sinf(0.9) * 4 + iterer->gravity;
			iterer->isWhiteDmg = true;
			CAMERAMANAGER->rectInCamera(iterer->damage_rect_out, iterer->damage_rect_real, isCanprint);
		}
		iter->alpha -= 2;
		if (iter->alpha <= 0)
		{
			iter = damage_vector.erase(iter);
			isEnd = true;
			break;
		}
		if (isEnd == false)++iter;
	}

	//몬스터 to 플레이어 대미지 포물선 공식
	for (auto iter = Monster_damage_vector.begin(); iter != Monster_damage_vector.end(); )
	{
		bool isEnd = false;
		for (auto iterer = iter->pieces.begin(); iterer != iter->pieces.end(); ++iterer)
		{
			bool isCanprint = true;
			iterer->gravity += 0.07;
			iterer->damage_rect_real.left += cosf(0.9) * 4;
			iterer->damage_rect_real.right += cosf(0.9) * 4;
			iterer->damage_rect_real.top += -sinf(0.9) * 4 + iterer->gravity;
			iterer->damage_rect_real.bottom += -sinf(0.9) * 4 + iterer->gravity;
			iterer->isWhiteDmg = false;
			CAMERAMANAGER->rectInCamera(iterer->damage_rect_out, iterer->damage_rect_real, isCanprint);
		}
		iter->alpha -= 2;
		if (iter->alpha <= 0)
		{
			iter = Monster_damage_vector.erase(iter);
			isEnd = true;
			break;
		}
		if (isEnd == false)++iter;
	}


}

void SampleScene::render(HDC hdc)
{
	for (auto& tile : m_tiles)
		tile.render(hdc);

	for (auto& Monster : monster_vector)
	{
		if (monster_vector.size() == 0)
			continue;
		Monster.render(hdc);
	}
	npc_m.render(hdc);
	player.render(hdc);

	for (auto iter = damage_vector.begin(); iter != damage_vector.end(); ++iter)
	{
		if (monster_vector.size() == 0)
			continue;
		iter->alphaRender(hdc);
	}

	for (auto iter = Monster_damage_vector.begin(); iter != Monster_damage_vector.end(); ++iter)
	{
		if (monster_vector.size() == 0)
			continue;
		iter->alphaRender(hdc);
	}


}

void SampleScene::afterRender(HDC hdc)
{



	if (start_alpha >= 0)
	{
		black_bg->alphaRender(hdc, 0, 0, start_alpha);
	}


	if (quest == true && isClearMonster == false)
	{

		black_bg_quest->alphaRender(hdc, WINSIZEX - 200, 200, 150);
		UTIL::PrintText(hdc, "마을을 지키자!", "", WINSIZEX - 195, 205, 13, RGB(255, 255, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "포링 처치", "", WINSIZEX - 195, 225, 13, RGB(255, 255, 0), true, RGB(0, 0, 0));

		std::string poring_die_temp = std::to_string(poring_die) + " / 10";
		UTIL::PrintText(hdc, poring_die_temp.c_str(), "", WINSIZEX - 195, 245, 13, RGB(255, 255, 0), true, RGB(0, 0, 0));
	}
	else if (quest == true && isClearMonster == true)
	{

		black_bg_quest->alphaRender(hdc, WINSIZEX - 200, 200, 150);
		UTIL::PrintText(hdc, "마을을 지키자!", "", WINSIZEX - 195, 205, 13, RGB(255, 255, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "포링 처치", "", WINSIZEX - 195, 225, 13, RGB(255, 255, 0), true, RGB(0, 0, 0));

		std::string poring_die_temp = std::to_string(poring_die) + " / 10  (완료)";
		UTIL::PrintText(hdc, poring_die_temp.c_str(), "", WINSIZEX - 195, 245, 13, RGB(100, 255, 100), true, RGB(0, 0, 0));
	}


	if (NpcChatNum == 1)
	{
		npc_smile->render(hdc, WINSIZEX - 349, WINSIZEY - 445);
		npc_bg->render(hdc, npc_bg_rect.left, npc_bg_rect.top);
		npc_ok->render(hdc, npc_ok_rect.left, npc_ok_rect.top);

		UTIL::PrintText(hdc, "[유나]", "", npc_bg_rect.left + 15, npc_bg_rect.top + 15, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "어디보자...", "", npc_bg_rect.left + 15, npc_bg_rect.top + 32, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "새로온 모험가님이 어디계시지...?", "", npc_bg_rect.left + 15, npc_bg_rect.top + 49, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "앗, 모험가님!", "", npc_bg_rect.left + 15, npc_bg_rect.top + 66, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "이쪽이에요!!", "", npc_bg_rect.left + 15, npc_bg_rect.top + 83, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));

	}

	if (NpcChatNum == 4)
	{
		npc_smile->render(hdc, WINSIZEX - 349, WINSIZEY - 445);
		npc_bg->render(hdc, npc_bg_rect.left, npc_bg_rect.top);
		npc_next->render(hdc, npc_next_rect.left, npc_next_rect.top);

		UTIL::PrintText(hdc, "[유나]", "", npc_bg_rect.left + 15, npc_bg_rect.top + 15, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "안녕하세요. 전 모험가님을 도와드릴", "", npc_bg_rect.left + 15, npc_bg_rect.top + 32, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "유나라고해요.", "", npc_bg_rect.left + 15, npc_bg_rect.top + 49, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "지금 마을사람들은 몬스터와의 전쟁중이라 ", "", npc_bg_rect.left + 15, npc_bg_rect.top + 66, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "저 혼자 마을을 지키고 있어요.", "", npc_bg_rect.left + 15, npc_bg_rect.top + 83, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "에고, 말이 참 길었죠?", "", npc_bg_rect.left + 15, npc_bg_rect.top + 100, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
	}
	if (NpcChatNum == 5)
	{
		npc_base->render(hdc, WINSIZEX - 349, WINSIZEY - 445);
		npc_bg->render(hdc, npc_bg_rect.left, npc_bg_rect.top);
		npc_next->render(hdc, npc_next_rect.left, npc_next_rect.top);

		UTIL::PrintText(hdc, "[유나]", "", npc_bg_rect.left + 15, npc_bg_rect.top + 15, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "초보 모험가님도 훌륭한 모험가가", "", npc_bg_rect.left + 15, npc_bg_rect.top + 32, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "될 수 있을거에요.", "", npc_bg_rect.left + 15, npc_bg_rect.top + 49, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, ".....", "", npc_bg_rect.left + 15, npc_bg_rect.top + 66, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "엥?", "", npc_bg_rect.left + 15, npc_bg_rect.top + 83, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "이게 무슨소리지...?", "", npc_bg_rect.left + 15, npc_bg_rect.top + 100, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
	}
	if (NpcChatNum == 6)
	{
		npc_gugjung->render(hdc, WINSIZEX - 349, WINSIZEY - 445);
		npc_bg->render(hdc, npc_bg_rect.left, npc_bg_rect.top);
		npc_ok->render(hdc, npc_ok_rect.left, npc_ok_rect.top);

		UTIL::PrintText(hdc, "[유나]", "", npc_bg_rect.left + 15, npc_bg_rect.top + 15, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "마을사람이 없는 틈을 타서 ", "", npc_bg_rect.left + 15, npc_bg_rect.top + 32, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "포링무리가 쳐들어왔어요!!", "", npc_bg_rect.left + 15, npc_bg_rect.top + 49, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "모험가님, 제가 물약을 지급 해드릴테니", "", npc_bg_rect.left + 15, npc_bg_rect.top + 66, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "포링을 물리쳐 마을을 지켜주세요!", "", npc_bg_rect.left + 15, npc_bg_rect.top + 83, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "만약 도움이 필요하면, 다시 찾아주세요!", "", npc_bg_rect.left + 15, npc_bg_rect.top + 100, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
	}
	if (NpcChatNum == 7 && isClearMonster == false && player.isDie == false && player.isRescu == false && player.moveOk == false)
	{
		npc_gugjung->render(hdc, WINSIZEX - 349, WINSIZEY - 445);
		npc_bg->render(hdc, npc_bg_rect.left, npc_bg_rect.top);
		npc_ok->render(hdc, npc_ok_rect.left, npc_ok_rect.top);

		UTIL::PrintText(hdc, "[유나]", "", npc_bg_rect.left + 15, npc_bg_rect.top + 15, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "도움을 요청하세요!", "", npc_bg_rect.left + 15, npc_bg_rect.top + 32, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
	}
	if (NpcChatNum == 8 && player.moveOk == false)
	{
		npc_smile->render(hdc, WINSIZEX - 349, WINSIZEY - 445);
		npc_bg->render(hdc, npc_bg_rect.left, npc_bg_rect.top);
		npc_ok->render(hdc, npc_ok_rect.left, npc_ok_rect.top);

		UTIL::PrintText(hdc, "[유나]", "", npc_bg_rect.left + 15, npc_bg_rect.top + 15, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "훌륭하게 마을을 지키셨네요.", "", npc_bg_rect.left + 15, npc_bg_rect.top + 32, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "이제 제법 모험가 티가 나는데요?", "", npc_bg_rect.left + 15, npc_bg_rect.top + 49, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "...", "", npc_bg_rect.left + 15, npc_bg_rect.top + 66, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "마을사람들이 빨리 돌아와야", "", npc_bg_rect.left + 15, npc_bg_rect.top + 83, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
		UTIL::PrintText(hdc, "할텐데...", "", npc_bg_rect.left + 15, npc_bg_rect.top + 100, 13, RGB(0, 0, 0), true, RGB(0, 0, 0));
	}



	for (auto& Monster : monster_vector)
	{
		if (monster_vector.size() == 0)
			continue;
		Monster.afterRender(hdc);
	}

	if (isgetitem)
	{
		getItem_img->render(hdc, WINSIZEX / 2 - 62, 97);
		getitem.Item_icon_image->render(hdc, WINSIZEX / 2 - 52, 106);
		std::string	getitemtemp = getitem.Item_name + " " + std::to_string(getitem.Item_ea) + "개 획득";
		UTIL::PrintText(hdc, getitemtemp.c_str(), "", WINSIZEX / 2 - 20, 109, 12, RGB(0, 0, 0), true, RGB(0, 0, 0));
	}

	npc_m.afterRender(hdc);
	player.afterRender(hdc);

}

void SampleScene::debugRender(HDC hdc)
{
	for (auto& tile : m_tiles)
	{
		tile.debugRender(hdc);
	}

	npc_m.debugRender(hdc);
	player.debugRender(hdc);
	for (auto& Monster : monster_vector)
	{
		if (monster_vector.size() == 0)
			continue;
		Monster.debugRender(hdc);
	}
}

TileType SampleScene::getTileType(POINT _XY)
{
	if (0 <= _XY.x && _XY.x <= m_TileColEA && 0 <= _XY.y && _XY.y <= m_TileRowEA)
	{
		return m_tiles[_XY.x + _XY.y * m_TileColEA].m_Type;
	}
	else
	{
		return TileType::outrange;
	}
}



void SampleScene::release()
{
}
