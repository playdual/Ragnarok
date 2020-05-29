#pragma once
#include "Game/GameObject/Object.h"
#include "Game/Map/Tile.h"
#include "Game/Skill/Skill.h"

#include <list>

class Coordinate // x, y 좌표 클래스
{
public:
	int x;
	int y;
public:
	inline void Set(int _x = 0, int _y = 0)
	{
		x = _x; y = _y;
	}
public:
	Coordinate() = default;
	Coordinate(int _x, int _y)
		: x(_x), y(_y)
	{}
};

class Astar
{
public:

	class Node
	{
	public:
		Coordinate point;
		int F, G, H; // F = 비용, G = 지난 거리, H = 남은 거리

		Coordinate DestPoint;
		Node* pParent;

	public:
		Node() = default;
		Node(int _x, int _y, Node* _pParent, Coordinate _DestPoint);
		~Node();

		bool init();
		void update(float _deltaTime);
		void release();
		void render(HDC hdc);
		void afterRender(HDC hdc);
		void debugRender(HDC hdc);
	};


public:
	Astar(Coordinate _StartPoint, Coordinate _EndPoint, std::vector<tile>& tiles)
		:m_Tiles(tiles)
	{
		StartPoint.x = _StartPoint.x;
		StartPoint.y = _StartPoint.y;
		EndPoint.x = _EndPoint.x;
		EndPoint.y = _EndPoint.y;
		//FindPath();
	}
	Astar(std::vector<tile>& tiles)
		:m_Tiles(tiles)
	{
	}
	~Astar();

private:
	// 오픈노드 중 F값이 제일 작은 노드 찾아서 반환
	std::list<Node*>::iterator FindNextNode(std::list<Node*>* pOpenNode);
	// 노드리스트에서 x,y 좌표의 노드를 찾아서 주소를 반환. 없으면 end()반환.
	std::list<Node*>::iterator FindCoordNode(int _x, int _y, std::list<Node*>* NodeList);
	// 8방향 노드를 탐색하고 열린 노드에 추가 및 부모 변경을 실행함
	void ExploreNode(Node* SNode, std::list<Node*>* OpenNode, std::list<Node*>* CloseNode, Coordinate EndPoint);

public:
	std::list<Coordinate*> FindPath(Coordinate StartPoint, Coordinate EndPoint);
	Coordinate GetPos(int order); // order번째 경로의 좌표를 받아옴
	inline std::list<Coordinate*> GetPath() { return path; } // 경로를 Coordinate* 리스트로 통째로 받아옴

	void PrintNavi();
	void PrintPath();
	void PrintPath(std::list<Coordinate*> _path);

	TileType getNodeTiletype(POINT _XY);


private:
	tile Navi; // 맵 생성
	tile printNavi; // 출력용 맵 생성(경로까지 출력)

private:

	std::vector<tile>& m_Tiles; // 타일을 참조하고 있다
	Coordinate StartPoint; // 출발지점
	Coordinate EndPoint; // 목표지점
	std::list<Coordinate*> path; // 경로
	std::list<Coordinate*>::iterator iter; // 경로 iterator


};

class character
{
public:
	character(std::vector<tile>& tiles)
		:m_Tiles(tiles), m_Astar(tiles)
	{
	}
	~character() {}

	bool init(int startX, int startY);
	void release();

public:
	void update(float _deltaTime);
	void render(HDC hdc);
	void afterRender(HDC hdc);
	void debugRender(HDC hdc);

