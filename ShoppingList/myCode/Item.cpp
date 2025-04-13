/*
 * Item.cpp
 *
 *  Created on: Apr 6, 2025
 *      Author: divya
 */

#include "Item.h"
#include <string>

Item::~Item()
{
	// TODO Auto-generated destructor stub
}

Item::Item(std::string name, std::string shop, int until):name(name),
		shop(shop),until(until)
{
}
std::string Item::getName()const
{
	return this->name;
}

std::string Item::getShop() const
{
	return this->shop;
}

int Item::getUntil() const
{
	return this->until;
}

std::string Item::toString() const
{
	std::string item;
	item = this->getName()+"("+getShop()+")";
	return item;
}

void Item::save(std::ostream &to) const
{
	to<<"Item;"<<getName()<<";"<<getShop()<<";"<<getUntil();

}

std::set<std::string> Item::getNotes()
{
	return std::set<std::string>();
}

Item* Item::restore(std::string line)
{
	std::string identifier;
	std::string name;
	std::string shopname;
	int until;
	identifier= splitAt(line,';');
	if(identifier=="Item")
	{
		auto pos=line.find(';');
		name = line.substr(0,pos);
		//std::cout<<name<<std::endl;
		line.erase(0,pos+1);
		auto pos2 =line.find(';');
	    shopname = line.substr(0,pos2);
		line.erase(0,pos2+1);
		until = stoi(line);
		//std::cout<<"Error"<<std::endl;

	}
	return new Item(name,shopname,until);
	//return new(name,shopname,until);
}

std::ostream& operator <<(std::ostream &lhs, const Item &item)
{
	lhs<<item.getName()<<" "<<item.getShop()<<" "<<item.getUntil()<<std::endl;
	return lhs;
}
