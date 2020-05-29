#pragma once
#include "Game/GameObject/Object.h"
#include "Game/Map/Tile.h"

class Monster_Coordinate // x, y 좌표 클래스
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
	Monster_Coordinate() = default;
	Monster_Coordinate(int _x, int _y)
		: x(_x), y(_y)
	{}
};

class Monster_Astar
{
public:

	class Monster_Node
	{
	public:
		Monster_Coordinate point;
		int F, G, H; // F = 비용, G = 지난 거리, H = 남은 거리

		Monster_Coordinate DestPoint;
		Monster_Node* pParent;

	public:
		Monster_Node() = default;
		Monster_Node(int _x, int _y, Monster_Node* _pParent, Monster_Coordinate _DestPoint);
		~Monster_Node();

		bool init();
		void update(float _deltaTime);
		void release();
		void render(HDC hdc);
		void afterRender(HDC hdc);
		void debugRender(HDC hdc);
	};


public:
	Monster_Astar(Monster_Coordinate _StartPoint, Monster_Coordinate _EndPoint, std::vector<tile>* tiles)
		:m_Tiles(tiles)
	{
		StartPoint.x = _StartPoint.x;
		StartPoint.y = _StartPoint.y;
		EndPoint.x = _EndPoint.x;
		EndPoint.y = _EndPoint.y;
		//FindPath();
	}
	Monster_Astar(std::vector<tile>* tiles)
		:m_Tiles(tiles)
	{
	}
	~Monster_Astar();

private:
	// 오픈노드 중 F값이 제일 작은 노드 찾아서 반환
	std::list<Monster_Node*>::iterator FindNextNode(std::list<Monster_Node*>* pOpenNode);
	// 노드리스트에서 x,y 좌표의 노드를 찾아서 주소를 반환. 없으면 end()반환.
	std::list<Monster_Node*>::iterator FindCoordNode(int _x, int _y, std::list<Monster_Node*>* NodeList);
	// 8방향 노드를 탐색하고 열린 노드에 추가 및 부모 변경을 실행함
	void ExploreNode(Monster_Node* SNode, std::list<Monster_Node*>* OpenNode, std::list<Monster_Node*>* CloseNode, Monster_Coordinate EndPoint);

public:
	std::list<Monster_Coordinate*> FindPath(Monster_Coordinate StartPoint, Monster_Coordinate EndPoint);
	Monster_Coordinate GetPos(int order); // order번째 경로의 좌표를 받아옴
	inline std::list<Monster_Coordinate*> GetPath() { return path; } // 경로를 Coordinate* 리스트로 통째로 받아옴

	void PrintNavi();
	void PrintPath();
	void PrintPath(std::list<Monster_Coordinate*> _path);

	TileType getNodeTiletype(POINT _XY);


private:
	tile Navi; // 맵 생성
	tile printNavi; // 출력용 맵 생성(경로까지 출력)

private:

	std::vector<tile>* m_Tiles = nullptr; // 타일을 참조하고 있다(by pointer)
	Monster_Coordinate StartPoint; // 출발지점
	Monster_Coordinate EndPoint; // 목표지점
	std::list<Monster_Coordinate*> path; // 경로
	std::list<Monster_Coordinate*>::iterator iter; // 경로 iterator


};
class monster

{

public:
	monster() = default;
	monster(std::vector<tile>* tiles)
		:m_Tiles(tiles), m_Astar(tiles)
	{
	}
	~monster();
	bool init(int startX, int startY, std::string _name);
	void release();
public:
	void update(float _deltaTime);
	void render(HDC hdc);
	void afterRender(HDC hdc);
	void debugRender(HDC hdc);

	void monsterAnihandle();
	void setMonsterDamageAni(bool value) { isMonsterDamageAni = value; }
	int getMonsterHp() { return m_Hp;}
	void setMonsterLive(bool _isLive) { isLive = _isLive; }
	bool getisEraseMonster() { return isEraseMonster; }
	void setisShowMonsterName(bool _isShowName) { isShowName = _isShowName; }

	UTIL::IRECT getMonsterRect() { return m_outmonster; }
	UTIL::IRECT getMonsterRealRect() { return m_monster; }
	void movesetting();
	POINT getTileindex();
	void monsterGensetting(std::string _name);
	void monsterDamagesetting(bool _isMonsterDamage, int playerArrow);
	void monsterAttacksetting(bool _isPlayerBattle, int playerArrow);
	void setMonsterHp(int damage) { m_Hp -= damage; }