	POINT getMemoryTileIndex();
	POINT getPlayerTileIndex();
	bool getisMonster(POINT _XY);
	bool getPlayerisTileDest();
	bool getisMove() { return isMove; }
	bool getisUi() { return isUi; }
	UTIL::IRECT getPlayerRect() { return m_player; }
	void setisMove(bool Movebool) { isMove = Movebool; }
	void itemsettiong();
	void moveSetting(float _deltaTime);
	bool getisNpc(POINT _XY);
	void Hp_Sp_mini_bar_setting();
	void statSetting();
	void uiSetting();
	void playerImgSetting();
	void battleSetting();
	void settoMonsterIndex(POINT _XY) { toMonsterIndex = _XY; }
	void setTargetMonster(bool Value) { isTargetMonster = Value; }
	bool getTargetMonster() { return isTargetMonster; }
	void setTargetMonsterRect(UTIL::IRECT Value) { TargetMonster = Value; }
	void setPlayerHp(int damage) { stat_Curhp -= damage; }
	void setisBattle(bool _isBattle) { isBattle = _isBattle; }
	void setisDamaged(bool _isDamaged) { isDamaged = _isDamaged; }
	void setisAttackCursor(bool _isAttackcursor) { isAttackcursor = _isAttackcursor; }
	bool getisAttack() { return isAttack; }
	bool getisBattle() { return isBattle; }
	bool getisDie() { return isDie; }
	int getStatDef() { return stat_def; }
	void setBaseExp(int _baseExp) { stat_base_curExp += _baseExp; }
	void setJobExp(int _jobExp) { stat_job_curExp += _jobExp; }
	void setHp(int monsterDamage) { stat_Curhp -= monsterDamage; }
	POINT getPlayerToMonsterindex() { return toMonsterIndex; }
	int getPlayerAtk() { return stat_atk; }
	int getisAttackCount() { return attack_delay_count; }
	int getPlayerArrow() { return playerArrow; }
	TileType getTileType(POINT _XY);

	void playerAnihandle();

	void setfocusCamera(UTIL::IRECT realRect);

	void setStartGame(bool _start) { isStartGame = _start; }
public:


	//story
	
	bool moveOk = true;
	bool isLevelup = false;
	int levelup_cnt = 0;

	bool npc_cursor = false;
	bool isStartGame = false;
	float openTime = 0;

	bool isCanprint = true;

	bool isdie_first = true;
	bool isdie_fix = false;
	UTIL::IRECT die_ui_rect;
	UTIL::IRECT die_ui_bar_rect;
	UTIL::IRECT die_ui_bar_cancle_rect;
	UTIL::IRECT die_ui_bar_recure_rect;
	
	Image* choose_Bar;

	int die_memory_x = WINSIZEX / 2 - 100;
	int die_memory_y = WINSIZEY / 2 ;
	int die_alpha = 255;
	int cheat_temp = 0;
	bool isNpcchat = false;
	bool isRescu = false;

	bool iswing = false;
	int Rescu_alpha = 0;
	Image* black_bg_;

	Image* die_ui_img;
	Image* wing_img;
	Image* wing_wing_img;
	Animation* ani_wing;
	Animation* ani_wing_wing;

	Image* npc_cursor_img;

	

	std::string player_name;

	std::vector<tile>& m_Tiles; // 타일을 참조하고 있다
	std::list<Coordinate*> m_FindPath;
	std::vector<skill_struct> quickslot;
	std::vector<skill_struct> quickslot2;
	std::vector<skill_struct> move_icon;

	UTIL::IRECT m_player;
	UTIL::IRECT m_outPlayer;
	UTIL::IRECT TargetMonster;
	int playerTilenumber = -1;
	int m_playerPosX = 0;
	int m_playerPosY = 0;
	int QuickSlot_1_count = 0;
	int QuickSlot_2_count = 0;

	Astar m_Astar;

	POINT toMonsterIndex;
	POINT PlayercurTileIndex;
	POINT DestcurTileIndex;
	POINT memoryDestCurTileindex = { -1,-1 };

	bool isUseQuickSlot_1 = false;
	bool isUseQuickSlot_2 = false;
	bool isUseQuickSlot_3 = false;
	bool isUseQuickSlot_4 = false;
	bool ismemoryMoveIndex = true;
	bool isMove = false;
	bool isMoveComplete = true;
	bool isDest = false;
	bool isMovetemp = false;
	bool isMovetoMonster = false;
	bool isBattle = false;
	bool isAttack = false;
	bool isTargetMonster = false;
	bool isDie = false;

	int playerArrow;

	bool is_player_arrow_1 = false;
	bool is_player_arrow_3 = false;
	bool is_player_arrow_5 = false;
	bool is_player_arrow_6 = false;
	bool is_player_arrow_7 = false;
	bool is_player_arrow_9 = false;
	bool is_player_arrow_10 = false;
	bool is_player_arrow_12 = false;

