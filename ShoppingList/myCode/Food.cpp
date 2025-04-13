/*
 * Food.cpp
 *
 *  Created on: Apr 6, 2025
 *      Author: divya
 */

#include "Food.h"
#include "item.h"

Food::Food(std::string name, std::string shop, int until, bool needsCooling):
Item(name,shop,until),needsCooling(needsCooling)
{
}

bool Food::getNeedsCooling() const
{
	return this->needsCooling;
}

std::set<std::string> Food::getNotes() const
{
	if(!needsCooling)
	{
		return std::set<std::string>();
	}
	std::set<std::string>result;
	result.insert("One or more items require cooling!");
	return result;

}

std::string Food::toString() const
{
	std::cout<<"Error"<<std::endl;
	std::string result="[Keep cool!]";

	if(getNeedsCooling()==true)
	{
		result+=Item::toString();
		return result;
	}
	return Item::toString();
	//return Item::toString();
	//std::cout<<result<<std::endl;

}

void Food::save(std::ostream &to) const
{
	to<<"Food;";
	if(getNeedsCooling()==1)
	{
		Item::save(to);
		to<<";"<<"true";
		to<<std::endl;
	}
	else
	{
		Item::save(to);
		to<<";"<<"false";
		to<<std::endl;
	}
	//std::cout<<std::endl;

}

Food* Food::restore(std::string line)
{
	bool needscool;
	std::string cool;
	std::string extra;
	Item *it;
	std::string result = splitAt(line,';');
	if(result == "Food")
	{
		it = Item::restore(line);
	}
	std::string name = it->getName();
	std::string shop = it->getShop();
	int until = it->getUntil();
	cool = line;
	std::cout<<"Error"<<std::endl;
	//std::cout<<line<<std::endl;
	if(line.find("true")!=std::string::npos)
	{
		needscool = true;
	}
	else if(line.find("false")!=std::string::npos)
	{
		needscool = false;
	}
	return new Food(name,shop,until,needscool);
}

Food::~Food()
{
	// TODO Auto-generated destructor stub
}

