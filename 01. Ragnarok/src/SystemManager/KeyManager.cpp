#include "stdafx.h"
#include "keyManager.h"
DEFINITION_SINGLE(KeyManager)

KeyManager::KeyManager()
{
}


KeyManager::~KeyManager()
{
}

HRESULT KeyManager::init()
{
	//키가 전부 눌려있지 않은 상태로 초기화하자
	for (int i = 0; i < KEYMAX; i++) {
		_keyUp.set(i, false);
		_keyDown.set(i, false);
	}

	playerKey[P1_UP] = VK_UP;
	playerKey[P1_DOWN] = VK_DOWN;
	playerKey[P1_LEFT] = VK_LEFT;
	playerKey[P1_RIGHT] = VK_RIGHT;
	playerKey[P1_EVENT] = VK_SPACE;
	playerKey[P1_USEITEM] = VK_TAB;
	playerKey[GAME_STAT] = 'E';
	playerKey[GAME_INVEN] = 'I';
	playerKey[GAME_SKILL] = 'S';
	playerKey[GAME_1] = '1';
	playerKey[GAME_2] = '2';
	playerKey[GAME_3] = '3';
	playerKey[GAME_4] = '4';

	playerKey[GAME_A] = 'A';
	playerKey[GAME_B] = 'B';
	playerKey[GAME_C] = 'C';
	playerKey[GAME_D] = 'D';
	playerKey[GAME_E] = 'E';
	playerKey[GAME_F] = 'F';
	playerKey[GAME_G] = 'G';
	playerKey[GAME_H] = 'H';
	playerKey[GAME_I] = 'I';
	playerKey[GAME_J] = 'J';
	playerKey[GAME_K] = 'K';
	playerKey[GAME_L] = 'L';
	playerKey[GAME_M] = 'M';
	playerKey[GAME_N] = 'N';
	playerKey[GAME_O] = 'O';
	playerKey[GAME_P] = 'P';
	playerKey[GAME_Q] = 'Q';
	playerKey[GAME_R] = 'R';
	playerKey[GAME_S] = 'S';
	playerKey[GAME_T] = 'T';
	playerKey[GAME_U] = 'U';
	playerKey[GAME_V] = 'V';
	playerKey[GAME_W] = 'W';
	playerKey[GAME_X] = 'X';
	playerKey[GAME_Y] = 'Y';
	playerKey[GAME_Z] = 'Z';
	playerKey[GAME_BACK] = VK_BACK;
	playerKey[GAME_SPACE] = VK_SPACE;


	playerKey[GAME_SHOWFPS] = VK_F1;
	playerKey[GAME_RECTMODE] = VK_F2;
	playerKey[GAME_DEBUGMODE] = VK_F3;
	playerKey[GAME_RTT] = VK_F4;
	playerKey[GAME_LMOUSE] = VK_LBUTTON;
	playerKey[GAME_RMOUSE] = VK_RBUTTON;
	playerKey[GAME_ENTER] = VK_RETURN;

	return S_OK;
}

void KeyManager::release()
{
}

bool KeyManager::isOnceKeyDown(int key)
{
	//GetAsyncKeyState현재 키의 상태를 알아오는 녀석
	//키가 눌려졌을때나 떨어졌을때 호출
	//0x8000 이전에는 누른적이 없고 호출시점에서 눌린상태
	if (GetAsyncKeyState(playerKey[key]) & 0x8000)
	{
		if (!_keyDown[playerKey[key]]) {
			_keyDown.set(playerKey[key], true);
			return true;
		}
	}
	else _keyDown.set(playerKey[key], false);
	return false;
}

bool KeyManager::isOnceKeyUp(int key)
{
	if (GetAsyncKeyState(playerKey[key]) & 0x8000)
		_keyUp.set(playerKey[key], true);
	else {
		if (_keyUp[playerKey[key]]) {
			_keyUp.set(playerKey[key], false);
			return true;
		}
	}
	return false;
}

bool KeyManager::isStayKeyDown(int key)
{
	if (GetAsyncKeyState(playerKey[key]) & 0x8000)
		return true;
	return false;
}

bool KeyManager::isToggleKey(int key)
{

	//GetKeyState :현재 키의 토글상태
	//0x0001이전에 누른적이 있고 호출시점에서 안눌린 상태
	if (GetKeyState(playerKey[key]) & 0x0001)
		return true;
	return false;
}

void KeyManager::setCustomKey(int dest, int userKey)
{
	playerKey[dest] = userKey;
}