	bool is_player_move_1 = false;
	bool is_player_move_3 = false;
	bool is_player_move_5 = false;
	bool is_player_move_6 = false;
	bool is_player_move_7 = false;
	bool is_player_move_9 = false;
	bool is_player_move_10 = false;
	bool is_player_move_12 = false;

	bool is_player_attack_1 = false;
	bool is_player_attack_5 = false;
	bool is_player_attack_7 = false;
	bool is_player_attack_10 = false;

	bool is_player_attackwait_1 = false;
	bool is_player_attackwait_5 = false;
	bool is_player_attackwait_7 = false;
	bool is_player_attackwait_10 = false;

	bool isDamaged = false;
	bool is_player_damaged_1 = false;
	bool is_player_damaged_5 = false;
	bool is_player_damaged_7 = false;
	bool is_player_damaged_10 = false;

	Image* player_shadow;

	Image* player_body_base;
	Image* player_move_1;
	Image* player_move_3;
	Image* player_move_5;
	Image* player_move_6;
	Image* player_move_7;
	Image* player_move_9;
	Image* player_move_10;
	Image* player_move_12;

	Image* player_attack_1;
	Image* player_attack_5;
	Image* player_attack_7;
	Image* player_attack_10;

	Image* player_attackwait_1;
	Image* player_attackwait_5;
	Image* player_attackwait_7;
	Image* player_attackwait_10;

	Image* player_damaged_1;
	Image* player_damaged_5;
	Image* player_damaged_7;
	Image* player_damaged_10;

	Image* player_head_move_1;
	Image* player_head_move_3;
	Image* player_head_move_5;
	Image* player_head_move_6;
	Image* player_head_move_7;
	Image* player_head_move_9;
	Image* player_head_move_10;
	Image* player_head_move_12;

	Image* player_head_attack_1;
	Image* player_head_attack_5;
	Image* player_head_attack_7;
	Image* player_head_attack_10;

	Image* player_head_attackwait_1;
	Image* player_head_attackwait_5;
	Image* player_head_attackwait_7;
	Image* player_head_attackwait_10;

	Image* player_head_damaged_1;
	Image* player_head_damaged_5;
	Image* player_head_damaged_7;
	Image* player_head_damaged_10;

	Image* weapon_wait_1;
	Image* weapon_wait_5;
	Image* weapon_wait_7;
	Image* weapon_wait_10;

	Image* weapon_attack_1;
	Image* weapon_attack_5;
	Image* weapon_attack_7;
	Image* weapon_attack_10;

	Image* player_die_1;
	Image* player_die_5;
	Image* player_die_7;
	Image* player_die_10;

	Image* player_base_levelUp;
	Image* player_job_levelUp;

	Image* player_head_base;

	Image* player_die;
	Image* player_head_die;

	Image* dest_tile;
	Image* cursor_base;
	Image* cursor_add;
	Image* cursor_add_select;
	Image* cursor_attack;

	Animation* ani_cursor_base;
	Animation* ani_cursor_npc;

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

	Animation* ani_player_move_1;
	Animation* ani_player_move_3;
	Animation* ani_player_move_5;
	Animation* ani_player_move_6;
	Animation* ani_player_move_7;
	Animation* ani_player_move_9;
	Animation* ani_player_move_10;
	Animation* ani_player_move_12;

	Animation* ani_player_head_move_1;
	Animation* ani_player_head_move_3;
	Animation* ani_player_head_move_5;
	Animation* ani_player_head_move_6;
	Animation* ani_player_head_move_7;
	Animation* ani_player_head_move_9;
	Animation* ani_player_head_move_10;
	Animation* ani_player_head_move_12;

	Animation* ani_player_attack_1;
	Animation* ani_player_attack_5;
	Animation* ani_player_attack_7;
	Animation* ani_player_attack_10;

	Animation* ani_player_attackwait_1;
	Animation* ani_player_attackwait_5;
	Animation* ani_player_attackwait_7;
	Animation* ani_player_attackwait_10;

	Animation* ani_player_damaged_1;
	Animation* ani_player_damaged_5;
	Animation* ani_player_damaged_7;
	Animation* ani_player_damaged_10;

