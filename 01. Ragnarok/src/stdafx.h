// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
#pragma once
#pragma warning(disable : 4996)
#define WIN32_LEAN_AND_MEAN 
#include <windows.h>
#include <SDKDDKVer.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <math.h>
#include <assert.h>

//STL
#include <vector>
#include <map>
#include <string>
#include <memory>
#include <algorithm>
#include <bitset>
#include <stack>
#include <vector>
#include <list>

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include "Common/UTILS.h"

//======================================
//##			디파인문			  ##
//======================================
#define WINNAME		(LPTSTR)(TEXT("Ragnarok"))
#define WINSTARTX   100
#define WINSTARTY   100
#define WINSIZEX	1024
#define	WINSIZEY	768
#define WINSTYLE	WS_CAPTION | WS_SYSMENU

//player key setting
#define P1_UP			0
#define P1_DOWN			1
#define P1_LEFT			2
#define P1_RIGHT		3
#define P1_EVENT		4
#define P1_USEITEM		5
#define GAME_STAT		6
#define GAME_SKILL		7
#define GAME_INVEN		8
#define GAME_1			9
#define GAME_2			10
#define GAME_3			11
#define GAME_4			12


#define GAME_A			13
#define GAME_B			14
#define GAME_C			15
#define GAME_D			16
#define GAME_E			17
#define GAME_F			18
#define GAME_G			19
#define GAME_H			20
#define GAME_I			21
#define GAME_J			22
#define GAME_K			23
#define GAME_L			24
#define GAME_M			25
#define GAME_N			26
#define GAME_O			27
#define GAME_P			28
#define GAME_Q			29
#define GAME_R			30
#define GAME_S			31
#define GAME_T			32
#define GAME_U			33
#define GAME_V			34
#define GAME_W			35
#define GAME_X			36
#define GAME_Y			37
#define GAME_Z			38
#define GAME_BACK		39
#define GAME_SPACE		40


#define GAME_LMOUSE		48
#define GAME_RMOUSE		49
#define GAME_SHOWFPS    50
#define GAME_DEBUGMODE	51
#define GAME_RECTMODE   52
#define GAME_RTT		53
#define GAME_ENTER		54

//게임에 쓸 디파인문
#define zoom 1
#define WIDTH (60*zoom)
#define HEIGHT (60*zoom)
#define OFFSETX (2*zoom)
#define OFFSETY (54*zoom)
#define PLAYER_IMAGE_OFFSETX (+10*zoom)
#define PLAYER_IMAGE_OFFSETY (-25*zoom)
#define MONSTER_IMAGE_OFFSETX +5
#define m_TileColEA	31	//x
#define m_TileRowEA 32	//y
#define NOT_POINT_TILE POINT{-1,-1}


//======================================
//## 메인게임 릴리즈에서 사용하는 녀석##
//======================================
#define SAFE_DELETE(p) {if(p) { delete(p); (p) = nullptr;} }

//================================================
//             Singleton Macro                  //
//================================================
#define DECLARE_SINGLE(TYPE) \
static TYPE* mInst; \
\
public: \
	static TYPE* GetInst() {\
		if (!mInst)\
			return mInst = new TYPE;\
		return mInst;\
	}\
	void Destroy() {\
		SAFE_DELETE(mInst);\
	} \
private:\
	TYPE();\
	~TYPE();

#define DEFINITION_SINGLE(TYPE) TYPE* TYPE::mInst = nullptr;
#define GET_SINGLE(TYPE) TYPE::GetInst()
#define RELEASE_SINGLE(TYPE) TYPE::GetInst()->Destroy()

//================================================
//전역변수(인스턴스, 윈도우 핸들, 마우스 좌표)  ##
//================================================
extern HINSTANCE m_hInstance;
extern HWND m_hWnd;
extern POINT m_ptMouse;
extern bool m_bLoop;
extern bool m_showFPS;
extern bool m_showRect;
extern bool m_debugMode;

///

inline bool operator==(const POINT& a, const POINT& b) 
{
	if (a.x == b.x && a.y == b.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
inline bool operator!=(const POINT& a, const POINT& b)
{
	if (a.x != b.x || a.y != b.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

