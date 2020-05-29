#include "stdafx.h"
#include "Npc.h"

npc::~npc()
{
}
bool npc::init(int startX, int startY)
{
	m_npc = UTIL::IRectMake(startX * WIDTH + OFFSETX, startY * HEIGHT + OFFSETY, WIDTH, HEIGHT);
	m_name = "유나";

	m_npc_PosX = startX;
	m_npc_PosY = startY;

	prvPos = { m_npc_PosX, m_npc_PosY };

	CAMERAMANAGER->rectInCamera(m_outnpc, m_npc, isCanprint);

	zondagirl_img = IMAGEMANAGER->findImage("npc_zondagirl");
	ANIMANAGER->addAnimation("npc_zondagirl", "npc_zondagirl", 0, 9, 8, false, true);

	ani_zondagirl = ANIMANAGER->findAnimation("npc_zondagirl");
	return true;
}
void npc::release()
{
}
void npc::update(float _deltaTime)
{
	CAMERAMANAGER->rectInCamera(m_outnpc, m_npc, isCanprint);
	CAMERAMANAGER->update();


	POINT m_npc_Pos = { m_npc_PosX, m_npc_PosY };

	settilenpc(m_npc_Pos);
	
	

	ANIMANAGER->resume("npc_zondagirl");
}
void npc::render(HDC hdc)
{
	

	zondagirl_img->aniRender(hdc, m_outnpc.left-10 , m_outnpc.top-50, ani_zondagirl);
	if (isShowName == true)
	{
		UTIL::PrintText(hdc, m_name.c_str(), "",700, m_outnpc.left + 10, m_outnpc.bottom + 5, 24, RGB(255, 0, 0), true, RGB(0, 0, 0));
	}
}
void npc::afterRender(HDC hdc)
{

}
void npc::debugRender(HDC hdc)
{
	UTIL::DrawColorRect(hdc, m_outnpc, RGB(0, 0, 255), false);
	UTIL::DrawColorRect(hdc, npc_target, RGB(0, 255, 0), false);
}

POINT npc::getTileindex()
{
	{
		return { m_npc_PosX,m_npc_PosY };
	}
}

void npc::settilenpc(POINT _XY)
{
	return (m_Tiles)[_XY.x + _XY.y * m_TileColEA].setisNpc(true);
}

