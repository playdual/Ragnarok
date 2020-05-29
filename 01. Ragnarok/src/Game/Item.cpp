#include "stdafx.h"
#include "Game/Item.h"
DEFINITION_SINGLE(Item)


Item::Item() {}
Item::~Item() {}

void Item::init()
{
}

void Item::release()
{
}

void Item::update()
{
}

Item_struct Item::Item_collect(std::string _itemname, int _ea)
{

	if (_itemname == "젤로피")
	{
		Item_struct zelopy;

		zelopy.Item_name = "젤로피";
		zelopy.Item_type = "기타";
		zelopy.Item_clothes = ""; //타입이 장비라면 입을 슬롯
		zelopy.Item_icon_rect;
		zelopy.Item_des_rect;
		zelopy.Item_icon_image = IMAGEMANAGER->findImage("젤로피");
		zelopy.Item_des_mini_image = IMAGEMANAGER->findImage("젤로피_des");
		zelopy.Item_des_image = IMAGEMANAGER->findImage("item_des_ui");
		zelopy.Item_ea = _ea;
		zelopy.Item_sell_price = 50;
		zelopy.Item_buy_price = 100;
		zelopy.Item_effect_type = "";
		zelopy.Item_effect = 0;
		zelopy.Item_des = "몬스터에게서 발견되는 보석";
		zelopy.Item_weight = 5;

		return zelopy;
	}

	if (_itemname == "빨간포션")
	{
		Item_struct red_potion;

		red_potion.Item_name = "빨간포션";
		red_potion.Item_type = "소비";
		red_potion.Item_clothes = ""; //타입이 장비라면 입을 슬롯
		red_potion.Item_icon_rect;
		red_potion.Item_des_rect;
		red_potion.Item_icon_image = IMAGEMANAGER->findImage("빨간포션");
		red_potion.Item_des_mini_image = IMAGEMANAGER->findImage("빨간포션_des");
		red_potion.Item_des_image = IMAGEMANAGER->findImage("item_des_ui");
		red_potion.Item_ea = _ea;
		red_potion.Item_sell_price = 75;
		red_potion.Item_buy_price = 150;
		red_potion.Item_effect_type = "HP";
		red_potion.Item_effect = 30;
		red_potion.Item_des = "빨간허브를 갈아넣어 만든 포션";
		red_potion.Item_weight = 5;
		return red_potion;
	}

	if (_itemname == "파란포션")
	{
		Item_struct blue_potion;
		blue_potion.Item_name = "파란포션";
		blue_potion.Item_type = "소비";
		blue_potion.Item_clothes = ""; //타입이 장비라면 입을 슬롯
		blue_potion.Item_icon_rect;
		blue_potion.Item_des_rect;
		blue_potion.Item_icon_image = IMAGEMANAGER->findImage("파란포션");
		blue_potion.Item_des_mini_image = IMAGEMANAGER->findImage("파란포션_des");
		blue_potion.Item_des_image = IMAGEMANAGER->findImage("item_des_ui");
		blue_potion.Item_ea = _ea;
		blue_potion.Item_sell_price = 100;
		blue_potion.Item_buy_price = 200;
		blue_potion.Item_effect_type = "SP";
		blue_potion.Item_effect = 30;
		blue_potion.Item_des = "파란허브를 갈아넣어 만든 포션";
		blue_potion.Item_weight = 5;
		return blue_potion;
	}

}