	Animation* ani_player_head_attack_1;
	Animation* ani_player_head_attack_5;
	Animation* ani_player_head_attack_7;
	Animation* ani_player_head_attack_10;

	Animation* ani_player_head_attackwait_1;
	Animation* ani_player_head_attackwait_5;
	Animation* ani_player_head_attackwait_7;
	Animation* ani_player_head_attackwait_10;

	Animation* ani_player_head_damaged_1;
	Animation* ani_player_head_damaged_5;
	Animation* ani_player_head_damaged_7;
	Animation* ani_player_head_damaged_10;

	Animation* ani_weapon_wait_1;
	Animation* ani_weapon_wait_5;
	Animation* ani_weapon_wait_7;
	Animation* ani_weapon_wait_10;

	Animation* ani_weapon_attack_1;
	Animation* ani_weapon_attack_5;
	Animation* ani_weapon_attack_7;
	Animation* ani_weapon_attack_10;

	/////////////////ui//////////////////////
	UTIL::IRECT base_ui_rect;
	UTIL::IRECT quickslot_ui_rect;
	UTIL::IRECT quickslot_1_ui_rect;
	UTIL::IRECT quickslot_2_ui_rect;

	bool is_skill_icon_move = false;
	bool is_item_icon_move = false;

	Image* base_ui_img;
	Image* quickslot_ui_img;
	Image* quickslot_item_ui_img;

	bool isAddcursor = false;
	bool isAddcursor_select = false;
	bool isAttackcursor = false;
	bool isUi = false;
	bool isbase = false;
	bool isStat = false;
	bool isStat_btn = false;
	bool isStat_first = true;
	bool isStat_fix = false;
	bool isSkill = false;
	bool isSkill_btn = false;
	bool isSkill_first = true;
	bool isSkill_fix = false;
	bool isItem = false;
	bool isItem_btn = false;
	bool isItem_first = true;
	bool isItem_fix = false;

	bool isStatAddStr = false;
	bool isStatAddAgi = false;
	bool isStatAddVit = false;
	bool isStatAddInt = false;
	bool isStatAddDex = false;
	bool isStatAddLuk = false;



	//status
	Image* stat_ui_img;
	Image* skill_ui_img;
	Image* ui_bar_img;
	Image* ui_bar_cancle_img;
	Image* ui_minicircle_on_img;
	Image* ui_minicircle_off_img;

	Image* stat_ui_btn_on_img;
	Image* stat_ui_btn_off_img;

	//skill
	Image* skill_ui_btn_on_img;
	Image* skill_ui_btn_off_img;

	Image* stat_add_img;
	Image* skill_no_img;



	Image* gaze_left;
	Image* gaze_mid;
	Image* gaze_right;

	//Hp, Sp mini bar
	UTIL::IRECT stat_mini_Hp_gaze;
	UTIL::IRECT stat_mini_Hp_Cur_gaze;
	UTIL::IRECT stat_mini_Sp_gaze;
	UTIL::IRECT stat_mini_Sp_Cur_gaze;


	UTIL::IRECT stat_Hp_gaze;
	UTIL::IRECT stat_Sp_gaze;

	UTIL::IRECT stat_ui_rect;
	UTIL::IRECT stat_ui_bar_rect;
	UTIL::IRECT stat_ui_bar_cancle_rect;
	UTIL::IRECT stat_ui_btn_rect;

	UTIL::IRECT skill_ui_rect;
	UTIL::IRECT skill_ui_bar_rect;
	UTIL::IRECT skill_ui_bar_cancle_rect;
	UTIL::IRECT skill_ui_btn_rect;

	UTIL::IRECT stat_add_str_btn_rect;
	UTIL::IRECT stat_add_agi_btn_rect;
	UTIL::IRECT stat_add_vit_btn_rect;
	UTIL::IRECT stat_add_int_btn_rect;
	UTIL::IRECT stat_add_dex_btn_rect;
	UTIL::IRECT stat_add_luk_btn_rect;

	UTIL::IRECT stat_base_Exp_rect;
	UTIL::IRECT stat_base_Cur_Exp_rect;
	UTIL::IRECT stat_job_Exp_rect;
	UTIL::IRECT stat_job_Cur_Exp_rect;