	int getMonsterDef() { return m_def; }
	int getBaseExp() { return m_base_exp; }
	int getJobExp() { return m_job_exp; }
	int getMonsterAttackDelay() { return monster_attack_delay; }
private:
	std::vector<tile>* m_Tiles = nullptr; // 타일을 참조하고 있다(by pointer)
	std::list<Monster_Coordinate*> m_FindPath;
	Monster_Astar m_Astar;
	std::map<std::string, std::string> m_AniNameMap;

public:
	POINT prvPos;
	static int s_AniCount;
	Item_struct	m_have_item_1;
	Item_struct	m_have_item_2;
	int move_delay = 0;
	int move_delay_cnt = 0;
	bool isMoveSolo = false;
	bool isShowName = false;
	bool isTargeted = false;
	bool isCanprint = true;
	bool isDest = false;
	bool isMove = false;
	bool isMoveComplete = false;
	bool isMonsterDamage = false;
	bool isMonsterDamageAni = false;
	bool isMonsterAttack = false;
	bool isMonsterAttackAni = false;
	bool isMonsterBattle = false;
	bool isMonsterBattleFind = false;
	bool isEraseMonster = false;

	bool is_monster_arrow_1 = false;
	bool is_monster_arrow_3 = false;
	bool is_monster_arrow_5 = false;
	bool is_monster_arrow_6 = false;
	bool is_monster_arrow_7 = false;
	bool is_monster_arrow_9 = false;
	bool is_monster_arrow_10 = false;
	bool is_monster_arrow_12 = false;

	bool is_monster_move_1 = false;
	bool is_monster_move_3 = false;
	bool is_monster_move_5 = false;
	bool is_monster_move_6 = false;
	bool is_monster_move_7 = false;
	bool is_monster_move_9 = false;
	bool is_monster_move_10 = false;
	bool is_monster_move_12 = false;

	bool  is_monster_damage_1 = false;
	bool  is_monster_damage_5 = false;
	bool  is_monster_damage_7 = false;
	bool  is_monster_damage_10 = false;

	bool is_monster_attack_1 = false;
	bool is_monster_attack_5 = false;
	bool is_monster_attack_7 = false;
	bool is_monster_attack_10 = false;


	bool isLive = true;
	int m_monster_PosX;
	int m_monster_PosY;

	int monsterDieAlpha = 255;
	int monsterDieFrameX = 0;
	int dieCount = 0;
	int dieIndex;

	UTIL::IRECT m_monster;
	UTIL::IRECT m_outmonster;
	UTIL::IRECT monster_mini_Hp_gaze;
	UTIL::IRECT monster_mini_curHp_gaze;
	UTIL::IRECT monster_target;

	Image* m_target;
	Image* m_shadow;

	Image* m_monster_arrow_img_1;
	Image* m_monster_arrow_img_3;
	Image* m_monster_arrow_img_5;
	Image* m_monster_arrow_img_6;
	Image* m_monster_arrow_img_7;
	Image* m_monster_arrow_img_9;
	Image* m_monster_arrow_img_10;
	Image* m_monster_arrow_img_12;

	Image* m_monster_move_img_1;
	Image* m_monster_move_img_3;
	Image* m_monster_move_img_5;
	Image* m_monster_move_img_6;
	Image* m_monster_move_img_7;
	Image* m_monster_move_img_9;
	Image* m_monster_move_img_10;
	Image* m_monster_move_img_12;

	Image* m_monster_attack_img_1;
	Image* m_monster_attack_img_5;
	Image* m_monster_attack_img_7;
	Image* m_monster_attack_img_10;

	Image* m_monster_damage_img_1;
	Image* m_monster_damage_img_5;
	Image* m_monster_damage_img_7;
	Image* m_monster_damage_img_10;

	Image* m_monster_die_img;

	Animation* ani_monster_arrow_1;
	Animation* ani_monster_arrow_5;
	Animation* ani_monster_arrow_7;
	Animation* ani_monster_arrow_10;

	Animation* ani_monster_move_1;
	Animation* ani_monster_move_5;
	Animation* ani_monster_move_7;
	Animation* ani_monster_move_10;

	Animation* ani_monster_attack_img_1;
	Animation* ani_monster_attack_img_5;
	Animation* ani_monster_attack_img_7;
	Animation* ani_monster_attack_img_10;

	Animation* ani_monster_damage_img_1;
	Animation* ani_monster_damage_img_5;
	Animation* ani_monster_damage_img_7;
	Animation* ani_monster_damage_img_10;

	Animation* ani_monster_die;

	std::string m_name;

	int m_level;
	int m_Hp;
	int m_MaxHp;
	int m_atk;
	int m_matk;
	int m_def;
	int m_mdef;
	int m_feel;
	int m_aspd;
	int m_base_exp;
	int m_job_exp;

	int monsterArrow;

	int monster_attack_count = 0;
	int monster_attack_delay = 0;


};



