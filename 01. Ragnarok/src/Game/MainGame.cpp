#include "stdafx.h"
#include "MainGame.h"
#include "GameScene/SampleScene.h"
#include "GameScene/IntroScene.h"

//#include "../example/ExScene/ExAnimationManagerScene.h"
//#include "../example/ExScene/ExEffectManagerScene.h"

MainGame::MainGame()
{
}
MainGame::~MainGame()
{
}

HRESULT MainGame::init()
{
	GameNode::init();

	//Image
	//intro
	IMAGEMANAGER->addImage("main_bg", "Images/Intro/bgi_temp.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("create_player_off", "Images/Intro/img_slot2_over.bmp", 255, 312, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("create_player_on", "Images/Intro/img_slot_select1.bmp", 255, 312, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("main_info", "Images/Intro/img_info.bmp", 172, 312, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("reset_Btn", "Images/Intro/bt_info_over.bmp", 45, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("create_Btn", "Images/Intro/btn_create_over.bmp", 68, 20, true, RGB(255, 0, 255));

	//player_body
	IMAGEMANAGER->addFrameImage("player_base", "Images/player/player_base.bmp", 320, 77, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_move_1", "Images/player/player_move_1.bmp", 384, 71, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_move_3", "Images/player/player_move_3.bmp", 384, 66, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_move_5", "Images/player/player_move_5.bmp", 352, 71, 8, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_move_6", "Images/player/player_move_6.bmp", 352, 75, 8, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("player_move_7", "Images/player/player_move_7.bmp", 352, 71, 8, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("player_move_9", "Images/player/player_move_9.bmp", 384, 66, 8, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("player_move_10", "Images/player/player_move_10.bmp", 384, 71, 8, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("player_move_12", "Images/player/player_move_12.bmp", 320, 70, 8, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("player_attack_1", "Images/player/player_attack_1.bmp", 52, 693, 1, 9, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_attack_5", "Images/player/player_attack_5.bmp", 64, 603, 1, 9, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_attack_7", "Images/player/player_attack_7.bmp", 64, 603, 1, 9, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_attack_10", "Images/player/player_attack_10.bmp", 52, 693, 1, 9, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_attackwait_1", "Images/player/player_attackwait_1.bmp", 44, 480, 1, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_attackwait_5", "Images/player/player_attackwait_5.bmp", 52, 450, 1, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_attackwait_7", "Images/player/player_attackwait_7.bmp", 56, 450, 1, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_attackwait_10", "Images/player/player_attackwait_10.bmp", 40, 480, 1, 6, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_damaged_1", "Images/player/player_damaged_1.bmp", 144, 60, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_damaged_5", "Images/player/player_damaged_5.bmp", 96, 62, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_damaged_7", "Images/player/player_damaged_7.bmp", 96, 62, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_damaged_10", "Images/player/player_damaged_10.bmp", 144, 60, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_die", "Images/player/player_die.bmp", 68, 53, 1, 1, true, RGB(255, 0, 255));


	//player_head
	IMAGEMANAGER->addFrameImage("player_head_base", "Images/player/player_head.bmp", 256, 26, 8, 1, true, RGB(255, 255, 255));
	IMAGEMANAGER->addFrameImage("player_head_move_1", "Images/player/player_head_move_1.bmp", 224, 28, 8, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("player_head_move_3", "Images/player/player_head_move_3.bmp", 224, 28, 8, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("player_head_move_5", "Images/player/player_head_move_5.bmp", 224, 28, 8, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("player_head_move_6", "Images/player/player_head_move_6.bmp", 224, 28, 8, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("player_head_move_7", "Images/player/player_head_move_7.bmp", 224, 28, 8, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("player_head_move_9", "Images/player/player_head_move_9.bmp", 224, 28, 8, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("player_head_move_10", "Images/player/player_head_move_10.bmp", 224, 28, 8, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("player_head_move_12", "Images/player/player_head_move_12.bmp", 224, 28, 8, 1, true, RGB(0, 0, 0));
	IMAGEMANAGER->addFrameImage("player_head_attack_1", "Images/player/player_head_attack_1.bmp", 468, 39, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_head_attack_5", "Images/player/player_head_attack_5.bmp", 504, 48, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_head_attack_7", "Images/player/player_head_attack_7.bmp", 504, 48, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_head_attack_10", "Images/player/player_head_attack_10.bmp", 468, 39, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_head_attackwait_1", "Images/player/player_head_attackwait_1.bmp", 168, 29, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_head_attackwait_5", "Images/player/player_head_attackwait_5.bmp", 168, 29, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_head_attackwait_7", "Images/player/player_head_attackwait_7.bmp", 168, 29, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_head_attackwait_10", "Images/player/player_head_attackwait_10.bmp", 168, 29, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_head_damaged_1", "Images/player/player_head_damaged_1.bmp", 96, 27, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_head_damaged_5", "Images/player/player_head_damaged_5.bmp", 108, 27, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_head_damaged_7", "Images/player/player_head_damaged_7.bmp", 108, 27, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_head_damaged_10", "Images/player/player_head_damaged_10.bmp", 108, 27, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player_head_die", "Images/player/player_head_die.bmp", 28, 25, 1, 1, true, RGB(255, 0, 255));


	//player_weapon
	IMAGEMANAGER->addFrameImage("weapon_dangum_wait_1", "Images/player/weapon/weapon_dangum_wait_1.bmp", 168, 16, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("weapon_dangum_wait_5", "Images/player/weapon/weapon_dangum_wait_5.bmp", 192, 17, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("weapon_dangum_wait_7", "Images/player/weapon/weapon_dangum_wait_7.bmp", 192, 17, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("weapon_dangum_wait_10", "Images/player/weapon/weapon_dangum_wait_10.bmp", 168, 16, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("weapon_dangum_attack_1", "Images/player/weapon/weapon_dangum_attack_1.bmp", 540, 26, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("weapon_dangum_attack_5", "Images/player/weapon/weapon_dangum_attack_5.bmp", 756, 20, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("weapon_dangum_attack_7", "Images/player/weapon/weapon_dangum_attack_7.bmp", 756, 20, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("weapon_dangum_attack_10", "Images/player/weapon/weapon_dangum_attack_10.bmp", 540, 26, 9, 1, true, RGB(255, 0, 255));
	

	//monster
	IMAGEMANAGER->addFrameImage("poring_1", "Images/monster/poring/poring_1.bmp", 220, 50, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poring_5", "Images/monster/poring/poring_5.bmp", 220, 50, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poring_7", "Images/monster/poring/poring_7.bmp", 220, 50, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poring_10", "Images/monster/poring/poring_10.bmp", 220, 50, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poring_move_1", "Images/monster/poring/poring_move_1.bmp", 550, 50, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poring_move_5", "Images/monster/poring/poring_move_5.bmp", 550, 55, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poring_move_7", "Images/monster/poring/poring_move_7.bmp", 550, 55, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poring_move_10", "Images/monster/poring/poring_move_10.bmp", 550, 50, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poring_damage_1", "Images/monster/poring/poring_damage_1.bmp", 325, 46, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poring_damage_5", "Images/monster/poring/poring_damage_5.bmp", 300, 46, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poring_damage_7", "Images/monster/poring/poring_damage_7.bmp", 300, 46, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poring_damage_10", "Images/monster/poring/poring_damage_10.bmp", 300, 46, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poring_attack_1", "Images/monster/poring/poring_attack_1.bmp", 1960, 64, 28, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poring_attack_5", "Images/monster/poring/poring_attack_5.bmp", 2100, 55, 28, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poring_attack_7", "Images/monster/poring/poring_attack_7.bmp", 2100, 55, 28, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poring_attack_10", "Images/monster/poring/poring_attack_10.bmp", 1960, 64, 28, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("poring_die", "Images/monster/poring/poring_die.bmp", 88, 77, 1, 1, true, RGB(255, 0, 255));

	//npc
	IMAGEMANAGER->addFrameImage("npc_cursor", "Images/npc/npc_cursor.bmp", 288, 23, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("npc_zondagirl", "Images/npc/zondagirl.bmp", 560, 91, 10, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("npc_base", "Images/npc/laime_evenor01.bmp", 349, 445, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("npc_smile", "Images/npc/laime_evenor02.bmp", 349, 445, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("npc_gugjung", "Images/npc/laime_evenor04.bmp", 349, 445, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("npc_bg", "Images/npc/npc_bg.bmp", 277, 178, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("npc_ok", "Images/npc/btn_ok_a.bmp", 42, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("npc_next", "Images/npc/btn_next_a.bmp", 42, 20, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("wing", "Images/player/wing.bmp", 6944, 195, 28, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wing_wing", "Images/player/wing_wing.bmp", 7072, 206, 26, 1, true, RGB(255, 0, 255));

	//Item
	IMAGEMANAGER->addImage("젤로피", "Images/Item/젤로피.bmp", 20, 16, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("빨간포션", "Images/Item/빨간포션.bmp", 25, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("파란포션", "Images/Item/파란포션.bmp", 25, 20, true, RGB(255, 0, 255));

	//item_des
	IMAGEMANAGER->addImage("item_des_ui", "Images/ui/skillcollection.bmp", 300, 130, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("젤로피_des", "Images/Item/젤로피_des.bmp", 75, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("빨간포션_des", "Images/Item/빨간포션_des.bmp", 75, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("파란포션_des", "Images/Item/파란포션_des.bmp", 75, 100, true, RGB(255, 0, 255));


	//Tile_prontera 
	IMAGEMANAGER->addImage("pron_bot_01", "Images/tile/pd_bot01.bmp", 240, 240, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("prt_wall01", "Images/tile/prt_wall01.bmp", 240, 240, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("prt_wall02", "Images/tile/prt_wall02.bmp", 240, 240, true, RGB(255, 0, 255));
	
	//Ui
	IMAGEMANAGER->addImage("chat_bg", "Images/ui/chat_bg.bmp", 467, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("chat_on", "Images/ui/chat_on.bmp", 467, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("black_bg", "Images/ui/black.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("black_bg_quest", "Images/ui/black.bmp", 200, 60, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addFrameImage("cursor_base", "Images/ui/cursor_base.bmp", 196, 32, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("cursor_add", "Images/ui/add_cursors.bmp", 32, 23, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("cursor_add_select", "Images/ui/add_cursors_select.bmp", 32, 23, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("cursor_attack", "Images/ui/attack_cursors.bmp", 24, 19, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("dest_tile", "Images/ui/dest_tile.bmp", WIDTH, HEIGHT, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("base_ui", "Images/ui/basewin_bg.bmp", 280, 120, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("stat_ui", "Images/ui/statwin_bg.bmp", 280, 103, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("stat_btn_on_ui", "Images/ui/btn_status_on.bmp", 30, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("stat_btn_off_ui", "Images/ui/btn_status_off.bmp", 30, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("skill_btn_on_ui", "Images/ui/btn_skill_on.bmp", 30, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("skill_btn_off_ui", "Images/ui/btn_skill_off.bmp", 30, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("skill_ui", "Images/ui/skillcollection.bmp", 280, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("skill_des_ui", "Images/ui/skillcollection.bmp", 300, 120, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("plus_btn", "Images/ui/plus_btn.bmp", 10, 10, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("item_btn_on_ui", "Images/ui/btn_items_on.bmp", 30, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("item_btn_off_ui", "Images/ui/btn_items_off.bmp", 30, 20, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("item_ui", "Images/ui/skillcollection.bmp", 280, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("item_des_ui", "Images/ui/skillcollection.bmp", 300, 120, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tab_use", "Images/ui/tab_itm_01.bmp", 20, 82, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tab_equip", "Images/ui/tab_itm_02.bmp", 20, 82, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("tab_kind", "Images/ui/tab_itm_03.bmp", 20, 82, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("item_get", "Images/ui/item_get.bmp", 150, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("item_shadow", "Images/ui/itemwin_mid.bmp", 32, 32, true, RGB(255, 255, 255));

	IMAGEMANAGER->addImage("ui_info_bar", "Images/ui/titlebar_fix.bmp", 300, 17, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ui_info_bar_cancle", "Images/ui/sys_close_off.bmp", 11, 11, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ui_bar", "Images/ui/titlebar_fix.bmp", 280, 17, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ui_bar_cancle", "Images/ui/sys_close_off.bmp", 11, 11, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ui_minicircle_on", "Images/ui/sys_base_on.bmp", 11, 11, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ui_minicircle_off", "Images/ui/sys_base_off.bmp", 11, 11, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ui_stat_add", "Images/ui/arw_right.bmp", 11, 11, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ui_gaze_left", "Images/ui/gzeblue_left.bmp", 4, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ui_gaze_mid", "Images/ui/gzeblue_mid.bmp", 77, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ui_gaze_right", "Images/ui/gzeblue_right.bmp", 4, 8, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("die_ui", "Images/ui/skillcollection.bmp", 280, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("choose_bar", "Images/ui/field_name_bg.bmp", 200, 20, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addImage("damage0", "Images/ui/Damage_0.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("damage1", "Images/ui/Damage_1.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("damage2", "Images/ui/Damage_2.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("damage3", "Images/ui/Damage_3.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("damage4", "Images/ui/Damage_4.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("damage5", "Images/ui/Damage_5.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("damage6", "Images/ui/Damage_6.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("damage7", "Images/ui/Damage_7.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("damage8", "Images/ui/Damage_8.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("damage9", "Images/ui/Damage_9.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Reddamage0", "Images/ui/Damage_Red_0.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Reddamage1", "Images/ui/Damage_Red_1.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Reddamage2", "Images/ui/Damage_Red_2.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Reddamage3", "Images/ui/Damage_Red_3.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Reddamage4", "Images/ui/Damage_Red_4.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Reddamage5", "Images/ui/Damage_Red_5.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Reddamage6", "Images/ui/Damage_Red_6.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Reddamage7", "Images/ui/Damage_Red_7.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Reddamage8", "Images/ui/Damage_Red_8.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Reddamage9", "Images/ui/Damage_Red_9.bmp", 16, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("target", "Images/ui/target.bmp", 15, 15, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("shadow_base", "Images/ui/shadow_base.bmp", 42, 42, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("shadow_base_poring", "Images/ui/shadow_base.bmp", 48, 42, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("quickslot", "Images/ui/quickslot.bmp", 77, 34, true, RGB(255, 0, 255));



	//skill
	IMAGEMANAGER->addImage("skill_no_ui", "Images/ui/no_skill.bmp", 24, 24, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Novice_basefunction", "Images/ui/novice_icon.bmp", 30, 30, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Novice_basefunction", "Images/ui/novice_icon.bmp", 30, 30, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Novice_emergencyheal", "Images/ui/heal_icon.bmp", 30, 30, true, RGB(255, 0, 255));
	//add Scene
	SCENEMANAGER->addScene("Intro", new IntroScene);
	SCENEMANAGER->addScene("Sample", new SampleScene);
	SCENEMANAGER->changeScene("Intro");



	//sound
	SOUNDMANAGER->addStream("title", "Sounds/01.mp3", true);
	SOUNDMANAGER->addStream("pron", "Sounds/08.mp3", true);
	SOUNDMANAGER->addStream("heal", "Sounds/heal.mp3", false);
	SOUNDMANAGER->addStream("levelup", "Sounds/levelup.mp3", false);
	SOUNDMANAGER->addStream("player_damaged", "Sounds/player_damaged.mp3", false);
	SOUNDMANAGER->addStream("poring_die", "Sounds/poring_die.mp3", false);
	SOUNDMANAGER->addStream("attack", "Sounds/attack.mp3", false);
	SOUNDMANAGER->addStream("effect", "Sounds/effect.mp3", false);
	SOUNDMANAGER->playSound("title", Channel::eChannelBgm);

	sceneInit = true;
	return S_OK;
}

void MainGame::release()
{
	GameNode::release();
}

void MainGame::update()
{
	if (KEYMANAGER->isOnceKeyDown(GAME_RECTMODE))
		m_showRect = !m_showRect;
	if (KEYMANAGER->isOnceKeyDown(GAME_SHOWFPS))
		m_showFPS = !m_showFPS;

	TIMEMANAGER->update(60.f);
	deltaTime = TIMEMANAGER->getElapsedTime();
	EFFECTMANAGER->update();
	SCENEMANAGER->update(deltaTime);
	ANIMANAGER->update(deltaTime);


}

void MainGame::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);

	SCENEMANAGER->render(getMemDC());
	SCENEMANAGER->afterRender(getMemDC());
	EFFECTMANAGER->render(getMemDC());
	if (m_showRect)
		SCENEMANAGER->debugRender(getMemDC());
	if (m_showFPS)
		TIMEMANAGER->render(getMemDC());

	getBackBuffer()->render(getHDC(), 0, 0);
}

LRESULT MainGame::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	if (sceneInit)
		return SCENEMANAGER->getCurScene()->SceneProc(hWnd, iMessage, wParam, lParam);
	else {
		switch (iMessage)
		{
		case WM_MOUSEMOVE:
			m_ptMouse.x = LOWORD(lParam);
			m_ptMouse.y = HIWORD(lParam);
			break;
		case WM_DESTROY:
			m_bLoop = false;
			PostQuitMessage(0);
			break;
		}
	}
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}