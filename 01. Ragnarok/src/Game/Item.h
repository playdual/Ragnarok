#pragma once
#include "Common/SystemManagers.h"
struct Item_struct
{
	std::string Item_name;
	std::string Item_type;
	std::string Item_clothes; //타입이 장비라면 입을 슬롯
	UTIL::IRECT Item_icon_rect;
	UTIL::IRECT Item_des_rect;
	Image* Item_icon_image;
	Image* Item_des_mini_image;
	Image* Item_des_image;
	int Item_ea;
	int Item_sell_price;
	int Item_buy_price;	
	int Item_weight;
	
	std::string Item_effect_type;
	int Item_effect;

	std::string Item_des;

};


class Item
{
public:
	void init();
	void release();
	void update();

	Item_struct Item_collect(std::string _itemname, int _ea);



private:
	DECLARE_SINGLE(Item)
};

#define ITEM Item::GetInst()