	int skill_alpha = 255;

	int stat_alpha = 255;

	int stat_memory_x = 300;
	int stat_memory_y = 400;

	int skill_memory_x = 700;
	int skill_memory_y = 400;

	int skill_point = 0;

	std::string job;

	int stat_base_level = 1;
	int stat_job_level = 1;
	int stat_point;

	int stat_Maxweight;
	int stat_Curweight = 0;

	int stat_str;
	int stat_agi;
	int stat_vit;
	int stat_int;
	int stat_dex;
	int stat_luk;

	int stat_str_need_point = 2;
	int stat_agi_need_point = 2;
	int stat_vit_need_point = 2;
	int stat_int_need_point = 2;
	int stat_dex_need_point = 2;
	int stat_luk_need_point = 2;

	int stat_atk;
	int stat_matk;
	int stat_def;
	int stat_mdef;
	int stat_hit;
	int stat_cri;
	int stat_feel;
	int stat_aspd;
	int aspd_Maxcount;
	int aspd_count = 0;
	int attack_delay = 70;
	int attack_delay_count = 0;

	bool isAttackAni = false;
	bool isDamagedAni = false;

	int Damaged_count = 0;

	int stat_Maxhp;
	int stat_Curhp;
	int stat_Maxsp;
	int stat_Cursp;
	int stat_base_MaxExp = 65;
	int stat_job_MaxExp = 20;
	int stat_base_curExp = 0;
	int stat_job_curExp = 0;

	int equip_atk = 50;
	int equip_matk = 0;
	int equip_def = 0;
	int equip_mdef = 0;
	int equip_hit = 0;
	int equip_cri = 0;
	int equip_feel = 0;
	int equip_aspd = 0;

	int have_zeny = 0;

	///아이템 관리///
	bool isIteminfoView = false; //아이템 정보 보기

	bool isGetItem = false;		//아이템 얻었을때 판별
	bool is_item_usetab = true;		//소비탭
	bool is_item_equiptab = false;	//장비탭
	bool is_item_kindtab = false;	//기타탭

public:
	std::vector<Item_struct> quickslot_item_1;		//아이템 퀵슬롯용
	std::vector<Item_struct> quickslot_item_2;
	std::vector<Item_struct> move_item_icon;

	UTIL::IRECT quickslot_item_ui_rect;
	UTIL::IRECT quickslot_item_1_ui_rect;
	UTIL::IRECT quickslot_item_2_ui_rect;


	std::vector<Item_struct> item_collection;		//아이템 분류작업용
	std::vector<Item_struct> item_use_vector;		//소비탭
	std::vector<Item_struct> item_equip_vector;		//장비탭
	std::vector<Item_struct> item_kind_vector;		//기타탭
	std::vector<Item_struct> item_info_vector;		//정보를 보기위한 벡터



	UTIL::IRECT item_ui_rect;
	UTIL::IRECT item_ui_bar_rect;
	UTIL::IRECT item_ui_bar_cancle_rect;
	UTIL::IRECT item_use_rect;
	UTIL::IRECT item_equip_rect;
	UTIL::IRECT item_kind_rect;
	UTIL::IRECT item_ui_btn_rect;

	UTIL::IRECT item_info_cancle_rect;

	Image* item_shadow_img;
	
	Image* Item_ui_img;
	Image* Item_ui_potiontab_img;
	Image* Item_ui_equiptab_img;
	Image* Item_ui_kindtab_img;

	Image* item_ui_btn_on_img;
	Image* item_ui_btn_off_img;

	Image* item_info_bar_img;
	Image* item_info_bar_cancle_img;


	int item_alpha = 255;
	int item_memory_x = 300;
	int item_memory_y = 300;


	//chat
	UTIL::IRECT chat_rect;
	UTIL::IRECT chat_player_rect;
	Image* chat_bg;
	Image* chat_on;
	int chat_alpha =150;
	bool is_chat=false;

	std::vector<std::string> chat_input;
	std::string chat_1;
	std::string chat_2;
	std::string chat_3;

	std::string underbar;

	float curtime = 0;

	int cheat = 1;
	bool ischeat = false;
	int chatcnt = 301;
	int cheatcnt = 0;


};

